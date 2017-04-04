#ifndef __C2MEX_H__
#define __C2MEX_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "mex.h"
#include "stddef.h"
#ifdef __cplusplus
}
#endif

#if defined(__GNUC__)      /* GCC */
#define inline __inline__
#elif defined(_WIN32)      /* Visual Studio */
#define inline __inline
#endif

/*
 * Return the minimum of two values.
 */
#define MAX_ARG2(arg1, arg2) (arg1 >= arg2 ? arg1 : arg2)

/*
 * Return the minimum of two values.
 */
#define MIN_ARG2(arg1, arg2) (arg1 >= arg2 ? arg2 : arg1)


/*
 * Return the number of dimensions of a MATLAB Array.
 */
inline int _n_dims( const mxArray *mat) {
    int dim = mxGetNumberOfDimensions(mat);
    if (mxGetNumberOfElements(mat)==1)
        return 0;
    else if (dim>2)
        return dim;
    else if (mxGetM(mat)==1 || mxGetN(mat)==1)
        return 1;
    else
        return 2;
}

/*
 * Get the n'th dimension of a MATLAB Array object.
 */
#define _dim( mat, idxno) \
    ((idxno >= mxGetNumberOfDimensions(mat)) ? 1 : mxGetDimensions(mat)[idxno])

/* Define 64-bit integers for 64-bit machines. */
typedef long long           int64;
typedef unsigned long long  uint64;

/* Define others. */
typedef int                 int32;
typedef unsigned int        uint32;

typedef short               int16;
typedef unsigned short      uint16;

typedef char                int8;
typedef unsigned char       uint8;

/* Define a macro for dealing with different types. It leaves out default case */
#define switch_types( HELPER, TYPE) \
  switch (mxGetClassID( mat)) { \
  case mxDOUBLE_CLASS: HELPER( double, TYPE); \
  case mxSINGLE_CLASS: HELPER( float, TYPE); \
  case mxINT8_CLASS:   HELPER( int8, TYPE); \
  case mxUINT8_CLASS:  HELPER( uint8, TYPE); \
  case mxINT16_CLASS:  HELPER( int16, TYPE); \
  case mxUINT16_CLASS: HELPER( uint16, TYPE); \
  case mxINT32_CLASS:  HELPER( int32, TYPE); \
  case mxUINT32_CLASS: HELPER( uint32, TYPE); \
  case mxINT64_CLASS:  HELPER( int64, TYPE);  \
  case mxUINT64_CLASS: HELPER( uint64, TYPE); \

#define GET_HELPER( MTYPE, TYPE) { \
    MTYPE *pr = (MTYPE*)mxGetData(mat); \
    mwSize idx; \
    for (idx = 0; idx < n_elements; ++idx) \
        *arr++ = (TYPE)*(MTYPE*)pr++; \
    } \
    break;

#define GET_NUMERIC_ARRAY( TYPE) \
inline int \
_get_numeric_array_##TYPE(const mxArray *mat, TYPE *arr) \
{ \
    mwSize n_elements = mxGetNumberOfElements(mat); \
    switch_types( GET_HELPER, TYPE) \
    default: return 0; \
    } \
    return 1; /* No error. */ \
}

GET_NUMERIC_ARRAY(double)
GET_NUMERIC_ARRAY(float)
GET_NUMERIC_ARRAY(int64)
GET_NUMERIC_ARRAY(uint64)
GET_NUMERIC_ARRAY(int32)
GET_NUMERIC_ARRAY(uint32)
GET_NUMERIC_ARRAY(int16)
GET_NUMERIC_ARRAY(uint16)
GET_NUMERIC_ARRAY(int8)
GET_NUMERIC_ARRAY(uint8)

#define GET_SCALAR_HELPER( MTYPE, TYPE) \
        return *(MTYPE*)mxGetPr(mat)

#define GET_NUMERIC_SCALAR( TYPE) \
inline TYPE \
_get_numeric_scalar_##TYPE(const mxArray *mat) \
{ \
    switch_types( GET_SCALAR_HELPER, TYPE) \
        default: mexErrMsgTxt("Unknown data type."); \
        return 0; \
    } \
}

GET_NUMERIC_SCALAR(double)
GET_NUMERIC_SCALAR(float)
GET_NUMERIC_SCALAR(int64)
GET_NUMERIC_SCALAR(uint64)
GET_NUMERIC_SCALAR(int32)
GET_NUMERIC_SCALAR(uint32)
GET_NUMERIC_SCALAR(int16)
GET_NUMERIC_SCALAR(uint16)
GET_NUMERIC_SCALAR(int8)
GET_NUMERIC_SCALAR(uint8)

/* 
 * The follow pair of functions are for allocating and deallocating buffer 
 * space for storing C strings from MATLAB chars.
 */
inline char * _mxGetString( const mxArray *arr, size_t *fstrlen) {
    mwSize len = mxGetNumberOfElements(arr)+1;
    char *s = (char *)mxMalloc( len);
    mxGetString(arr, s, len);
    if ( fstrlen) *fstrlen = len;
    return s;
}

inline void _mxPutString( char *s, mxArray *arr) {
    mxChar *pr = (mxChar*)mxGetData(arr);
    mwSize idx;
    for (idx = mxGetNumberOfElements(arr)-1; idx >= 0; --idx)
        pr[idx] = (mxChar)s[idx];
    mxFree(s);
}

inline void _mxFreeString( char *s) {
    mxFree(s);
}

#endif
