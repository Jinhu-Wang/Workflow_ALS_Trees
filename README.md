# Workflow_ALS_Trees

Workflow modules related to tree individualization using ALS point clouds.

## Table of Contents

- [Overview](#overview)
- [File Structure](#file-structure)
- [Requirements](#requirements)
- [Usage Instructions](#usage-instructions)
- [License](#license)
- [Contact](#contact)

## Overview

This repository holds the modules for tree individualization from 3D point cloud datasets obtained by airborne laser scanning.

## File Structure

```plaintext
project_directory/
│
├── 3rd_party/      # The third party software, i.e. LAStools, shapelib.
|
├── clipping/      # Holds the clipping scripts.
|      ├── src/    # Source codes.
|      |
|      └── CMakeLists.txt   # Making configuration using CMake.
|
├── retile_by_count/                      # C++ scripts of retile by number of tiles
|        ├── src/                         # Source codes
|        └── CMakeLists.txt               # Configuration using CMake tool
|
└── retile_by_size/                       # C++ scripts of retile by size in two directions
         ├── src/                         # Source codes
         └── CMakeLists.txt               # Configuration using CMake tool
```

## Requirements

The `C++` scripts in this repository depends on the **[LAStools](https://lastools.github.io/)** to read point cloud data in **LAS/LAZ** formats and the **[shapelib](http://shapelib.maptools.org/)** for reading **ESRI** shapefiles.

To use the scripts, a `C++` compiler, i.e. `g++`,`gcc`, `mscv`, `clang++`, etc., should be installed.

## Usage Instructions

### There are two ways to build

- Option 1: Using CMake to generate makefiles and then 'make' (on Linux/macOS).

  - On Linux or maxOS, simply:

```
    cd path-to-dir
    mkdir release  && cd release
    cmake -DCMAKE_BUILD_TYPE=release ..
    make
```

- Option 2: Use any IDE that can directly handle CMakeLists files to open the `CMakeLists.txt` in the **root** directory of Trees3D.
  Then you should have obtained a usable project and just build it. I recommend using
  [CLion](https://www.jetbrains.com/clion/) or [QtCreator](https://www.qt.io/product). For Windows users: your IDE must be set for `x64`.

### Module 1: [clipping]

This module clips the LiDAR point clouds in LAS/LAS format w.r.t. the polygons (with *.shp format).

There are three parameters to specify:

```
    std::string shp_file_path:  The full path to the shapefile.
    std::string in_las_dir:     The full path to the directory of LAS/LAZ files.
    std::string out_las_dir:    The full path to the output directory of lipped LAS/LAZ files.
```

```javascript {.line-numbers}
void usage(char *argv)
{
    std::cout << "Usage:" << std::endl;
    std::cout << argv << " [Path of *.shp file] [Directory of input LAS/LAZ files] [Directory of output LAS/LAZ files]" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        usage(argv[0]);
        return 1;
    }

    std::string shp_file_path = argv[1];
    std::string in_las_dir = argv[2];
    std::string out_las_dir = argv[3];

    mm::ClipLas *clip = new mm::ClipLas;

    clip->getAllLasFiles(in_las_dir);
    clip->setShpFilePath(shp_file_path);
    clip->readShpFile();
    clip->getPositivePolygons();
    clip->setLasFileDirName(in_las_dir, out_las_dir);
    clip->runClipping();

    if (clip)
    {
        delete clip;
        clip = nullptr;
    }

    return 0;
}
```

## License

MIT License

## Contact

For any suggestions and bug reports, please contact:

Jinhu Wang

jinhu.wang (at) hotmail (dot) com
