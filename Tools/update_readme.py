from __future__ import print_function
import re
import sys
import io

# Usage: python Tools/update_readme.py Tools/README_TEMPLATE.md README.md <RELEASE_VERSION> <STACK_LAYER_VERSION> <AUX_VERSION> <OSS_LAYERS_VERSION> <HALIF_HEADERS_VERSION> <VENDOR_OSS_VERSION> <PRODUCT_RPI_VERSION> <VENDOR_RPI_DEV_VERSION> <RASPBERRYPI_COMMIT>

def main():
    if len(sys.argv) != 12:
        print("Usage: python Tools/update_readme.py Tools/README_TEMPLATE.md README.md <RELEASE_VERSION> <STACK_LAYER_VERSION> <AUX_VERSION> <OSS_LAYERS_VERSION> <HALIF_HEADERS_VERSION> <VENDOR_OSS_VERSION> <PRODUCT_RPI_VERSION> <VENDOR_RPI_DEV_VERSION> <RASPBERRYPI_COMMIT>")
        sys.exit(1)

    template_file = sys.argv[1]
    output_file = sys.argv[2]
    placeholders = [
        '<RELEASE_VERSION>', '<STACK_LAYER_VERSION>', '<AUX_VERSION>', '<OSS_LAYERS_VERSION>',
        '<HALIF_HEADERS_VERSION>', '<VENDOR_OSS_VERSION>', '<PRODUCT_RPI_VERSION>', '<VENDOR_RPI_DEV_VERSION>', '<RASPBERRYPI_COMMIT>'
    ]
    values = sys.argv[3:]

    with io.open(template_file, 'r', encoding='utf-8') as f:
        content = f.read()

    for placeholder, value in zip(placeholders, values):
        content = content.replace(placeholder, value)

    with io.open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)
    print("Updated README written to {}".format(output_file))

if __name__ == "__main__":
    main()
