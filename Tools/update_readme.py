from __future__ import print_function
import sys
import io
import requests
import xml.etree.ElementTree as ET
import re

MANIFEST_URL = "https://raw.githubusercontent.com/rdkcentral/vendor-manifest-raspberrypi/{tag}/{manifest_name}.xml"

# Remove XML comments to avoid parsing commented or disabled sections
COMMENT_RE = re.compile(r'<!--.*?-->', re.DOTALL)

def fetch_manifest_xml(manifest_name, release_tag):
    if not manifest_name.endswith('.xml'):
        manifest_name += '.xml'
    url = MANIFEST_URL.format(tag=release_tag, manifest_name=manifest_name[:-4])
    resp = requests.get(url)
    if resp.status_code != 200:
        print("Failed to fetch manifest XML from {}".format(url))
        sys.exit(1)
    return resp.text

def parse_manifest(xml_text):
    # Remove XML comments
    xml_text = COMMENT_RE.sub('', xml_text)
    tree = ET.ElementTree(ET.fromstring(xml_text))
    root = tree.getroot()
    # Get Yocto version
    yocto_elem = root.find('yocto')
    yocto_version = yocto_elem.get('version') if yocto_elem is not None and yocto_elem.get('version') else 'Kirkstone'
    # Build table rows for all projects
    table_rows = []
    for project in root.findall('project'):
        name = project.get('name')
        revision = project.get('revision')
        if name and revision:
            table_rows.append('| {} | {} |'.format(name, revision))
    return yocto_version, table_rows

def main():
    if len(sys.argv) != 5:
        print("Setup requirements (one time): pip install requests")
        print("Usage: python Tools/update_readme.py Tools/README_TEMPLATE.md README.md <MANIFEST_NAME> <RELEASE_VERSION>")
        sys.exit(1)

    template_file = sys.argv[1]
    output_file = sys.argv[2]
    manifest_name = sys.argv[3]
    release_version = sys.argv[4]

    xml_text = fetch_manifest_xml(manifest_name, release_version)
    yocto_version, table_rows = parse_manifest(xml_text)

    with io.open(template_file, 'r', encoding='utf-8') as f:
        content = f.read()

    content = content.replace('<RELEASE_VERSION>', release_version)
    content = content.replace('<YOCTO_VERSION>', yocto_version)
    # Replace <LAYER_TABLE> with generated table
    table_md = '\n'.join(table_rows)
    content = content.replace('<LAYER_TABLE>', table_md)

    with io.open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)
    print("Updated README written to {}".format(output_file))

if __name__ == "__main__":
    main()
