
This is the release of mexCGNS for CGNS v3.1.3-4. It provides MEX 
interfaces of the mid-level library of CGNS. It is compatible with both 
MATLAB and Octave. 

To use mexCGNS, you must run the startup_mexcgns.m script in MATLAB/Octave 
every time you launch MATLAB/Octave. The first time you run startup_mexcgns, 
it will compile the MEX functions automatically and perform some testing.
It should work for MATLAB/Octave on UNIX systems (including Linux, Mac OS X, 
Solaris, etc.). On Microsoft Windows, only MATLAB with Visual C++ is supported.

For typical users working with unstructured meshes, it would be sufficient 
to use the high-level functions readcgns_unstr.m and writecgns_unstr.m to 
read and write CGNS files. Currently, these functions only support 
unstructured meshes with a single zone. In the future, we will extend these 
functions to support structured meshes. You can also adapt these M-files 
yourself to fit your needs by calling any of the functions in the mid-level 
library of CGNS.

Enjoy!

-Xiangmin Jiao
jiao@ams.sunysb.edu
02/01/2012
Stony Brook, NY, USA
