## Introduction

This is CGNS4m, formerly known as mexcgns. It provides MEX interfaces of the mid-level library of CGNS. It is compatible with both MATLAB and Octave.

### Installation

CGNS4m is easy to install. Simply download the gzipped tar file [cgns4m.tgz](https://github.com/meshkit/cgns4m/archive/master.tar.gz), untar it into your work directory (e.g., using the command `tar zxvf cgns4m.tgz` on UNIX), and then run the `startup_cgns4m` script in MATLAB/Octave.

You need to run the `startup_cgns4m` script every time you launch MATLAB/Octave. It  adds the CGNS4m directories into the path. When you run `startup_cgns4m` for the first time, the script automatically compiles the MEX functions and performs some tests to make sure CGNS4m is installed correctly.

### Note for MATLAB on Microsoft Windows

On Microsoft Windows, CGNS4m requires MATLAB and Microsoft Visual C++. After installing Visual C++, just run `mex -setup` in MATLAB to choose Visual C++ as the compiler, and then build CGNS4m using `startup_cgns4m`.

For typical users working with unstructured meshes, it would be sufficient
to use the high-level functions `readcgns.m` and `writecgns.m` to
read and write CGNS files. Currently, these functions only support
unstructured meshes with a single zone. You can also adapt these M-files
yourself to fit your needs by calling any of the functions in the mid-level
library of CGNS.
