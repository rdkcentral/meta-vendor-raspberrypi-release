# RaspberryPI Vendor Layer Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

## Vendor Release Details
| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [Vendor Release 4.11.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.11.0) |
| Yocto Version | kirkstone |
| Date          | 2026-03-26 18:00:11 UTC |

The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release 4.11.0](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.11.0) which aligns with below layer combination.

### Meta-layer Versions
| Layer | Current tag: 4.11.0 | Previous tag: 4.10.0 |
|-------|-----------------------|-----------------------|
| build-scripts | refs/tags/1.0.1 | refs/tags/1.0.1 |
| meta-image-support-rdke | refs/tags/1.0.0 | refs/tags/1.0.0 |
| meta-openembedded | refs/tags/rdk-4.0.0 | refs/tags/rdk-4.0.0 |
| meta-oss-common-config | refs/tags/1.4.0 | refs/tags/1.4.0 |
| meta-oss-vendor-raspberrypi | refs/tags/4.1.4 | refs/tags/4.1.3 |
| meta-product-raspberrypi | refs/tags/4.1.4 | refs/tags/4.1.3 |
| meta-raspberrypi | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf | ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf |
| meta-rdk-auxiliary | refs/tags/1.8.0 | refs/tags/1.7.0 |
| meta-rdk-halif-headers | refs/tags/4.1.4 | refs/tags/3.0.2 |
| meta-rdk-oss-reference | refs/tags/4.12.0 | refs/tags/4.10.0 |
| meta-stack-layering-support | refs/tags/3.2.0 | refs/tags/3.1.5 |
| meta-vendor-raspberrypi-dev | refs/tags/4.11.0 | refs/tags/4.10.0 |
| poky | refs/tags/rdk-4.6.0 | refs/tags/rdk-4.5.0 |
| rdke-common-config | refs/tags/1.0.20 | refs/tags/1.0.13 |
| rdke-stb-config | refs/tags/1.0.0 | refs/tags/1.0.0 |

* RDKE RaspberryPi Vendor build instructions -> [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi/tree/4.10.0?tab=readme-ov-file#vendor-manifest-for-raspberry-pi)
* RDKE RaspberryPi flashing instructions -> [here](https://wiki.rdkcentral.com/display/RDKM/Build+Setup+and+Flashing+Instructions)

## Release includes
* Upgrade OSS Version to 4.12.0 and common meta layers.
* Upgrade meta-rdk-halif-headers version to 4.1.4.
* Upgrade Westros to 1.01.64 for RDKM.
* update common-config to v1.0.20 with FACTORY_APPS_PATH.
* Build the Vulkan recipes from the oss-reference layer and removed it from vendor oss layer.
* Make new RDK AppManagers as default and disable RDKShell at runtime
* Fixed the SSH to device over LAN/wlan0 is not working issue.
* Fixed the Assert Error in GetHDRCapabilities.
* Fixed the EntServices : DeviceInfo.socname API return error response issue.
* Bring rdke-generic-manifest xmls in vendor layer manifests.
* Fixed the Bluetoothctl is not working in vendor image Ticket.
* Fixed the Video resolution: not able to select 2160p50 and 2160p60 and sometimes not listing issue.
* Fixed the Not able to set 576p resolution and it is displaying the resolution as Undefined under Settings/Video issue.
* Added the ctrlm_config.json remote configuration in /etc/vendor/input/ directory as part of vendor layer rootfs and removed from Image assembler.
* Configure the runtime required mount points for DAC Apps with respect to platform's partition logic.

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

--- 

For more instructions to refresh the contents referenced in this README see [UPDATE_GUIDE](Tools/UPDATE_GUIDE.md).

---
