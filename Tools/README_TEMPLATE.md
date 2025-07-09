# Vendor Layer Release Note
## RaspberryPI Vendor Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

### Vendor Release Details
The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release <RELEASE_VERSION>](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/<RELEASE_VERSION>) which aligns with below layer combination.

For a comprehensive list of changes, updates, and release history, refer to the [Changelog](CHANGELOG.md).

| Yocto Version | Kirkstone |
|--------------|-----------------|
| meta-stack-layering-support | [<STACK_LAYER_VERSION>](https://github.com/rdkcentral/meta-stack-layering-support/releases/tag/<STACK_LAYER_VERSION>) |
| meta-rdk-auxiliary | [<AUX_VERSION>](https://github.com/rdkcentral/meta-rdk-auxiliary/releases/tag/<AUX_VERSION>) |
| RDK OSS Layers | [<OSS_LAYERS_VERSION>](https://github.com/rdkcentral/rdke-oss-manifest/releases/tag/<OSS_LAYERS_VERSION>) |
| *meta-rdk-halif-headers* | [<HALIF_HEADERS_VERSION>](https://github.com/rdkcentral/meta-rdk-halif-headers/releases/tag/<HALIF_HEADERS_VERSION>) |
| meta-oss-vendor-raspberrypi | [<VENDOR_OSS_VERSION>](https://github.com/rdkcentral/meta-oss-vendor-raspberrypi/releases/tag/<VENDOR_OSS_VERSION>) |
| meta-product-raspberrypi | [<PRODUCT_RPI_VERSION>](https://github.com/rdkcentral/meta-product-raspberrypi/releases/tag/<PRODUCT_RPI_VERSION>) |
| meta-vendor-raspberrypi-dev | [<VENDOR_RPI_DEV_VERSION>](https://github.com/rdkcentral/meta-vendor-raspberrypi-dev/releases/tag/<VENDOR_RPI_DEV_VERSION>) |
| meta-raspberrypi | [<RASPBERRYPI_COMMIT>](https://git.yoctoproject.org/meta-raspberrypi/commit/?h=kirkstone&id=<RASPBERRYPI_COMMIT>) |

Refer RDKE RaspberryPi Vendor build instructions [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi?tab=readme-ov-file#vendor-manifest-raspberrypi)

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

---

#### How to update this README automatically

1. Generate and replace `VendorPackagesAndVersions.md` from vendor stack for the `<RELEASE_VERSION>`. See [variables.md](https://github.com/rdkcentral/meta-stack-layering-support/blob/main/docs/variables.md) for details on how to generate it.
2. Run `Tools/update_readme.py` script from base directory to generate the final README. Note: change to match Host's shell conventions and filesystem path syntax(Windows/Linux/Mac).
```sh
Usage: python ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md <RELEASE_VERSION> <STACK_LAYER_VERSION> <AUX_VERSION> <OSS_LAYERS_VERSION> <HALIF_HEADERS_VERSION> <VENDOR_OSS_VERSION> <PRODUCT_RPI_VERSION> <VENDOR_RPI_DEV_VERSION> <RASPBERRYPI_COMMIT>
```
- Replace the arguments with the actual release/tag/commit values matching the release.

Eg (Linux Host):
```sh
python ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md 4.5.0 2.0.1 1.3.0 4.6.2-community 3.0.0 4.0.5 4.0.9 4.5.0 ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf
```

---
