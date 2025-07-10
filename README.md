# Vendor Layer Release Note
## RaspberryPI Vendor Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

### Vendor Release Details
The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release 4.5.1](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.5.1) which aligns with below layer combination.

For a comprehensive list of changes, updates, and release history, refer to the [Changelog](CHANGELOG.md).

| Yocto Version | Kirkstone |
|--------------|-----------------|
| meta-stack-layering-support | [3.0.0](https://github.com/rdkcentral/meta-stack-layering-support/releases/tag/3.0.0) |
| meta-rdk-auxiliary | [1.3.0](https://github.com/rdkcentral/meta-rdk-auxiliary/releases/tag/1.3.0) |
| RDK OSS Layers | [4.6.2-community](https://github.com/rdkcentral/rdke-oss-manifest/releases/tag/4.6.2-community) |
| *meta-rdk-halif-headers* | [3.0.0](https://github.com/rdkcentral/meta-rdk-halif-headers/releases/tag/3.0.0) |
| meta-oss-vendor-raspberrypi | [4.0.5](https://github.com/rdkcentral/meta-oss-vendor-raspberrypi/releases/tag/4.0.5) |
| meta-product-raspberrypi | [4.0.10](https://github.com/rdkcentral/meta-product-raspberrypi/releases/tag/4.0.10) |
| meta-vendor-raspberrypi-dev | [4.5.1](https://github.com/rdkcentral/meta-vendor-raspberrypi-dev/releases/tag/4.5.1) |
| meta-raspberrypi | [ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf](https://git.yoctoproject.org/meta-raspberrypi/commit/?h=kirkstone&id=ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf) |

Refer RDKE RaspberryPi Vendor build instructions [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi?tab=readme-ov-file#vendor-manifest-raspberrypi)

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

---

#### How to update this README automatically

1. Generate and replace `VendorPackagesAndVersions.md` from vendor stack for the `4.5.1`. See [variables.md](https://github.com/rdkcentral/meta-stack-layering-support/blob/main/docs/variables.md) for details on how to generate it.
2. Run `Tools/update_readme.py` script from base directory to generate the final README. Note: change to match Host's shell conventions and filesystem path syntax(Windows/Linux/Mac).
```sh
Usage: python ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md 4.5.1 3.0.0 1.3.0 4.6.2-community 3.0.0 4.0.5 4.0.10 4.5.1 ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf
```
- Replace the arguments with the actual release/tag/commit values matching the release.

Eg (Linux Host):
```sh
python ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md 4.5.0 2.0.1 1.3.0 4.6.2-community 3.0.0 4.0.5 4.0.9 4.5.0 ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf
```

---
