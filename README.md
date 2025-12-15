# RaspberryPI Vendor Layer Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

## Vendor Release Details
| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [Vendor Release 4.9.1](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.9.1) |
| Yocto Version | kirkstone |
| Date          | 2025-12-19 10:45:32 UTC |

The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release 4.9.1](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.9.1) which aligns with below layer combination.

### Meta-layer Versions
| Layer | Current tag: 4.9.1 | Previous tag: 4.9.0 |
|-------|-----------------------|-----------------------|
| build-scripts | refs/tags/1.0.1 | refs/tags/1.0.1 |
| meta-openembedded | refs/tags/rdk-4.0.0 | refs/tags/rdk-4.0.0 |
| meta-oss-common-config | refs/tags/1.3.1 | refs/tags/1.3.1 |
| meta-oss-reference-release | refs/tags/4.9.0 | refs/tags/4.9.0 |
| meta-oss-vendor-raspberrypi | refs/tags/4.1.2 | refs/tags/4.1.1 |
| meta-product-raspberrypi | refs/tags/4.1.2 | refs/tags/4.1.1 |
| meta-raspberrypi | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf |
| meta-rdk-auxiliary | refs/tags/1.6.0 | refs/tags/1.5.1 |
| meta-rdk-halif-headers | refs/tags/3.0.2 | refs/tags/3.0.2 |
| meta-rdk-oss-reference | refs/tags/4.9.0 | refs/tags/4.9.0 |
| meta-stack-layering-support | refs/tags/3.0.1 | refs/tags/3.0.1 |
| meta-vendor-raspberrypi-dev | refs/tags/4.9.1 | refs/tags/4.9.0 |
| poky | refs/tags/rdk-4.4.1 | refs/tags/rdk-4.4.1 |
| rdke-common-config | refs/tags/1.0.10 | refs/tags/1.0.8 |
| rdke-stb-config | refs/tags/1.0.0 | refs/tags/1.0.0 |
| meta-image-support-rdke | refs/tags/1.0.0 | refs/tags/1.0.0 |

* RDKE RaspberryPi Vendor build instructions -> [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi/tree/4.9.1?tab=readme-ov-file#vendor-manifest-for-raspberry-pi)
* RDKE RaspberryPi flashing instructions -> [here](https://wiki.rdkcentral.com/display/RDKM/Build+Setup+and+Flashing+Instructions)
* Extended release notes -> [here](https://wiki.rdkcentral.com/spaces/RDKM/pages/447127773/V4.9.1+Q4+M12-2025+Vendor+Layer+-+RPI+4+-+RDK+8+-+Release+-+RI+Engineering+-+Device+-+RDKE)

## Release includes
* Erofs file system support.
* Fix for Bluetooth HCI init status having Invalid BD address issue.
* Resolved Unable to perform SCP issue.
* Fix for Serial console got stuck with V4.1.1 product layer changes in upper layers.
* Update HDD_APP_MOUNT_PATH in device properties.
* Align the "rdke/vendor" path sub-directories with other reference platforms.

## Test Resultes
M12 Test results -> [Vendor](https://jira.rdkcentral.com/jira/browse/RDKEVL-7333) & [Full-Stack](https://jira.rdkcentral.com/jira/browse/RDKEVL-7334)
Test results are attached in docs folder (https://github.com/rdkcentral/meta-vendor-raspberrypi-release/releases/tags/4.9.1/docs).
For faster access, refer to the CSV files; the comprehensive results are documented in the Excel files.

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

--- 

For more instructions to refresh the contents referenced in this README see [UPDATE_GUIDE](Tools/UPDATE_GUIDE.md).

---
