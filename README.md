## Introduction

This is mexCGNS for CGNS v3.1.3-4. It provides MEX interfaces of the mid-level library of CGNS. It is compatible with both MATLAB and Octave. 

### Installation

MexCGNS is easy to install. Simply download the gzipped tar file [mexcgns3.tgz](https://github.com/mexcgns/mexcgns/archive/master.tar.gz), untar it into your work directory (e.g., using the command `tar zxvf mexcgns3.tgz` on UNIX), and then run the `startup_mexcgns` script in MATLAB/Octave.

You need to run the `startup_mexcgns` script every time you launch MATLAB/Octave. It  adds the mexCGNS directories into the path. When you run `startup_mexcgns` for the first time, the script automatically compiles the MEX functions and performs some tests to make sure mexCGNS is installed correctly.

### Note for MATLAB on Microsoft Windows

On Microsoft Windows, mexCGNS requires MATLAB and Microsoft Visual C++. After installing Visual C++, just run `mex -setup` in MATLAB to choose Visual C++ as the compiler, and then build mexCGNS using `startup_mexcgns`.

For typical users working with unstructured meshes, it would be sufficient 
to use the high-level functions `readcgns_unstr.m` and `writecgns_unstr.m` to 
read and write CGNS files. Currently, these functions only support 
unstructured meshes with a single zone. You can also adapt these M-files 
yourself to fit your needs by calling any of the functions in the mid-level 
library of CGNS.
