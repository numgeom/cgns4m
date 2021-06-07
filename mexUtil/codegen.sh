#!/bin/bash

# Regenerate source code.
# Use `codegen.sh` or `codegen.sh 1` to generate 64-bit code.
# Use `codegen.sh 0` to generate 32-bit code.

[[ -z "$1" || "1 true True" =~ (^| )$1($| ) ]] && BUILD64BIT=1 || BUILD64BIT=0

# To regenerate the C code after updating the cgnslib.h, run the following 
# this script in the root directory of cgns4m

set -e

# Download CGNS source code
CGNS_VERSION=4.2.0
mkdir -p cgnslib_$CGNS_VERSION
curl -L https://github.com/CGNS/CGNS/archive/v$CGNS_VERSION.tar.gz \
| tar zxvf - --strip-components=2 -C cgnslib_$CGNS_VERSION CGNS-$CGNS_VERSION/src/\
{LICENSE,cg_hashmap.c,cg_hashmap.h,cg_malloc.c,cgns_header.h,cgns_io.c,cgnsKeywords.h,cgnslib.h,cgnstypes.h.in,\
cg_malloc.h,cgns_error.c,cgns_internals.c,cgns_io.h,cgnslib.c,fortran_macros.h} \
CGNS-$CGNS_VERSION/src/adf/{ADF_fbind.h,ADF.h,ADF_interface.c,ADF_internals.c,ADF_internals.h} \
CGNS-$CGNS_VERSION/src/adfh/{ADF.h,ADFH.c,ADFH.h}

mv cgnslib_$CGNS_VERSION/cgnstypes.h.in src/cgnstypes.h

if [ $BUILD64BIT -eq 1 ]; then
    # Enable 64-bit integer
    perl -i -pe 's/\@BUILD64BIT\@/1/g;' \
            -e 's/\@CG\_?LONG\_?T\@/long long/g;' src/cgnstypes.h
    perl -i -pe 's/typedef [\w\s]+ cgsize_t;/typedef long long cgsize_t;/g' src/cgnslib.h
else
    # Disable 64-bit integer
    perl -i -pe 's/\@BUILD64BIT\@/0/g;' \
           -e 's/\@CG\_?LONG\_?T\@/int/g'  src/cgnstypes.h
    perl -i -pe 's/typedef [\w\s]+ cgsize_t;/typedef int cgsize_t;/g' src/cgnslib.h
fi

# Set other features
perl -i -pe 's/\@BUILDHDF5\@/1/g;' \
       -e 's/\@HAVE_COMPLEX_C99_EXT\@/1/g;' \
       -e 's/\@BUILDLEGACY\@/0/g;' \
       -e 's/\@BUILDSCOPE\@/1/g;' \
       -e 's/\@BUILDBASESCOPE\@/0/g;' \
       -e 's/\@BUILDPARALLEL\@/0/g;' \
       -e 's/\@HDF5_HAVE_\w+\@//g;' \
       -e 's/\@HAVE_STAT64_STRUCT\@/0/g;' \
       -e 's/\@FORTRAN_\w+\@/0/;' src/cgnstypes.h

# generate M files and cgnslib_mex.c file
./mexUtil/c2mex -outdir src src/cgnslib.h

# Copy src/CG_*.m to private/ and strip out CG_ prefix in the file name...
mkdir -p private
ls src/CG_*.m  | perl -e "s/src\/CG_(\w+\.m)/cp src\/CG_\$1 private\/\$1/g" -p | bash

# and strip off the CG_ prefix of the function names in private
perl -e 's/= CG_/= /g' -p -i private/*.m
