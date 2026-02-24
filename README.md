# RaspberryPI Vendor Layer Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

## Vendor Release Details
| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [Vendor Release 4.10.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.10.0) |
| Yocto Version | kirkstone |
| Date          | 2026-02-24 |

The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release 4.10.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.10.0) which aligns with below layer combination.

### Meta-layer Versions
| Layer | Current tag: 4.10.0 | Previous tag: 4.9.1 |
|-------|-----------------------|-----------------------|
| build-scripts | refs/tags/1.0.1 | refs/tags/1.0.1 |
| meta-openembedded | refs/tags/rdk-4.0.0 | refs/tags/rdk-4.0.0 |
| meta-oss-common-config | refs/tags/1.4.0 | refs/tags/1.3.1 |
| meta-oss-reference-release | NA | refs/tags/4.9.0 |
| meta-oss-vendor-raspberrypi | refs/tags/4.1.3 | refs/tags/4.1.2 |
| meta-product-raspberrypi | refs/tags/4.1.3 | refs/tags/4.1.2 |
| meta-raspberrypi | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf |
| meta-rdk-auxiliary | refs/tags/1.7.0 | refs/tags/1.6.0 |
| meta-rdk-halif-headers | refs/tags/3.0.2 | refs/tags/3.0.2 |
| meta-rdk-oss-reference | refs/tags/4.10.0 | refs/tags/4.9.0 |
| meta-stack-layering-support | refs/tags/3.1.5 | refs/tags/3.0.1 |
| meta-vendor-raspberrypi-dev | refs/tags/4.10.0 | refs/tags/4.9.1 |
| poky | refs/tags/rdk-4.5.0 | refs/tags/rdk-4.4.1 |
| rdke-common-config | refs/tags/1.0.13 | refs/tags/1.0.10 |
| rdke-stb-config | refs/tags/1.0.0 | refs/tags/1.0.0 |

* RDKE RaspberryPi Vendor build instructions -> [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi/tree/4.10.0?tab=readme-ov-file#vendor-manifest-for-raspberry-pi)
* RDKE RaspberryPi flashing instructions -> [here](https://wiki.rdkcentral.com/display/RDKM/Build+Setup+and+Flashing+Instructions)

## Release includes
* Upgrade OSS Version to 4.10.0.
* Supported new OSS consumption model architecture.
* Supported dm-verity for DAC 2.0.
* Supported gpu-layer implementations for DAC 2.0.
* Added support for CEC Source HAL v1.1.0
* Resolved the MSE playback not working issue on webkit browser.
* Resolved the SDK_VERSION showing unknown in version.txt issue.
* Fixed bluetooth not paring issue.

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

--- 

For more instructions to refresh the contents referenced in this README see [UPDATE_GUIDE](Tools/UPDATE_GUIDE.md).

---
