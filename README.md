# RaspberryPI Vendor Layer Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

## Vendor Release Details
| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [Vendor Release RDK8-1.0.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/RDK8-1.0.0) |
| Yocto Version | kirkstone |
| Date          | 2026-05-04 11:55:15 UTC |

The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release RDK8-1.0.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/RDK8-1.0.0) which aligns with below layer combination.

### Meta-layer Versions
| Layer | Current tag: RDK8-1.0.0 | Previous tag: 4.11.0 |
|-------|-----------------------|-----------------------|
| build-scripts | refs/tags/1.0.1 | refs/tags/1.0.1 |
| meta-image-support-rdke | refs/tags/1.0.0 | refs/tags/1.0.0 |
| meta-openembedded | refs/tags/rdk-4.0.0 | refs/tags/rdk-4.0.0 |
| meta-oss-common-config | refs/tags/1.4.0 | refs/tags/1.4.0 |
| meta-oss-vendor-raspberrypi | refs/tags/4.1.5 | refs/tags/4.1.4 |
| meta-product-raspberrypi | refs/tags/4.1.4 | refs/tags/4.1.4 |
| meta-raspberrypi | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf |
| meta-rdk-auxiliary | refs/tags/1.8.0 | refs/tags/1.8.0 |
| meta-rdk-halif-headers | refs/tags/4.1.4 | refs/tags/4.1.4 |
| meta-rdk-oss-reference | refs/tags/4.12.0 | refs/tags/4.12.0 |
| meta-stack-layering-support | refs/tags/3.2.0 | refs/tags/3.2.0 |
| meta-vendor-raspberrypi-dev | refs/tags/4.11.1 | refs/tags/4.11.0 |
| poky | refs/tags/rdk-4.6.0 | refs/tags/rdk-4.6.0 |
| rdke-common-config | refs/tags/1.0.20 | refs/tags/1.0.20 |
| rdke-stb-config | refs/tags/1.0.0 | refs/tags/1.0.0 |

* RDKE RaspberryPi Vendor build instructions -> [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi/tree/4.10.0?tab=readme-ov-file#vendor-manifest-for-raspberry-pi)
* RDKE RaspberryPi flashing instructions -> [here](https://wiki.rdkcentral.com/display/RDKM/Build+Setup+and+Flashing+Instructions)

## Release includes
* REFPLTV-3098: Observing visible slowness For Installed Apps including YouTube.
* RDKMVE-2122: Pin libvcos.so to prevent TLS destructor crashes in client

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

--- 

For more instructions to refresh the contents referenced in this README see [UPDATE_GUIDE](Tools/UPDATE_GUIDE.md).

---
