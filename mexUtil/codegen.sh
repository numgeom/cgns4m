#!/bin/bash

# To regenerate the C code after updating the cgnslib.h, run the following 
# this script in the root directory of cgns4m

set -e

# Download CGNS source code
CGNS_VERSION=3.4.1
mkdir -p cgnslib_$CGNS_VERSION
curl -L https://github.com/CGNS/CGNS/archive/v3.4.1.tar.gz \
| tar zxvf - --strip-components=2 -C cgnslib_$CGNS_VERSION CGNS-$CGNS_VERSION/src/\
{LICENSE,cg_malloc.c,cgns_header.h,cgns_io.c,cgnsKeywords.h,cgnslib.h,\
cg_malloc.h,cgns_error.c,cgns_internals.c,cgns_io.h,cgnslib.c,fortran_macros.h} \
CGNS-$CGNS_VERSION/src/adf/{ADF_fbind.h,ADF.h,ADF_interface.c,ADF_internals.c,ADF_internals.h} \
CGNS-$CGNS_VERSION/src/adfh/{ADF.h,ADFH.c,ADFH.h}

# generate M files and cgnslib_mex.c file
./mexUtil/c2mex -debug -outdir src src/cgnslib.h

# Copy src/CG_*.m to private/ and strip out CG_ prefix in the file name...
mkdir -p private
ls src/CG_*.m  | perl -e "s/src\/CG_(\w+\.m)/cp src\/CG_\$1 private\/\$1/g" -p | bash

# and strip off the CG_ prefix of the function names in private
perl -e 's/= CG_/= /g' -p -i private/*.m

