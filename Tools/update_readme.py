from __future__ import print_function
import sys
import io
import requests
import xml.etree.ElementTree as ET
import re
from datetime import datetime, timezone

MANIFEST_URL = "https://raw.githubusercontent.com/rdkcentral/vendor-manifest-raspberrypi/{tag}/{manifest_name}.xml"
COMMENT_RE = re.compile(r'<!--.*?-->', re.DOTALL)


def fetch_manifest_xml(manifest_name, release_tag):
    if not manifest_name.endswith('.xml'):
        manifest_name += '.xml'
    url = MANIFEST_URL.format(tag=release_tag, manifest_name=manifest_name[:-4])
    resp = requests.get(url)
    if resp.status_code != 200:
        print(f"Failed to fetch manifest XML from {url}")
        sys.exit(1)
    return resp.text


def parse_manifest(xml_text):
    """Parse manifest XML into dict {meta-layer: revision} + Yocto version."""
    xml_text = COMMENT_RE.sub('', xml_text)
    tree = ET.ElementTree(ET.fromstring(xml_text))
    root = tree.getroot()

    yocto_elem = root.find('yocto')
    yocto_version = yocto_elem.get('version') if yocto_elem is not None and yocto_elem.get('version') else "Kirkstone"

    meta_versions = {}
    for project in root.findall('project'):
        name = project.get('name')
        revision = project.get('revision')
        if name and revision:
            meta_versions[name] = revision

    return yocto_version, meta_versions


def generate_table_single(meta_versions):
    """Generate a 2-column table (name | revision)."""
    rows = ["| Layer | Revision |", "|-------|----------|"]
    for k, v in meta_versions.items():
        rows.append(f"| {k} | {v} |")
    return "\n".join(rows)


def generate_table_compare(meta_new, meta_old, new_tag, old_tag):
    """Generate a 3-column comparison table."""
    all_keys = sorted(set(meta_new.keys()).union(meta_old.keys()))
    rows = [
        f"| Layer | Current tag: {new_tag} | Previous tag: {old_tag} |",
        "|-------|-----------------------|-----------------------|"
    ]
    for key in all_keys:
        v1 = meta_new.get(key, "N/A")
        v2 = meta_old.get(key, "N/A")
        rows.append(f"| {key} | {v1} | {v2} |")
    return "\n".join(rows)


def main():
    if len(sys.argv) not in (5, 6):
        print("Usage for single:   python3 Tools/update_readme.py TEMPLATE.md README.md <manifest.xml> <release_tag>")
        print("Usage for compare:  python3 Tools/update_readme.py TEMPLATE.md README.md <manifest.xml> <new_tag> <old_tag>")
        sys.exit(1)

    template_file = sys.argv[1]
    output_file = sys.argv[2]
    manifest_name = sys.argv[3]
    new_release = sys.argv[4]
    old_release = sys.argv[5] if len(sys.argv) == 6 else None

    # Always parse new release
    xml_new = fetch_manifest_xml(manifest_name, new_release)
    yocto_version, meta_new = parse_manifest(xml_new)

    # If old release provided, fetch and compare
    if old_release:
        xml_old = fetch_manifest_xml(manifest_name, old_release)
        _, meta_old = parse_manifest(xml_old)
        table_md = generate_table_compare(meta_new, meta_old, new_release, old_release)
    else:
        table_md = generate_table_single(meta_new)

    with io.open(template_file, 'r', encoding='utf-8') as f:
        content = f.read()

    content = content.replace("<RELEASE_VERSION>", new_release)
    content = content.replace("<YOCTO_VERSION>", yocto_version)
    content = content.replace("<GEN_DATE>", datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC'))
    content = content.replace("{{VERSION_TABLE}}", table_md)

    with io.open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"Updated README written to {output_file}")


if __name__ == "__main__":
    main()
