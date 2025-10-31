# RaspberryPI Vendor Layer Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

## Vendor Release Details
| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [Vendor Release 4.8.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.8.0) |
| Yocto Version | kirkstone |
| Date          | 2025-10-31 10:21:44 UTC |

The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release 4.8.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.8.0) which aligns with below layer combination.

### Meta-layer Versions
| Layer | Current tag: 4.8.0 | Previous tag: 4.7.0 |
|-------|-----------------------|-----------------------|
| build-scripts | refs/tags/1.0.1 | refs/tags/1.0.1 |
| meta-openembedded | refs/tags/rdk-4.0.0 | refs/tags/rdk-4.0.0 |
| meta-oss-common-config | refs/tags/1.3.0 | refs/tags/1.3.0 |
| meta-oss-reference-release | refs/tags/4.8.0 | refs/tags/4.7.4-community |
| meta-oss-vendor-raspberrypi | refs/tags/4.1.0 | refs/tags/4.1.0 |
| meta-product-raspberrypi | refs/tags/4.1.0 | refs/tags/4.1.0 |
| meta-raspberrypi | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf |
| meta-rdk-auxiliary | refs/tags/1.5.1 | refs/tags/1.5.1 |
| meta-rdk-halif-headers | refs/tags/3.0.2 | refs/tags/3.0.2 |
| meta-rdk-oss-reference | refs/tags/4.8.0 | refs/tags/4.7.4-community |
| meta-stack-layering-support | refs/tags/3.0.1 | refs/tags/3.0.1 |
| meta-vendor-raspberrypi-dev | refs/tags/4.8.0 | refs/tags/4.7.0 |
| poky | refs/tags/rdk-4.4.1 | refs/tags/rdk-4.4.1 |
| rdke-common-config | refs/tags/1.0.9 | refs/tags/1.0.8 |
| rdke-stb-config | refs/tags/1.0.0 | refs/tags/1.0.0 |

* RDKE RaspberryPi Vendor build instructions -> [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi?tab=readme-ov-file#vendor-manifest-raspberrypi)
* RDKE RaspberryPi flashing instructions -> [here](https://wiki.rdkcentral.com/display/RDKM/Build+Setup+and+Flashing+Instructions)

## Release includes
* Android Raspberrypi kernel upgrade to version 6.1 from 5.15.
Github path: https://github.com/android-rpi/kernel_arpi Branch: arpi14-6.1
* Vendor OSS version to 4.8.0.
* Upgrade rdke-common-config 1.0.9.
* Dummy nvram.service to fix systemd service failure on restart.
* HAL Implementation for Specific Methods in LEDControl Plugin.
* Implementation for org.rdk.DisplaySettings.1.getVideoFormat API failure.

## Test Resultes
M10 Test results [here](https://jira.rdkcentral.com/jira/browse/RDKEVL-6864)

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

--- 

For more instructions to refresh the contents referenced in this README see [UPDATE_GUIDE](Tools/UPDATE_GUIDE.md).

---
