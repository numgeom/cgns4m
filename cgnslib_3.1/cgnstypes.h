#ifndef CGNSTYPES_H
#define CGNSTYPES_H

#include <stddef.h>

#define CG_BUILD_SCOPE  1

#define CG_MAX_INT32 0x7FFFFFFF

#if defined(_LP64) || defined(_WIN64)
#  define CG_SIZEOF_SIZE    64
#  define CG_SIZE_DATATYPE "I8"
# else
#  define CG_SIZEOF_SIZE    32
#  define CG_SIZE_DATATYPE "I4"
#endif

typedef ptrdiff_t cgsize_t;
typedef ptrdiff_t cglong_t;
typedef size_t cgulong_t;

typedef int cgerr_t;
typedef int cgint_t;
typedef double cgid_t;

#endif
