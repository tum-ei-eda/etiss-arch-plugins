# ETISS ArchImpl Plugins

This repository contains plugins for custom ArchImpl support in [ETISS](https://github.com/tum-ei-eda/etiss).

## Contents

- `RV32IMACFDK`: TODO: Description

## Building Instructions

### Integrated ETISS Build

1. Clone ETISS repository
2. Copy (or symlink) the plugin directory (i.e. `RV32IMACFDK`) into the `PluginImpl` directory of the ETISS source tree.
3. Build ETISS as usual (following the instructions in the README)

### Out-of-Tree Build

1. Clone, build and install ETISS according to the README.
2. Enter one plugin directory, i.e. `cd RV32IMACFDK`
3. Build plugin with CMake, passing it `ETISS_DIR` to find the relevant CMake configuration

```sh
cmake -S . -B build -DETISS_DIR=/path/to/etiss/install/lib/CMake/ETISS -DCMAKE_INSTALL_PREFIX=$(pwd)/build/install
cmake --build build -j$(nproc)
cmake --install build
```

## Running Instructions

### Integrated ETISS Build

### Out-of-Tree Build

#### Option A (`etiss_wd`)

1. Create a directory: `mkdir ./temp/`
2. Create INI file with following contents:
```ini
# Filename: custom.ini
[StringConfigurations]
etiss_wd=/path/to/temp/
jit.external_header_paths="/path/to/temp/PluginImpl/;"
```
3. Create `PluginImpl` subdirectory: `mkdir ./temp/PluginImpl`
4. Copy library and include files into this subdir: `cp ./build/install/lib/plugins/*.so ./temp/PluginImpl && cp -r ./build/install/include/jit/* ./temp/PluginImpl`
5. Run ETISS via `run_helper.sh` script (or calling `bare_etiss_processor` directly)
```sh
/path/to/etiss/install/bin/run_helper.sh /path/to/program --arch.cpu=RV32IMACFDK -icustom.ini
```

**Hint:** Steps 1.-3. can be skipped if executing ETISS in the same path where the `PluginImpl` directory is located. This yields to this more simple procedure:

```sh
mkdir ./PluginImpl
cp ./build/install/lib/plugins/*.so ./PluginImpl
cp -r ./build/install/include/jit/* PluginImpl/
/path/to/etiss/install/bin/run_helper.sh /path/to/program --arch.cpu=RV32IMACFDK --jit.external_header_paths="$(pwd)/PluginImpl/;"
```

#### Option B (`list.txt`)

1. Edit the `list.txt` file located in `/path/to/etiss/install/lib/plugins/`
```sh
cat $(pwd)/build/install/lib/plugins/list.txt >> /path/to/etiss/install/lib/plugins/list.txt
```
2. Run ETISS: `/path/to/etiss/install/bin/run_helper.sh /path/to/program --arch.cpu=RV32IMACFDK --jit.external_header_paths="$(pwd)/build/install/include/jit;"`


**Warning**: These changes will be overwritten, when ETISS is being rebuilt!
