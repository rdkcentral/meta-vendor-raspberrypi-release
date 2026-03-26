from __future__ import print_function
import sys
import io
import requests
import xml.etree.ElementTree as ET
import re
from datetime import datetime, timezone

COMMENT_RE = re.compile(r'<!--.*?-->', re.DOTALL)

def fetch_manifest_xml(repo_name, manifest_name, revision):
    # Add .xml if missing
    if not manifest_name.endswith('.xml'):
        manifest_name += '.xml'
    url = f"https://raw.githubusercontent.com/rdkcentral/{repo_name}/{revision}/{manifest_name}"
    resp = requests.get(url)
    if resp.status_code != 200:
        print(f"Failed to fetch manifest XML from {url}")
        sys.exit(1)
    return resp.text

def parse_manifest(repo_name, manifest_name, revision, parsed_manifests=None):
    if parsed_manifests is None:
        parsed_manifests = set()

    key = (repo_name, manifest_name, revision)
    if key in parsed_manifests:
        return None, {}
    parsed_manifests.add(key)

    xml_text = fetch_manifest_xml(repo_name, manifest_name, revision)
    xml_text = COMMENT_RE.sub('', xml_text)
    tree = ET.ElementTree(ET.fromstring(xml_text))
    root = tree.getroot()

    yocto_version = None
    if len(parsed_manifests) == 1:
        yocto_elem = root.find('yocto')
        yocto_version = yocto_elem.get('version') if yocto_elem is not None and yocto_elem.get('version') else "Kirkstone"

    meta_versions = {}
    for project in root.findall('project'):
        name = project.get('name')
        rev = project.get('revision')
        if name and rev:
            if name in meta_versions:
                print(f"Warning: Duplicate project name '{name}' found in manifests.")
            meta_versions[name] = rev

    for submanifest in root.findall('submanifest'):
        sm_repo = submanifest.get('project')
        sm_manifest_name = submanifest.get('manifest-name')
        sm_revision = submanifest.get('revision') or revision
        if sm_repo and sm_manifest_name:
            try:
                _, submeta = parse_manifest(sm_repo, sm_manifest_name, sm_revision, parsed_manifests)
                meta_versions.update(submeta)
            except Exception as e:
                print(f"Warning: Failed to parse submanifest {sm_repo}/{sm_revision}/{sm_manifest_name}: {e}")

    return yocto_version, meta_versions

def generate_table_single(meta_versions):
    rows = ["| Layer | Revision |", "|-------|----------|"]
    for k, v in meta_versions.items():
        rows.append(f"| {k} | {v} |")
    return "\n".join(rows)

def generate_table_compare(meta_new, meta_old, new_tag, old_tag):
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

    # Top-level always starts with repo = "vendor-manifest-raspberrypi"
    yocto_version, meta_new = parse_manifest('vendor-manifest-raspberrypi', manifest_name, new_release)

    if old_release:
        _, meta_old = parse_manifest('vendor-manifest-raspberrypi', manifest_name, old_release)
        table_md = generate_table_compare(meta_new, meta_old, new_release, old_release)
    else:
        table_md = generate_table_single(meta_new)

    with io.open(template_file, 'r', encoding='utf-8') as f:
        content = f.read()

    content = content.replace("<RELEASE_VERSION>", new_release)
    content = content.replace("<YOCTO_VERSION>", yocto_version if yocto_version else "Kirkstone")
    content = content.replace("<GEN_DATE>", datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC'))
    content = content.replace("{{VERSION_TABLE}}", table_md)

    with io.open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"Updated README written to {output_file}")

if __name__ == "__main__":
    main()