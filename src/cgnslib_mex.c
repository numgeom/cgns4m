/*
 * This file was automatically generated for MATLAB & Octave from 
 * cgnslib_3.0/cgnslib.h using Xiangmin Jiao's c2mex. 
 * For bug reports of c2mex, email jiao@ams.sunysb.edu.
 */

#include "c2mex.h"   /* This includes "mex.h". */

#include "cgnslib_3.0/cgnslib.h"


#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C
#endif

#ifdef EXTERN
#undef EXTERN
#endif

#ifdef __cplusplus
  #define EXTERN extern "C"
#else
  #define EXTERN extern
#endif

/* Gateway function 
 * [out_file_type, ierr] = cg_is_cgns(in_filename) 
 *
 * The original C interface is 
 * int cg_is_cgns( const char * filename, int * file_type);
 */
EXTERN_C void cg_is_cgns_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_filename;
    int out_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_filename = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_is_cgns(in_filename, &out_file_type);


    /******** Free up input buffers. ********/
    _mxFreeString(in_filename);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_file_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_fn, ierr] = cg_open(in_filename, in_mode) 
 *
 * The original C interface is 
 * int cg_open( char const * filename, int mode, int * fn);
 */
EXTERN_C void cg_open_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_filename;
    int in_mode;
    int out_fn;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_filename = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument mode");
    in_mode = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_open(in_filename, in_mode, &out_fn);


    /******** Free up input buffers. ********/
    _mxFreeString(in_filename);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_fn;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_FileVersion, ierr] = cg_version(in_fn) 
 *
 * The original C interface is 
 * int cg_version( int fn, float * FileVersion);
 */
EXTERN_C void cg_version_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    float out_FileVersion;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_version(in_fn, &out_FileVersion);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
    *(float*)mxGetData(plhs[0]) = out_FileVersion;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_close(in_fn) 
 *
 * The original C interface is 
 * int cg_close( int fn);
 */
EXTERN_C void cg_close_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_close(in_fn);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_save_as(in_fn, in_filename, in_file_type, in_follow_links) 
 *
 * The original C interface is 
 * int cg_save_as( int fn, const char * filename, int file_type, int follow_links);
 */
EXTERN_C void cg_save_as_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    char * in_filename;
    int in_file_type;
    int in_follow_links;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    in_filename = _mxGetString(prhs[1], NULL);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_type");
    in_file_type = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument follow_links");
    in_follow_links = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_save_as(in_fn, in_filename, in_file_type, in_follow_links);


    /******** Free up input buffers. ********/
    _mxFreeString(in_filename);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_set_file_type(in_file_type) 
 *
 * The original C interface is 
 * int cg_set_file_type( int file_type);
 */
EXTERN_C void cg_set_file_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_type");
    in_file_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_set_file_type(in_file_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_get_file_type(in_fn, io_file_type) 
 *
 * The original C interface is 
 * int cg_get_file_type( int fn, int * file_type);
 */
EXTERN_C void cg_get_file_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int * io_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_file_type = (int*)mxGetData(prhs[1]);
    else {
        io_file_type = (int*)mxCalloc(mxGetNumberOfElements(prhs[1]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[1], io_file_type))
            mexErrMsgTxt("Expecting numeric matrix for argument file_type");
    }


    /******** Invoke computational function ********/
    ierr = cg_get_file_type(in_fn, io_file_type);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[1]) && !mxIsUint32(prhs[1]))
        mxFree(io_file_type);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_rootid, ierr] = cg_root_id(in_fn) 
 *
 * The original C interface is 
 * int cg_root_id( int fn, double * rootid);
 */
EXTERN_C void cg_root_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    double out_rootid;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_root_id(in_fn, &out_rootid);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_rootid;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_configure(in_what, in_value) 
 *
 * The original C interface is 
 * int cg_configure( int what, void * value);
 */
EXTERN_C void cg_configure_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_what;
    void * in_value;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument what");
    in_what = _get_numeric_scalar_int32(prhs[0]);

    in_value = mxGetData( prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_configure(in_what, in_value);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_set_compress(in_compress) 
 *
 * The original C interface is 
 * int cg_set_compress( int compress);
 */
EXTERN_C void cg_set_compress_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_compress;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument compress");
    in_compress = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_set_compress(in_compress);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_compress, ierr] = cg_get_compress() 
 *
 * The original C interface is 
 * int cg_get_compress( int * compress);
 */
EXTERN_C void cg_get_compress_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_compress;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_get_compress(&out_compress);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_compress;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_set_path(in_path) 
 *
 * The original C interface is 
 * int cg_set_path( const char * path);
 */
EXTERN_C void cg_set_path_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_path = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_set_path(in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_add_path(in_path) 
 *
 * The original C interface is 
 * int cg_add_path( const char * path);
 */
EXTERN_C void cg_add_path_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_path = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_add_path(in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * name = cg_MassUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_MassUnitsName( MassUnits_t type);
 */
EXTERN_C void cg_MassUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    MassUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_MassUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_LengthUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_LengthUnitsName( LengthUnits_t type);
 */
EXTERN_C void cg_LengthUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    LengthUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_LengthUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_TimeUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_TimeUnitsName( TimeUnits_t type);
 */
EXTERN_C void cg_TimeUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    TimeUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_TimeUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_TemperatureUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_TemperatureUnitsName( TemperatureUnits_t type);
 */
EXTERN_C void cg_TemperatureUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    TemperatureUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_TemperatureUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_AngleUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_AngleUnitsName( AngleUnits_t type);
 */
EXTERN_C void cg_AngleUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    AngleUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AngleUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_ElectricCurrentUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_ElectricCurrentUnitsName( ElectricCurrentUnits_t type);
 */
EXTERN_C void cg_ElectricCurrentUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ElectricCurrentUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ElectricCurrentUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_SubstanceAmountUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_SubstanceAmountUnitsName( SubstanceAmountUnits_t type);
 */
EXTERN_C void cg_SubstanceAmountUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    SubstanceAmountUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_SubstanceAmountUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_LuminousIntensityUnitsName(in_type) 
 *
 * The original C interface is 
 * const char * cg_LuminousIntensityUnitsName( LuminousIntensityUnits_t type);
 */
EXTERN_C void cg_LuminousIntensityUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    LuminousIntensityUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_LuminousIntensityUnitsName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_DataClassName(in_type) 
 *
 * The original C interface is 
 * const char * cg_DataClassName( DataClass_t type);
 */
EXTERN_C void cg_DataClassName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataClass_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_DataClassName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_GridLocationName(in_type) 
 *
 * The original C interface is 
 * const char * cg_GridLocationName( GridLocation_t type);
 */
EXTERN_C void cg_GridLocationName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GridLocation_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GridLocationName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_BCDataTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_BCDataTypeName( BCDataType_t type);
 */
EXTERN_C void cg_BCDataTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    BCDataType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_BCDataTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_GridConnectivityTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_GridConnectivityTypeName( GridConnectivityType_t type);
 */
EXTERN_C void cg_GridConnectivityTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GridConnectivityType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GridConnectivityTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_PointSetTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_PointSetTypeName( PointSetType_t type);
 */
EXTERN_C void cg_PointSetTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    PointSetType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_PointSetTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_GoverningEquationsTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_GoverningEquationsTypeName( GoverningEquationsType_t type);
 */
EXTERN_C void cg_GoverningEquationsTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GoverningEquationsType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GoverningEquationsTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_ModelTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_ModelTypeName( ModelType_t type);
 */
EXTERN_C void cg_ModelTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ModelType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ModelTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_BCTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_BCTypeName( BCType_t type);
 */
EXTERN_C void cg_BCTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    BCType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_BCTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_DataTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_DataTypeName( DataType_t type);
 */
EXTERN_C void cg_DataTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_DataTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_ElementTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_ElementTypeName( ElementType_t type);
 */
EXTERN_C void cg_ElementTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ElementType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ElementTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_ZoneTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_ZoneTypeName( ZoneType_t type);
 */
EXTERN_C void cg_ZoneTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ZoneType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ZoneTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_RigidGridMotionTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_RigidGridMotionTypeName( RigidGridMotionType_t type);
 */
EXTERN_C void cg_RigidGridMotionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    RigidGridMotionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_RigidGridMotionTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_ArbitraryGridMotionTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_ArbitraryGridMotionTypeName( ArbitraryGridMotionType_t type);
 */
EXTERN_C void cg_ArbitraryGridMotionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ArbitraryGridMotionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ArbitraryGridMotionTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_SimulationTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_SimulationTypeName( SimulationType_t type);
 */
EXTERN_C void cg_SimulationTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    SimulationType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_SimulationTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_WallFunctionTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_WallFunctionTypeName( WallFunctionType_t type);
 */
EXTERN_C void cg_WallFunctionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    WallFunctionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_WallFunctionTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_AreaTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_AreaTypeName( AreaType_t type);
 */
EXTERN_C void cg_AreaTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    AreaType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AreaTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * name = cg_AverageInterfaceTypeName(in_type) 
 *
 * The original C interface is 
 * const char * cg_AverageInterfaceTypeName( AverageInterfaceType_t type);
 */
EXTERN_C void cg_AverageInterfaceTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    AverageInterfaceType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AverageInterfaceTypeName(in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function 
 * ierr = cg_nbases(in_fn, io_nbases) 
 *
 * The original C interface is 
 * int cg_nbases( int fn, int * nbases);
 */
EXTERN_C void cg_nbases_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int * io_nbases;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_nbases = (int*)mxGetData(prhs[1]);
    else {
        io_nbases = (int*)mxCalloc(mxGetNumberOfElements(prhs[1]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[1], io_nbases))
            mexErrMsgTxt("Expecting numeric matrix for argument nbases");
    }


    /******** Invoke computational function ********/
    ierr = cg_nbases(in_fn, io_nbases);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[1]) && !mxIsUint32(prhs[1]))
        mxFree(io_nbases);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_cell_dim, out_phys_dim, ierr] = cg_base_read(in_file_number, in_B, io_basename) 
 *
 * The original C interface is 
 * int cg_base_read( int file_number, int B, char * basename, int * cell_dim, int * phys_dim);
 */
EXTERN_C void cg_base_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    char * io_basename;
    int out_cell_dim;
    int out_phys_dim;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 4 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    io_basename = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_base_read(in_file_number, in_B, io_basename, &out_cell_dim, &out_phys_dim);


    /******** Process inout argument. ********/
    /* _mxPutString(io_basename, (mxArray*)prhs[2]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_cell_dim;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_phys_dim;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateString(io_basename);
    }
}

/* Gateway function 
 * [out_base_id, ierr] = cg_base_id(in_fn, in_B) 
 *
 * The original C interface is 
 * int cg_base_id( int fn, int B, double * base_id);
 */
EXTERN_C void cg_base_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    double out_base_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_base_id(in_fn, in_B, &out_base_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_base_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_B, ierr] = cg_base_write(in_file_number, in_basename, in_cell_dim, in_phys_dim) 
 *
 * The original C interface is 
 * int cg_base_write( int file_number, char const * basename, int cell_dim, int phys_dim, int * B);
 */
EXTERN_C void cg_base_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    char * in_basename;
    int in_cell_dim;
    int in_phys_dim;
    int out_B;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    in_basename = _mxGetString(prhs[1], NULL);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument cell_dim");
    in_cell_dim = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument phys_dim");
    in_phys_dim = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_base_write(in_file_number, in_basename, in_cell_dim, in_phys_dim, &out_B);


    /******** Free up input buffers. ********/
    _mxFreeString(in_basename);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_B;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nzones, ierr] = cg_nzones(in_fn, in_B) 
 *
 * The original C interface is 
 * int cg_nzones( int fn, int B, int * nzones);
 */
EXTERN_C void cg_nzones_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int out_nzones;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_nzones(in_fn, in_B, &out_nzones);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nzones;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_zone_read(in_fn, in_B, in_Z, io_zonename, io_size) 
 *
 * The original C interface is 
 * int cg_zone_read( int fn, int B, int Z, char * zonename, int * size);
 */
EXTERN_C void cg_zone_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    char * io_zonename;
    int * io_size;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    io_zonename = _mxGetString(prhs[3], NULL);

    if (mxGetNumberOfElements(prhs[4]) < (int) (9) || _n_dims(prhs[4]) > 1)
        mexErrMsgTxt("Error in dimension of argument size");
    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        io_size = (int*)mxGetData(prhs[4]);
    else {
        io_size = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], io_size))
            mexErrMsgTxt("Expecting numeric matrix for argument size");
    }


    /******** Invoke computational function ********/
    ierr = cg_zone_read(in_fn, in_B, in_Z, io_zonename, io_size);


    /******** Process inout argument. ********/
    /* _mxPutString(io_zonename, (mxArray*)prhs[3]); */
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(io_size);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_zonename);
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_zone_type(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_zone_type( int file_number, int B, int Z, ZoneType_t * type);
 */
EXTERN_C void cg_zone_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    ZoneType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_zone_type(in_file_number, in_B, in_Z, &out_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_zone_id, ierr] = cg_zone_id(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_zone_id( int fn, int B, int Z, double * zone_id);
 */
EXTERN_C void cg_zone_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    double out_zone_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_zone_id(in_fn, in_B, in_Z, &out_zone_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_zone_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_Z, ierr] = cg_zone_write(in_fn, in_B, in_zonename, in_size, in_type) 
 *
 * The original C interface is 
 * int cg_zone_write( int fn, int B, char const * zonename, int const * size, ZoneType_t type, int * Z);
 */
EXTERN_C void cg_zone_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    char * in_zonename;
    int * in_size;
    ZoneType_t in_type;
    int out_Z;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    in_zonename = _mxGetString(prhs[2], NULL);

    if (mxGetNumberOfElements(prhs[3]) < (int) (9) || _n_dims(prhs[3]) > 1)
        mexErrMsgTxt("Error in dimension of argument size");
    if (mxIsInt32(prhs[3]) || mxIsUint32(prhs[3]))
        in_size = (int*)mxGetData(prhs[3]);
    else {
        in_size = (int*)mxCalloc(mxGetNumberOfElements(prhs[3]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[3], in_size))
            mexErrMsgTxt("Expecting numeric matrix for argument size");
    }

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_zone_write(in_fn, in_B, in_zonename, in_size, in_type, &out_Z);


    /******** Free up input buffers. ********/
    _mxFreeString(in_zonename);
    if (!mxIsInt32(prhs[3]) && !mxIsUint32(prhs[3]))
        mxFree(in_size);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Z;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nfamilies, ierr] = cg_nfamilies(in_file_number, in_B) 
 *
 * The original C interface is 
 * int cg_nfamilies( int file_number, int B, int * nfamilies);
 */
EXTERN_C void cg_nfamilies_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int out_nfamilies;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_nfamilies(in_file_number, in_B, &out_nfamilies);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfamilies;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nboco, out_ngeos, ierr] = cg_family_read(in_file_number, in_B, in_F, io_family_name) 
 *
 * The original C interface is 
 * int cg_family_read( int file_number, int B, int F, char * family_name, int * nboco, int * ngeos);
 */
EXTERN_C void cg_family_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    char * io_family_name;
    int out_nboco;
    int out_ngeos;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 4 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    io_family_name = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_family_read(in_file_number, in_B, in_F, io_family_name, &out_nboco, &out_ngeos);


    /******** Process inout argument. ********/
    /* _mxPutString(io_family_name, (mxArray*)prhs[3]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nboco;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_ngeos;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateString(io_family_name);
    }
}

/* Gateway function 
 * [out_F, ierr] = cg_family_write(in_file_number, in_B, in_family_name) 
 *
 * The original C interface is 
 * int cg_family_write( int file_number, int B, char const * family_name, int * F);
 */
EXTERN_C void cg_family_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    char * in_family_name;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    in_family_name = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_family_write(in_file_number, in_B, in_family_name, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_family_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_famname_read(io_family_name) 
 *
 * The original C interface is 
 * int cg_famname_read( char * family_name);
 */
EXTERN_C void cg_famname_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * io_family_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    io_family_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_famname_read(io_family_name);


    /******** Process inout argument. ********/
    /* _mxPutString(io_family_name, (mxArray*)prhs[0]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;

    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_family_name);
    }
}

/* Gateway function 
 * ierr = cg_famname_write(in_family_name) 
 *
 * The original C interface is 
 * int cg_famname_write( char const * family_name);
 */
EXTERN_C void cg_famname_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_family_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_family_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_famname_write(in_family_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_family_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_bocotype, ierr] = cg_fambc_read(in_file_number, in_B, in_F, in_BC, io_fambc_name) 
 *
 * The original C interface is 
 * int cg_fambc_read( int file_number, int B, int F, int BC, char * fambc_name, BCType_t * bocotype);
 */
EXTERN_C void cg_fambc_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    int in_BC;
    char * io_fambc_name;
    BCType_t out_bocotype;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    io_fambc_name = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_fambc_read(in_file_number, in_B, in_F, in_BC, io_fambc_name, &out_bocotype);


    /******** Process inout argument. ********/
    /* _mxPutString(io_fambc_name, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_bocotype;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_fambc_name);
    }
}

/* Gateway function 
 * [out_BC, ierr] = cg_fambc_write(in_file_number, in_B, in_F, in_fambc_name, in_bocotype) 
 *
 * The original C interface is 
 * int cg_fambc_write( int file_number, int B, int F, char const * fambc_name, BCType_t bocotype, int * BC);
 */
EXTERN_C void cg_fambc_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    char * in_fambc_name;
    BCType_t in_bocotype;
    int out_BC;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    in_fambc_name = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument bocotype");
    in_bocotype = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_fambc_write(in_file_number, in_B, in_F, in_fambc_name, in_bocotype, &out_BC);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fambc_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BC;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_geo_file, out_npart, ierr] = cg_geo_read(in_file_number, in_B, in_F, in_G, io_geo_name, io_CAD_name) 
 *
 * The original C interface is 
 * int cg_geo_read( int file_number, int B, int F, int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
 */
EXTERN_C void cg_geo_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    int in_G;
    char * io_geo_name;
    char * out_geo_file;
    char * io_CAD_name;
    int out_npart;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 5 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[3]);

    io_geo_name = _mxGetString(prhs[4], NULL);

    io_CAD_name = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_geo_read(in_file_number, in_B, in_F, in_G, io_geo_name, &out_geo_file, io_CAD_name, &out_npart);


    /******** Process inout argument. ********/
    /* _mxPutString(io_geo_name, (mxArray*)prhs[4]); */
    /* _mxPutString(io_CAD_name, (mxArray*)prhs[5]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateString(out_geo_file);
    cg_free( out_geo_file);

    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_npart;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateString(io_geo_name);
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateString(io_CAD_name);
    }
}

/* Gateway function 
 * [out_G, ierr] = cg_geo_write(in_file_number, in_B, in_F, in_geo_name, in_filename, in_CADname) 
 *
 * The original C interface is 
 * int cg_geo_write( int file_number, int B, int F, char const * geo_name, char const * filename, char const * CADname, int * G);
 */
EXTERN_C void cg_geo_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    char * in_geo_name;
    char * in_filename;
    char * in_CADname;
    int out_G;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    in_geo_name = _mxGetString(prhs[3], NULL);

    in_filename = _mxGetString(prhs[4], NULL);

    in_CADname = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_geo_write(in_file_number, in_B, in_F, in_geo_name, in_filename, in_CADname, &out_G);


    /******** Free up input buffers. ********/
    _mxFreeString(in_geo_name);
    _mxFreeString(in_filename);
    _mxFreeString(in_CADname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_G;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_part_read(in_file_number, in_B, in_F, in_G, in_P, io_part_name) 
 *
 * The original C interface is 
 * int cg_part_read( int file_number, int B, int F, int G, int P, char * part_name);
 */
EXTERN_C void cg_part_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    int in_G;
    int in_P;
    char * io_part_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument P");
    in_P = _get_numeric_scalar_int32(prhs[4]);

    io_part_name = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_part_read(in_file_number, in_B, in_F, in_G, in_P, io_part_name);


    /******** Process inout argument. ********/
    /* _mxPutString(io_part_name, (mxArray*)prhs[5]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_part_name);
    }
}

/* Gateway function 
 * [out_P, ierr] = cg_part_write(in_file_number, in_B, in_F, in_G, in_part_name) 
 *
 * The original C interface is 
 * int cg_part_write( int file_number, int B, int F, int G, char const * part_name, int * P);
 */
EXTERN_C void cg_part_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_F;
    int in_G;
    char * in_part_name;
    int out_P;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[3]);

    in_part_name = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_part_write(in_file_number, in_B, in_F, in_G, in_part_name, &out_P);


    /******** Free up input buffers. ********/
    _mxFreeString(in_part_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_P;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_ngrids, ierr] = cg_ngrids(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_ngrids( int file_number, int B, int Z, int * ngrids);
 */
EXTERN_C void cg_ngrids_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int out_ngrids;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_ngrids(in_file_number, in_B, in_Z, &out_ngrids);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ngrids;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_grid_read(in_file_number, in_B, in_Z, in_G, io_gridname) 
 *
 * The original C interface is 
 * int cg_grid_read( int file_number, int B, int Z, int G, char * gridname);
 */
EXTERN_C void cg_grid_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_G;
    char * io_gridname;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[3]);

    io_gridname = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_grid_read(in_file_number, in_B, in_Z, in_G, io_gridname);


    /******** Process inout argument. ********/
    /* _mxPutString(io_gridname, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_gridname);
    }
}

/* Gateway function 
 * [out_G, ierr] = cg_grid_write(in_file_number, in_B, in_Z, in_zcoorname) 
 *
 * The original C interface is 
 * int cg_grid_write( int file_number, int B, int Z, char const * zcoorname, int * G);
 */
EXTERN_C void cg_grid_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_zcoorname;
    int out_G;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_zcoorname = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_grid_write(in_file_number, in_B, in_Z, in_zcoorname, &out_G);


    /******** Free up input buffers. ********/
    _mxFreeString(in_zcoorname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_G;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_ncoords, ierr] = cg_ncoords(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_ncoords( int fn, int B, int Z, int * ncoords);
 */
EXTERN_C void cg_ncoords_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_ncoords;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_ncoords(in_fn, in_B, in_Z, &out_ncoords);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ncoords;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_coord_info(in_fn, in_B, in_Z, in_C, io_coordname) 
 *
 * The original C interface is 
 * int cg_coord_info( int fn, int B, int Z, int C, DataType_t * type, char * coordname);
 */
EXTERN_C void cg_coord_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    DataType_t out_type;
    char * io_coordname;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument C");
    in_C = _get_numeric_scalar_int32(prhs[3]);

    io_coordname = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_coord_info(in_fn, in_B, in_Z, in_C, &out_type, io_coordname);


    /******** Process inout argument. ********/
    /* _mxPutString(io_coordname, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_coordname);
    }
}

/* Gateway function 
 * ierr = cg_coord_read(in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord) 
 *
 * The original C interface is 
 * int cg_coord_read( int fn, int B, int Z, char const * coordname, DataType_t type, int const * rmin, int const * rmax, void * coord);
 */
EXTERN_C void cg_coord_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    char * in_coordname;
    DataType_t in_type;
    int * in_rmin;
    int * in_rmax;
    void * io_coord;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_coordname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        in_rmin = (int*)mxGetData(prhs[5]);
    else {
        in_rmin = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], in_rmin))
            mexErrMsgTxt("Expecting numeric matrix for argument rmin");
    }

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_rmax = (int*)mxGetData(prhs[6]);
    else {
        in_rmax = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_rmax))
            mexErrMsgTxt("Expecting numeric matrix for argument rmax");
    }

    io_coord = mxGetData( prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_coord_read(in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(in_rmin);
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_rmax);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_coord_id, ierr] = cg_coord_id(in_fn, in_B, in_Z, in_C) 
 *
 * The original C interface is 
 * int cg_coord_id( int fn, int B, int Z, int C, double * coord_id);
 */
EXTERN_C void cg_coord_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    double out_coord_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument C");
    in_C = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_coord_id(in_fn, in_B, in_Z, in_C, &out_coord_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_coord_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_C, ierr] = cg_coord_write(in_fn, in_B, in_Z, in_type, in_coordname, in_coord_ptr) 
 *
 * The original C interface is 
 * int cg_coord_write( int fn, int B, int Z, DataType_t type, char const * coordname, void const * coord_ptr, int * C);
 */
EXTERN_C void cg_coord_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    DataType_t in_type;
    char * in_coordname;
    void const * in_coord_ptr;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[3]);

    in_coordname = _mxGetString(prhs[4], NULL);

    in_coord_ptr = mxGetData( prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_coord_write(in_fn, in_B, in_Z, in_type, in_coordname, in_coord_ptr, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_C;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_C, ierr] = cg_coord_partial_write(in_fn, in_B, in_Z, in_type, in_coordname, in_rmin, in_rmax, in_coord_ptr) 
 *
 * The original C interface is 
 * int cg_coord_partial_write( int fn, int B, int Z, DataType_t type, char const * coordname, int * rmin, int * rmax, void const * coord_ptr, int * C);
 */
EXTERN_C void cg_coord_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    DataType_t in_type;
    char * in_coordname;
    int * in_rmin;
    int * in_rmax;
    void const * in_coord_ptr;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[3]);

    in_coordname = _mxGetString(prhs[4], NULL);

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        in_rmin = (int*)mxGetData(prhs[5]);
    else {
        in_rmin = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], in_rmin))
            mexErrMsgTxt("Expecting numeric matrix for argument rmin");
    }

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_rmax = (int*)mxGetData(prhs[6]);
    else {
        in_rmax = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_rmax))
            mexErrMsgTxt("Expecting numeric matrix for argument rmax");
    }

    in_coord_ptr = mxGetData( prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_coord_partial_write(in_fn, in_B, in_Z, in_type, in_coordname, in_rmin, in_rmax, in_coord_ptr, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(in_rmin);
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_rmax);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_C;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nsections, ierr] = cg_nsections(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_nsections( int file_number, int B, int Z, int * nsections);
 */
EXTERN_C void cg_nsections_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int out_nsections;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nsections(in_file_number, in_B, in_Z, &out_nsections);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsections;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, out_start, out_end, out_nbndry, out_parent_flag, ierr] = cg_section_read(in_file_number, in_B, in_Z, in_S, io_SectionName) 
 *
 * The original C interface is 
 * int cg_section_read( int file_number, int B, int Z, int S, char * SectionName, ElementType_t * type, int * start, int * end, int * nbndry, int * parent_flag);
 */
EXTERN_C void cg_section_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    char * io_SectionName;
    ElementType_t out_type;
    int out_start;
    int out_end;
    int out_nbndry;
    int out_parent_flag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 7 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    io_SectionName = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_section_read(in_file_number, in_B, in_Z, in_S, io_SectionName, &out_type, &out_start, &out_end, &out_nbndry, &out_parent_flag);


    /******** Process inout argument. ********/
    /* _mxPutString(io_SectionName, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_start;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_end;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_nbndry;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_parent_flag;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = ierr;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateString(io_SectionName);
    }
}

/* Gateway function 
 * ierr = cg_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data) 
 *
 * The original C interface is 
 * int cg_elements_read( int file_number, int B, int Z, int S, int * elements, int * parent_data);
 */
EXTERN_C void cg_elements_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int * io_elements;
    int * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        io_elements = (int*)mxGetData(prhs[4]);
    else {
        io_elements = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], io_elements))
            mexErrMsgTxt("Expecting numeric matrix for argument elements");
    }

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        io_parent_data = (int*)mxGetData(prhs[5]);
    else {
        io_parent_data = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], io_parent_data))
            mexErrMsgTxt("Expecting numeric matrix for argument parent_data");
    }


    /******** Invoke computational function ********/
    ierr = cg_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(io_elements);
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(io_parent_data);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_S, ierr] = cg_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements) 
 *
 * The original C interface is 
 * int cg_section_write( int file_number, int B, int Z, char const * SectionName, ElementType_t type, int start, int end, int nbndry, int const * elements, int * S);
 */
EXTERN_C void cg_section_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    ElementType_t in_type;
    int in_start;
    int in_end;
    int in_nbndry;
    int * in_elements;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_SectionName = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt32(prhs[8]) || mxIsUint32(prhs[8]))
        in_elements = (int*)mxGetData(prhs[8]);
    else {
        in_elements = (int*)mxCalloc(mxGetNumberOfElements(prhs[8]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[8], in_elements))
            mexErrMsgTxt("Expecting numeric matrix for argument elements");
    }


    /******** Invoke computational function ********/
    ierr = cg_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);
    if (!mxIsInt32(prhs[8]) && !mxIsUint32(prhs[8]))
        mxFree(in_elements);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data) 
 *
 * The original C interface is 
 * int cg_parent_data_write( int file_number, int B, int Z, int S, int const * parent_data);
 */
EXTERN_C void cg_parent_data_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int * in_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        in_parent_data = (int*)mxGetData(prhs[4]);
    else {
        in_parent_data = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], in_parent_data))
            mexErrMsgTxt("Expecting numeric matrix for argument parent_data");
    }


    /******** Invoke computational function ********/
    ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(in_parent_data);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_npe, ierr] = cg_npe(in_type) 
 *
 * The original C interface is 
 * int cg_npe( ElementType_t type, int * npe);
 */
EXTERN_C void cg_npe_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    ElementType_t in_type;
    int out_npe;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_npe(in_type, &out_npe);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_npe;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_ElementDataSize, ierr] = cg_ElementDataSize(in_file_number, in_B, in_Z, in_S) 
 *
 * The original C interface is 
 * int cg_ElementDataSize( int file_number, int B, int Z, int S, int * ElementDataSize);
 */
EXTERN_C void cg_ElementDataSize_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int out_ElementDataSize;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_ElementDataSize(in_file_number, in_B, in_Z, in_S, &out_ElementDataSize);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ElementDataSize;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_S, ierr] = cg_section_partial_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry) 
 *
 * The original C interface is 
 * int cg_section_partial_write( int file_number, int B, int Z, char const * SectionName, ElementType_t type, int start, int end, int nbndry, int * S);
 */
EXTERN_C void cg_section_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    ElementType_t in_type;
    int in_start;
    int in_end;
    int in_nbndry;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_SectionName = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[7]);


    /******** Invoke computational function ********/
    ierr = cg_section_partial_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements) 
 *
 * The original C interface is 
 * int cg_elements_partial_write( int fn, int B, int Z, int S, int start, int end, int const * elements);
 */
EXTERN_C void cg_elements_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int in_start;
    int in_end;
    int * in_elements;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[5]);

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_elements = (int*)mxGetData(prhs[6]);
    else {
        in_elements = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_elements))
            mexErrMsgTxt("Expecting numeric matrix for argument elements");
    }


    /******** Invoke computational function ********/
    ierr = cg_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_elements);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_parent_data_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_ParentData) 
 *
 * The original C interface is 
 * int cg_parent_data_partial_write( int fn, int B, int Z, int S, int start, int end, int const * ParentData);
 */
EXTERN_C void cg_parent_data_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int in_start;
    int in_end;
    int * in_ParentData;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[5]);

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_ParentData = (int*)mxGetData(prhs[6]);
    else {
        in_ParentData = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_ParentData))
            mexErrMsgTxt("Expecting numeric matrix for argument ParentData");
    }


    /******** Invoke computational function ********/
    ierr = cg_parent_data_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_ParentData);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_ParentData);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data) 
 *
 * The original C interface is 
 * int cg_elements_partial_read( int file_number, int B, int Z, int S, int start, int end, int * elements, int * parent_data);
 */
EXTERN_C void cg_elements_partial_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int in_start;
    int in_end;
    int * io_elements;
    int * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[5]);

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        io_elements = (int*)mxGetData(prhs[6]);
    else {
        io_elements = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], io_elements))
            mexErrMsgTxt("Expecting numeric matrix for argument elements");
    }

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        io_parent_data = (int*)mxGetData(prhs[7]);
    else {
        io_parent_data = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], io_parent_data))
            mexErrMsgTxt("Expecting numeric matrix for argument parent_data");
    }


    /******** Invoke computational function ********/
    ierr = cg_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(io_elements);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(io_parent_data);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_ElementDataSize, ierr] = cg_ElementPartialSize(in_file_number, in_B, in_Z, in_S, in_start, in_end) 
 *
 * The original C interface is 
 * int cg_ElementPartialSize( int file_number, int B, int Z, int S, int start, int end, int * ElementDataSize);
 */
EXTERN_C void cg_ElementPartialSize_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int in_start;
    int in_end;
    int out_ElementDataSize;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int32(prhs[5]);


    /******** Invoke computational function ********/
    ierr = cg_ElementPartialSize(in_file_number, in_B, in_Z, in_S, in_start, in_end, &out_ElementDataSize);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ElementDataSize;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nsols, ierr] = cg_nsols(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_nsols( int fn, int B, int Z, int * nsols);
 */
EXTERN_C void cg_nsols_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_nsols;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nsols(in_fn, in_B, in_Z, &out_nsols);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsols;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_location, ierr] = cg_sol_info(in_fn, in_B, in_Z, in_S, io_solname) 
 *
 * The original C interface is 
 * int cg_sol_info( int fn, int B, int Z, int S, char * solname, GridLocation_t * location);
 */
EXTERN_C void cg_sol_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char * io_solname;
    GridLocation_t out_location;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    io_solname = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_sol_info(in_fn, in_B, in_Z, in_S, io_solname, &out_location);


    /******** Process inout argument. ********/
    /* _mxPutString(io_solname, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_location;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_solname);
    }
}

/* Gateway function 
 * [out_sol_id, ierr] = cg_sol_id(in_fn, in_B, in_Z, in_S) 
 *
 * The original C interface is 
 * int cg_sol_id( int fn, int B, int Z, int S, double * sol_id);
 */
EXTERN_C void cg_sol_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    double out_sol_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_sol_id(in_fn, in_B, in_Z, in_S, &out_sol_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_sol_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_S, ierr] = cg_sol_write(in_fn, in_B, in_Z, in_solname, in_location) 
 *
 * The original C interface is 
 * int cg_sol_write( int fn, int B, int Z, char const * solname, GridLocation_t location, int * S);
 */
EXTERN_C void cg_sol_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    char * in_solname;
    GridLocation_t in_location;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_solname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_sol_write(in_fn, in_B, in_Z, in_solname, in_location, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_solname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nfields, ierr] = cg_nfields(in_fn, in_B, in_Z, in_S) 
 *
 * The original C interface is 
 * int cg_nfields( int fn, int B, int Z, int S, int * nfields);
 */
EXTERN_C void cg_nfields_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int out_nfields;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_nfields(in_fn, in_B, in_Z, in_S, &out_nfields);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfields;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_field_info(in_fn, in_B, in_Z, in_S, in_F, io_fieldname) 
 *
 * The original C interface is 
 * int cg_field_info( int fn, int B, int Z, int S, int F, DataType_t * type, char * fieldname);
 */
EXTERN_C void cg_field_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int in_F;
    DataType_t out_type;
    char * io_fieldname;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[4]);

    io_fieldname = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_field_info(in_fn, in_B, in_Z, in_S, in_F, &out_type, io_fieldname);


    /******** Process inout argument. ********/
    /* _mxPutString(io_fieldname, (mxArray*)prhs[5]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_fieldname);
    }
}

/* Gateway function 
 * ierr = cg_field_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr) 
 *
 * The original C interface is 
 * int cg_field_read( int fn, int B, int Z, int S, char const * fieldname, DataType_t type, int * rmin, int * rmax, void * field_ptr);
 */
EXTERN_C void cg_field_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char * in_fieldname;
    DataType_t in_type;
    int * in_rmin;
    int * in_rmax;
    void * io_field_ptr;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    in_fieldname = _mxGetString(prhs[4], NULL);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[5]);

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_rmin = (int*)mxGetData(prhs[6]);
    else {
        in_rmin = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_rmin))
            mexErrMsgTxt("Expecting numeric matrix for argument rmin");
    }

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        in_rmax = (int*)mxGetData(prhs[7]);
    else {
        in_rmax = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], in_rmax))
            mexErrMsgTxt("Expecting numeric matrix for argument rmax");
    }

    io_field_ptr = mxGetData( prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_field_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_rmin);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(in_rmax);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_field_id, ierr] = cg_field_id(in_fn, in_B, in_Z, in_S, in_F) 
 *
 * The original C interface is 
 * int cg_field_id( int fn, int B, int Z, int S, int F, double * field_id);
 */
EXTERN_C void cg_field_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int in_F;
    double out_field_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_field_id(in_fn, in_B, in_Z, in_S, in_F, &out_field_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_field_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_F, ierr] = cg_field_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_field_ptr) 
 *
 * The original C interface is 
 * int cg_field_write( int fn, int B, int Z, int S, DataType_t type, char const * fieldname, void const * field_ptr, int * F);
 */
EXTERN_C void cg_field_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    DataType_t in_type;
    char * in_fieldname;
    void const * in_field_ptr;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    in_fieldname = _mxGetString(prhs[5], NULL);

    in_field_ptr = mxGetData( prhs[6]);

    /******** Invoke computational function ********/
    ierr = cg_field_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_field_ptr, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_F, ierr] = cg_field_partial_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr) 
 *
 * The original C interface is 
 * int cg_field_partial_write( int fn, int B, int Z, int S, DataType_t type, char const * fieldname, int * rmin, int * rmax, void const * field_ptr, int * F);
 */
EXTERN_C void cg_field_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    DataType_t in_type;
    char * in_fieldname;
    int * in_rmin;
    int * in_rmax;
    void const * in_field_ptr;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument S");
    in_S = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    in_fieldname = _mxGetString(prhs[5], NULL);

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_rmin = (int*)mxGetData(prhs[6]);
    else {
        in_rmin = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_rmin))
            mexErrMsgTxt("Expecting numeric matrix for argument rmin");
    }

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        in_rmax = (int*)mxGetData(prhs[7]);
    else {
        in_rmax = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], in_rmax))
            mexErrMsgTxt("Expecting numeric matrix for argument rmax");
    }

    in_field_ptr = mxGetData( prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_field_partial_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_rmin);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(in_rmax);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nholes, ierr] = cg_nholes(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_nholes( int fn, int B, int Z, int * nholes);
 */
EXTERN_C void cg_nholes_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_nholes;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nholes(in_fn, in_B, in_Z, &out_nholes);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nholes;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_location, out_ptset_type, out_nptsets, out_npnts, ierr] = cg_hole_info(in_fn, in_B, in_Z, in_I, io_holename) 
 *
 * The original C interface is 
 * int cg_hole_info( int fn, int B, int Z, int I, char * holename, GridLocation_t * location, PointSetType_t * ptset_type, int * nptsets, int * npnts);
 */
EXTERN_C void cg_hole_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    char * io_holename;
    GridLocation_t out_location;
    PointSetType_t out_ptset_type;
    int out_nptsets;
    int out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 6 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    io_holename = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_hole_info(in_fn, in_B, in_Z, in_I, io_holename, &out_location, &out_ptset_type, &out_nptsets, &out_npnts);


    /******** Process inout argument. ********/
    /* _mxPutString(io_holename, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_location;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_ptset_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_nptsets;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_npnts;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateString(io_holename);
    }
}

/* Gateway function 
 * ierr = cg_hole_read(in_fn, in_B, in_Z, in_I, io_pnts) 
 *
 * The original C interface is 
 * int cg_hole_read( int fn, int B, int Z, int I, int * pnts);
 */
EXTERN_C void cg_hole_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    int * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        io_pnts = (int*)mxGetData(prhs[4]);
    else {
        io_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], io_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }


    /******** Invoke computational function ********/
    ierr = cg_hole_read(in_fn, in_B, in_Z, in_I, io_pnts);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(io_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_hole_id, ierr] = cg_hole_id(in_fn, in_B, in_Z, in_I) 
 *
 * The original C interface is 
 * int cg_hole_id( int fn, int B, int Z, int I, double * hole_id);
 */
EXTERN_C void cg_hole_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    double out_hole_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_hole_id(in_fn, in_B, in_Z, in_I, &out_hole_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_hole_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_I, ierr] = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts) 
 *
 * The original C interface is 
 * int cg_hole_write( int fn, int B, int Z, char const * holename, GridLocation_t location, PointSetType_t ptset_type, int nptsets, int npnts, int const * pnts, int * I);
 */
EXTERN_C void cg_hole_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    char * in_holename;
    GridLocation_t in_location;
    PointSetType_t in_ptset_type;
    int in_nptsets;
    int in_npnts;
    int * in_pnts;
    int out_I;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_holename = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument nptsets");
    in_nptsets = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt32(prhs[8]) || mxIsUint32(prhs[8]))
        in_pnts = (int*)mxGetData(prhs[8]);
    else {
        in_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[8]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[8], in_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }


    /******** Invoke computational function ********/
    ierr = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts, &out_I);


    /******** Free up input buffers. ********/
    _mxFreeString(in_holename);
    if (!mxIsInt32(prhs[8]) && !mxIsUint32(prhs[8]))
        mxFree(in_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_I;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_nconns, ierr] = cg_nconns(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_nconns( int fn, int B, int Z, int * nconns);
 */
EXTERN_C void cg_nconns_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_nconns;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nconns(in_fn, in_B, in_Z, &out_nconns);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nconns;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_location, out_type, out_ptset_type, out_npnts, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr] = cg_conn_info(in_file_number, in_B, in_Z, in_I, io_connectname, io_donorname) 
 *
 * The original C interface is 
 * int cg_conn_info( int file_number, int B, int Z, int I, char * connectname, GridLocation_t * location, GridConnectivityType_t * type, PointSetType_t * ptset_type, int * npnts, char * donorname, ZoneType_t * donor_zonetype, PointSetType_t * donor_ptset_type, DataType_t * donor_datatype, int * ndata_donor);
 */
EXTERN_C void cg_conn_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    char * io_connectname;
    GridLocation_t out_location;
    GridConnectivityType_t out_type;
    PointSetType_t out_ptset_type;
    int out_npnts;
    char * io_donorname;
    ZoneType_t out_donor_zonetype;
    PointSetType_t out_donor_ptset_type;
    DataType_t out_donor_datatype;
    int out_ndata_donor;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 11 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    io_connectname = _mxGetString(prhs[4], NULL);

    io_donorname = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_conn_info(in_file_number, in_B, in_Z, in_I, io_connectname, &out_location, &out_type, &out_ptset_type, &out_npnts, io_donorname, &out_donor_zonetype, &out_donor_ptset_type, &out_donor_datatype, &out_ndata_donor);


    /******** Process inout argument. ********/
    /* _mxPutString(io_connectname, (mxArray*)prhs[4]); */
    /* _mxPutString(io_donorname, (mxArray*)prhs[5]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_location;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_ptset_type;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_npnts;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_donor_zonetype;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_donor_ptset_type;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = out_donor_datatype;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[7]) = out_ndata_donor;
    }
    if (nlhs > 8) {
        plhs[8] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[8]) = ierr;
    }
    if (nlhs > 9) {
        plhs[9] = mxCreateString(io_connectname);
    }
    if (nlhs > 10) {
        plhs[10] = mxCreateString(io_donorname);
    }
}

/* Gateway function 
 * ierr = cg_conn_read(in_file_number, in_B, in_Z, in_I, in_donor_datatype, io_pnts, io_donor_data) 
 *
 * The original C interface is 
 * int cg_conn_read( int file_number, int B, int Z, int I, int * pnts, DataType_t donor_datatype, void * donor_data);
 */
EXTERN_C void cg_conn_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    int * io_pnts;
    DataType_t in_donor_datatype;
    void * io_donor_data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument donor_datatype");
    in_donor_datatype = _get_numeric_scalar_int32(prhs[4]);

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        io_pnts = (int*)mxGetData(prhs[5]);
    else {
        io_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], io_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }

    io_donor_data = mxGetData( prhs[6]);

    /******** Invoke computational function ********/
    ierr = cg_conn_read(in_file_number, in_B, in_Z, in_I, io_pnts, in_donor_datatype, io_donor_data);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(io_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_conn_id, ierr] = cg_conn_id(in_fn, in_B, in_Z, in_I) 
 *
 * The original C interface is 
 * int cg_conn_id( int fn, int B, int Z, int I, double * conn_id);
 */
EXTERN_C void cg_conn_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    double out_conn_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_conn_id(in_fn, in_B, in_Z, in_I, &out_conn_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_conn_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_I, ierr] = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data) 
 *
 * The original C interface is 
 * int cg_conn_write( int file_number, int B, int Z, char const * connectname, GridLocation_t location, GridConnectivityType_t type, PointSetType_t ptset_type, int npnts, int const * pnts, char const * donorname, ZoneType_t donor_zonetype, PointSetType_t donor_ptset_type, DataType_t donor_datatype, int ndata_donor, void const * donor_data, int * I);
 */
EXTERN_C void cg_conn_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_connectname;
    GridLocation_t in_location;
    GridConnectivityType_t in_type;
    PointSetType_t in_ptset_type;
    int in_npnts;
    int * in_pnts;
    char * in_donorname;
    ZoneType_t in_donor_zonetype;
    PointSetType_t in_donor_ptset_type;
    DataType_t in_donor_datatype;
    int in_ndata_donor;
    void const * in_donor_data;
    int out_I;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 15)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_connectname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt32(prhs[8]) || mxIsUint32(prhs[8]))
        in_pnts = (int*)mxGetData(prhs[8]);
    else {
        in_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[8]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[8], in_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }

    in_donorname = _mxGetString(prhs[9], NULL);

    if (_n_dims(prhs[10]) > 0)
        mexErrMsgTxt("Error in dimension of argument donor_zonetype");
    in_donor_zonetype = _get_numeric_scalar_int32(prhs[10]);

    if (_n_dims(prhs[11]) > 0)
        mexErrMsgTxt("Error in dimension of argument donor_ptset_type");
    in_donor_ptset_type = _get_numeric_scalar_int32(prhs[11]);

    if (_n_dims(prhs[12]) > 0)
        mexErrMsgTxt("Error in dimension of argument donor_datatype");
    in_donor_datatype = _get_numeric_scalar_int32(prhs[12]);

    if (_n_dims(prhs[13]) > 0)
        mexErrMsgTxt("Error in dimension of argument ndata_donor");
    in_ndata_donor = _get_numeric_scalar_int32(prhs[13]);

    in_donor_data = mxGetData( prhs[14]);

    /******** Invoke computational function ********/
    ierr = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data, &out_I);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    if (!mxIsInt32(prhs[8]) && !mxIsUint32(prhs[8]))
        mxFree(in_pnts);
    _mxFreeString(in_donorname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_I;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_I, ierr] = cg_conn_write_short(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname) 
 *
 * The original C interface is 
 * int cg_conn_write_short( int file_number, int B, int Z, char const * connectname, GridLocation_t location, GridConnectivityType_t type, PointSetType_t ptset_type, int npnts, int const * pnts, char const * donorname, int * I);
 */
EXTERN_C void cg_conn_write_short_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_connectname;
    GridLocation_t in_location;
    GridConnectivityType_t in_type;
    PointSetType_t in_ptset_type;
    int in_npnts;
    int * in_pnts;
    char * in_donorname;
    int out_I;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 10)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_connectname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt32(prhs[8]) || mxIsUint32(prhs[8]))
        in_pnts = (int*)mxGetData(prhs[8]);
    else {
        in_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[8]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[8], in_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }

    in_donorname = _mxGetString(prhs[9], NULL);


    /******** Invoke computational function ********/
    ierr = cg_conn_write_short(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, &out_I);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    if (!mxIsInt32(prhs[8]) && !mxIsUint32(prhs[8]))
        mxFree(in_pnts);
    _mxFreeString(in_donorname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_I;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_conn_read_short(in_file_number, in_B, in_Z, in_I, io_pnts) 
 *
 * The original C interface is 
 * int cg_conn_read_short( int file_number, int B, int Z, int I, int * pnts);
 */
EXTERN_C void cg_conn_read_short_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    int * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        io_pnts = (int*)mxGetData(prhs[4]);
    else {
        io_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], io_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }


    /******** Invoke computational function ********/
    ierr = cg_conn_read_short(in_file_number, in_B, in_Z, in_I, io_pnts);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(io_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_n1to1, ierr] = cg_n1to1(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_n1to1( int fn, int B, int Z, int * n1to1);
 */
EXTERN_C void cg_n1to1_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_n1to1;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_n1to1(in_fn, in_B, in_Z, &out_n1to1);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n1to1;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_1to1_read(in_fn, in_B, in_Z, in_I, io_connectname, io_donorname, io_range, io_donor_range, io_transform) 
 *
 * The original C interface is 
 * int cg_1to1_read( int fn, int B, int Z, int I, char * connectname, char * donorname, int * range, int * donor_range, int * transform);
 */
EXTERN_C void cg_1to1_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    char * io_connectname;
    char * io_donorname;
    int * io_range;
    int * io_donor_range;
    int * io_transform;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    io_connectname = _mxGetString(prhs[4], NULL);

    io_donorname = _mxGetString(prhs[5], NULL);

    if (mxGetNumberOfElements(prhs[6]) < (int) (6) || _n_dims(prhs[6]) > 1)
        mexErrMsgTxt("Error in dimension of argument range");
    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        io_range = (int*)mxGetData(prhs[6]);
    else {
        io_range = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], io_range))
            mexErrMsgTxt("Expecting numeric matrix for argument range");
    }

    if (mxGetNumberOfElements(prhs[7]) < (int) (6) || _n_dims(prhs[7]) > 1)
        mexErrMsgTxt("Error in dimension of argument donor_range");
    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        io_donor_range = (int*)mxGetData(prhs[7]);
    else {
        io_donor_range = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], io_donor_range))
            mexErrMsgTxt("Expecting numeric matrix for argument donor_range");
    }

    if (mxGetNumberOfElements(prhs[8]) < (int) (3) || _n_dims(prhs[8]) > 1)
        mexErrMsgTxt("Error in dimension of argument transform");
    if (mxIsInt32(prhs[8]) || mxIsUint32(prhs[8]))
        io_transform = (int*)mxGetData(prhs[8]);
    else {
        io_transform = (int*)mxCalloc(mxGetNumberOfElements(prhs[8]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[8], io_transform))
            mexErrMsgTxt("Expecting numeric matrix for argument transform");
    }


    /******** Invoke computational function ********/
    ierr = cg_1to1_read(in_fn, in_B, in_Z, in_I, io_connectname, io_donorname, io_range, io_donor_range, io_transform);


    /******** Process inout argument. ********/
    /* _mxPutString(io_connectname, (mxArray*)prhs[4]); */
    /* _mxPutString(io_donorname, (mxArray*)prhs[5]); */
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(io_range);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(io_donor_range);
    if (!mxIsInt32(prhs[8]) && !mxIsUint32(prhs[8]))
        mxFree(io_transform);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_connectname);
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_donorname);
    }
}

/* Gateway function 
 * [out_one21_id, ierr] = cg_1to1_id(in_fn, in_B, in_Z, in_I) 
 *
 * The original C interface is 
 * int cg_1to1_id( int fn, int B, int Z, int I, double * one21_id);
 */
EXTERN_C void cg_1to1_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_I;
    double out_one21_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_id(in_fn, in_B, in_Z, in_I, &out_one21_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_one21_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_I, ierr] = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform) 
 *
 * The original C interface is 
 * int cg_1to1_write( int fn, int B, int Z, char const * connectname, char const * donorname, int const * range, int const * donor_range, int const * transform, int * I);
 */
EXTERN_C void cg_1to1_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    char * in_connectname;
    char * in_donorname;
    int * in_range;
    int * in_donor_range;
    int * in_transform;
    int out_I;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_connectname = _mxGetString(prhs[3], NULL);

    in_donorname = _mxGetString(prhs[4], NULL);

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        in_range = (int*)mxGetData(prhs[5]);
    else {
        in_range = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], in_range))
            mexErrMsgTxt("Expecting numeric matrix for argument range");
    }

    if (mxIsInt32(prhs[6]) || mxIsUint32(prhs[6]))
        in_donor_range = (int*)mxGetData(prhs[6]);
    else {
        in_donor_range = (int*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[6], in_donor_range))
            mexErrMsgTxt("Expecting numeric matrix for argument donor_range");
    }

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        in_transform = (int*)mxGetData(prhs[7]);
    else {
        in_transform = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], in_transform))
            mexErrMsgTxt("Expecting numeric matrix for argument transform");
    }


    /******** Invoke computational function ********/
    ierr = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform, &out_I);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    _mxFreeString(in_donorname);
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(in_range);
    if (!mxIsInt32(prhs[6]) && !mxIsUint32(prhs[6]))
        mxFree(in_donor_range);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(in_transform);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_I;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_n1to1_global, ierr] = cg_n1to1_global(in_fn, in_B) 
 *
 * The original C interface is 
 * int cg_n1to1_global( int fn, int B, int * n1to1_global);
 */
EXTERN_C void cg_n1to1_global_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int out_n1to1_global;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_n1to1_global(in_fn, in_B, &out_n1to1_global);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n1to1_global;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* External gateway function */
EXTERN void cg_1to1_read_global_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[]);

/* Gateway function 
 * [out_nbocos, ierr] = cg_nbocos(in_fn, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_nbocos( int fn, int B, int Z, int * nbocos);
 */
EXTERN_C void cg_nbocos_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int out_nbocos;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nbocos(in_fn, in_B, in_Z, &out_nbocos);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nbocos;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_bocotype, out_ptset_type, out_npnts, out_NormalListFlag, out_NormalDataType, out_ndataset, ierr] = cg_boco_info(in_fn, in_B, in_Z, in_BC, io_boconame, io_NormalIndex) 
 *
 * The original C interface is 
 * int cg_boco_info( int fn, int B, int Z, int BC, char * boconame, BCType_t * bocotype, PointSetType_t * ptset_type, int * npnts, int * NormalIndex, int * NormalListFlag, DataType_t * NormalDataType, int * ndataset);
 */
EXTERN_C void cg_boco_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    char * io_boconame;
    BCType_t out_bocotype;
    PointSetType_t out_ptset_type;
    int out_npnts;
    int * io_NormalIndex;
    int out_NormalListFlag;
    DataType_t out_NormalDataType;
    int out_ndataset;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 8 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    io_boconame = _mxGetString(prhs[4], NULL);

    if (mxIsInt32(prhs[5]) || mxIsUint32(prhs[5]))
        io_NormalIndex = (int*)mxGetData(prhs[5]);
    else {
        io_NormalIndex = (int*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[5], io_NormalIndex))
            mexErrMsgTxt("Expecting numeric matrix for argument NormalIndex");
    }


    /******** Invoke computational function ********/
    ierr = cg_boco_info(in_fn, in_B, in_Z, in_BC, io_boconame, &out_bocotype, &out_ptset_type, &out_npnts, io_NormalIndex, &out_NormalListFlag, &out_NormalDataType, &out_ndataset);


    /******** Process inout argument. ********/
    /* _mxPutString(io_boconame, (mxArray*)prhs[4]); */
    if (!mxIsInt32(prhs[5]) && !mxIsUint32(prhs[5]))
        mxFree(io_NormalIndex);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_bocotype;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_ptset_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_npnts;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_NormalListFlag;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_NormalDataType;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_ndataset;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = ierr;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateString(io_boconame);
    }
}

/* Gateway function 
 * ierr = cg_boco_read(in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList) 
 *
 * The original C interface is 
 * int cg_boco_read( int fn, int B, int Z, int BC, int * pnts, void * NormalList);
 */
EXTERN_C void cg_boco_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    int * io_pnts;
    void * io_NormalList;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        io_pnts = (int*)mxGetData(prhs[4]);
    else {
        io_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], io_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }

    io_NormalList = mxGetData( prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_boco_read(in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(io_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_boco_id, ierr] = cg_boco_id(in_fn, in_B, in_Z, in_BC) 
 *
 * The original C interface is 
 * int cg_boco_id( int fn, int B, int Z, int BC, double * boco_id);
 */
EXTERN_C void cg_boco_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    double out_boco_id;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_boco_id(in_fn, in_B, in_Z, in_BC, &out_boco_id);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_boco_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_BC, ierr] = cg_boco_write(in_file_number, in_B, in_Z, in_boconame, in_bocotype, in_ptset_type, in_npnts, in_pnts) 
 *
 * The original C interface is 
 * int cg_boco_write( int file_number, int B, int Z, char const * boconame, BCType_t bocotype, PointSetType_t ptset_type, int npnts, int const * pnts, int * BC);
 */
EXTERN_C void cg_boco_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_boconame;
    BCType_t in_bocotype;
    PointSetType_t in_ptset_type;
    int in_npnts;
    int * in_pnts;
    int out_BC;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_boconame = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument bocotype");
    in_bocotype = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int32(prhs[6]);

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        in_pnts = (int*)mxGetData(prhs[7]);
    else {
        in_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[7]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[7], in_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }


    /******** Invoke computational function ********/
    ierr = cg_boco_write(in_file_number, in_B, in_Z, in_boconame, in_bocotype, in_ptset_type, in_npnts, in_pnts, &out_BC);


    /******** Free up input buffers. ********/
    _mxFreeString(in_boconame);
    if (!mxIsInt32(prhs[7]) && !mxIsUint32(prhs[7]))
        mxFree(in_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BC;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_boco_normal_write(in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList) 
 *
 * The original C interface is 
 * int cg_boco_normal_write( int file_number, int B, int Z, int BC, int const * NormalIndex, int NormalListFlag, DataType_t NormalDataType, void const * NormalList);
 */
EXTERN_C void cg_boco_normal_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    int * in_NormalIndex;
    int in_NormalListFlag;
    DataType_t in_NormalDataType;
    void const * in_NormalList;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        in_NormalIndex = (int*)mxGetData(prhs[4]);
    else {
        in_NormalIndex = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], in_NormalIndex))
            mexErrMsgTxt("Expecting numeric matrix for argument NormalIndex");
    }

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument NormalListFlag");
    in_NormalListFlag = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument NormalDataType");
    in_NormalDataType = _get_numeric_scalar_int32(prhs[6]);

    in_NormalList = mxGetData( prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_boco_normal_write(in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(in_NormalIndex);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS, io_name) 
 *
 * The original C interface is 
 * int cg_dataset_read( int fn, int B, int Z, int BC, int DS, char * name, BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
 */
EXTERN_C void cg_dataset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    int in_DS;
    char * io_name;
    BCType_t out_BCType;
    int out_DirichletFlag;
    int out_NeumannFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 5 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument DS");
    in_DS = _get_numeric_scalar_int32(prhs[4]);

    io_name = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS, io_name, &out_BCType, &out_DirichletFlag, &out_NeumannFlag);


    /******** Process inout argument. ********/
    /* _mxPutString(io_name, (mxArray*)prhs[5]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BCType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_DirichletFlag;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_NeumannFlag;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateString(io_name);
    }
}

/* Gateway function 
 * [out_Dset, ierr] = cg_dataset_write(in_file_number, in_B, in_Z, in_BC, in_name, in_BCType) 
 *
 * The original C interface is 
 * int cg_dataset_write( int file_number, int B, int Z, int BC, char const * name, BCType_t BCType, int * Dset);
 */
EXTERN_C void cg_dataset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    char * in_name;
    BCType_t in_BCType;
    int out_Dset;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    in_name = _mxGetString(prhs[4], NULL);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCType");
    in_BCType = _get_numeric_scalar_int32(prhs[5]);


    /******** Invoke computational function ********/
    ierr = cg_dataset_write(in_file_number, in_B, in_Z, in_BC, in_name, in_BCType, &out_Dset);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Dset;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_bcdataset_write(in_BCType, in_BCDataType, io_name) 
 *
 * The original C interface is 
 * int cg_bcdataset_write( char const * name, BCType_t BCType, BCDataType_t BCDataType);
 */
EXTERN_C void cg_bcdataset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_name;
    BCType_t in_BCType;
    BCDataType_t in_BCDataType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_name = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCType");
    in_BCType = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCDataType");
    in_BCDataType = _get_numeric_scalar_int32(prhs[2]);

    /******** Invoke computational function ********/
    ierr = cg_bcdataset_write(in_name, in_BCType, in_BCDataType);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_n_dataset, ierr] = cg_bcdataset_info() 
 *
 * The original C interface is 
 * int cg_bcdataset_info( int * n_dataset);
 */
EXTERN_C void cg_bcdataset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_n_dataset;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_bcdataset_info(&out_n_dataset);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_dataset;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_bcdataset_read(in_index, io_name) 
 *
 * The original C interface is 
 * int cg_bcdataset_read( int index, char * name, BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
 */
EXTERN_C void cg_bcdataset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_index;
    char * io_name;
    BCType_t out_BCType;
    int out_DirichletFlag;
    int out_NeumannFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 5 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument index");
    in_index = _get_numeric_scalar_int32(prhs[0]);

    io_name = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_bcdataset_read(in_index, io_name, &out_BCType, &out_DirichletFlag, &out_NeumannFlag);


    /******** Process inout argument. ********/
    /* _mxPutString(io_name, (mxArray*)prhs[1]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BCType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_DirichletFlag;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_NeumannFlag;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateString(io_name);
    }
}

/* Gateway function 
 * ierr = cg_bcdata_write(in_file_number, in_B, in_Z, in_BC, in_Dset, in_BCDataType) 
 *
 * The original C interface is 
 * int cg_bcdata_write( int file_number, int B, int Z, int BC, int Dset, BCDataType_t BCDataType);
 */
EXTERN_C void cg_bcdata_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    int in_Dset;
    BCDataType_t in_BCDataType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument Dset");
    in_Dset = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCDataType");
    in_BCDataType = _get_numeric_scalar_int32(prhs[5]);


    /******** Invoke computational function ********/
    ierr = cg_bcdata_write(in_file_number, in_B, in_Z, in_BC, in_Dset, in_BCDataType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_ndiscrete, ierr] = cg_ndiscrete(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_ndiscrete( int file_number, int B, int Z, int * ndiscrete);
 */
EXTERN_C void cg_ndiscrete_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int out_ndiscrete;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_ndiscrete(in_file_number, in_B, in_Z, &out_ndiscrete);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ndiscrete;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_discrete_read(in_file_number, in_B, in_Z, in_D, io_discrete_name) 
 *
 * The original C interface is 
 * int cg_discrete_read( int file_number, int B, int Z, int D, char * discrete_name);
 */
EXTERN_C void cg_discrete_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_D;
    char * io_discrete_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument D");
    in_D = _get_numeric_scalar_int32(prhs[3]);

    io_discrete_name = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_discrete_read(in_file_number, in_B, in_Z, in_D, io_discrete_name);


    /******** Process inout argument. ********/
    /* _mxPutString(io_discrete_name, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_discrete_name);
    }
}

/* Gateway function 
 * [out_D, ierr] = cg_discrete_write(in_file_number, in_B, in_Z, in_discrete_name) 
 *
 * The original C interface is 
 * int cg_discrete_write( int file_number, int B, int Z, char const * discrete_name, int * D);
 */
EXTERN_C void cg_discrete_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_discrete_name;
    int out_D;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_discrete_name = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_discrete_write(in_file_number, in_B, in_Z, in_discrete_name, &out_D);


    /******** Free up input buffers. ********/
    _mxFreeString(in_discrete_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_D;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_n_rigid_motions, ierr] = cg_n_rigid_motions(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_n_rigid_motions( int file_number, int B, int Z, int * n_rigid_motions);
 */
EXTERN_C void cg_n_rigid_motions_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int out_n_rigid_motions;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_n_rigid_motions(in_file_number, in_B, in_Z, &out_n_rigid_motions);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_rigid_motions;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_rigid_motion_read(in_file_number, in_B, in_Z, in_R, io_name) 
 *
 * The original C interface is 
 * int cg_rigid_motion_read( int file_number, int B, int Z, int R, char * name, RigidGridMotionType_t * type);
 */
EXTERN_C void cg_rigid_motion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_R;
    char * io_name;
    RigidGridMotionType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument R");
    in_R = _get_numeric_scalar_int32(prhs[3]);

    io_name = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_rigid_motion_read(in_file_number, in_B, in_Z, in_R, io_name, &out_type);


    /******** Process inout argument. ********/
    /* _mxPutString(io_name, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_name);
    }
}

/* Gateway function 
 * [out_R, ierr] = cg_rigid_motion_write(in_file_number, in_B, in_Z, in_name, in_type) 
 *
 * The original C interface is 
 * int cg_rigid_motion_write( int file_number, int B, int Z, char const * name, RigidGridMotionType_t type, int * R);
 */
EXTERN_C void cg_rigid_motion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_name;
    RigidGridMotionType_t in_type;
    int out_R;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_name = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_rigid_motion_write(in_file_number, in_B, in_Z, in_name, in_type, &out_R);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_R;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_n_arbitrary_motions, ierr] = cg_n_arbitrary_motions(in_file_number, in_B, in_Z) 
 *
 * The original C interface is 
 * int cg_n_arbitrary_motions( int file_number, int B, int Z, int * n_arbitrary_motions);
 */
EXTERN_C void cg_n_arbitrary_motions_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int out_n_arbitrary_motions;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_n_arbitrary_motions(in_file_number, in_B, in_Z, &out_n_arbitrary_motions);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_arbitrary_motions;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A, io_name) 
 *
 * The original C interface is 
 * int cg_arbitrary_motion_read( int file_number, int B, int Z, int A, char * name, ArbitraryGridMotionType_t * type);
 */
EXTERN_C void cg_arbitrary_motion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_A;
    char * io_name;
    ArbitraryGridMotionType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[3]);

    io_name = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A, io_name, &out_type);


    /******** Process inout argument. ********/
    /* _mxPutString(io_name, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_name);
    }
}

/* Gateway function 
 * [out_A, ierr] = cg_arbitrary_motion_write(in_file_number, in_B, in_Z, in_amotionname, in_type) 
 *
 * The original C interface is 
 * int cg_arbitrary_motion_write( int file_number, int B, int Z, char const * amotionname, ArbitraryGridMotionType_t type, int * A);
 */
EXTERN_C void cg_arbitrary_motion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_amotionname;
    ArbitraryGridMotionType_t in_type;
    int out_A;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_amotionname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_arbitrary_motion_write(in_file_number, in_B, in_Z, in_amotionname, in_type, &out_A);


    /******** Free up input buffers. ********/
    _mxFreeString(in_amotionname);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_A;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_type, ierr] = cg_simulation_type_read(in_file_number, in_B) 
 *
 * The original C interface is 
 * int cg_simulation_type_read( int file_number, int B, SimulationType_t * type);
 */
EXTERN_C void cg_simulation_type_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    SimulationType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_simulation_type_read(in_file_number, in_B, &out_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_simulation_type_write(in_file_number, in_B, in_type) 
 *
 * The original C interface is 
 * int cg_simulation_type_write( int file_number, int B, SimulationType_t type);
 */
EXTERN_C void cg_simulation_type_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    SimulationType_t in_type;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_simulation_type_write(in_file_number, in_B, in_type);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_nsteps, ierr] = cg_biter_read(in_file_number, in_B, io_bitername) 
 *
 * The original C interface is 
 * int cg_biter_read( int file_number, int B, char * bitername, int * nsteps);
 */
EXTERN_C void cg_biter_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    char * io_bitername;
    int out_nsteps;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    io_bitername = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_biter_read(in_file_number, in_B, io_bitername, &out_nsteps);


    /******** Process inout argument. ********/
    /* _mxPutString(io_bitername, (mxArray*)prhs[2]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsteps;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_bitername);
    }
}

/* Gateway function 
 * ierr = cg_biter_write(in_file_number, in_B, in_bitername, in_nsteps) 
 *
 * The original C interface is 
 * int cg_biter_write( int file_number, int B, char const * bitername, int nsteps);
 */
EXTERN_C void cg_biter_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    char * in_bitername;
    int in_nsteps;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    in_bitername = _mxGetString(prhs[2], NULL);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument nsteps");
    in_nsteps = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_biter_write(in_file_number, in_B, in_bitername, in_nsteps);


    /******** Free up input buffers. ********/
    _mxFreeString(in_bitername);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_ziter_read(in_file_number, in_B, in_Z, io_zitername) 
 *
 * The original C interface is 
 * int cg_ziter_read( int file_number, int B, int Z, char * zitername);
 */
EXTERN_C void cg_ziter_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * io_zitername;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    io_zitername = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_ziter_read(in_file_number, in_B, in_Z, io_zitername);


    /******** Process inout argument. ********/
    /* _mxPutString(io_zitername, (mxArray*)prhs[3]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_zitername);
    }
}

/* Gateway function 
 * ierr = cg_ziter_write(in_file_number, in_B, in_Z, in_zitername) 
 *
 * The original C interface is 
 * int cg_ziter_write( int file_number, int B, int Z, char const * zitername);
 */
EXTERN_C void cg_ziter_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_zitername;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_zitername = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_ziter_write(in_file_number, in_B, in_Z, in_zitername);


    /******** Free up input buffers. ********/
    _mxFreeString(in_zitername);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_gravity_read(in_file_number, in_B, io_gravity_vector) 
 *
 * The original C interface is 
 * int cg_gravity_read( int file_number, int B, float * gravity_vector);
 */
EXTERN_C void cg_gravity_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    float * io_gravity_vector;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        io_gravity_vector = (float*)mxGetData(prhs[2]);
    else {
        io_gravity_vector = (float*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (float));
        if (!_get_numeric_array_float(prhs[2], io_gravity_vector))
             mexErrMsgTxt("Expecting numeric matrix for argument gravity_vector");
    }


    /******** Invoke computational function ********/
    ierr = cg_gravity_read(in_file_number, in_B, io_gravity_vector);


    /******** Process inout argument. ********/
    if (!mxIsSingle(prhs[2])) mxFree(io_gravity_vector);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_gravity_write(in_file_number, in_B, in_gravity_vector) 
 *
 * The original C interface is 
 * int cg_gravity_write( int file_number, int B, float const * gravity_vector);
 */
EXTERN_C void cg_gravity_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    float * in_gravity_vector;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        in_gravity_vector = (float*)mxGetData(prhs[2]);
    else {
        in_gravity_vector = (float*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (float));
        if (!_get_numeric_array_float(prhs[2], in_gravity_vector))
             mexErrMsgTxt("Expecting numeric matrix for argument gravity_vector");
    }


    /******** Invoke computational function ********/
    ierr = cg_gravity_write(in_file_number, in_B, in_gravity_vector);


    /******** Free up input buffers. ********/
    if (!mxIsSingle(prhs[2])) mxFree(in_gravity_vector);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_axisym_read(in_file_number, in_B, io_ref_point, io_axis) 
 *
 * The original C interface is 
 * int cg_axisym_read( int file_number, int B, float * ref_point, float * axis);
 */
EXTERN_C void cg_axisym_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    float * io_ref_point;
    float * io_axis;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        io_ref_point = (float*)mxGetData(prhs[2]);
    else {
        io_ref_point = (float*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (float));
        if (!_get_numeric_array_float(prhs[2], io_ref_point))
             mexErrMsgTxt("Expecting numeric matrix for argument ref_point");
    }

    if (mxIsSingle(prhs[3]))
        io_axis = (float*)mxGetData(prhs[3]);
    else {
        io_axis = (float*)mxCalloc(mxGetNumberOfElements(prhs[3]), sizeof (float));
        if (!_get_numeric_array_float(prhs[3], io_axis))
             mexErrMsgTxt("Expecting numeric matrix for argument axis");
    }


    /******** Invoke computational function ********/
    ierr = cg_axisym_read(in_file_number, in_B, io_ref_point, io_axis);


    /******** Process inout argument. ********/
    if (!mxIsSingle(prhs[2])) mxFree(io_ref_point);
    if (!mxIsSingle(prhs[3])) mxFree(io_axis);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis) 
 *
 * The original C interface is 
 * int cg_axisym_write( int file_number, int B, float const * ref_point, float const * axis);
 */
EXTERN_C void cg_axisym_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    float * in_ref_point;
    float * in_axis;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        in_ref_point = (float*)mxGetData(prhs[2]);
    else {
        in_ref_point = (float*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (float));
        if (!_get_numeric_array_float(prhs[2], in_ref_point))
             mexErrMsgTxt("Expecting numeric matrix for argument ref_point");
    }

    if (mxIsSingle(prhs[3]))
        in_axis = (float*)mxGetData(prhs[3]);
    else {
        in_axis = (float*)mxCalloc(mxGetNumberOfElements(prhs[3]), sizeof (float));
        if (!_get_numeric_array_float(prhs[3], in_axis))
             mexErrMsgTxt("Expecting numeric matrix for argument axis");
    }


    /******** Invoke computational function ********/
    ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis);


    /******** Free up input buffers. ********/
    if (!mxIsSingle(prhs[2])) mxFree(in_ref_point);
    if (!mxIsSingle(prhs[3])) mxFree(in_axis);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_rotating_read(io_rot_rate, io_rot_center) 
 *
 * The original C interface is 
 * int cg_rotating_read( float * rot_rate, float * rot_center);
 */
EXTERN_C void cg_rotating_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    float * io_rot_rate;
    float * io_rot_center;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsSingle(prhs[0]))
        io_rot_rate = (float*)mxGetData(prhs[0]);
    else {
        io_rot_rate = (float*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (float));
        if (!_get_numeric_array_float(prhs[0], io_rot_rate))
             mexErrMsgTxt("Expecting numeric matrix for argument rot_rate");
    }

    if (mxIsSingle(prhs[1]))
        io_rot_center = (float*)mxGetData(prhs[1]);
    else {
        io_rot_center = (float*)mxCalloc(mxGetNumberOfElements(prhs[1]), sizeof (float));
        if (!_get_numeric_array_float(prhs[1], io_rot_center))
             mexErrMsgTxt("Expecting numeric matrix for argument rot_center");
    }


    /******** Invoke computational function ********/
    ierr = cg_rotating_read(io_rot_rate, io_rot_center);


    /******** Process inout argument. ********/
    if (!mxIsSingle(prhs[0])) mxFree(io_rot_rate);
    if (!mxIsSingle(prhs[1])) mxFree(io_rot_center);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_rotating_write(in_rot_rate, in_rot_center) 
 *
 * The original C interface is 
 * int cg_rotating_write( float const * rot_rate, float const * rot_center);
 */
EXTERN_C void cg_rotating_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    float * in_rot_rate;
    float * in_rot_center;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsSingle(prhs[0]))
        in_rot_rate = (float*)mxGetData(prhs[0]);
    else {
        in_rot_rate = (float*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (float));
        if (!_get_numeric_array_float(prhs[0], in_rot_rate))
             mexErrMsgTxt("Expecting numeric matrix for argument rot_rate");
    }

    if (mxIsSingle(prhs[1]))
        in_rot_center = (float*)mxGetData(prhs[1]);
    else {
        in_rot_center = (float*)mxCalloc(mxGetNumberOfElements(prhs[1]), sizeof (float));
        if (!_get_numeric_array_float(prhs[1], in_rot_center))
             mexErrMsgTxt("Expecting numeric matrix for argument rot_center");
    }


    /******** Invoke computational function ********/
    ierr = cg_rotating_write(in_rot_rate, in_rot_center);


    /******** Free up input buffers. ********/
    if (!mxIsSingle(prhs[0])) mxFree(in_rot_rate);
    if (!mxIsSingle(prhs[1])) mxFree(in_rot_center);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_WallFunctionType, ierr] = cg_bc_wallfunction_read(in_file_number, in_B, in_Z, in_BC) 
 *
 * The original C interface is 
 * int cg_bc_wallfunction_read( int file_number, int B, int Z, int BC, WallFunctionType_t * WallFunctionType);
 */
EXTERN_C void cg_bc_wallfunction_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    WallFunctionType_t out_WallFunctionType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_bc_wallfunction_read(in_file_number, in_B, in_Z, in_BC, &out_WallFunctionType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_WallFunctionType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_bc_wallfunction_write(in_file_number, in_B, in_Z, in_BC, in_WallFunctionType) 
 *
 * The original C interface is 
 * int cg_bc_wallfunction_write( int file_number, int B, int Z, int BC, WallFunctionType_t WallFunctionType);
 */
EXTERN_C void cg_bc_wallfunction_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    WallFunctionType_t in_WallFunctionType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument WallFunctionType");
    in_WallFunctionType = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_bc_wallfunction_write(in_file_number, in_B, in_Z, in_BC, in_WallFunctionType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_AreaType, out_SurfaceArea, ierr] = cg_bc_area_read(in_file_number, in_B, in_Z, in_BC, io_RegionName) 
 *
 * The original C interface is 
 * int cg_bc_area_read( int file_number, int B, int Z, int BC, AreaType_t * AreaType, float * SurfaceArea, char * RegionName);
 */
EXTERN_C void cg_bc_area_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    AreaType_t out_AreaType;
    float out_SurfaceArea;
    char * io_RegionName;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 4 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    io_RegionName = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_bc_area_read(in_file_number, in_B, in_Z, in_BC, &out_AreaType, &out_SurfaceArea, io_RegionName);


    /******** Process inout argument. ********/
    /* _mxPutString(io_RegionName, (mxArray*)prhs[4]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_AreaType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
        *(float*)mxGetData(plhs[1]) = out_SurfaceArea;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateString(io_RegionName);
    }
}

/* Gateway function 
 * ierr = cg_bc_area_write(in_file_number, in_B, in_Z, in_BC, in_AreaType, in_SurfaceArea, in_RegionName) 
 *
 * The original C interface is 
 * int cg_bc_area_write( int file_number, int B, int Z, int BC, AreaType_t AreaType, float SurfaceArea, char const * RegionName);
 */
EXTERN_C void cg_bc_area_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    AreaType_t in_AreaType;
    float in_SurfaceArea;
    char * in_RegionName;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument AreaType");
    in_AreaType = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument SurfaceArea");
    in_SurfaceArea = _get_numeric_scalar_float(prhs[5]);

    in_RegionName = _mxGetString(prhs[6], NULL);


    /******** Invoke computational function ********/
    ierr = cg_bc_area_write(in_file_number, in_B, in_Z, in_BC, in_AreaType, in_SurfaceArea, in_RegionName);


    /******** Free up input buffers. ********/
    _mxFreeString(in_RegionName);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_conn_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation) 
 *
 * The original C interface is 
 * int cg_conn_periodic_read( int file_number, int B, int Z, int I, float * RotationCenter, float * RotationAngle, float * Translation);
 */
EXTERN_C void cg_conn_periodic_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    float * io_RotationCenter;
    float * io_RotationAngle;
    float * io_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxGetNumberOfElements(prhs[4]) < (int) (3) || _n_dims(prhs[4]) > 1)
        mexErrMsgTxt("Error in dimension of argument RotationCenter");
    if (mxIsSingle(prhs[4]))
        io_RotationCenter = (float*)mxGetData(prhs[4]);
    else {
        io_RotationCenter = (float*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (float));
        if (!_get_numeric_array_float(prhs[4], io_RotationCenter))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationCenter");
    }

    if (mxGetNumberOfElements(prhs[5]) < (int) (3) || _n_dims(prhs[5]) > 1)
        mexErrMsgTxt("Error in dimension of argument RotationAngle");
    if (mxIsSingle(prhs[5]))
        io_RotationAngle = (float*)mxGetData(prhs[5]);
    else {
        io_RotationAngle = (float*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (float));
        if (!_get_numeric_array_float(prhs[5], io_RotationAngle))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationAngle");
    }

    if (mxGetNumberOfElements(prhs[6]) < (int) (3) || _n_dims(prhs[6]) > 1)
        mexErrMsgTxt("Error in dimension of argument Translation");
    if (mxIsSingle(prhs[6]))
        io_Translation = (float*)mxGetData(prhs[6]);
    else {
        io_Translation = (float*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (float));
        if (!_get_numeric_array_float(prhs[6], io_Translation))
             mexErrMsgTxt("Expecting numeric matrix for argument Translation");
    }


    /******** Invoke computational function ********/
    ierr = cg_conn_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation);


    /******** Process inout argument. ********/
    if (!mxIsSingle(prhs[4])) mxFree(io_RotationCenter);
    if (!mxIsSingle(prhs[5])) mxFree(io_RotationAngle);
    if (!mxIsSingle(prhs[6])) mxFree(io_Translation);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation) 
 *
 * The original C interface is 
 * int cg_conn_periodic_write( int file_number, int B, int Z, int I, float const * RotationCenter, float const * RotationAngle, float const * Translation);
 */
EXTERN_C void cg_conn_periodic_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    float * in_RotationCenter;
    float * in_RotationAngle;
    float * in_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsSingle(prhs[4]))
        in_RotationCenter = (float*)mxGetData(prhs[4]);
    else {
        in_RotationCenter = (float*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (float));
        if (!_get_numeric_array_float(prhs[4], in_RotationCenter))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationCenter");
    }

    if (mxIsSingle(prhs[5]))
        in_RotationAngle = (float*)mxGetData(prhs[5]);
    else {
        in_RotationAngle = (float*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (float));
        if (!_get_numeric_array_float(prhs[5], in_RotationAngle))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationAngle");
    }

    if (mxIsSingle(prhs[6]))
        in_Translation = (float*)mxGetData(prhs[6]);
    else {
        in_Translation = (float*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (float));
        if (!_get_numeric_array_float(prhs[6], in_Translation))
             mexErrMsgTxt("Expecting numeric matrix for argument Translation");
    }


    /******** Invoke computational function ********/
    ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation);


    /******** Free up input buffers. ********/
    if (!mxIsSingle(prhs[4])) mxFree(in_RotationCenter);
    if (!mxIsSingle(prhs[5])) mxFree(in_RotationAngle);
    if (!mxIsSingle(prhs[6])) mxFree(in_Translation);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_1to1_periodic_write(in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation) 
 *
 * The original C interface is 
 * int cg_1to1_periodic_write( int file_number, int B, int Z, int I, float const * RotationCenter, float const * RotationAngle, float const * Translation);
 */
EXTERN_C void cg_1to1_periodic_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    float * in_RotationCenter;
    float * in_RotationAngle;
    float * in_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsSingle(prhs[4]))
        in_RotationCenter = (float*)mxGetData(prhs[4]);
    else {
        in_RotationCenter = (float*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (float));
        if (!_get_numeric_array_float(prhs[4], in_RotationCenter))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationCenter");
    }

    if (mxIsSingle(prhs[5]))
        in_RotationAngle = (float*)mxGetData(prhs[5]);
    else {
        in_RotationAngle = (float*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (float));
        if (!_get_numeric_array_float(prhs[5], in_RotationAngle))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationAngle");
    }

    if (mxIsSingle(prhs[6]))
        in_Translation = (float*)mxGetData(prhs[6]);
    else {
        in_Translation = (float*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (float));
        if (!_get_numeric_array_float(prhs[6], in_Translation))
             mexErrMsgTxt("Expecting numeric matrix for argument Translation");
    }


    /******** Invoke computational function ********/
    ierr = cg_1to1_periodic_write(in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation);


    /******** Free up input buffers. ********/
    if (!mxIsSingle(prhs[4])) mxFree(in_RotationCenter);
    if (!mxIsSingle(prhs[5])) mxFree(in_RotationAngle);
    if (!mxIsSingle(prhs[6])) mxFree(in_Translation);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation) 
 *
 * The original C interface is 
 * int cg_1to1_periodic_read( int file_number, int B, int Z, int I, float * RotationCenter, float * RotationAngle, float * Translation);
 */
EXTERN_C void cg_1to1_periodic_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    float * io_RotationCenter;
    float * io_RotationAngle;
    float * io_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (mxGetNumberOfElements(prhs[4]) < (int) (3) || _n_dims(prhs[4]) > 1)
        mexErrMsgTxt("Error in dimension of argument RotationCenter");
    if (mxIsSingle(prhs[4]))
        io_RotationCenter = (float*)mxGetData(prhs[4]);
    else {
        io_RotationCenter = (float*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (float));
        if (!_get_numeric_array_float(prhs[4], io_RotationCenter))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationCenter");
    }

    if (mxGetNumberOfElements(prhs[5]) < (int) (3) || _n_dims(prhs[5]) > 1)
        mexErrMsgTxt("Error in dimension of argument RotationAngle");
    if (mxIsSingle(prhs[5]))
        io_RotationAngle = (float*)mxGetData(prhs[5]);
    else {
        io_RotationAngle = (float*)mxCalloc(mxGetNumberOfElements(prhs[5]), sizeof (float));
        if (!_get_numeric_array_float(prhs[5], io_RotationAngle))
             mexErrMsgTxt("Expecting numeric matrix for argument RotationAngle");
    }

    if (mxGetNumberOfElements(prhs[6]) < (int) (3) || _n_dims(prhs[6]) > 1)
        mexErrMsgTxt("Error in dimension of argument Translation");
    if (mxIsSingle(prhs[6]))
        io_Translation = (float*)mxGetData(prhs[6]);
    else {
        io_Translation = (float*)mxCalloc(mxGetNumberOfElements(prhs[6]), sizeof (float));
        if (!_get_numeric_array_float(prhs[6], io_Translation))
             mexErrMsgTxt("Expecting numeric matrix for argument Translation");
    }


    /******** Invoke computational function ********/
    ierr = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation);


    /******** Process inout argument. ********/
    if (!mxIsSingle(prhs[4])) mxFree(io_RotationCenter);
    if (!mxIsSingle(prhs[5])) mxFree(io_RotationAngle);
    if (!mxIsSingle(prhs[6])) mxFree(io_Translation);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_AverageInterfaceType, ierr] = cg_conn_average_read(in_file_number, in_B, in_Z, in_I) 
 *
 * The original C interface is 
 * int cg_conn_average_read( int file_number, int B, int Z, int I, AverageInterfaceType_t * AverageInterfaceType);
 */
EXTERN_C void cg_conn_average_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    AverageInterfaceType_t out_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_conn_average_read(in_file_number, in_B, in_Z, in_I, &out_AverageInterfaceType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_AverageInterfaceType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_conn_average_write(in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType) 
 *
 * The original C interface is 
 * int cg_conn_average_write( int file_number, int B, int Z, int I, AverageInterfaceType_t AverageInterfaceType);
 */
EXTERN_C void cg_conn_average_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    AverageInterfaceType_t in_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument AverageInterfaceType");
    in_AverageInterfaceType = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_conn_average_write(in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_1to1_average_write(in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType) 
 *
 * The original C interface is 
 * int cg_1to1_average_write( int file_number, int B, int Z, int I, AverageInterfaceType_t AverageInterfaceType);
 */
EXTERN_C void cg_1to1_average_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    AverageInterfaceType_t in_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument AverageInterfaceType");
    in_AverageInterfaceType = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_average_write(in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_AverageInterfaceType, ierr] = cg_1to1_average_read(in_file_number, in_B, in_Z, in_I) 
 *
 * The original C interface is 
 * int cg_1to1_average_read( int file_number, int B, int Z, int I, AverageInterfaceType_t * AverageInterfaceType);
 */
EXTERN_C void cg_1to1_average_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_Z;
    int in_I;
    AverageInterfaceType_t out_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument I");
    in_I = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_average_read(in_file_number, in_B, in_Z, in_I, &out_AverageInterfaceType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_AverageInterfaceType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* External gateway function */
EXTERN void cg_goto_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[]);

/* External gateway function */
EXTERN void cg_gorel_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[]);

/* Gateway function 
 * ierr = cg_gopath(in_file_number, in_path) 
 *
 * The original C interface is 
 * int cg_gopath( int file_number, const char * path);
 */
EXTERN_C void cg_gopath_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_file_number;
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    in_path = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_gopath(in_file_number, in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* External gateway function */
EXTERN void cg_golist_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[]);

/* External gateway function */
EXTERN void cg_where_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[]);

/* Gateway function 
 * [out_NormDefinitions, ierr] = cg_convergence_read(io_iterations) 
 *
 * The original C interface is 
 * int cg_convergence_read( int * iterations, char ** NormDefinitions);
 */
EXTERN_C void cg_convergence_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * io_iterations;
    char * out_NormDefinitions;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_iterations = (int*)mxGetData(prhs[0]);
    else {
        io_iterations = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], io_iterations))
            mexErrMsgTxt("Expecting numeric matrix for argument iterations");
    }


    /******** Invoke computational function ********/
    ierr = cg_convergence_read(io_iterations, &out_NormDefinitions);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(io_iterations);

    /******** Process output arguments ********/
    plhs[0] = mxCreateString(out_NormDefinitions);
    cg_free( out_NormDefinitions);

    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_convergence_write(in_iterations, in_NormDefinitions) 
 *
 * The original C interface is 
 * int cg_convergence_write( int iterations, char const * NormDefinitions);
 */
EXTERN_C void cg_convergence_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_iterations;
    char * in_NormDefinitions;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument iterations");
    in_iterations = _get_numeric_scalar_int32(prhs[0]);

    in_NormDefinitions = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_convergence_write(in_iterations, in_NormDefinitions);


    /******** Free up input buffers. ********/
    _mxFreeString(in_NormDefinitions);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_StateDescription, ierr] = cg_state_read() 
 *
 * The original C interface is 
 * int cg_state_read( char ** StateDescription);
 */
EXTERN_C void cg_state_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * out_StateDescription;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_state_read(&out_StateDescription);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(out_StateDescription);
    cg_free( out_StateDescription);

    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_state_write(in_StateDescription) 
 *
 * The original C interface is 
 * int cg_state_write( char const * StateDescription);
 */
EXTERN_C void cg_state_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_StateDescription;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_StateDescription = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_state_write(in_StateDescription);


    /******** Free up input buffers. ********/
    _mxFreeString(in_StateDescription);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_EquationDimension, out_GoverningEquationsFlag, out_GasModelFlag, out_ViscosityModelFlag, out_ThermalConductivityModelFlag, out_TurbulenceClosureFlag, out_TurbulenceModelFlag, ierr] = cg_equationset_read() 
 *
 * The original C interface is 
 * int cg_equationset_read( int * EquationDimension, int * GoverningEquationsFlag, int * GasModelFlag, int * ViscosityModelFlag, int * ThermalConductivityModelFlag, int * TurbulenceClosureFlag, int * TurbulenceModelFlag);
 */
EXTERN_C void cg_equationset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_EquationDimension;
    int out_GoverningEquationsFlag;
    int out_GasModelFlag;
    int out_ViscosityModelFlag;
    int out_ThermalConductivityModelFlag;
    int out_TurbulenceClosureFlag;
    int out_TurbulenceModelFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 8 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_equationset_read(&out_EquationDimension, &out_GoverningEquationsFlag, &out_GasModelFlag, &out_ViscosityModelFlag, &out_ThermalConductivityModelFlag, &out_TurbulenceClosureFlag, &out_TurbulenceModelFlag);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_EquationDimension;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_GoverningEquationsFlag;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_GasModelFlag;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_ViscosityModelFlag;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_ThermalConductivityModelFlag;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_TurbulenceClosureFlag;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = out_TurbulenceModelFlag;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[7]) = ierr;
    }
}

/* Gateway function 
 * [out_ThermalRelaxationFlag, out_ChemicalKineticsFlag, ierr] = cg_equationset_chemistry_read() 
 *
 * The original C interface is 
 * int cg_equationset_chemistry_read( int * ThermalRelaxationFlag, int * ChemicalKineticsFlag);
 */
EXTERN_C void cg_equationset_chemistry_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_ThermalRelaxationFlag;
    int out_ChemicalKineticsFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_equationset_chemistry_read(&out_ThermalRelaxationFlag, &out_ChemicalKineticsFlag);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ThermalRelaxationFlag;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_ChemicalKineticsFlag;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_equationset_elecmagn_read(io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag) 
 *
 * The original C interface is 
 * int cg_equationset_elecmagn_read( int * ElecFldModelFlag, int * MagnFldModelFlag, int * ConductivityModelFlag);
 */
EXTERN_C void cg_equationset_elecmagn_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * io_ElecFldModelFlag;
    int * io_MagnFldModelFlag;
    int * io_ConductivityModelFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_ElecFldModelFlag = (int*)mxGetData(prhs[0]);
    else {
        io_ElecFldModelFlag = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], io_ElecFldModelFlag))
            mexErrMsgTxt("Expecting numeric matrix for argument ElecFldModelFlag");
    }

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_MagnFldModelFlag = (int*)mxGetData(prhs[1]);
    else {
        io_MagnFldModelFlag = (int*)mxCalloc(mxGetNumberOfElements(prhs[1]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[1], io_MagnFldModelFlag))
            mexErrMsgTxt("Expecting numeric matrix for argument MagnFldModelFlag");
    }

    if (mxIsInt32(prhs[2]) || mxIsUint32(prhs[2]))
        io_ConductivityModelFlag = (int*)mxGetData(prhs[2]);
    else {
        io_ConductivityModelFlag = (int*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[2], io_ConductivityModelFlag))
            mexErrMsgTxt("Expecting numeric matrix for argument ConductivityModelFlag");
    }


    /******** Invoke computational function ********/
    ierr = cg_equationset_elecmagn_read(io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(io_ElecFldModelFlag);
    if (!mxIsInt32(prhs[1]) && !mxIsUint32(prhs[1]))
        mxFree(io_MagnFldModelFlag);
    if (!mxIsInt32(prhs[2]) && !mxIsUint32(prhs[2]))
        mxFree(io_ConductivityModelFlag);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_equationset_write(in_EquationDimension) 
 *
 * The original C interface is 
 * int cg_equationset_write( int EquationDimension);
 */
EXTERN_C void cg_equationset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_EquationDimension;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument EquationDimension");
    in_EquationDimension = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_equationset_write(in_EquationDimension);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_EquationsType, ierr] = cg_governing_read() 
 *
 * The original C interface is 
 * int cg_governing_read( GoverningEquationsType_t * EquationsType);
 */
EXTERN_C void cg_governing_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GoverningEquationsType_t out_EquationsType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_governing_read(&out_EquationsType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_EquationsType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_governing_write(in_Equationstype) 
 *
 * The original C interface is 
 * int cg_governing_write( GoverningEquationsType_t Equationstype);
 */
EXTERN_C void cg_governing_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GoverningEquationsType_t in_Equationstype;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Equationstype");
    in_Equationstype = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_governing_write(in_Equationstype);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_diffusion_read(io_diffusion_model) 
 *
 * The original C interface is 
 * int cg_diffusion_read( int * diffusion_model);
 */
EXTERN_C void cg_diffusion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * io_diffusion_model;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_diffusion_model = (int*)mxGetData(prhs[0]);
    else {
        io_diffusion_model = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], io_diffusion_model))
            mexErrMsgTxt("Expecting numeric matrix for argument diffusion_model");
    }


    /******** Invoke computational function ********/
    ierr = cg_diffusion_read(io_diffusion_model);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(io_diffusion_model);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_diffusion_write(in_diffusion_model) 
 *
 * The original C interface is 
 * int cg_diffusion_write( int const * diffusion_model);
 */
EXTERN_C void cg_diffusion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * in_diffusion_model;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        in_diffusion_model = (int*)mxGetData(prhs[0]);
    else {
        in_diffusion_model = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], in_diffusion_model))
            mexErrMsgTxt("Expecting numeric matrix for argument diffusion_model");
    }


    /******** Invoke computational function ********/
    ierr = cg_diffusion_write(in_diffusion_model);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(in_diffusion_model);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_ModelType, ierr] = cg_model_read(in_ModelLabel) 
 *
 * The original C interface is 
 * int cg_model_read( char const * ModelLabel, ModelType_t * ModelType);
 */
EXTERN_C void cg_model_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_ModelLabel;
    ModelType_t out_ModelType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_ModelLabel = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_model_read(in_ModelLabel, &out_ModelType);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ModelLabel);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ModelType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_model_write(in_ModelLabel, in_ModelType) 
 *
 * The original C interface is 
 * int cg_model_write( char const * ModelLabel, ModelType_t ModelType);
 */
EXTERN_C void cg_model_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_ModelLabel;
    ModelType_t in_ModelType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_ModelLabel = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument ModelType");
    in_ModelType = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_model_write(in_ModelLabel, in_ModelType);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ModelLabel);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_narrays, ierr] = cg_narrays() 
 *
 * The original C interface is 
 * int cg_narrays( int * narrays);
 */
EXTERN_C void cg_narrays_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_narrays;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_narrays(&out_narrays);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_narrays;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_DataType, out_DataDimension, ierr] = cg_array_info(in_A, io_ArrayName, io_DimensionVector) 
 *
 * The original C interface is 
 * int cg_array_info( int A, char * ArrayName, DataType_t * DataType, int * DataDimension, int * DimensionVector);
 */
EXTERN_C void cg_array_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_A;
    char * io_ArrayName;
    DataType_t out_DataType;
    int out_DataDimension;
    int * io_DimensionVector;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 4 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    io_ArrayName = _mxGetString(prhs[1], NULL);

    if (mxGetNumberOfElements(prhs[2]) < (int) (3) || _n_dims(prhs[2]) > 1)
        mexErrMsgTxt("Error in dimension of argument DimensionVector");
    if (mxIsInt32(prhs[2]) || mxIsUint32(prhs[2]))
        io_DimensionVector = (int*)mxGetData(prhs[2]);
    else {
        io_DimensionVector = (int*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[2], io_DimensionVector))
            mexErrMsgTxt("Expecting numeric matrix for argument DimensionVector");
    }


    /******** Invoke computational function ********/
    ierr = cg_array_info(in_A, io_ArrayName, &out_DataType, &out_DataDimension, io_DimensionVector);


    /******** Process inout argument. ********/
    /* _mxPutString(io_ArrayName, (mxArray*)prhs[1]); */
    if (!mxIsInt32(prhs[2]) && !mxIsUint32(prhs[2]))
        mxFree(io_DimensionVector);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_DataType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_DataDimension;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateString(io_ArrayName);
    }
}

/* Gateway function 
 * ierr = cg_array_read(in_A, io_Data) 
 *
 * The original C interface is 
 * int cg_array_read( int A, void * Data);
 */
EXTERN_C void cg_array_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_A;
    void * io_Data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    io_Data = mxGetData( prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_array_read(in_A, io_Data);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_array_read_as(in_A, in_type, io_Data) 
 *
 * The original C interface is 
 * int cg_array_read_as( int A, DataType_t type, void * Data);
 */
EXTERN_C void cg_array_read_as_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_A;
    DataType_t in_type;
    void * io_Data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[1]);

    io_Data = mxGetData( prhs[2]);

    /******** Invoke computational function ********/
    ierr = cg_array_read_as(in_A, in_type, io_Data);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_array_write(in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data) 
 *
 * The original C interface is 
 * int cg_array_write( char const * ArrayName, DataType_t DataType, int DataDimension, int const * DimensionVector, void const * Data);
 */
EXTERN_C void cg_array_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_ArrayName;
    DataType_t in_DataType;
    int in_DataDimension;
    int * in_DimensionVector;
    void const * in_Data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_DataDimension = _get_numeric_scalar_int32(prhs[2]);
    in_ArrayName = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataDimension");

    if (mxGetNumberOfElements(prhs[3]) < (int) (in_DataDimension) || _n_dims(prhs[3]) > 1)
        mexErrMsgTxt("Error in dimension of argument DimensionVector");
    if (mxIsInt32(prhs[3]) || mxIsUint32(prhs[3]))
        in_DimensionVector = (int*)mxGetData(prhs[3]);
    else {
        in_DimensionVector = (int*)mxCalloc(mxGetNumberOfElements(prhs[3]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[3], in_DimensionVector))
            mexErrMsgTxt("Expecting numeric matrix for argument DimensionVector");
    }

    in_Data = mxGetData( prhs[4]);

    /******** Invoke computational function ********/
    ierr = cg_array_write(in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ArrayName);
    if (!mxIsInt32(prhs[3]) && !mxIsUint32(prhs[3]))
        mxFree(in_DimensionVector);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_nuser_data, ierr] = cg_nuser_data() 
 *
 * The original C interface is 
 * int cg_nuser_data( int * nuser_data);
 */
EXTERN_C void cg_nuser_data_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_nuser_data;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nuser_data(&out_nuser_data);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nuser_data;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_user_data_read(in_Index, io_user_data_name) 
 *
 * The original C interface is 
 * int cg_user_data_read( int Index, char * user_data_name);
 */
EXTERN_C void cg_user_data_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_Index;
    char * io_user_data_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Index");
    in_Index = _get_numeric_scalar_int32(prhs[0]);

    io_user_data_name = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_user_data_read(in_Index, io_user_data_name);


    /******** Process inout argument. ********/
    /* _mxPutString(io_user_data_name, (mxArray*)prhs[1]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_user_data_name);
    }
}

/* Gateway function 
 * ierr = cg_user_data_write(in_user_data_name) 
 *
 * The original C interface is 
 * int cg_user_data_write( char const * user_data_name);
 */
EXTERN_C void cg_user_data_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_user_data_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_user_data_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_user_data_write(in_user_data_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_user_data_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_nintegrals, ierr] = cg_nintegrals() 
 *
 * The original C interface is 
 * int cg_nintegrals( int * nintegrals);
 */
EXTERN_C void cg_nintegrals_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_nintegrals;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nintegrals(&out_nintegrals);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nintegrals;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_integral_read(in_IntegralDataIndex, io_IntegralDataName) 
 *
 * The original C interface is 
 * int cg_integral_read( int IntegralDataIndex, char * IntegralDataName);
 */
EXTERN_C void cg_integral_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_IntegralDataIndex;
    char * io_IntegralDataName;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument IntegralDataIndex");
    in_IntegralDataIndex = _get_numeric_scalar_int32(prhs[0]);

    io_IntegralDataName = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_integral_read(in_IntegralDataIndex, io_IntegralDataName);


    /******** Process inout argument. ********/
    /* _mxPutString(io_IntegralDataName, (mxArray*)prhs[1]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(io_IntegralDataName);
    }
}

/* Gateway function 
 * ierr = cg_integral_write(in_IntegralDataName) 
 *
 * The original C interface is 
 * int cg_integral_write( char const * IntegralDataName);
 */
EXTERN_C void cg_integral_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_IntegralDataName;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_IntegralDataName = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_integral_write(in_IntegralDataName);


    /******** Free up input buffers. ********/
    _mxFreeString(in_IntegralDataName);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_rind_read(io_RindData) 
 *
 * The original C interface is 
 * int cg_rind_read( int * RindData);
 */
EXTERN_C void cg_rind_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * io_RindData;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_RindData = (int*)mxGetData(prhs[0]);
    else {
        io_RindData = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], io_RindData))
            mexErrMsgTxt("Expecting numeric matrix for argument RindData");
    }


    /******** Invoke computational function ********/
    ierr = cg_rind_read(io_RindData);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(io_RindData);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_rind_write(in_RindData) 
 *
 * The original C interface is 
 * int cg_rind_write( int const * RindData);
 */
EXTERN_C void cg_rind_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * in_RindData;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        in_RindData = (int*)mxGetData(prhs[0]);
    else {
        in_RindData = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], in_RindData))
            mexErrMsgTxt("Expecting numeric matrix for argument RindData");
    }


    /******** Invoke computational function ********/
    ierr = cg_rind_write(in_RindData);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(in_RindData);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_ndescriptors, ierr] = cg_ndescriptors() 
 *
 * The original C interface is 
 * int cg_ndescriptors( int * ndescriptors);
 */
EXTERN_C void cg_ndescriptors_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_ndescriptors;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ndescriptors(&out_ndescriptors);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ndescriptors;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_descr_text, ierr] = cg_descriptor_read(in_descr_no, io_descr_name) 
 *
 * The original C interface is 
 * int cg_descriptor_read( int descr_no, char * descr_name, char ** descr_text);
 */
EXTERN_C void cg_descriptor_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_descr_no;
    char * io_descr_name;
    char * out_descr_text;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument descr_no");
    in_descr_no = _get_numeric_scalar_int32(prhs[0]);

    io_descr_name = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_descriptor_read(in_descr_no, io_descr_name, &out_descr_text);


    /******** Process inout argument. ********/
    /* _mxPutString(io_descr_name, (mxArray*)prhs[1]); */

    /******** Process output arguments ********/
    plhs[0] = mxCreateString(out_descr_text);
    cg_free( out_descr_text);

    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(io_descr_name);
    }
}

/* Gateway function 
 * ierr = cg_descriptor_write(in_descr_name, in_descr_text) 
 *
 * The original C interface is 
 * int cg_descriptor_write( char const * descr_name, char const * descr_text);
 */
EXTERN_C void cg_descriptor_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_descr_name;
    char * in_descr_text;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_descr_name = _mxGetString(prhs[0], NULL);

    in_descr_text = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_descriptor_write(in_descr_name, in_descr_text);


    /******** Free up input buffers. ********/
    _mxFreeString(in_descr_name);
    _mxFreeString(in_descr_text);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_nunits, ierr] = cg_nunits() 
 *
 * The original C interface is 
 * int cg_nunits( int * nunits);
 */
EXTERN_C void cg_nunits_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_nunits;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nunits(&out_nunits);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nunits;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_mass, out_length, out_time, out_temperature, out_angle, ierr] = cg_units_read() 
 *
 * The original C interface is 
 * int cg_units_read( MassUnits_t * mass, LengthUnits_t * length, TimeUnits_t * time, TemperatureUnits_t * temperature, AngleUnits_t * angle);
 */
EXTERN_C void cg_units_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    MassUnits_t out_mass;
    LengthUnits_t out_length;
    TimeUnits_t out_time;
    TemperatureUnits_t out_temperature;
    AngleUnits_t out_angle;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 6 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_units_read(&out_mass, &out_length, &out_time, &out_temperature, &out_angle);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_mass;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_length;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_time;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_temperature;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_angle;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_units_write(in_mass, in_length, in_time, in_temperature, in_angle) 
 *
 * The original C interface is 
 * int cg_units_write( MassUnits_t mass, LengthUnits_t length, TimeUnits_t time, TemperatureUnits_t temperature, AngleUnits_t angle);
 */
EXTERN_C void cg_units_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    MassUnits_t in_mass;
    LengthUnits_t in_length;
    TimeUnits_t in_time;
    TemperatureUnits_t in_temperature;
    AngleUnits_t in_angle;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument mass");
    in_mass = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument length");
    in_length = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument time");
    in_time = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument temperature");
    in_temperature = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument angle");
    in_angle = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_units_write(in_mass, in_length, in_time, in_temperature, in_angle);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_mass, out_length, out_time, out_temperature, out_angle, out_current, out_amount, out_intensity, ierr] = cg_unitsfull_read() 
 *
 * The original C interface is 
 * int cg_unitsfull_read( MassUnits_t * mass, LengthUnits_t * length, TimeUnits_t * time, TemperatureUnits_t * temperature, AngleUnits_t * angle, ElectricCurrentUnits_t * current, SubstanceAmountUnits_t * amount, LuminousIntensityUnits_t * intensity);
 */
EXTERN_C void cg_unitsfull_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    MassUnits_t out_mass;
    LengthUnits_t out_length;
    TimeUnits_t out_time;
    TemperatureUnits_t out_temperature;
    AngleUnits_t out_angle;
    ElectricCurrentUnits_t out_current;
    SubstanceAmountUnits_t out_amount;
    LuminousIntensityUnits_t out_intensity;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 9 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_unitsfull_read(&out_mass, &out_length, &out_time, &out_temperature, &out_angle, &out_current, &out_amount, &out_intensity);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_mass;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_length;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_time;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_temperature;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_angle;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_current;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = out_amount;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[7]) = out_intensity;
    }
    if (nlhs > 8) {
        plhs[8] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[8]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_unitsfull_write(in_mass, in_length, in_time, in_temperature, in_angle, in_current, in_amount, in_intensity) 
 *
 * The original C interface is 
 * int cg_unitsfull_write( MassUnits_t mass, LengthUnits_t length, TimeUnits_t time, TemperatureUnits_t temperature, AngleUnits_t angle, ElectricCurrentUnits_t current, SubstanceAmountUnits_t amount, LuminousIntensityUnits_t intensity);
 */
EXTERN_C void cg_unitsfull_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    MassUnits_t in_mass;
    LengthUnits_t in_length;
    TimeUnits_t in_time;
    TemperatureUnits_t in_temperature;
    AngleUnits_t in_angle;
    ElectricCurrentUnits_t in_current;
    SubstanceAmountUnits_t in_amount;
    LuminousIntensityUnits_t in_intensity;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument mass");
    in_mass = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument length");
    in_length = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument time");
    in_time = _get_numeric_scalar_int32(prhs[2]);

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument temperature");
    in_temperature = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument angle");
    in_angle = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument current");
    in_current = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument amount");
    in_amount = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument intensity");
    in_intensity = _get_numeric_scalar_int32(prhs[7]);


    /******** Invoke computational function ********/
    ierr = cg_unitsfull_write(in_mass, in_length, in_time, in_temperature, in_angle, in_current, in_amount, in_intensity);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_DataType, ierr] = cg_exponents_info() 
 *
 * The original C interface is 
 * int cg_exponents_info( DataType_t * DataType);
 */
EXTERN_C void cg_exponents_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t out_DataType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_exponents_info(&out_DataType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_DataType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_nexponents(io_numexp) 
 *
 * The original C interface is 
 * int cg_nexponents( int * numexp);
 */
EXTERN_C void cg_nexponents_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int * io_numexp;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_numexp = (int*)mxGetData(prhs[0]);
    else {
        io_numexp = (int*)mxCalloc(mxGetNumberOfElements(prhs[0]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[0], io_numexp))
            mexErrMsgTxt("Expecting numeric matrix for argument numexp");
    }


    /******** Invoke computational function ********/
    ierr = cg_nexponents(io_numexp);


    /******** Process inout argument. ********/
    if (!mxIsInt32(prhs[0]) && !mxIsUint32(prhs[0]))
        mxFree(io_numexp);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_exponents_read(io_exponents) 
 *
 * The original C interface is 
 * int cg_exponents_read( void * exponents);
 */
EXTERN_C void cg_exponents_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    void * io_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    io_exponents = mxGetData( prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_exponents_read(io_exponents);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_exponents_write(in_DataType, in_exponents) 
 *
 * The original C interface is 
 * int cg_exponents_write( DataType_t DataType, void const * exponents);
 */
EXTERN_C void cg_exponents_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t in_DataType;
    void const * in_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_exponents = mxGetData( prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_exponents_write(in_DataType, in_exponents);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_expfull_read(io_exponents) 
 *
 * The original C interface is 
 * int cg_expfull_read( void * exponents);
 */
EXTERN_C void cg_expfull_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    void * io_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    io_exponents = mxGetData( prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_expfull_read(io_exponents);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_expfull_write(in_DataType, in_exponents) 
 *
 * The original C interface is 
 * int cg_expfull_write( DataType_t DataType, void const * exponents);
 */
EXTERN_C void cg_expfull_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t in_DataType;
    void const * in_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_exponents = mxGetData( prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_expfull_write(in_DataType, in_exponents);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_DataType, ierr] = cg_conversion_info() 
 *
 * The original C interface is 
 * int cg_conversion_info( DataType_t * DataType);
 */
EXTERN_C void cg_conversion_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t out_DataType;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_conversion_info(&out_DataType);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_DataType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_conversion_read(io_ConversionFactors) 
 *
 * The original C interface is 
 * int cg_conversion_read( void * ConversionFactors);
 */
EXTERN_C void cg_conversion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    void * io_ConversionFactors;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    io_ConversionFactors = mxGetData( prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_conversion_read(io_ConversionFactors);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_conversion_write(in_DataType, in_ConversionFactors) 
 *
 * The original C interface is 
 * int cg_conversion_write( DataType_t DataType, void const * ConversionFactors);
 */
EXTERN_C void cg_conversion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataType_t in_DataType;
    void const * in_ConversionFactors;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_ConversionFactors = mxGetData( prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_conversion_write(in_DataType, in_ConversionFactors);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_dataclass, ierr] = cg_dataclass_read() 
 *
 * The original C interface is 
 * int cg_dataclass_read( DataClass_t * dataclass);
 */
EXTERN_C void cg_dataclass_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataClass_t out_dataclass;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_dataclass_read(&out_dataclass);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_dataclass;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_dataclass_write(in_dataclass) 
 *
 * The original C interface is 
 * int cg_dataclass_write( DataClass_t dataclass);
 */
EXTERN_C void cg_dataclass_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    DataClass_t in_dataclass;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument dataclass");
    in_dataclass = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_dataclass_write(in_dataclass);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_GridLocation, ierr] = cg_gridlocation_read() 
 *
 * The original C interface is 
 * int cg_gridlocation_read( GridLocation_t * GridLocation);
 */
EXTERN_C void cg_gridlocation_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GridLocation_t out_GridLocation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_gridlocation_read(&out_GridLocation);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_GridLocation;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_gridlocation_write(in_GridLocation) 
 *
 * The original C interface is 
 * int cg_gridlocation_write( GridLocation_t GridLocation);
 */
EXTERN_C void cg_gridlocation_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    GridLocation_t in_GridLocation;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument GridLocation");
    in_GridLocation = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_gridlocation_write(in_GridLocation);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_Ordinal, ierr] = cg_ordinal_read() 
 *
 * The original C interface is 
 * int cg_ordinal_read( int * Ordinal);
 */
EXTERN_C void cg_ordinal_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_Ordinal;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ordinal_read(&out_Ordinal);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Ordinal;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_ordinal_write(in_Ordinal) 
 *
 * The original C interface is 
 * int cg_ordinal_write( int Ordinal);
 */
EXTERN_C void cg_ordinal_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int in_Ordinal;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Ordinal");
    in_Ordinal = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_ordinal_write(in_Ordinal);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_ptset_type, out_npnts, ierr] = cg_ptset_info() 
 *
 * The original C interface is 
 * int cg_ptset_info( PointSetType_t * ptset_type, int * npnts);
 */
EXTERN_C void cg_ptset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    PointSetType_t out_ptset_type;
    int out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ptset_info(&out_ptset_type, &out_npnts);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ptset_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_npnts;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_ptset_write(in_ptset_type, in_npnts, in_pnts) 
 *
 * The original C interface is 
 * int cg_ptset_write( PointSetType_t ptset_type, int npnts, int const * pnts);
 */
EXTERN_C void cg_ptset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    PointSetType_t in_ptset_type;
    int in_npnts;
    int * in_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsInt32(prhs[2]) || mxIsUint32(prhs[2]))
        in_pnts = (int*)mxGetData(prhs[2]);
    else {
        in_pnts = (int*)mxCalloc(mxGetNumberOfElements(prhs[2]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[2], in_pnts))
            mexErrMsgTxt("Expecting numeric matrix for argument pnts");
    }


    /******** Invoke computational function ********/
    ierr = cg_ptset_write(in_ptset_type, in_npnts, in_pnts);


    /******** Free up input buffers. ********/
    if (!mxIsInt32(prhs[2]) && !mxIsUint32(prhs[2]))
        mxFree(in_pnts);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * [out_pnts, ierr] = cg_ptset_read() 
 *
 * The original C interface is 
 * int cg_ptset_read( int * pnts);
 */
EXTERN_C void cg_ptset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ptset_read(&out_pnts);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_pnts;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_path_length, ierr] = cg_is_link() 
 *
 * The original C interface is 
 * int cg_is_link( int * path_length);
 */
EXTERN_C void cg_is_link_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    int out_path_length;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_is_link(&out_path_length);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_path_length;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function 
 * [out_filename, out_link_path, ierr] = cg_link_read() 
 *
 * The original C interface is 
 * int cg_link_read( char ** filename, char ** link_path);
 */
EXTERN_C void cg_link_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * out_filename;
    char * out_link_path;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_link_read(&out_filename, &out_link_path);


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(out_filename);
    cg_free( out_filename);

    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_link_path);
    }
    cg_free( out_link_path);

    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_link_write(in_nodename, in_filename, in_name_in_file) 
 *
 * The original C interface is 
 * int cg_link_write( char const * nodename, char const * filename, char const * name_in_file);
 */
EXTERN_C void cg_link_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_nodename;
    char * in_filename;
    char * in_name_in_file;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_nodename = _mxGetString(prhs[0], NULL);

    in_filename = _mxGetString(prhs[1], NULL);

    in_name_in_file = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_link_write(in_nodename, in_filename, in_name_in_file);


    /******** Free up input buffers. ********/
    _mxFreeString(in_nodename);
    _mxFreeString(in_filename);
    _mxFreeString(in_name_in_file);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_delete_node(in_node_name) 
 *
 * The original C interface is 
 * int cg_delete_node( char const * node_name);
 */
EXTERN_C void cg_delete_node_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    char * in_node_name;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_node_name = _mxGetString(prhs[0], NULL);

    /******** Invoke computational function ********/
    ierr = cg_delete_node(in_node_name);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * msg = cg_get_error() 
 *
 * The original C interface is 
 * const char * cg_get_error( );
 */
EXTERN_C void cg_get_error_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
    const char * msg;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    msg = cg_get_error();


    /******** Process output arguments ********/
    plhs[0] = mxCreateString(msg);
}

/* Gateway function 
 * cg_error_exit() 
 *
 * The original C interface is 
 * void cg_error_exit( );
 */
EXTERN_C void cg_error_exit_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 0 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    cg_error_exit();

}

/* Gateway function 
 * cg_error_print() 
 *
 * The original C interface is 
 * void cg_error_print( );
 */
EXTERN_C void cg_error_print_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 0 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    cg_error_print();

}

#include "cgnslib_mex_ext.c"

/* Main gateway function */
EXTERN_C void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{

    typedef void (*C2mex_func_ptr)(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]);

    int  func_id;
    static C2mex_func_ptr  fptrs[] = {
        NULL,
        /* 1 */ cg_is_cgns_MeX,
        /* 2 */ cg_open_MeX,
        /* 3 */ cg_version_MeX,
        /* 4 */ cg_close_MeX,
        /* 5 */ cg_save_as_MeX,
        /* 6 */ cg_set_file_type_MeX,
        /* 7 */ cg_get_file_type_MeX,
        /* 8 */ cg_root_id_MeX,
        /* 9 */ cg_configure_MeX,
        /* 10 */ cg_set_compress_MeX,
        /* 11 */ cg_get_compress_MeX,
        /* 12 */ cg_set_path_MeX,
        /* 13 */ cg_add_path_MeX,
        /* 14 */ cg_MassUnitsName_MeX,
        /* 15 */ cg_LengthUnitsName_MeX,
        /* 16 */ cg_TimeUnitsName_MeX,
        /* 17 */ cg_TemperatureUnitsName_MeX,
        /* 18 */ cg_AngleUnitsName_MeX,
        /* 19 */ cg_ElectricCurrentUnitsName_MeX,
        /* 20 */ cg_SubstanceAmountUnitsName_MeX,
        /* 21 */ cg_LuminousIntensityUnitsName_MeX,
        /* 22 */ cg_DataClassName_MeX,
        /* 23 */ cg_GridLocationName_MeX,
        /* 24 */ cg_BCDataTypeName_MeX,
        /* 25 */ cg_GridConnectivityTypeName_MeX,
        /* 26 */ cg_PointSetTypeName_MeX,
        /* 27 */ cg_GoverningEquationsTypeName_MeX,
        /* 28 */ cg_ModelTypeName_MeX,
        /* 29 */ cg_BCTypeName_MeX,
        /* 30 */ cg_DataTypeName_MeX,
        /* 31 */ cg_ElementTypeName_MeX,
        /* 32 */ cg_ZoneTypeName_MeX,
        /* 33 */ cg_RigidGridMotionTypeName_MeX,
        /* 34 */ cg_ArbitraryGridMotionTypeName_MeX,
        /* 35 */ cg_SimulationTypeName_MeX,
        /* 36 */ cg_WallFunctionTypeName_MeX,
        /* 37 */ cg_AreaTypeName_MeX,
        /* 38 */ cg_AverageInterfaceTypeName_MeX,
        /* 39 */ cg_nbases_MeX,
        /* 40 */ cg_base_read_MeX,
        /* 41 */ cg_base_id_MeX,
        /* 42 */ cg_base_write_MeX,
        /* 43 */ cg_nzones_MeX,
        /* 44 */ cg_zone_read_MeX,
        /* 45 */ cg_zone_type_MeX,
        /* 46 */ cg_zone_id_MeX,
        /* 47 */ cg_zone_write_MeX,
        /* 48 */ cg_nfamilies_MeX,
        /* 49 */ cg_family_read_MeX,
        /* 50 */ cg_family_write_MeX,
        /* 51 */ cg_famname_read_MeX,
        /* 52 */ cg_famname_write_MeX,
        /* 53 */ cg_fambc_read_MeX,
        /* 54 */ cg_fambc_write_MeX,
        /* 55 */ cg_geo_read_MeX,
        /* 56 */ cg_geo_write_MeX,
        /* 57 */ cg_part_read_MeX,
        /* 58 */ cg_part_write_MeX,
        /* 59 */ cg_ngrids_MeX,
        /* 60 */ cg_grid_read_MeX,
        /* 61 */ cg_grid_write_MeX,
        /* 62 */ cg_ncoords_MeX,
        /* 63 */ cg_coord_info_MeX,
        /* 64 */ cg_coord_read_MeX,
        /* 65 */ cg_coord_id_MeX,
        /* 66 */ cg_coord_write_MeX,
        /* 67 */ cg_coord_partial_write_MeX,
        /* 68 */ cg_nsections_MeX,
        /* 69 */ cg_section_read_MeX,
        /* 70 */ cg_elements_read_MeX,
        /* 71 */ cg_section_write_MeX,
        /* 72 */ cg_parent_data_write_MeX,
        /* 73 */ cg_npe_MeX,
        /* 74 */ cg_ElementDataSize_MeX,
        /* 75 */ cg_section_partial_write_MeX,
        /* 76 */ cg_elements_partial_write_MeX,
        /* 77 */ cg_parent_data_partial_write_MeX,
        /* 78 */ cg_elements_partial_read_MeX,
        /* 79 */ cg_ElementPartialSize_MeX,
        /* 80 */ cg_nsols_MeX,
        /* 81 */ cg_sol_info_MeX,
        /* 82 */ cg_sol_id_MeX,
        /* 83 */ cg_sol_write_MeX,
        /* 84 */ cg_nfields_MeX,
        /* 85 */ cg_field_info_MeX,
        /* 86 */ cg_field_read_MeX,
        /* 87 */ cg_field_id_MeX,
        /* 88 */ cg_field_write_MeX,
        /* 89 */ cg_field_partial_write_MeX,
        /* 90 */ cg_nholes_MeX,
        /* 91 */ cg_hole_info_MeX,
        /* 92 */ cg_hole_read_MeX,
        /* 93 */ cg_hole_id_MeX,
        /* 94 */ cg_hole_write_MeX,
        /* 95 */ cg_nconns_MeX,
        /* 96 */ cg_conn_info_MeX,
        /* 97 */ cg_conn_read_MeX,
        /* 98 */ cg_conn_id_MeX,
        /* 99 */ cg_conn_write_MeX,
        /* 100 */ cg_conn_write_short_MeX,
        /* 101 */ cg_conn_read_short_MeX,
        /* 102 */ cg_n1to1_MeX,
        /* 103 */ cg_1to1_read_MeX,
        /* 104 */ cg_1to1_id_MeX,
        /* 105 */ cg_1to1_write_MeX,
        /* 106 */ cg_n1to1_global_MeX,
        /* 107 */ cg_1to1_read_global_MeX,
        /* 108 */ cg_nbocos_MeX,
        /* 109 */ cg_boco_info_MeX,
        /* 110 */ cg_boco_read_MeX,
        /* 111 */ cg_boco_id_MeX,
        /* 112 */ cg_boco_write_MeX,
        /* 113 */ cg_boco_normal_write_MeX,
        /* 114 */ cg_dataset_read_MeX,
        /* 115 */ cg_dataset_write_MeX,
        /* 116 */ cg_bcdataset_write_MeX,
        /* 117 */ cg_bcdataset_info_MeX,
        /* 118 */ cg_bcdataset_read_MeX,
        /* 119 */ cg_bcdata_write_MeX,
        /* 120 */ cg_ndiscrete_MeX,
        /* 121 */ cg_discrete_read_MeX,
        /* 122 */ cg_discrete_write_MeX,
        /* 123 */ cg_n_rigid_motions_MeX,
        /* 124 */ cg_rigid_motion_read_MeX,
        /* 125 */ cg_rigid_motion_write_MeX,
        /* 126 */ cg_n_arbitrary_motions_MeX,
        /* 127 */ cg_arbitrary_motion_read_MeX,
        /* 128 */ cg_arbitrary_motion_write_MeX,
        /* 129 */ cg_simulation_type_read_MeX,
        /* 130 */ cg_simulation_type_write_MeX,
        /* 131 */ cg_biter_read_MeX,
        /* 132 */ cg_biter_write_MeX,
        /* 133 */ cg_ziter_read_MeX,
        /* 134 */ cg_ziter_write_MeX,
        /* 135 */ cg_gravity_read_MeX,
        /* 136 */ cg_gravity_write_MeX,
        /* 137 */ cg_axisym_read_MeX,
        /* 138 */ cg_axisym_write_MeX,
        /* 139 */ cg_rotating_read_MeX,
        /* 140 */ cg_rotating_write_MeX,
        /* 141 */ cg_bc_wallfunction_read_MeX,
        /* 142 */ cg_bc_wallfunction_write_MeX,
        /* 143 */ cg_bc_area_read_MeX,
        /* 144 */ cg_bc_area_write_MeX,
        /* 145 */ cg_conn_periodic_read_MeX,
        /* 146 */ cg_conn_periodic_write_MeX,
        /* 147 */ cg_1to1_periodic_write_MeX,
        /* 148 */ cg_1to1_periodic_read_MeX,
        /* 149 */ cg_conn_average_read_MeX,
        /* 150 */ cg_conn_average_write_MeX,
        /* 151 */ cg_1to1_average_write_MeX,
        /* 152 */ cg_1to1_average_read_MeX,
        /* 153 */ cg_goto_MeX,
        /* 154 */ cg_gorel_MeX,
        /* 155 */ cg_gopath_MeX,
        /* 156 */ cg_golist_MeX,
        /* 157 */ cg_where_MeX,
        /* 158 */ cg_convergence_read_MeX,
        /* 159 */ cg_convergence_write_MeX,
        /* 160 */ cg_state_read_MeX,
        /* 161 */ cg_state_write_MeX,
        /* 162 */ cg_equationset_read_MeX,
        /* 163 */ cg_equationset_chemistry_read_MeX,
        /* 164 */ cg_equationset_elecmagn_read_MeX,
        /* 165 */ cg_equationset_write_MeX,
        /* 166 */ cg_governing_read_MeX,
        /* 167 */ cg_governing_write_MeX,
        /* 168 */ cg_diffusion_read_MeX,
        /* 169 */ cg_diffusion_write_MeX,
        /* 170 */ cg_model_read_MeX,
        /* 171 */ cg_model_write_MeX,
        /* 172 */ cg_narrays_MeX,
        /* 173 */ cg_array_info_MeX,
        /* 174 */ cg_array_read_MeX,
        /* 175 */ cg_array_read_as_MeX,
        /* 176 */ cg_array_write_MeX,
        /* 177 */ cg_nuser_data_MeX,
        /* 178 */ cg_user_data_read_MeX,
        /* 179 */ cg_user_data_write_MeX,
        /* 180 */ cg_nintegrals_MeX,
        /* 181 */ cg_integral_read_MeX,
        /* 182 */ cg_integral_write_MeX,
        /* 183 */ cg_rind_read_MeX,
        /* 184 */ cg_rind_write_MeX,
        /* 185 */ cg_ndescriptors_MeX,
        /* 186 */ cg_descriptor_read_MeX,
        /* 187 */ cg_descriptor_write_MeX,
        /* 188 */ cg_nunits_MeX,
        /* 189 */ cg_units_read_MeX,
        /* 190 */ cg_units_write_MeX,
        /* 191 */ cg_unitsfull_read_MeX,
        /* 192 */ cg_unitsfull_write_MeX,
        /* 193 */ cg_exponents_info_MeX,
        /* 194 */ cg_nexponents_MeX,
        /* 195 */ cg_exponents_read_MeX,
        /* 196 */ cg_exponents_write_MeX,
        /* 197 */ cg_expfull_read_MeX,
        /* 198 */ cg_expfull_write_MeX,
        /* 199 */ cg_conversion_info_MeX,
        /* 200 */ cg_conversion_read_MeX,
        /* 201 */ cg_conversion_write_MeX,
        /* 202 */ cg_dataclass_read_MeX,
        /* 203 */ cg_dataclass_write_MeX,
        /* 204 */ cg_gridlocation_read_MeX,
        /* 205 */ cg_gridlocation_write_MeX,
        /* 206 */ cg_ordinal_read_MeX,
        /* 207 */ cg_ordinal_write_MeX,
        /* 208 */ cg_ptset_info_MeX,
        /* 209 */ cg_ptset_write_MeX,
        /* 210 */ cg_ptset_read_MeX,
        /* 211 */ cg_is_link_MeX,
        /* 212 */ cg_link_read_MeX,
        /* 213 */ cg_link_write_MeX,
        /* 214 */ cg_delete_node_MeX,
        /* 215 */ cg_get_error_MeX,
        /* 216 */ cg_error_exit_MeX,
        /* 217 */ cg_error_print_MeX
    };

    /******** Check function selector argument. ********/ 
    if (nrhs < 1 || !mxIsInt32(prhs[0]) || mxGetNumberOfElements(prhs[0])!=1)
        mexErrMsgTxt("Invalid functiin selector.\n");

    func_id = *(int*)mxGetData( prhs[0]);

    if (func_id < 1 || func_id > 217)
        mexErrMsgTxt("Function selector out of bound.\n");
    
    /******** Invoke the function. ********/ 
    (*fptrs[func_id])(nlhs, plhs, nrhs-1, &prhs[1]);
}
