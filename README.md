
# RDKE Vendor Layer 4.5.1 Release Note

| Summary       | Content |
|---------------|---------|
| Manifest URL  | https://github.com/rdkcentral/vendor-manifest-raspberrypi |
| Release Tag   | [4.5.1](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.5.1) |
| Yocto Version | kirkstone |
| Date          | 2025-07-23 04:01:34 UTC |
| Author        | support@rdkcentral.com |


### Vendor Release Details
The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing Vendor-supplied package names and their versions of [Vendor Release 4.5.1](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/4.5.1) which aligns with below layer combination.

For a comprehensive list of changes, updates, and release history, refer to the [Changelog](CHANGELOG.md).

Test Report: Contact support@rdkcentral.com

| Layer Name | Current Revision/Tag |
|------------|-------------------|
| build-scripts | [1.0.1](https://github.com/rdkcentral/build-scripts/tree/1.0.1) |
| meta-stack-layering-support | [3.0.0](https://github.com/rdkcentral/meta-stack-layering-support/tree/3.0.0) |
| meta-rdk-auxiliary | [1.3.0](https://github.com/rdkcentral/meta-rdk-auxiliary/tree/1.3.0) |
| meta-openembedded | [rdk-4.0.0](https://github.com/rdkcentral/meta-openembedded/tree/rdk-4.0.0) |
| poky | [rdk-4.2.1](https://github.com/rdkcentral/poky/tree/rdk-4.2.1) |
| meta-oss-reference-release | [4.6.2-community](https://github.com/rdkcentral/meta-oss-reference-release/tree/4.6.2-community) |
| meta-rdk-oss-reference | [1.2.0](https://github.com/rdkcentral/meta-rdk-oss-reference/tree/1.2.0) |
| meta-oss-common-config | [1.1.0](https://github.com/rdkcentral/meta-oss-common-config/tree/1.1.0) |
| meta-rdk-halif-headers | [3.0.0](https://github.com/rdkcentral/meta-rdk-halif-headers/tree/3.0.0) |
| rdke-stb-config | [1.0.0](https://github.com/rdkcentral/rdke-stb-config/tree/1.0.0) |
| rdke-common-config | [1.0.4](https://github.com/rdkcentral/rdke-common-config/tree/1.0.4) |
| meta-oss-vendor-raspberrypi | [4.0.5](https://github.com/rdkcentral/meta-oss-vendor-raspberrypi/tree/4.0.5) |
| meta-product-raspberrypi | [4.0.10](https://github.com/rdkcentral/meta-product-raspberrypi/tree/4.0.10) |
| meta-vendor-raspberrypi-dev | [4.5.1](https://github.com/rdkcentral/meta-vendor-raspberrypi-dev/tree/4.5.1) |
| meta-raspberrypi | [ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf](https://git.yoctoproject.org/cgit/cgit.cgi/meta-raspberrypi/commit/?id=ab5815a2ca0a460398878f77a7e39bc1a6dfe0bf) |

For RDKE Vendor layer specific build instructions, refer [this](https://github.com/rdkcentral/vendor-manifest-raspberrypi/blob/4.5.1/README.md)

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

---

#### How to update this README automatically

1. Generate `PackagesAndVersions.md` for the target `PACKAGE_ARCH` by building the Vendor stack for `4.5.1` with `DEPLOY_IPK_FEED = "1"` and `GENERATE_IPK_VERSION_DOC = "1"` in `${BUILDDIR}/conf/local.conf`. The generated file will be in `${BUILDDIR}/tmp/deploy/ipk/${PACKAGE_ARCH}/`. See [variables.md](https://github.com/rdkcentral/meta-stack-layering-support/blob/3.0.0/docs/variables.md) for supported options.
2. Run `Tools/update_readme.py` script from base directory to generate the final README. Note: change to match Host's shell conventions and filesystem path syntax(Windows/Linux/Mac).
```sh
# Requires Python 3.x
# Setup requirements (one time): pip install requests
Usage: python3 ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md <MANIFEST_REPO_BASE_URL> <MANIFEST_NAME> 4.5.1 Vendor "AUTHOR,email" "[TestReportUrl(optional)]"
```
- Replace the arguments with the actual release/tag/commit values matching the release.

Eg (Linux Host):
```sh
python3 ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md https://github.com/rdkcentral/vendor-manifest-raspberrypi rdke-raspberrypi.xml 4.5.1 Vendor "ReleaseTeam, email_id" "https://example.com/test-report"
```

---
