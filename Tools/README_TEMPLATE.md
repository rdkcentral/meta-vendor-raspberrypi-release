# Vendor Layer Release Note
## RaspberryPI Vendor Release Note
RaspberryPi RDKE Vendor Release aligning to below detailed baseline.

### Vendor Release Details
The [Packages And Versions](VendorPackagesAndVersions.md) file provides a table listing vendor-supplied package names and their versions of [Vendor Release <RELEASE_VERSION>](https://github.com/rdkcentral/vendor-manifest-raspberrypi/releases/tag/<RELEASE_VERSION>) which aligns with below layer combination.

For a comprehensive list of changes, updates, and release history, refer to the [Changelog](CHANGELOG.md).

| Yocto Version | <YOCTO_VERSION> |
|--------------|-----------------|
<LAYER_TABLE>

Refer RDKE RaspberryPi Vendor build instructions [here](https://github.com/rdkcentral/vendor-manifest-raspberrypi?tab=readme-ov-file#vendor-manifest-raspberrypi)

## License Details
This project is distributed under the terms outlined in the associated [License](LICENSE) and [Notice](NOTICE) files. Please review these files for detailed information.

---

#### How to update this README automatically

1. Generate and replace `VendorPackagesAndVersions.md` from vendor stack for the `<RELEASE_VERSION>`. See [variables.md](https://github.com/rdkcentral/meta-stack-layering-support/blob/main/docs/variables.md) for details on how to generate it.
2. Run `Tools/update_readme.py` script from base directory to generate the final README. Note: change to match Host's shell conventions and filesystem path syntax(Windows/Linux/Mac).
```sh
# Requires Python 3.x
# Setup requirements (one time): pip install requests
Usage: python3 ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md <MANIFEST_NAME> <RELEASE_VERSION>
```
- Replace the arguments with the actual release/tag/commit values matching the release.

Eg (Linux Host):
```sh
python3 ./Tools/update_readme.py ./Tools/README_TEMPLATE.md ./README.md rdke-raspberrypi.xml 4.5.1
```

---
