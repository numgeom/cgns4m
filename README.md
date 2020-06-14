# CGNS4m

## Introduction

**CGNS4m**, formerly known as **mexCGNS**, allows you to access virtually all the functionalities provided by the serial API of [the mid-level library](https://cgns.github.io/CGNS_docs_current/midlevel/) of [CGNS](https://cgns.github.io) (a.k.a. `cgnslib`) with the convenience of MATLAB or GNU Octave. It also provides two high-level functions `readcgns` and `writecgns` for reading and writing mesh files with node-based or cell-centered data. These high-level functions are entirely written in MATLAB, so you can adapt for your purpose, without writing a single line of C code or a makefile.

| master | v3.4.1 | v4.1.1 |
|--------|--------|--------|
| [![Build Status](https://travis-ci.org/meshkit/cgns4m.svg?branch=master)](https://travis-ci.org/meshkit/cgns4m) | [![Build Status](https://travis-ci.org/meshkit/cgns4m.svg?branch=devel_v3.4.1)](https://travis-ci.org/meshkit/cgns4m) | [![Build Status](https://travis-ci.org/meshkit/cgns4m.svg?branch=devel_v3.4.1)](https://travis-ci.org/meshkit/cgns4m) |

## Copyright and license

The copyright of CGNS4m belongs to Stony Brook University. CGNS is distributed free of charge under the CGNS License, the same as `cgnslib`.

## Installation

### Pre-built binary for MATLAB
The easiest way to install CGNS4m is to download the binary distribution [cgns4m-v3.4.1-binary.tar.gz](https://github.com/meshkit/cgns4m/archive/v3.4.1-binary.tar.gz). It contains binary MEX files for 64-bit Linux, Windows, and Mac OS X, and should work for MATLAB R2016b or later. They were built with 64-bit integers enabled to support large files, and they were statically linked with HDF5 1.8.12, which is the same version as the recent releases of MATLAB.

After downloading cgns4m, please run `run cgns4m-v3.4.1-binary/startup_cgns4m` (or the root directory of `cgns4m`) within MATLAB to add the `cgns4m` path in MATLAB.

### Compilating CGNS4m for GNU Octave
In Octave, CGNS4m must be built using the HDF5 library bundled within Octave. Hence, a binary distribution is unavailable. You can download the [the master branch](https://github.com/meshkit/cgns4m/archive/master.tar.gz) of the CGNS4m source code. You can also reuse the binary distribution of CGNS4m for MATLAB. The build will have 64-bit integer enabled.

After downloading and untarring cgns4m, please run `run cgns4m-master/startup_cgns4m` (or the root directory of `cgns4m`) within Octave. The script will build the MEX file automatically if it does not yet exist and also add the `cgns4m` path to Octave. The build script has been tested using the binary distributions of Octave 4.2.2 in Ubuntu 18.04 and Octave 5.2.0 in Ubuntu 20.04.

### Using CGNS4m
Before using `cgns4m`, you need to run the `startup_cgns4m` script each time you start MATLAB/Octave. If you plan to use `cgns4m` regularly, it is advisable to add the `run startup_cgns4m` command to your `startup` script for [MATLAB](https://www.mathworks.com/help/matlab/ref/startup.html) or [Octave](https://octave.org/doc/v4.2.1/Startup-Files.html).

For most users working with structured or unstructured meshes, it would be sufficient to use the high-level functions `readcgns` and `writecgns` to read and write CGNS files. For example, use
```
[xs, elems, typestr, var_nodes, var_cells] = readcgns('tri_mesh.cgns');
```
to read in the nodal coordinates, element connectivity, element type, nod-based values, and cell-centered field values. The function supports both HDF5 and the legacy ADF formats. The `var_nodes`  and `var_cells` are MATLAB structures, so you can access the field variables easily.

For additional information about these functions, run
```
help readcgns
```
and similarly for `writecgns`.

Currently, these high-level functions only support meshes with a single zone and with node-based or cell-centered values. For more general purposes, you can adapt these functions by calling any of the mid-level functions of CGNS provided by the MATLAB gateway functions to the MEX. These MATLAB gateway functions have similar API as the C interface of `cgnslib`, and they handle type-casting automatically. You can also use `help` command on any of the CGNS functions, such as
```
help cg_coord_read
```
The help messages will print out the types of the arguments, and also provide a URL to their official CGNS documentation for the C interface.

## Developing CGNS4m

CGNS4m, formerly known as mexCGNS, was developed by Prof. Xiangmin Jiao's group at Stony Brook University when he served on the CGNS Steering Committee between 2007 and 2010. The goal of CGNS4m is to facilitate collaborative research activities in computational science, such as meshing, CFD, and multiphysics simulations, etc. As CGNS gains popularity, the demand for a high-level interface for CGNS has grown. The renaming of mexCGNS to CGNS4m is due to an anticipation of a sister package CGNS4py in the future.

### Contributing to high-level functions
Third-party contributions to CGNS4m are welcome. If you have developed an extension to the high-level functions, please create a fork on github and submit a pull request.

### Regenerating CGNS4m source
Most of the C and MATLAB source codes of CGNS4m were generated automatically from the annotated `cgnslib.h` using `c2mex`, a Perl program that extended `matwrap` developed by Gary R. Holt. A few gateway functions were written by hand and are contained in `cgnslib_mex_ext.c`. Do not edit the auto-generated C and MATLAB code by hand.

CGNS4m enables 64-bit integer support by default. To regenerate CGNS4m with  32-bit integer support only, run `mexUtil/codegen.sh 0` on a UNIX system with `bash` and `perl` to regenerate the MATLAB and C codes.

### Recompiling CGNS4m from scratch
To compile cgns4m from scratch, run `build_cgns4m` or `build_cgns4m -force` after running `startup_cgns4m`. Note that for MATLAB on Microsoft Windows, CGNS4m requires [Microsoft Visual Studio](https://visualstudio.microsoft.com/) (the free community edition suffices). After installing Visual Studio, just run `mex -setup` in MATLAB to choose Visual C++ as the compiler.

### Updating CGNS4m to another CGNS version
You can generate CGNS4m for a different version of `cgnslib` (3.1.x or later).  To do this, please follow these steps:
1. Checkout the [barebone branch](https://github.com/meshkit/cgns4m/tree/barebone) of cgns4m.
2. Download a new copy of `cgnslib.h` for the desired version from https://github.com/CGNS/cgns. Merge the c2mex annotations in `src/cgnslib.h` into the downloaded `cgnslib.h`, and then copy the merged file to overwrite `src/cgnslib.h`.
3. Change CGNS_VERSION in `mexUtil/codegen.sh` and `mexUtil/build_cgns4m.sh` to use this new cgnslib version.
4. Delete the old `cgnslib_mex.mex*` files. Run `./mexUtil/codegen.sh` in `bash` and `startup_cgns4m` in MATLAB/Octave.
