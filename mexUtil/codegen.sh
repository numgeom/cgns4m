#!/bin/bash

# To regenerate the C code after updating the cgnslib.h, run the following 
# this script in the root directory of cgns4m

set -e

# generate M files and cgnslib_mex.c file
./mexUtil/c2mex -debug -outdir src src/cgnslib.h

# Copy src/CG_*.m to private/ and strip out CG_ prefix in the file name...
ls src/CG_*.m  | perl -e "s/src\/CG_(\w+\.m)/cp src\/CG_\$1 private\/\$1/g" -p | bash

# and strip off the CG_ prefix of the function names in private
perl -e 's/= CG_/= /g' -p -i private/*.m

