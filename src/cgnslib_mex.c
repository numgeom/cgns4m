/*
 * This file was automatically generated for MATLAB & Octave from
 * src/cgnslib.h using Xiangmin Jiao's c2mex.
 * For bug reports of c2mex, email jiao@ams.sunysb.edu.
 */

#include "c2mex.h"   /* This includes "mex.h". */

#include "src/cgnslib.h"


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


static mwSize scalar_dimensions[] = {1,1}; // A value to pass to give the
                                // dimensions of a scalar.

/* Gateway function
 * [out_file_type, ierr] = cg_is_cgns(in_filename)
 *
 * The original C interface is
 * int cg_is_cgns(const char * filename, int * file_type);
 */
EXTERN_C void cg_is_cgns_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_filename;
    int out_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_filename = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_is_cgns(in_filename, &out_file_type);


    /******** Free up input buffers. ********/
    _mxFreeString(in_filename);

    /******** Process output scalars and strings ********/
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
 * int cg_open(const char * filename, int mode, int * fn);
 */
EXTERN_C void cg_open_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_filename;
    int in_mode;
    int out_fn;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_filename = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument mode");
    in_mode = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_open(in_filename, in_mode, &out_fn);


    /******** Free up input buffers. ********/
    _mxFreeString(in_filename);

    /******** Process output scalars and strings ********/
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
 * int cg_version(int fn, float * FileVersion);
 */
EXTERN_C void cg_version_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    float out_FileVersion;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_version(in_fn, &out_FileVersion);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
    *(float*)mxGetData(plhs[0]) = out_FileVersion;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_precision, ierr] = cg_precision(in_fn)
 *
 * The original C interface is
 * int cg_precision(int fn, int * precision);
 */
EXTERN_C void cg_precision_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int out_precision;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_precision(in_fn, &out_precision);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_precision;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_close(in_fn)
 *
 * The original C interface is
 * int cg_close(int fn);
 */
EXTERN_C void cg_close_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_close(in_fn);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_save_as(in_fn, in_filename, in_file_type, in_follow_links)
 *
 * The original C interface is
 * int cg_save_as(int fn, const char * filename, int file_type, int follow_links);
 */
EXTERN_C void cg_save_as_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    char * in_filename;
    int in_file_type;
    int in_follow_links;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_set_file_type(in_file_type)
 *
 * The original C interface is
 * int cg_set_file_type(int file_type);
 */
EXTERN_C void cg_set_file_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_type");
    in_file_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_set_file_type(in_file_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_get_file_type(in_fn, io_file_type)
 *
 * The original C interface is
 * int cg_get_file_type(int fn, int * file_type);
 */
EXTERN_C void cg_get_file_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int * io_file_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_file_type = (int*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument file_type");


    /******** Invoke computational function ********/
    ierr = cg_get_file_type(in_fn, io_file_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_rootid, ierr] = cg_root_id(in_fn)
 *
 * The original C interface is
 * int cg_root_id(int fn, double * rootid);
 */
EXTERN_C void cg_root_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    double out_rootid;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_root_id(in_fn, &out_rootid);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_rootid;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_cgio_num, ierr] = cg_get_cgio(in_fn)
 *
 * The original C interface is
 * int cg_get_cgio(int fn, int * cgio_num);
 */
EXTERN_C void cg_get_cgio_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int out_cgio_num;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_get_cgio(in_fn, &out_cgio_num);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_cgio_num;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_configure(in_what, in_value)
 *
 * The original C interface is
 * int cg_configure(int what, void * value);
 */
EXTERN_C void cg_configure_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_what;
    void * in_value;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument what");
    in_what = _get_numeric_scalar_int32(prhs[0]);

    in_value = mxGetData(prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_configure(in_what, in_value);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_set_compress(in_compress)
 *
 * The original C interface is
 * int cg_set_compress(int compress);
 */
EXTERN_C void cg_set_compress_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_compress;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument compress");
    in_compress = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_set_compress(in_compress);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_compress, ierr] = cg_get_compress()
 *
 * The original C interface is
 * int cg_get_compress(int * compress);
 */
EXTERN_C void cg_get_compress_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_compress;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_get_compress(&out_compress);


    /******** Process output scalars and strings ********/
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
 * int cg_set_path(const char * path);
 */
EXTERN_C void cg_set_path_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_path = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_set_path(in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_add_path(in_path)
 *
 * The original C interface is
 * int cg_add_path(const char * path);
 */
EXTERN_C void cg_add_path_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_path = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_add_path(in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * name = cg_MassUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_MassUnitsName(CG_MassUnits_t type);
 */
EXTERN_C void cg_MassUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_MassUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_MassUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_LengthUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_LengthUnitsName(CG_LengthUnits_t type);
 */
EXTERN_C void cg_LengthUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_LengthUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_LengthUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_TimeUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_TimeUnitsName(CG_TimeUnits_t type);
 */
EXTERN_C void cg_TimeUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_TimeUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_TimeUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_TemperatureUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_TemperatureUnitsName(CG_TemperatureUnits_t type);
 */
EXTERN_C void cg_TemperatureUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_TemperatureUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_TemperatureUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_AngleUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_AngleUnitsName(CG_AngleUnits_t type);
 */
EXTERN_C void cg_AngleUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_AngleUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AngleUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_ElectricCurrentUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_ElectricCurrentUnitsName(CG_ElectricCurrentUnits_t type);
 */
EXTERN_C void cg_ElectricCurrentUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ElectricCurrentUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ElectricCurrentUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_SubstanceAmountUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_SubstanceAmountUnitsName(CG_SubstanceAmountUnits_t type);
 */
EXTERN_C void cg_SubstanceAmountUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_SubstanceAmountUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_SubstanceAmountUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_LuminousIntensityUnitsName(in_type)
 *
 * The original C interface is
 * const char * cg_LuminousIntensityUnitsName(CG_LuminousIntensityUnits_t type);
 */
EXTERN_C void cg_LuminousIntensityUnitsName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_LuminousIntensityUnits_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_LuminousIntensityUnitsName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_DataClassName(in_type)
 *
 * The original C interface is
 * const char * cg_DataClassName(CG_DataClass_t type);
 */
EXTERN_C void cg_DataClassName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataClass_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_DataClassName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_GridLocationName(in_type)
 *
 * The original C interface is
 * const char * cg_GridLocationName(CG_GridLocation_t type);
 */
EXTERN_C void cg_GridLocationName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GridLocation_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GridLocationName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_BCDataTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_BCDataTypeName(CG_BCDataType_t type);
 */
EXTERN_C void cg_BCDataTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_BCDataType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_BCDataTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_GridConnectivityTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_GridConnectivityTypeName(CG_GridConnectivityType_t type);
 */
EXTERN_C void cg_GridConnectivityTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GridConnectivityType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GridConnectivityTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_PointSetTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_PointSetTypeName(CG_PointSetType_t type);
 */
EXTERN_C void cg_PointSetTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_PointSetType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_PointSetTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_GoverningEquationsTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_GoverningEquationsTypeName(CG_GoverningEquationsType_t type);
 */
EXTERN_C void cg_GoverningEquationsTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GoverningEquationsType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_GoverningEquationsTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_ModelTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_ModelTypeName(CG_ModelType_t type);
 */
EXTERN_C void cg_ModelTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ModelType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ModelTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_BCTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_BCTypeName(CG_BCType_t type);
 */
EXTERN_C void cg_BCTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_BCType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_BCTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_DataTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_DataTypeName(CG_DataType_t type);
 */
EXTERN_C void cg_DataTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_DataTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_ElementTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_ElementTypeName(CG_ElementType_t type);
 */
EXTERN_C void cg_ElementTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ElementType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ElementTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_ZoneTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_ZoneTypeName(CG_ZoneType_t type);
 */
EXTERN_C void cg_ZoneTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ZoneType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ZoneTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_RigidGridMotionTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_RigidGridMotionTypeName(CG_RigidGridMotionType_t type);
 */
EXTERN_C void cg_RigidGridMotionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_RigidGridMotionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_RigidGridMotionTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_ArbitraryGridMotionTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_ArbitraryGridMotionTypeName(CG_ArbitraryGridMotionType_t type);
 */
EXTERN_C void cg_ArbitraryGridMotionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ArbitraryGridMotionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_ArbitraryGridMotionTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_SimulationTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_SimulationTypeName(CG_SimulationType_t type);
 */
EXTERN_C void cg_SimulationTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_SimulationType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_SimulationTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_WallFunctionTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_WallFunctionTypeName(CG_WallFunctionType_t type);
 */
EXTERN_C void cg_WallFunctionTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_WallFunctionType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_WallFunctionTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_AreaTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_AreaTypeName(CG_AreaType_t type);
 */
EXTERN_C void cg_AreaTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_AreaType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AreaTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * name = cg_AverageInterfaceTypeName(in_type)
 *
 * The original C interface is
 * const char * cg_AverageInterfaceTypeName(CG_AverageInterfaceType_t type);
 */
EXTERN_C void cg_AverageInterfaceTypeName_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_AverageInterfaceType_t in_type;
    const char * name;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    name = cg_AverageInterfaceTypeName(in_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(name);
}

/* Gateway function
 * ierr = cg_nbases(in_fn, io_nbases)
 *
 * The original C interface is
 * int cg_nbases(int fn, int * nbases);
 */
EXTERN_C void cg_nbases_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int * io_nbases;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_nbases = (int*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument nbases");


    /******** Invoke computational function ********/
    ierr = cg_nbases(in_fn, io_nbases);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_basename, out_cell_dim, out_phys_dim, ierr] = cg_base_read(in_file_number, in_B)
 *
 * The original C interface is
 * int cg_base_read(int file_number, int B, char * basename, int * cell_dim, int * phys_dim);
 */
EXTERN_C void cg_base_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    char out_basename[33];
    int out_cell_dim;
    int out_phys_dim;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_base_read(in_file_number, in_B, out_basename, &out_cell_dim, &out_phys_dim);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_basename);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_cell_dim;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_phys_dim;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
}

/* Gateway function
 * [out_base_id, ierr] = cg_base_id(in_fn, in_B)
 *
 * The original C interface is
 * int cg_base_id(int fn, int B, double * base_id);
 */
EXTERN_C void cg_base_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    double out_base_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_base_id(in_fn, in_B, &out_base_id);


    /******** Process output scalars and strings ********/
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
 * int cg_base_write(int file_number, const char * basename, int cell_dim, int phys_dim, int * B);
 */
EXTERN_C void cg_base_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    char * in_basename;
    int in_cell_dim;
    int in_phys_dim;
    int out_B;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_B;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_cell_dim, ierr] = cg_cell_dim(in_fn, in_B)
 *
 * The original C interface is
 * int cg_cell_dim(int fn, int B, int * cell_dim);
 */
EXTERN_C void cg_cell_dim_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int out_cell_dim;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_cell_dim(in_fn, in_B, &out_cell_dim);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_cell_dim;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nzones, ierr] = cg_nzones(in_fn, in_B)
 *
 * The original C interface is
 * int cg_nzones(int fn, int B, int * nzones);
 */
EXTERN_C void cg_nzones_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int out_nzones;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_nzones(in_fn, in_B, &out_nzones);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nzones;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_zonename, out_size, ierr] = cg_zone_read(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_zone_read(int fn, int B, int Z, char * zonename, long long * size);
 */
EXTERN_C void cg_zone_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char out_zonename[33];
    long long * out_size;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    /******** Obtain fixed-size output arrays ********/
    plhs[1] = mxCreateNumericMatrix(9,1,mxINT64_CLASS, mxREAL);
    out_size = mxGetData(plhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_zone_read(in_fn, in_B, in_Z, out_zonename, out_size);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_zonename);
    if (nlhs > 1) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_type, ierr] = cg_zone_type(in_file_number, in_B, in_Z)
 *
 * The original C interface is
 * int cg_zone_type(int file_number, int B, int Z, CG_ZoneType_t * type);
 */
EXTERN_C void cg_zone_type_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    CG_ZoneType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_zone_id(int fn, int B, int Z, double * zone_id);
 */
EXTERN_C void cg_zone_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    double out_zone_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_zone_write(int fn, int B, const char * zonename, const long long * size, CG_ZoneType_t type, int * Z);
 */
EXTERN_C void cg_zone_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    char * in_zonename;
    long long * in_size;
    CG_ZoneType_t in_type;
    int out_Z;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    in_zonename = _mxGetString(prhs[2], NULL);

    if (mxGetNumberOfElements(prhs[3]) < (int) (9) || _n_dims(prhs[3]) > 1)
        mexErrMsgTxt("Error in dimension of argument size");
    if (mxIsInt64(prhs[3]) || mxIsUint64(prhs[3]))
        in_size = (long long*)mxGetData(prhs[3]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument size");

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_zone_write(in_fn, in_B, in_zonename, in_size, in_type, &out_Z);


    /******** Free up input buffers. ********/
    _mxFreeString(in_zonename);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Z;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_index_dim, ierr] = cg_index_dim(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_index_dim(int fn, int B, int Z, int * index_dim);
 */
EXTERN_C void cg_index_dim_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int * out_index_dim;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    /******** Obtain fixed-size output arrays ********/
    plhs[0] = mxCreateNumericMatrix(3,1,mxINT32_CLASS, mxREAL);
    out_index_dim = mxGetData(plhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_index_dim(in_fn, in_B, in_Z, out_index_dim);


    /******** Process output scalars and strings ********/
    plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[1]) = ierr;
}

/* Gateway function
 * [out_nfamilies, ierr] = cg_nfamilies(in_file_number, in_B)
 *
 * The original C interface is
 * int cg_nfamilies(int file_number, int B, int * nfamilies);
 */
EXTERN_C void cg_nfamilies_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int out_nfamilies;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_nfamilies(in_file_number, in_B, &out_nfamilies);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfamilies;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_family_name, out_nboco, out_ngeos, ierr] = cg_family_read(in_file_number, in_B, in_F)
 *
 * The original C interface is
 * int cg_family_read(int file_number, int B, int F, char * family_name, int * nboco, int * ngeos);
 */
EXTERN_C void cg_family_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    char out_family_name[33];
    int out_nboco;
    int out_ngeos;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_family_read(in_file_number, in_B, in_F, out_family_name, &out_nboco, &out_ngeos);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_family_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_nboco;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_ngeos;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
}

/* Gateway function
 * [out_F, ierr] = cg_family_write(in_file_number, in_B, in_family_name)
 *
 * The original C interface is
 * int cg_family_write(int file_number, int B, const char * family_name, int * F);
 */
EXTERN_C void cg_family_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    char * in_family_name;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nnames, ierr] = cg_nfamily_names(in_file_number, in_B, in_F)
 *
 * The original C interface is
 * int cg_nfamily_names(int file_number, int B, int F, int * nnames);
 */
EXTERN_C void cg_nfamily_names_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    int out_nnames;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_nfamily_names(in_file_number, in_B, in_F, &out_nnames);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nnames;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, out_family, ierr] = cg_family_name_read(in_file_number, in_B, in_F, in_N)
 *
 * The original C interface is
 * int cg_family_name_read(int file_number, int B, int F, int N, char * name, char * family);
 */
EXTERN_C void cg_family_name_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    int in_N;
    char out_name[33];
    char out_family;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument N");
    in_N = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_family_name_read(in_file_number, in_B, in_F, in_N, out_name, &out_family);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateCharArray(1, scalar_dimensions);
        *(mxChar *)mxGetData(plhs[1]) = out_family;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_family_name_write(in_file_number, in_B, in_F, in_name, in_family)
 *
 * The original C interface is
 * int cg_family_name_write(int file_number, int B, int F, const char * name, const char * family);
 */
EXTERN_C void cg_family_name_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    char * in_name;
    char * in_family;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[2]);

    in_name = _mxGetString(prhs[3], NULL);

    in_family = _mxGetString(prhs[4], NULL);


    /******** Invoke computational function ********/
    ierr = cg_family_name_write(in_file_number, in_B, in_F, in_name, in_family);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);
    _mxFreeString(in_family);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_node_family_write(in_family_name, io_F)
 *
 * The original C interface is
 * int cg_node_family_write(const char * family_name, int * F);
 */
EXTERN_C void cg_node_family_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_family_name;
    int * io_F;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_family_name = _mxGetString(prhs[0], NULL);

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_F = (int*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument F");


    /******** Invoke computational function ********/
    ierr = cg_node_family_write(in_family_name, io_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_family_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nfamilies, ierr] = cg_node_nfamilies()
 *
 * The original C interface is
 * int cg_node_nfamilies(int * nfamilies);
 */
EXTERN_C void cg_node_nfamilies_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nfamilies;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_node_nfamilies(&out_nfamilies);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfamilies;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_family_name, out_nFamBC, out_nGeo, ierr] = cg_node_family_read(in_F)
 *
 * The original C interface is
 * int cg_node_family_read(int F, char * family_name, int * nFamBC, int * nGeo);
 */
EXTERN_C void cg_node_family_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_F;
    char out_family_name[33];
    int out_nFamBC;
    int out_nGeo;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument F");
    in_F = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_node_family_read(in_F, out_family_name, &out_nFamBC, &out_nGeo);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_family_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_nFamBC;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_nGeo;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_node_family_name_write(in_node_name, in_family_name)
 *
 * The original C interface is
 * int cg_node_family_name_write(const char * node_name, const char * family_name);
 */
EXTERN_C void cg_node_family_name_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_node_name;
    char * in_family_name;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_node_name = _mxGetString(prhs[0], NULL);

    in_family_name = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_node_family_name_write(in_node_name, in_family_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_node_name);
    _mxFreeString(in_family_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nnames, ierr] = cg_node_nfamily_names()
 *
 * The original C interface is
 * int cg_node_nfamily_names(int * nnames);
 */
EXTERN_C void cg_node_nfamily_names_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nnames;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_node_nfamily_names(&out_nnames);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nnames;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_node_name, out_family_name, ierr] = cg_node_family_name_read(in_N)
 *
 * The original C interface is
 * int cg_node_family_name_read(int N, char * node_name, char * family_name);
 */
EXTERN_C void cg_node_family_name_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_N;
    char out_node_name[33];
    char out_family_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument N");
    in_N = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_node_family_name_read(in_N, out_node_name, out_family_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_node_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_family_name);
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_family_name, ierr] = cg_famname_read()
 *
 * The original C interface is
 * int cg_famname_read(char * family_name);
 */
EXTERN_C void cg_famname_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char out_family_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_famname_read(out_family_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_family_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_famname_write(in_family_name)
 *
 * The original C interface is
 * int cg_famname_write(const char * family_name);
 */
EXTERN_C void cg_famname_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_family_name;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_family_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_famname_write(in_family_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_family_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nfams, ierr] = cg_nmultifam()
 *
 * The original C interface is
 * int cg_nmultifam(int * nfams);
 */
EXTERN_C void cg_nmultifam_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nfams;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nmultifam(&out_nfams);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfams;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, out_family, ierr] = cg_multifam_read(in_N)
 *
 * The original C interface is
 * int cg_multifam_read(int N, char * name, char * family);
 */
EXTERN_C void cg_multifam_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_N;
    char out_name[33];
    char out_family[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument N");
    in_N = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_multifam_read(in_N, out_name, out_family);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_family);
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_multifam_write(in_name, in_family)
 *
 * The original C interface is
 * int cg_multifam_write(const char * name, const char * family);
 */
EXTERN_C void cg_multifam_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_name;
    char * in_family;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_name = _mxGetString(prhs[0], NULL);

    in_family = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_multifam_write(in_name, in_family);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);
    _mxFreeString(in_family);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_fambc_name, out_bocotype, ierr] = cg_fambc_read(in_file_number, in_B, in_F, in_BC)
 *
 * The original C interface is
 * int cg_fambc_read(int file_number, int B, int F, int BC, char * fambc_name, CG_BCType_t * bocotype);
 */
EXTERN_C void cg_fambc_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    int in_BC;
    char out_fambc_name[33];
    CG_BCType_t out_bocotype;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_fambc_read(in_file_number, in_B, in_F, in_BC, out_fambc_name, &out_bocotype);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_fambc_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_bocotype;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_BC, ierr] = cg_fambc_write(in_file_number, in_B, in_F, in_fambc_name, in_bocotype)
 *
 * The original C interface is
 * int cg_fambc_write(int file_number, int B, int F, const char * fambc_name, CG_BCType_t bocotype, int * BC);
 */
EXTERN_C void cg_fambc_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    char * in_fambc_name;
    CG_BCType_t in_bocotype;
    int out_BC;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BC;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_fambc_name, out_bocotype, ierr] = cg_node_fambc_read(in_BC)
 *
 * The original C interface is
 * int cg_node_fambc_read(int BC, char * fambc_name, CG_BCType_t * bocotype);
 */
EXTERN_C void cg_node_fambc_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_BC;
    char out_fambc_name[33];
    CG_BCType_t out_bocotype;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument BC");
    in_BC = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_node_fambc_read(in_BC, out_fambc_name, &out_bocotype);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_fambc_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_bocotype;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_BC, ierr] = cg_node_fambc_write(in_fambc_name, in_bocotype)
 *
 * The original C interface is
 * int cg_node_fambc_write(const char * fambc_name, CG_BCType_t bocotype, int * BC);
 */
EXTERN_C void cg_node_fambc_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_fambc_name;
    CG_BCType_t in_bocotype;
    int out_BC;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_fambc_name = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument bocotype");
    in_bocotype = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_node_fambc_write(in_fambc_name, in_bocotype, &out_BC);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fambc_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_BC;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cg_geo_read(in_file_number, in_B, in_F, in_G)
 *
 * The original C interface is
 * int cg_geo_read(int file_number, int B, int F, int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
 */
EXTERN_C void cg_geo_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    int in_G;
    char out_geo_name[33];
    char * out_geo_file;
    char out_CAD_name[33];
    int out_npart;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 5 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_geo_read(in_file_number, in_B, in_F, in_G, out_geo_name, &out_geo_file, out_CAD_name, &out_npart);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_geo_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_geo_file);
    }
    cg_free(out_geo_file);

    if (nlhs > 2) {
        plhs[2] = mxCreateString(out_CAD_name);
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_npart;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
}

/* Gateway function
 * [out_G, ierr] = cg_geo_write(in_file_number, in_B, in_F, in_geo_name, in_filename, in_CADname)
 *
 * The original C interface is
 * int cg_geo_write(int file_number, int B, int F, const char * geo_name, const char * filename, const char * CADname, int * G);
 */
EXTERN_C void cg_geo_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
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

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_G;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cg_node_geo_read(in_G)
 *
 * The original C interface is
 * int cg_node_geo_read(int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
 */
EXTERN_C void cg_node_geo_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_G;
    char out_geo_name[33];
    char * out_geo_file;
    char out_CAD_name[33];
    int out_npart;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 5 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_node_geo_read(in_G, out_geo_name, &out_geo_file, out_CAD_name, &out_npart);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_geo_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_geo_file);
    }
    cg_free(out_geo_file);

    if (nlhs > 2) {
        plhs[2] = mxCreateString(out_CAD_name);
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_npart;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
}

/* Gateway function
 * [out_G, ierr] = cg_node_geo_write(in_geo_name, in_filename, in_CADname)
 *
 * The original C interface is
 * int cg_node_geo_write(const char * geo_name, const char * filename, const char * CADname, int * G);
 */
EXTERN_C void cg_node_geo_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_geo_name;
    char * in_filename;
    char * in_CADname;
    int out_G;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_geo_name = _mxGetString(prhs[0], NULL);

    in_filename = _mxGetString(prhs[1], NULL);

    in_CADname = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_node_geo_write(in_geo_name, in_filename, in_CADname, &out_G);


    /******** Free up input buffers. ********/
    _mxFreeString(in_geo_name);
    _mxFreeString(in_filename);
    _mxFreeString(in_CADname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_G;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_part_name, ierr] = cg_part_read(in_file_number, in_B, in_F, in_G, in_P)
 *
 * The original C interface is
 * int cg_part_read(int file_number, int B, int F, int G, int P, char * part_name);
 */
EXTERN_C void cg_part_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_F;
    int in_G;
    int in_P;
    char out_part_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_part_read(in_file_number, in_B, in_F, in_G, in_P, out_part_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_part_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_P, ierr] = cg_part_write(in_file_number, in_B, in_F, in_G, in_part_name)
 *
 * The original C interface is
 * int cg_part_write(int file_number, int B, int F, int G, const char * part_name, int * P);
 */
EXTERN_C void cg_part_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
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

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_P;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_part_name, ierr] = cg_node_part_read(in_G, in_P)
 *
 * The original C interface is
 * int cg_node_part_read(int G, int P, char * part_name);
 */
EXTERN_C void cg_node_part_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_G;
    int in_P;
    char out_part_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument P");
    in_P = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_node_part_read(in_G, in_P, out_part_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_part_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_P, ierr] = cg_node_part_write(in_G, in_part_name)
 *
 * The original C interface is
 * int cg_node_part_write(int G, const char * part_name, int * P);
 */
EXTERN_C void cg_node_part_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_G;
    char * in_part_name;
    int out_P;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument G");
    in_G = _get_numeric_scalar_int32(prhs[0]);

    in_part_name = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_node_part_write(in_G, in_part_name, &out_P);


    /******** Free up input buffers. ********/
    _mxFreeString(in_part_name);

    /******** Process output scalars and strings ********/
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
 * int cg_ngrids(int file_number, int B, int Z, int * ngrids);
 */
EXTERN_C void cg_ngrids_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int out_ngrids;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ngrids;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_gridname, ierr] = cg_grid_read(in_file_number, in_B, in_Z, in_G)
 *
 * The original C interface is
 * int cg_grid_read(int file_number, int B, int Z, int G, char * gridname);
 */
EXTERN_C void cg_grid_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_G;
    char out_gridname[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_grid_read(in_file_number, in_B, in_Z, in_G, out_gridname);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_gridname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_G, ierr] = cg_grid_write(in_file_number, in_B, in_Z, in_zcoorname)
 *
 * The original C interface is
 * int cg_grid_write(int file_number, int B, int Z, const char * zcoorname, int * G);
 */
EXTERN_C void cg_grid_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_zcoorname;
    int out_G;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_G;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_grid_bounding_box_read(in_file_number, in_B, in_Z, in_G, in_type, io_boundingbox)
 *
 * The original C interface is
 * int cg_grid_bounding_box_read(int file_number, int B, int Z, int G, CG_DataType_t type, void * boundingbox);
 */
EXTERN_C void cg_grid_bounding_box_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_G;
    CG_DataType_t in_type;
    void * io_boundingbox;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    io_boundingbox = mxGetData(prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_grid_bounding_box_read(in_file_number, in_B, in_Z, in_G, in_type, io_boundingbox);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_grid_bounding_box_write(in_file_number, in_B, in_Z, in_G, in_type, in_boundingbox)
 *
 * The original C interface is
 * int cg_grid_bounding_box_write(int file_number, int B, int Z, int G, CG_DataType_t type, void * boundingbox);
 */
EXTERN_C void cg_grid_bounding_box_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_G;
    CG_DataType_t in_type;
    void * in_boundingbox;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[4]);

    in_boundingbox = mxGetData(prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_grid_bounding_box_write(in_file_number, in_B, in_Z, in_G, in_type, in_boundingbox);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ncoords, ierr] = cg_ncoords(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_ncoords(int fn, int B, int Z, int * ncoords);
 */
EXTERN_C void cg_ncoords_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_ncoords;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ncoords;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_type, out_coordname, ierr] = cg_coord_info(in_fn, in_B, in_Z, in_C)
 *
 * The original C interface is
 * int cg_coord_info(int fn, int B, int Z, int C, CG_DataType_t * type, char * coordname);
 */
EXTERN_C void cg_coord_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    CG_DataType_t out_type;
    char out_coordname[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_coord_info(in_fn, in_B, in_Z, in_C, &out_type, out_coordname);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_coordname);
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_coord_read(in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord)
 *
 * The original C interface is
 * int cg_coord_read(int fn, int B, int Z, const char * coordname, CG_DataType_t type, const long long * rmin, const long long * rmax, void * coord);
 */
EXTERN_C void cg_coord_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_coordname;
    CG_DataType_t in_type;
    long long * in_rmin;
    long long * in_rmax;
    void * io_coord;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_rmin = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmax = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    io_coord = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_coord_read(in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_coord_general_read(in_fn, in_B, in_Z, in_coordname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_coord_ptr)
 *
 * The original C interface is
 * int cg_coord_general_read(int fn, int B, int Z, const char * coordname, const long long * s_rmin, const long long * s_rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dimvals, const long long * m_rmin, const long long * m_rmax, void * coord_ptr);
 */
EXTERN_C void cg_coord_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_coordname;
    long long * in_s_rmin;
    long long * in_s_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dimvals;
    long long * in_m_rmin;
    long long * in_m_rmax;
    void * io_coord_ptr;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 12)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        in_s_rmin = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmin");

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_s_rmax = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmax");

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_m_dimvals = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dimvals");

    if (mxIsInt64(prhs[9]) || mxIsUint64(prhs[9]))
        in_m_rmin = (long long*)mxGetData(prhs[9]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[10]) || mxIsUint64(prhs[10]))
        in_m_rmax = (long long*)mxGetData(prhs[10]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    io_coord_ptr = mxGetData(prhs[11]);

    /******** Invoke computational function ********/
    ierr = cg_coord_general_read(in_fn, in_B, in_Z, in_coordname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_coord_ptr);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_coord_id, ierr] = cg_coord_id(in_fn, in_B, in_Z, in_C)
 *
 * The original C interface is
 * int cg_coord_id(int fn, int B, int Z, int C, double * coord_id);
 */
EXTERN_C void cg_coord_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    double out_coord_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_coord_write(int fn, int B, int Z, CG_DataType_t type, const char * coordname, const void * coord_ptr, int * C);
 */
EXTERN_C void cg_coord_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    CG_DataType_t in_type;
    char * in_coordname;
    const void * in_coord_ptr;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    in_coord_ptr = mxGetData(prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_coord_write(in_fn, in_B, in_Z, in_type, in_coordname, in_coord_ptr, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output scalars and strings ********/
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
 * int cg_coord_partial_write(int fn, int B, int Z, CG_DataType_t type, const char * coordname, const long long * rmin, const long long * rmax, const void * coord_ptr, int * C);
 */
EXTERN_C void cg_coord_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    CG_DataType_t in_type;
    char * in_coordname;
    long long * in_rmin;
    long long * in_rmax;
    const void * in_coord_ptr;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_rmin = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmax = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    in_coord_ptr = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_coord_partial_write(in_fn, in_B, in_Z, in_type, in_coordname, in_rmin, in_rmax, in_coord_ptr, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_C;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_C, ierr] = cg_coord_general_write(in_fn, in_B, in_Z, in_coordname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_coord_ptr)
 *
 * The original C interface is
 * int cg_coord_general_write(int fn, int B, int Z, const char * coordname, CG_DataType_t s_type, const long long * rmin, const long long * rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dims, const long long * m_rmin, const long long * m_rmax, const void * coord_ptr, int * C);
 */
EXTERN_C void cg_coord_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_coordname;
    CG_DataType_t in_s_type;
    long long * in_rmin;
    long long * in_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dims;
    long long * in_m_rmin;
    long long * in_m_rmax;
    const void * in_coord_ptr;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 13)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument s_type");
    in_s_type = _get_numeric_scalar_int32(prhs[4]);

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_rmin = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmax = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[7]);

    if (_n_dims(prhs[8]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[8]);

    if (mxIsInt64(prhs[9]) || mxIsUint64(prhs[9]))
        in_m_dims = (long long*)mxGetData(prhs[9]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dims");

    if (mxIsInt64(prhs[10]) || mxIsUint64(prhs[10]))
        in_m_rmin = (long long*)mxGetData(prhs[10]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[11]) || mxIsUint64(prhs[11]))
        in_m_rmax = (long long*)mxGetData(prhs[11]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    in_coord_ptr = mxGetData(prhs[12]);

    /******** Invoke computational function ********/
    ierr = cg_coord_general_write(in_fn, in_B, in_Z, in_coordname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_coord_ptr, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_coordname);

    /******** Process output scalars and strings ********/
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
 * int cg_nsections(int file_number, int B, int Z, int * nsections);
 */
EXTERN_C void cg_nsections_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int out_nsections;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsections;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_SectionName, out_type, out_start, out_end, out_nbndry, out_parent_flag, ierr] = cg_section_read(in_file_number, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_section_read(int file_number, int B, int Z, int S, char * SectionName, CG_ElementType_t * type, long long * start, long long * end, int * nbndry, int * parent_flag);
 */
EXTERN_C void cg_section_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    char out_SectionName[33];
    CG_ElementType_t out_type;
    long long out_start;
    long long out_end;
    int out_nbndry;
    int out_parent_flag;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 7 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_section_read(in_file_number, in_B, in_Z, in_S, out_SectionName, &out_type, &out_start, &out_end, &out_nbndry, &out_parent_flag);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_SectionName);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[2]) = out_start;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[3]) = out_end;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = out_nbndry;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_parent_flag;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data)
 *
 * The original C interface is
 * int cg_elements_read(int file_number, int B, int Z, int S, long long * elements, long long * parent_data);
 */
EXTERN_C void cg_elements_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long * io_elements;
    long long * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_elements = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        io_parent_data = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument parent_data");


    /******** Invoke computational function ********/
    ierr = cg_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_poly_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_connect_offset, io_parent_data)
 *
 * The original C interface is
 * int cg_poly_elements_read(int file_number, int B, int Z, int S, long long * elements, long long * connect_offset, long long * parent_data);
 */
EXTERN_C void cg_poly_elements_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long * io_elements;
    long long * io_connect_offset;
    long long * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_elements = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        io_connect_offset = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument connect_offset");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        io_parent_data = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument parent_data");


    /******** Invoke computational function ********/
    ierr = cg_poly_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_connect_offset, io_parent_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_S, ierr] = cg_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements)
 *
 * The original C interface is
 * int cg_section_write(int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, long long start, long long end, int nbndry, const long long * elements, int * S);
 */
EXTERN_C void cg_section_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    CG_ElementType_t in_type;
    long long in_start;
    long long in_end;
    int in_nbndry;
    long long * in_elements;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_elements = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");


    /******** Invoke computational function ********/
    ierr = cg_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_poly_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, in_connect_offset)
 *
 * The original C interface is
 * int cg_poly_section_write(int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, long long start, long long end, int nbndry, const long long * elements, const long long * connect_offset, int * S);
 */
EXTERN_C void cg_poly_section_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    CG_ElementType_t in_type;
    long long in_start;
    long long in_end;
    int in_nbndry;
    long long * in_elements;
    long long * in_connect_offset;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 10)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_elements = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[9]) || mxIsUint64(prhs[9]))
        in_connect_offset = (long long*)mxGetData(prhs[9]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument connect_offset");


    /******** Invoke computational function ********/
    ierr = cg_poly_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, in_connect_offset, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_section_general_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_elementDataType, in_start, in_end, in_elementDataSize, in_nbndry)
 *
 * The original C interface is
 * int cg_section_general_write(int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, CG_DataType_t elementDataType, long long start, long long end, long long elementDataSize, int nbndry, int * S);
 */
EXTERN_C void cg_section_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    CG_ElementType_t in_type;
    CG_DataType_t in_elementDataType;
    long long in_start;
    long long in_end;
    long long in_elementDataSize;
    int in_nbndry;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 10)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument elementDataType");
    in_elementDataType = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument start");
    in_start = _get_numeric_scalar_int64(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[7]);

    if (_n_dims(prhs[8]) > 0)
        mexErrMsgTxt("Error in dimension of argument elementDataSize");
    in_elementDataSize = _get_numeric_scalar_int64(prhs[8]);

    if (_n_dims(prhs[9]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[9]);


    /******** Invoke computational function ********/
    ierr = cg_section_general_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_elementDataType, in_start, in_end, in_elementDataSize, in_nbndry, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_section_initialize(in_file_number, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_section_initialize(int file_number, int B, int Z, int S);
 */
EXTERN_C void cg_section_initialize_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_section_initialize(in_file_number, in_B, in_Z, in_S);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data)
 *
 * The original C interface is
 * int cg_parent_data_write(int file_number, int B, int Z, int S, const long long * parent_data);
 */
EXTERN_C void cg_parent_data_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long * in_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        in_parent_data = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument parent_data");


    /******** Invoke computational function ********/
    ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_npe, ierr] = cg_npe(in_type)
 *
 * The original C interface is
 * int cg_npe(CG_ElementType_t type, int * npe);
 */
EXTERN_C void cg_npe_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_ElementType_t in_type;
    int out_npe;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_npe(in_type, &out_npe);


    /******** Process output scalars and strings ********/
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
 * int cg_ElementDataSize(int file_number, int B, int Z, int S, long long * ElementDataSize);
 */
EXTERN_C void cg_ElementDataSize_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long out_ElementDataSize;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    *(long long*)mxGetData(plhs[0]) = out_ElementDataSize;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_section_partial_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry)
 *
 * The original C interface is
 * int cg_section_partial_write(int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, long long start, long long end, int nbndry, int * S);
 */
EXTERN_C void cg_section_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_SectionName;
    CG_ElementType_t in_type;
    long long in_start;
    long long in_end;
    int in_nbndry;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument nbndry");
    in_nbndry = _get_numeric_scalar_int32(prhs[7]);


    /******** Invoke computational function ********/
    ierr = cg_section_partial_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_SectionName);

    /******** Process output scalars and strings ********/
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
 * int cg_elements_partial_write(int fn, int B, int Z, int S, long long start, long long end, const long long * elements);
 */
EXTERN_C void cg_elements_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long * in_elements;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_elements = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");


    /******** Invoke computational function ********/
    ierr = cg_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_elements_general_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_m_type, in_elements)
 *
 * The original C interface is
 * int cg_elements_general_write(int fn, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, const void * elements);
 */
EXTERN_C void cg_elements_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    const void * in_elements;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    in_elements = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_elements_general_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_m_type, in_elements);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_poly_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements, in_connect_offset)
 *
 * The original C interface is
 * int cg_poly_elements_partial_write(int fn, int B, int Z, int S, long long start, long long end, const long long * elements, const long long * connect_offset);
 */
EXTERN_C void cg_poly_elements_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long * in_elements;
    long long * in_connect_offset;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_elements = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_connect_offset = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument connect_offset");


    /******** Invoke computational function ********/
    ierr = cg_poly_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements, in_connect_offset);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_poly_elements_general_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_m_type, in_elements, in_connect_offset)
 *
 * The original C interface is
 * int cg_poly_elements_general_write(int fn, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, const void * elements, const void * connect_offset);
 */
EXTERN_C void cg_poly_elements_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    const void * in_elements;
    const void * in_connect_offset;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    in_elements = mxGetData(prhs[7]);
    in_connect_offset = mxGetData(prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_poly_elements_general_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_m_type, in_elements, in_connect_offset);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_parent_data_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_ParentData)
 *
 * The original C interface is
 * int cg_parent_data_partial_write(int fn, int B, int Z, int S, long long start, long long end, const long long * ParentData);
 */
EXTERN_C void cg_parent_data_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long * in_ParentData;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_ParentData = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument ParentData");


    /******** Invoke computational function ********/
    ierr = cg_parent_data_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_ParentData);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data)
 *
 * The original C interface is
 * int cg_elements_partial_read(int file_number, int B, int Z, int S, long long start, long long end, long long * elements, long long * parent_data);
 */
EXTERN_C void cg_elements_partial_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long * io_elements;
    long long * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        io_elements = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        io_parent_data = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument parent_data");


    /******** Invoke computational function ********/
    ierr = cg_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_poly_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_connect_offset, io_parent_data)
 *
 * The original C interface is
 * int cg_poly_elements_partial_read(int file_number, int B, int Z, int S, long long start, long long end, long long * elements, long long * connect_offset, long long * parent_data);
 */
EXTERN_C void cg_poly_elements_partial_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long * io_elements;
    long long * io_connect_offset;
    long long * io_parent_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        io_elements = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument elements");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        io_connect_offset = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument connect_offset");

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        io_parent_data = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument parent_data");


    /******** Invoke computational function ********/
    ierr = cg_poly_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_connect_offset, io_parent_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements)
 *
 * The original C interface is
 * int cg_elements_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * elements);
 */
EXTERN_C void cg_elements_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    void * io_elements;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    io_elements = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_poly_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements, io_connect_offset)
 *
 * The original C interface is
 * int cg_poly_elements_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * elements, void * connect_offset);
 */
EXTERN_C void cg_poly_elements_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    void * io_elements;
    void * io_connect_offset;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    io_elements = mxGetData(prhs[7]);
    io_connect_offset = mxGetData(prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_poly_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements, io_connect_offset);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_parent_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parelem)
 *
 * The original C interface is
 * int cg_parent_elements_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * parelem);
 */
EXTERN_C void cg_parent_elements_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    void * io_parelem;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    io_parelem = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_parent_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parelem);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_parent_elements_position_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parface)
 *
 * The original C interface is
 * int cg_parent_elements_position_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * parface);
 */
EXTERN_C void cg_parent_elements_position_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    CG_DataType_t in_m_type;
    void * io_parface;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    io_parface = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_parent_elements_position_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parface);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ElementDataSize, ierr] = cg_ElementPartialSize(in_file_number, in_B, in_Z, in_S, in_start, in_end)
 *
 * The original C interface is
 * int cg_ElementPartialSize(int file_number, int B, int Z, int S, long long start, long long end, long long * ElementDataSize);
 */
EXTERN_C void cg_ElementPartialSize_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_S;
    long long in_start;
    long long in_end;
    long long out_ElementDataSize;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_start = _get_numeric_scalar_int64(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument end");
    in_end = _get_numeric_scalar_int64(prhs[5]);


    /******** Invoke computational function ********/
    ierr = cg_ElementPartialSize(in_file_number, in_B, in_Z, in_S, in_start, in_end, &out_ElementDataSize);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    *(long long*)mxGetData(plhs[0]) = out_ElementDataSize;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nsols, ierr] = cg_nsols(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_nsols(int fn, int B, int Z, int * nsols);
 */
EXTERN_C void cg_nsols_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nsols;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsols;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_solname, out_location, ierr] = cg_sol_info(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_sol_info(int fn, int B, int Z, int S, char * solname, CG_GridLocation_t * location);
 */
EXTERN_C void cg_sol_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char out_solname[33];
    CG_GridLocation_t out_location;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_sol_info(in_fn, in_B, in_Z, in_S, out_solname, &out_location);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_solname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_location;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_sol_id, ierr] = cg_sol_id(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_sol_id(int fn, int B, int Z, int S, double * sol_id);
 */
EXTERN_C void cg_sol_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    double out_sol_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_sol_write(int fn, int B, int Z, const char * solname, CG_GridLocation_t location, int * S);
 */
EXTERN_C void cg_sol_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_solname;
    CG_GridLocation_t in_location;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_data_dim, ierr] = cg_sol_size(in_fn, in_B, in_Z, in_S, io_dim_vals)
 *
 * The original C interface is
 * int cg_sol_size(int fn, int B, int Z, int S, int * data_dim, long long * dim_vals);
 */
EXTERN_C void cg_sol_size_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int out_data_dim;
    long long * io_dim_vals;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_dim_vals = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument dim_vals");


    /******** Invoke computational function ********/
    ierr = cg_sol_size(in_fn, in_B, in_Z, in_S, &out_data_dim, io_dim_vals);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_data_dim;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_ptset_type, out_npnts, ierr] = cg_sol_ptset_info(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_sol_ptset_info(int fn, int B, int Z, int S, CG_PointSetType_t * ptset_type, long long * npnts);
 */
EXTERN_C void cg_sol_ptset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    CG_PointSetType_t out_ptset_type;
    long long out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_sol_ptset_info(in_fn, in_B, in_Z, in_S, &out_ptset_type, &out_npnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ptset_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[1]) = out_npnts;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_sol_ptset_read(in_fn, in_B, in_Z, in_S, io_pnts)
 *
 * The original C interface is
 * int cg_sol_ptset_read(int fn, int B, int Z, int S, long long * pnts);
 */
EXTERN_C void cg_sol_ptset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_sol_ptset_read(in_fn, in_B, in_Z, in_S, io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_S, ierr] = cg_sol_ptset_write(in_fn, in_B, in_Z, in_solname, in_location, in_ptset_type, in_npnts, in_pnts)
 *
 * The original C interface is
 * int cg_sol_ptset_write(int fn, int B, int Z, const char * solname, CG_GridLocation_t location, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * S);
 */
EXTERN_C void cg_sol_ptset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_solname;
    CG_GridLocation_t in_location;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int64(prhs[6]);

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_pnts = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_sol_ptset_write(in_fn, in_B, in_Z, in_solname, in_location, in_ptset_type, in_npnts, in_pnts, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_solname);

    /******** Process output scalars and strings ********/
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
 * int cg_nfields(int fn, int B, int Z, int S, int * nfields);
 */
EXTERN_C void cg_nfields_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int out_nfields;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nfields;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_type, out_fieldname, ierr] = cg_field_info(in_fn, in_B, in_Z, in_S, in_F)
 *
 * The original C interface is
 * int cg_field_info(int fn, int B, int Z, int S, int F, CG_DataType_t * type, char * fieldname);
 */
EXTERN_C void cg_field_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    int in_F;
    CG_DataType_t out_type;
    char out_fieldname[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_field_info(in_fn, in_B, in_Z, in_S, in_F, &out_type, out_fieldname);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_fieldname);
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_field_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr)
 *
 * The original C interface is
 * int cg_field_read(int fn, int B, int Z, int S, const char * fieldname, CG_DataType_t type, const long long * rmin, const long long * rmax, void * field_ptr);
 */
EXTERN_C void cg_field_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char * in_fieldname;
    CG_DataType_t in_type;
    long long * in_rmin;
    long long * in_rmax;
    void * io_field_ptr;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmin = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_rmax = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    io_field_ptr = mxGetData(prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_field_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_field_general_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_field_ptr)
 *
 * The original C interface is
 * int cg_field_general_read(int fn, int B, int Z, int S, const char * fieldname, const long long * s_rmin, const long long * s_rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dimvals, const long long * m_rmin, const long long * m_rmax, void * field_ptr);
 */
EXTERN_C void cg_field_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char * in_fieldname;
    long long * in_s_rmin;
    long long * in_s_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dimvals;
    long long * in_m_rmin;
    long long * in_m_rmax;
    void * io_field_ptr;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 13)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_s_rmin = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmin");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_s_rmax = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmax");

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[7]);

    if (_n_dims(prhs[8]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[8]);

    if (mxIsInt64(prhs[9]) || mxIsUint64(prhs[9]))
        in_m_dimvals = (long long*)mxGetData(prhs[9]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dimvals");

    if (mxIsInt64(prhs[10]) || mxIsUint64(prhs[10]))
        in_m_rmin = (long long*)mxGetData(prhs[10]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[11]) || mxIsUint64(prhs[11]))
        in_m_rmax = (long long*)mxGetData(prhs[11]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    io_field_ptr = mxGetData(prhs[12]);

    /******** Invoke computational function ********/
    ierr = cg_field_general_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_field_ptr);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_field_id, ierr] = cg_field_id(in_fn, in_B, in_Z, in_S, in_F)
 *
 * The original C interface is
 * int cg_field_id(int fn, int B, int Z, int S, int F, double * field_id);
 */
EXTERN_C void cg_field_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
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

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_field_write(int fn, int B, int Z, int S, CG_DataType_t type, const char * fieldname, const void * field_ptr, int * F);
 */
EXTERN_C void cg_field_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    CG_DataType_t in_type;
    char * in_fieldname;
    const void * in_field_ptr;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    in_field_ptr = mxGetData(prhs[6]);

    /******** Invoke computational function ********/
    ierr = cg_field_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_field_ptr, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output scalars and strings ********/
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
 * int cg_field_partial_write(int fn, int B, int Z, int S, CG_DataType_t type, const char * fieldname, const long long * rmin, const long long * rmax, const void * field_ptr, int * F);
 */
EXTERN_C void cg_field_partial_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    CG_DataType_t in_type;
    char * in_fieldname;
    long long * in_rmin;
    long long * in_rmax;
    const void * in_field_ptr;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmin = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_rmax = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    in_field_ptr = mxGetData(prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_field_partial_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_F, ierr] = cg_field_general_write(in_fn, in_B, in_Z, in_S, in_fieldname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_field_ptr)
 *
 * The original C interface is
 * int cg_field_general_write(int fn, int B, int Z, int S, const char * fieldname, CG_DataType_t s_type, const long long * rmin, const long long * rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dims, const long long * m_rmin, const long long * m_rmax, const void * field_ptr, int * F);
 */
EXTERN_C void cg_field_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char * in_fieldname;
    CG_DataType_t in_s_type;
    long long * in_rmin;
    long long * in_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dims;
    long long * in_m_rmin;
    long long * in_m_rmax;
    const void * in_field_ptr;
    int out_F;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 14)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument s_type");
    in_s_type = _get_numeric_scalar_int32(prhs[5]);

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_rmin = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmin");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_rmax = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument rmax");

    if (_n_dims(prhs[8]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[8]);

    if (_n_dims(prhs[9]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[9]);

    if (mxIsInt64(prhs[10]) || mxIsUint64(prhs[10]))
        in_m_dims = (long long*)mxGetData(prhs[10]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dims");

    if (mxIsInt64(prhs[11]) || mxIsUint64(prhs[11]))
        in_m_rmin = (long long*)mxGetData(prhs[11]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[12]) || mxIsUint64(prhs[12]))
        in_m_rmax = (long long*)mxGetData(prhs[12]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    in_field_ptr = mxGetData(prhs[13]);

    /******** Invoke computational function ********/
    ierr = cg_field_general_write(in_fn, in_B, in_Z, in_S, in_fieldname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_field_ptr, &out_F);


    /******** Free up input buffers. ********/
    _mxFreeString(in_fieldname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_F;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nsubreg, ierr] = cg_nsubregs(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_nsubregs(int fn, int B, int Z, int * nsubreg);
 */
EXTERN_C void cg_nsubregs_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nsubreg;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_nsubregs(in_fn, in_B, in_Z, &out_nsubreg);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nsubreg;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_regname, out_dimension, out_location, out_ptset_type, out_npnts, out_bcname_len, out_gcname_len, ierr] = cg_subreg_info(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_subreg_info(int fn, int B, int Z, int S, char * regname, int * dimension, CG_GridLocation_t * location, CG_PointSetType_t * ptset_type, long long * npnts, int * bcname_len, int * gcname_len);
 */
EXTERN_C void cg_subreg_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char out_regname[33];
    int out_dimension;
    CG_GridLocation_t out_location;
    CG_PointSetType_t out_ptset_type;
    long long out_npnts;
    int out_bcname_len;
    int out_gcname_len;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 8 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_subreg_info(in_fn, in_B, in_Z, in_S, out_regname, &out_dimension, &out_location, &out_ptset_type, &out_npnts, &out_bcname_len, &out_gcname_len);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_regname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_dimension;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_location;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_ptset_type;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[4]) = out_npnts;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = out_bcname_len;
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = out_gcname_len;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[7]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_subreg_ptset_read(in_fn, in_B, in_Z, in_S, io_pnts)
 *
 * The original C interface is
 * int cg_subreg_ptset_read(int fn, int B, int Z, int S, long long * pnts);
 */
EXTERN_C void cg_subreg_ptset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_subreg_ptset_read(in_fn, in_B, in_Z, in_S, io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_bcname, ierr] = cg_subreg_bcname_read(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_subreg_bcname_read(int fn, int B, int Z, int S, char * bcname);
 */
EXTERN_C void cg_subreg_bcname_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char out_bcname[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_subreg_bcname_read(in_fn, in_B, in_Z, in_S, out_bcname);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_bcname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_gcname, ierr] = cg_subreg_gcname_read(in_fn, in_B, in_Z, in_S)
 *
 * The original C interface is
 * int cg_subreg_gcname_read(int fn, int B, int Z, int S, char * gcname);
 */
EXTERN_C void cg_subreg_gcname_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_S;
    char out_gcname[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_subreg_gcname_read(in_fn, in_B, in_Z, in_S, out_gcname);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_gcname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_subreg_ptset_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_location, in_ptset_type, in_npnts, in_pnts)
 *
 * The original C interface is
 * int cg_subreg_ptset_write(int fn, int B, int Z, const char * regname, int dimension, CG_GridLocation_t location, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * S);
 */
EXTERN_C void cg_subreg_ptset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_regname;
    int in_dimension;
    CG_GridLocation_t in_location;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_regname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument dimension");
    in_dimension = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int64(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_pnts = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_subreg_ptset_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_location, in_ptset_type, in_npnts, in_pnts, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_regname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_subreg_bcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_bcname)
 *
 * The original C interface is
 * int cg_subreg_bcname_write(int fn, int B, int Z, const char * regname, int dimension, const char * bcname, int * S);
 */
EXTERN_C void cg_subreg_bcname_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_regname;
    int in_dimension;
    char * in_bcname;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_regname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument dimension");
    in_dimension = _get_numeric_scalar_int32(prhs[4]);

    in_bcname = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_subreg_bcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_bcname, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_regname);
    _mxFreeString(in_bcname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_S, ierr] = cg_subreg_gcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_gcname)
 *
 * The original C interface is
 * int cg_subreg_gcname_write(int fn, int B, int Z, const char * regname, int dimension, const char * gcname, int * S);
 */
EXTERN_C void cg_subreg_gcname_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_regname;
    int in_dimension;
    char * in_gcname;
    int out_S;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_regname = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument dimension");
    in_dimension = _get_numeric_scalar_int32(prhs[4]);

    in_gcname = _mxGetString(prhs[5], NULL);


    /******** Invoke computational function ********/
    ierr = cg_subreg_gcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_gcname, &out_S);


    /******** Free up input buffers. ********/
    _mxFreeString(in_regname);
    _mxFreeString(in_gcname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_S;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nzconns, ierr] = cg_nzconns(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_nzconns(int fn, int B, int Z, int * nzconns);
 */
EXTERN_C void cg_nzconns_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nzconns;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_nzconns(in_fn, in_B, in_Z, &out_nzconns);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nzconns;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, ierr] = cg_zconn_read(in_fn, in_B, in_Z, in_C)
 *
 * The original C interface is
 * int cg_zconn_read(int fn, int B, int Z, int C, char * name);
 */
EXTERN_C void cg_zconn_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    char out_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_zconn_read(in_fn, in_B, in_Z, in_C, out_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_C, ierr] = cg_zconn_write(in_fn, in_B, in_Z, in_name)
 *
 * The original C interface is
 * int cg_zconn_write(int fn, int B, int Z, const char * name, int * C);
 */
EXTERN_C void cg_zconn_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_name;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_name = _mxGetString(prhs[3], NULL);


    /******** Invoke computational function ********/
    ierr = cg_zconn_write(in_fn, in_B, in_Z, in_name, &out_C);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_C;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_C, ierr] = cg_zconn_get(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_zconn_get(int fn, int B, int Z, int * C);
 */
EXTERN_C void cg_zconn_get_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_zconn_get(in_fn, in_B, in_Z, &out_C);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_C;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_zconn_set(in_fn, in_B, in_Z, in_C)
 *
 * The original C interface is
 * int cg_zconn_set(int fn, int B, int Z, int C);
 */
EXTERN_C void cg_zconn_set_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_C;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_zconn_set(in_fn, in_B, in_Z, in_C);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nholes, ierr] = cg_nholes(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_nholes(int fn, int B, int Z, int * nholes);
 */
EXTERN_C void cg_nholes_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nholes;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nholes;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_holename, out_location, out_ptset_type, out_nptsets, out_npnts, ierr] = cg_hole_info(in_fn, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_hole_info(int fn, int B, int Z, int Ii, char * holename, CG_GridLocation_t * location, CG_PointSetType_t * ptset_type, int * nptsets, long long * npnts);
 */
EXTERN_C void cg_hole_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    char out_holename[33];
    CG_GridLocation_t out_location;
    CG_PointSetType_t out_ptset_type;
    int out_nptsets;
    long long out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 6 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_hole_info(in_fn, in_B, in_Z, in_Ii, out_holename, &out_location, &out_ptset_type, &out_nptsets, &out_npnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_holename);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_location;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_ptset_type;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_nptsets;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[4]) = out_npnts;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_hole_read(in_fn, in_B, in_Z, in_Ii, io_pnts)
 *
 * The original C interface is
 * int cg_hole_read(int fn, int B, int Z, int Ii, long long * pnts);
 */
EXTERN_C void cg_hole_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_hole_read(in_fn, in_B, in_Z, in_Ii, io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_hole_id, ierr] = cg_hole_id(in_fn, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_hole_id(int fn, int B, int Z, int Ii, double * hole_id);
 */
EXTERN_C void cg_hole_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    double out_hole_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_hole_id(in_fn, in_B, in_Z, in_Ii, &out_hole_id);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_hole_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_Ii, ierr] = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts)
 *
 * The original C interface is
 * int cg_hole_write(int fn, int B, int Z, const char * holename, CG_GridLocation_t location, CG_PointSetType_t ptset_type, int nptsets, long long npnts, const long long * pnts, int * Ii);
 */
EXTERN_C void cg_hole_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_holename;
    CG_GridLocation_t in_location;
    CG_PointSetType_t in_ptset_type;
    int in_nptsets;
    long long in_npnts;
    long long * in_pnts;
    int out_Ii;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_npnts = _get_numeric_scalar_int64(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_pnts = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts, &out_Ii);


    /******** Free up input buffers. ********/
    _mxFreeString(in_holename);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Ii;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_nconns, ierr] = cg_nconns(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_nconns(int fn, int B, int Z, int * nconns);
 */
EXTERN_C void cg_nconns_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nconns;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nconns;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_connectname, out_location, out_type, out_ptset_type, out_npnts, out_donorname, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr] = cg_conn_info(in_file_number, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_conn_info(int file_number, int B, int Z, int Ii, char * connectname, CG_GridLocation_t * location, CG_GridConnectivityType_t * type, CG_PointSetType_t * ptset_type, long long * npnts, char * donorname, CG_ZoneType_t * donor_zonetype, CG_PointSetType_t * donor_ptset_type, CG_DataType_t * donor_datatype, long long * ndata_donor);
 */
EXTERN_C void cg_conn_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    char out_connectname[33];
    CG_GridLocation_t out_location;
    CG_GridConnectivityType_t out_type;
    CG_PointSetType_t out_ptset_type;
    long long out_npnts;
    char out_donorname[33];
    CG_ZoneType_t out_donor_zonetype;
    CG_PointSetType_t out_donor_ptset_type;
    CG_DataType_t out_donor_datatype;
    long long out_ndata_donor;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 11 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_conn_info(in_file_number, in_B, in_Z, in_Ii, out_connectname, &out_location, &out_type, &out_ptset_type, &out_npnts, out_donorname, &out_donor_zonetype, &out_donor_ptset_type, &out_donor_datatype, &out_ndata_donor);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_connectname);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_location;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_type;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_ptset_type;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[4]) = out_npnts;
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateString(out_donorname);
    }
    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = out_donor_zonetype;
    }
    if (nlhs > 7) {
        plhs[7] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[7]) = out_donor_ptset_type;
    }
    if (nlhs > 8) {
        plhs[8] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[8]) = out_donor_datatype;
    }
    if (nlhs > 9) {
        plhs[9] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[9]) = out_ndata_donor;
    }
    if (nlhs > 10) {
        plhs[10] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[10]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_conn_read(in_file_number, in_B, in_Z, in_Ii, in_donor_datatype, io_pnts, io_donor_data)
 *
 * The original C interface is
 * int cg_conn_read(int file_number, int B, int Z, int Ii, long long * pnts, CG_DataType_t donor_datatype, long long * donor_data);
 */
EXTERN_C void cg_conn_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    long long * io_pnts;
    CG_DataType_t in_donor_datatype;
    long long * io_donor_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument donor_datatype");
    in_donor_datatype = _get_numeric_scalar_int32(prhs[4]);

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        io_pnts = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        io_donor_data = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument donor_data");


    /******** Invoke computational function ********/
    ierr = cg_conn_read(in_file_number, in_B, in_Z, in_Ii, io_pnts, in_donor_datatype, io_donor_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_conn_id, ierr] = cg_conn_id(in_fn, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_conn_id(int fn, int B, int Z, int Ii, double * conn_id);
 */
EXTERN_C void cg_conn_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    double out_conn_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_conn_id(in_fn, in_B, in_Z, in_Ii, &out_conn_id);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_conn_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_Ii, ierr] = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data)
 *
 * The original C interface is
 * int cg_conn_write(int file_number, int B, int Z, const char * connectname, CG_GridLocation_t location, CG_GridConnectivityType_t type, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, const char * donorname, CG_ZoneType_t donor_zonetype, CG_PointSetType_t donor_ptset_type, CG_DataType_t donor_datatype, long long ndata_donor, const long long * donor_data, int * Ii);
 */
EXTERN_C void cg_conn_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_connectname;
    CG_GridLocation_t in_location;
    CG_GridConnectivityType_t in_type;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    char * in_donorname;
    CG_ZoneType_t in_donor_zonetype;
    CG_PointSetType_t in_donor_ptset_type;
    CG_DataType_t in_donor_datatype;
    long long in_ndata_donor;
    long long * in_donor_data;
    int out_Ii;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 15)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_npnts = _get_numeric_scalar_int64(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_pnts = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");

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
    in_ndata_donor = _get_numeric_scalar_int64(prhs[13]);

    if (mxIsInt64(prhs[14]) || mxIsUint64(prhs[14]))
        in_donor_data = (long long*)mxGetData(prhs[14]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument donor_data");


    /******** Invoke computational function ********/
    ierr = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data, &out_Ii);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    _mxFreeString(in_donorname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Ii;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_Ii, ierr] = cg_conn_write_short(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname)
 *
 * The original C interface is
 * int cg_conn_write_short(int file_number, int B, int Z, const char * connectname, CG_GridLocation_t location, CG_GridConnectivityType_t type, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, const char * donorname, int * Ii);
 */
EXTERN_C void cg_conn_write_short_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_connectname;
    CG_GridLocation_t in_location;
    CG_GridConnectivityType_t in_type;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    char * in_donorname;
    int out_Ii;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 10)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_npnts = _get_numeric_scalar_int64(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_pnts = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");

    in_donorname = _mxGetString(prhs[9], NULL);


    /******** Invoke computational function ********/
    ierr = cg_conn_write_short(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, &out_Ii);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    _mxFreeString(in_donorname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Ii;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_conn_read_short(in_file_number, in_B, in_Z, in_Ii, io_pnts)
 *
 * The original C interface is
 * int cg_conn_read_short(int file_number, int B, int Z, int Ii, long long * pnts);
 */
EXTERN_C void cg_conn_read_short_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_conn_read_short(in_file_number, in_B, in_Z, in_Ii, io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_n1to1, ierr] = cg_n1to1(in_fn, in_B, in_Z)
 *
 * The original C interface is
 * int cg_n1to1(int fn, int B, int Z, int * n1to1);
 */
EXTERN_C void cg_n1to1_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_n1to1;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n1to1;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_connectname, out_donorname, out_range, out_donor_range, out_transform, ierr] = cg_1to1_read(in_fn, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_1to1_read(int fn, int B, int Z, int Ii, char * connectname, char * donorname, long long * range, long long * donor_range, int * transform);
 */
EXTERN_C void cg_1to1_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    char out_connectname[33];
    char out_donorname[33];
    long long * out_range;
    long long * out_donor_range;
    int * out_transform;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 6 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    /******** Obtain fixed-size output arrays ********/
    plhs[2] = mxCreateNumericMatrix(6,1,mxINT64_CLASS, mxREAL);
    out_range = mxGetData(plhs[2]);

    plhs[3] = mxCreateNumericMatrix(6,1,mxINT64_CLASS, mxREAL);
    out_donor_range = mxGetData(plhs[3]);

    plhs[4] = mxCreateNumericMatrix(3,1,mxINT32_CLASS, mxREAL);
    out_transform = mxGetData(plhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_read(in_fn, in_B, in_Z, in_Ii, out_connectname, out_donorname, out_range, out_donor_range, out_transform);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_connectname);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_donorname);
    }
    if (nlhs > 2) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = ierr;
    }
}

/* Gateway function
 * [out_one21_id, ierr] = cg_1to1_id(in_fn, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_1to1_id(int fn, int B, int Z, int Ii, double * one21_id);
 */
EXTERN_C void cg_1to1_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_Ii;
    double out_one21_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_id(in_fn, in_B, in_Z, in_Ii, &out_one21_id);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    *(double*)mxGetData(plhs[0]) = out_one21_id;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_Ii, ierr] = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform)
 *
 * The original C interface is
 * int cg_1to1_write(int fn, int B, int Z, const char * connectname, const char * donorname, const long long * range, const long long * donor_range, const int * transform, int * Ii);
 */
EXTERN_C void cg_1to1_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_connectname;
    char * in_donorname;
    long long * in_range;
    long long * in_donor_range;
    int * in_transform;
    int out_Ii;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_range = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument range");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_donor_range = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument donor_range");

    if (mxIsInt32(prhs[7]) || mxIsUint32(prhs[7]))
        in_transform = (int*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument transform");


    /******** Invoke computational function ********/
    ierr = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform, &out_Ii);


    /******** Free up input buffers. ********/
    _mxFreeString(in_connectname);
    _mxFreeString(in_donorname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Ii;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_n1to1_global, ierr] = cg_n1to1_global(in_fn, in_B)
 *
 * The original C interface is
 * int cg_n1to1_global(int fn, int B, int * n1to1_global);
 */
EXTERN_C void cg_n1to1_global_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int out_n1to1_global;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_n1to1_global(in_fn, in_B, &out_n1to1_global);


    /******** Process output scalars and strings ********/
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
 * int cg_nbocos(int fn, int B, int Z, int * nbocos);
 */
EXTERN_C void cg_nbocos_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int out_nbocos;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nbocos;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* External gateway function */
EXTERN void cg_boco_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]);

/* Gateway function
 * ierr = cg_boco_read(in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList)
 *
 * The original C interface is
 * int cg_boco_read(int fn, int B, int Z, int BC, long long * pnts, void * NormalList);
 */
EXTERN_C void cg_boco_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    long long * io_pnts;
    void * io_NormalList;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");

    io_NormalList = mxGetData(prhs[5]);

    /******** Invoke computational function ********/
    ierr = cg_boco_read(in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_boco_id, ierr] = cg_boco_id(in_fn, in_B, in_Z, in_BC)
 *
 * The original C interface is
 * int cg_boco_id(int fn, int B, int Z, int BC, double * boco_id);
 */
EXTERN_C void cg_boco_id_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    double out_boco_id;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_boco_write(int file_number, int B, int Z, const char * boconame, CG_BCType_t bocotype, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * BC);
 */
EXTERN_C void cg_boco_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_boconame;
    CG_BCType_t in_bocotype;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    int out_BC;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    in_npnts = _get_numeric_scalar_int64(prhs[6]);

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_pnts = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_boco_write(in_file_number, in_B, in_Z, in_boconame, in_bocotype, in_ptset_type, in_npnts, in_pnts, &out_BC);


    /******** Free up input buffers. ********/
    _mxFreeString(in_boconame);

    /******** Process output scalars and strings ********/
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
 * int cg_boco_normal_write(int file_number, int B, int Z, int BC, const int * NormalIndex, int NormalListFlag, CG_DataType_t NormalDataType, const void * NormalList);
 */
EXTERN_C void cg_boco_normal_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    int * in_NormalIndex;
    int in_NormalListFlag;
    CG_DataType_t in_NormalDataType;
    const void * in_NormalList;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument NormalIndex");

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument NormalListFlag");
    in_NormalListFlag = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument NormalDataType");
    in_NormalDataType = _get_numeric_scalar_int32(prhs[6]);

    in_NormalList = mxGetData(prhs[7]);

    /******** Invoke computational function ********/
    ierr = cg_boco_normal_write(in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_location, ierr] = cg_boco_gridlocation_read(in_file_number, in_B, in_Z, in_BC)
 *
 * The original C interface is
 * int cg_boco_gridlocation_read(int file_number, int B, int Z, int BC, CG_GridLocation_t * location);
 */
EXTERN_C void cg_boco_gridlocation_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_GridLocation_t out_location;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_boco_gridlocation_read(in_file_number, in_B, in_Z, in_BC, &out_location);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_location;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_boco_gridlocation_write(in_file_number, in_B, in_Z, in_BC, in_location)
 *
 * The original C interface is
 * int cg_boco_gridlocation_write(int file_number, int B, int Z, int BC, CG_GridLocation_t location);
 */
EXTERN_C void cg_boco_gridlocation_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_GridLocation_t in_location;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_boco_gridlocation_write(in_file_number, in_B, in_Z, in_BC, in_location);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS)
 *
 * The original C interface is
 * int cg_dataset_read(int fn, int B, int Z, int BC, int DS, char * name, CG_BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
 */
EXTERN_C void cg_dataset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_BC;
    int in_DS;
    char out_name[33];
    CG_BCType_t out_BCType;
    int out_DirichletFlag;
    int out_NeumannFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 5 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS, out_name, &out_BCType, &out_DirichletFlag, &out_NeumannFlag);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_BCType;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_DirichletFlag;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_NeumannFlag;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
}

/* Gateway function
 * [out_Dset, ierr] = cg_dataset_write(in_file_number, in_B, in_Z, in_BC, in_name, in_BCType)
 *
 * The original C interface is
 * int cg_dataset_write(int file_number, int B, int Z, int BC, const char * name, CG_BCType_t BCType, int * Dset);
 */
EXTERN_C void cg_dataset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    char * in_name;
    CG_BCType_t in_BCType;
    int out_Dset;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_Dset;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_bcdataset_write(in_name, in_BCType, in_BCDataType)
 *
 * The original C interface is
 * int cg_bcdataset_write(const char * name, CG_BCType_t BCType, CG_BCDataType_t BCDataType);
 */
EXTERN_C void cg_bcdataset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_name;
    CG_BCType_t in_BCType;
    CG_BCDataType_t in_BCDataType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_name = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCType");
    in_BCType = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument BCDataType");
    in_BCDataType = _get_numeric_scalar_int32(prhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_bcdataset_write(in_name, in_BCType, in_BCDataType);


    /******** Free up input buffers. ********/
    _mxFreeString(in_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_n_dataset, ierr] = cg_bcdataset_info()
 *
 * The original C interface is
 * int cg_bcdataset_info(int * n_dataset);
 */
EXTERN_C void cg_bcdataset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_n_dataset;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_bcdataset_info(&out_n_dataset);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_dataset;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_bcdataset_read(in_index)
 *
 * The original C interface is
 * int cg_bcdataset_read(int index, char * name, CG_BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
 */
EXTERN_C void cg_bcdataset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_index;
    char out_name[33];
    CG_BCType_t out_BCType;
    int out_DirichletFlag;
    int out_NeumannFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 5 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument index");
    in_index = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_bcdataset_read(in_index, out_name, &out_BCType, &out_DirichletFlag, &out_NeumannFlag);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_BCType;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_DirichletFlag;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = out_NeumannFlag;
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_bcdata_write(in_file_number, in_B, in_Z, in_BC, in_Dset, in_BCDataType)
 *
 * The original C interface is
 * int cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset, CG_BCDataType_t BCDataType);
 */
EXTERN_C void cg_bcdata_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    int in_Dset;
    CG_BCDataType_t in_BCDataType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 6)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ndiscrete, ierr] = cg_ndiscrete(in_file_number, in_B, in_Z)
 *
 * The original C interface is
 * int cg_ndiscrete(int file_number, int B, int Z, int * ndiscrete);
 */
EXTERN_C void cg_ndiscrete_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int out_ndiscrete;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ndiscrete;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_discrete_name, ierr] = cg_discrete_read(in_file_number, in_B, in_Z, in_D)
 *
 * The original C interface is
 * int cg_discrete_read(int file_number, int B, int Z, int D, char * discrete_name);
 */
EXTERN_C void cg_discrete_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_D;
    char out_discrete_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_discrete_read(in_file_number, in_B, in_Z, in_D, out_discrete_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_discrete_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_D, ierr] = cg_discrete_write(in_file_number, in_B, in_Z, in_discrete_name)
 *
 * The original C interface is
 * int cg_discrete_write(int file_number, int B, int Z, const char * discrete_name, int * D);
 */
EXTERN_C void cg_discrete_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_discrete_name;
    int out_D;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_D;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_data_dim, ierr] = cg_discrete_size(in_fn, in_B, in_Z, in_D, io_dim_vals)
 *
 * The original C interface is
 * int cg_discrete_size(int fn, int B, int Z, int D, int * data_dim, long long * dim_vals);
 */
EXTERN_C void cg_discrete_size_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_D;
    int out_data_dim;
    long long * io_dim_vals;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument D");
    in_D = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_dim_vals = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument dim_vals");


    /******** Invoke computational function ********/
    ierr = cg_discrete_size(in_fn, in_B, in_Z, in_D, &out_data_dim, io_dim_vals);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_data_dim;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_ptset_type, out_npnts, ierr] = cg_discrete_ptset_info(in_fn, in_B, in_Z, in_D)
 *
 * The original C interface is
 * int cg_discrete_ptset_info(int fn, int B, int Z, int D, CG_PointSetType_t * ptset_type, long long * npnts);
 */
EXTERN_C void cg_discrete_ptset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_D;
    CG_PointSetType_t out_ptset_type;
    long long out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument D");
    in_D = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_discrete_ptset_info(in_fn, in_B, in_Z, in_D, &out_ptset_type, &out_npnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ptset_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[1]) = out_npnts;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_discrete_ptset_read(in_fn, in_B, in_Z, in_D, io_pnts)
 *
 * The original C interface is
 * int cg_discrete_ptset_read(int fn, int B, int Z, int D, long long * pnts);
 */
EXTERN_C void cg_discrete_ptset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    int in_D;
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument D");
    in_D = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        io_pnts = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_discrete_ptset_read(in_fn, in_B, in_Z, in_D, io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_D, ierr] = cg_discrete_ptset_write(in_fn, in_B, in_Z, in_discrete_name, in_location, in_ptset_type, in_npnts, in_pnts)
 *
 * The original C interface is
 * int cg_discrete_ptset_write(int fn, int B, int Z, const char * discrete_name, CG_GridLocation_t location, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * D);
 */
EXTERN_C void cg_discrete_ptset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_fn;
    int in_B;
    int in_Z;
    char * in_discrete_name;
    CG_GridLocation_t in_location;
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    int out_D;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument Z");
    in_Z = _get_numeric_scalar_int32(prhs[2]);

    in_discrete_name = _mxGetString(prhs[3], NULL);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument location");
    in_location = _get_numeric_scalar_int32(prhs[4]);

    if (_n_dims(prhs[5]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[5]);

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int64(prhs[6]);

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_pnts = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_discrete_ptset_write(in_fn, in_B, in_Z, in_discrete_name, in_location, in_ptset_type, in_npnts, in_pnts, &out_D);


    /******** Free up input buffers. ********/
    _mxFreeString(in_discrete_name);

    /******** Process output scalars and strings ********/
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
 * int cg_n_rigid_motions(int file_number, int B, int Z, int * n_rigid_motions);
 */
EXTERN_C void cg_n_rigid_motions_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int out_n_rigid_motions;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_rigid_motions;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, out_type, ierr] = cg_rigid_motion_read(in_file_number, in_B, in_Z, in_R)
 *
 * The original C interface is
 * int cg_rigid_motion_read(int file_number, int B, int Z, int R, char * name, CG_RigidGridMotionType_t * type);
 */
EXTERN_C void cg_rigid_motion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_R;
    char out_name[33];
    CG_RigidGridMotionType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_rigid_motion_read(in_file_number, in_B, in_Z, in_R, out_name, &out_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_R, ierr] = cg_rigid_motion_write(in_file_number, in_B, in_Z, in_name, in_type)
 *
 * The original C interface is
 * int cg_rigid_motion_write(int file_number, int B, int Z, const char * name, CG_RigidGridMotionType_t type, int * R);
 */
EXTERN_C void cg_rigid_motion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_name;
    CG_RigidGridMotionType_t in_type;
    int out_R;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
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
 * int cg_n_arbitrary_motions(int file_number, int B, int Z, int * n_arbitrary_motions);
 */
EXTERN_C void cg_n_arbitrary_motions_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int out_n_arbitrary_motions;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_n_arbitrary_motions;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_name, out_type, ierr] = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A)
 *
 * The original C interface is
 * int cg_arbitrary_motion_read(int file_number, int B, int Z, int A, char * name, CG_ArbitraryGridMotionType_t * type);
 */
EXTERN_C void cg_arbitrary_motion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_A;
    char out_name[33];
    CG_ArbitraryGridMotionType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Invoke computational function ********/
    ierr = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A, out_name, &out_type);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_type;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * [out_A, ierr] = cg_arbitrary_motion_write(in_file_number, in_B, in_Z, in_amotionname, in_type)
 *
 * The original C interface is
 * int cg_arbitrary_motion_write(int file_number, int B, int Z, const char * amotionname, CG_ArbitraryGridMotionType_t type, int * A);
 */
EXTERN_C void cg_arbitrary_motion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_amotionname;
    CG_ArbitraryGridMotionType_t in_type;
    int out_A;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
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
 * int cg_simulation_type_read(int file_number, int B, CG_SimulationType_t * type);
 */
EXTERN_C void cg_simulation_type_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    CG_SimulationType_t out_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_simulation_type_read(in_file_number, in_B, &out_type);


    /******** Process output scalars and strings ********/
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
 * int cg_simulation_type_write(int file_number, int B, CG_SimulationType_t type);
 */
EXTERN_C void cg_simulation_type_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    CG_SimulationType_t in_type;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_bitername, out_nsteps, ierr] = cg_biter_read(in_file_number, in_B)
 *
 * The original C interface is
 * int cg_biter_read(int file_number, int B, char * bitername, int * nsteps);
 */
EXTERN_C void cg_biter_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    char out_bitername[33];
    int out_nsteps;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_biter_read(in_file_number, in_B, out_bitername, &out_nsteps);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_bitername);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_nsteps;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_biter_write(in_file_number, in_B, in_bitername, in_nsteps)
 *
 * The original C interface is
 * int cg_biter_write(int file_number, int B, const char * bitername, int nsteps);
 */
EXTERN_C void cg_biter_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    char * in_bitername;
    int in_nsteps;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_zitername, ierr] = cg_ziter_read(in_file_number, in_B, in_Z)
 *
 * The original C interface is
 * int cg_ziter_read(int file_number, int B, int Z, char * zitername);
 */
EXTERN_C void cg_ziter_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char out_zitername[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_ziter_read(in_file_number, in_B, in_Z, out_zitername);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_zitername);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_ziter_write(in_file_number, in_B, in_Z, in_zitername)
 *
 * The original C interface is
 * int cg_ziter_write(int file_number, int B, int Z, const char * zitername);
 */
EXTERN_C void cg_ziter_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    char * in_zitername;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_gravity_read(in_file_number, in_B, io_gravity_vector)
 *
 * The original C interface is
 * int cg_gravity_read(int file_number, int B, float * gravity_vector);
 */
EXTERN_C void cg_gravity_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    float * io_gravity_vector;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        io_gravity_vector = (float*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument gravity_vector");


    /******** Invoke computational function ********/
    ierr = cg_gravity_read(in_file_number, in_B, io_gravity_vector);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_gravity_write(in_file_number, in_B, in_gravity_vector)
 *
 * The original C interface is
 * int cg_gravity_write(int file_number, int B, float const * gravity_vector);
 */
EXTERN_C void cg_gravity_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    float * in_gravity_vector;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        in_gravity_vector = (float*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument gravity_vector");


    /******** Invoke computational function ********/
    ierr = cg_gravity_write(in_file_number, in_B, in_gravity_vector);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ref_point, out_axis, ierr] = cg_axisym_read(in_file_number, in_B)
 *
 * The original C interface is
 * int cg_axisym_read(int file_number, int B, float * ref_point, float * axis);
 */
EXTERN_C void cg_axisym_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    float * out_ref_point;
    float * out_axis;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    /******** Obtain fixed-size output arrays ********/
    plhs[0] = mxCreateNumericMatrix(2,1,mxSINGLE_CLASS, mxREAL);
    out_ref_point = mxGetData(plhs[0]);

    plhs[1] = mxCreateNumericMatrix(2,1,mxSINGLE_CLASS, mxREAL);
    out_axis = mxGetData(plhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_axisym_read(in_file_number, in_B, out_ref_point, out_axis);


    /******** Process output scalars and strings ********/
    plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[2]) = ierr;
}

/* Gateway function
 * ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis)
 *
 * The original C interface is
 * int cg_axisym_write(int file_number, int B, float const * ref_point, float const * axis);
 */
EXTERN_C void cg_axisym_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    float * in_ref_point;
    float * in_axis;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (mxIsSingle(prhs[2]))
        in_ref_point = (float*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument ref_point");

    if (mxIsSingle(prhs[3]))
        in_axis = (float*)mxGetData(prhs[3]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument axis");


    /******** Invoke computational function ********/
    ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_rotating_read(io_rot_rate, io_rot_center)
 *
 * The original C interface is
 * int cg_rotating_read(float * rot_rate, float * rot_center);
 */
EXTERN_C void cg_rotating_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    float * io_rot_rate;
    float * io_rot_center;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsSingle(prhs[0]))
        io_rot_rate = (float*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument rot_rate");

    if (mxIsSingle(prhs[1]))
        io_rot_center = (float*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument rot_center");


    /******** Invoke computational function ********/
    ierr = cg_rotating_read(io_rot_rate, io_rot_center);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_rotating_write(in_rot_rate, in_rot_center)
 *
 * The original C interface is
 * int cg_rotating_write(float const * rot_rate, float const * rot_center);
 */
EXTERN_C void cg_rotating_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    float * in_rot_rate;
    float * in_rot_center;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsSingle(prhs[0]))
        in_rot_rate = (float*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument rot_rate");

    if (mxIsSingle(prhs[1]))
        in_rot_center = (float*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument rot_center");


    /******** Invoke computational function ********/
    ierr = cg_rotating_write(in_rot_rate, in_rot_center);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_WallFunctionType, ierr] = cg_bc_wallfunction_read(in_file_number, in_B, in_Z, in_BC)
 *
 * The original C interface is
 * int cg_bc_wallfunction_read(int file_number, int B, int Z, int BC, CG_WallFunctionType_t * WallFunctionType);
 */
EXTERN_C void cg_bc_wallfunction_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_WallFunctionType_t out_WallFunctionType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
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
 * int cg_bc_wallfunction_write(int file_number, int B, int Z, int BC, CG_WallFunctionType_t WallFunctionType);
 */
EXTERN_C void cg_bc_wallfunction_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_WallFunctionType_t in_WallFunctionType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_AreaType, out_SurfaceArea, out_RegionName, ierr] = cg_bc_area_read(in_file_number, in_B, in_Z, in_BC)
 *
 * The original C interface is
 * int cg_bc_area_read(int file_number, int B, int Z, int BC, CG_AreaType_t * AreaType, float * SurfaceArea, char * RegionName);
 */
EXTERN_C void cg_bc_area_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_AreaType_t out_AreaType;
    float out_SurfaceArea;
    char out_RegionName[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
    ierr = cg_bc_area_read(in_file_number, in_B, in_Z, in_BC, &out_AreaType, &out_SurfaceArea, out_RegionName);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_AreaType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
        *(float*)mxGetData(plhs[1]) = out_SurfaceArea;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateString(out_RegionName);
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[3]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_bc_area_write(in_file_number, in_B, in_Z, in_BC, in_AreaType, in_SurfaceArea, in_RegionName)
 *
 * The original C interface is
 * int cg_bc_area_write(int file_number, int B, int Z, int BC, CG_AreaType_t AreaType, float SurfaceArea, const char * RegionName);
 */
EXTERN_C void cg_bc_area_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_BC;
    CG_AreaType_t in_AreaType;
    float in_SurfaceArea;
    char * in_RegionName;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_RotationCenter, out_RotationAngle, out_Translation, ierr] = cg_conn_periodic_read(in_file_number, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_conn_periodic_read(int file_number, int B, int Z, int Ii, float * RotationCenter, float * RotationAngle, float * Translation);
 */
EXTERN_C void cg_conn_periodic_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    float * out_RotationCenter;
    float * out_RotationAngle;
    float * out_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    /******** Obtain fixed-size output arrays ********/
    plhs[0] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_RotationCenter = mxGetData(plhs[0]);

    plhs[1] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_RotationAngle = mxGetData(plhs[1]);

    plhs[2] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_Translation = mxGetData(plhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_conn_periodic_read(in_file_number, in_B, in_Z, in_Ii, out_RotationCenter, out_RotationAngle, out_Translation);


    /******** Process output scalars and strings ********/
    plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[3]) = ierr;
}

/* Gateway function
 * ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation)
 *
 * The original C interface is
 * int cg_conn_periodic_write(int file_number, int B, int Z, int Ii, float const * RotationCenter, float const * RotationAngle, float const * Translation);
 */
EXTERN_C void cg_conn_periodic_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    float * in_RotationCenter;
    float * in_RotationAngle;
    float * in_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsSingle(prhs[4]))
        in_RotationCenter = (float*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument RotationCenter");

    if (mxIsSingle(prhs[5]))
        in_RotationAngle = (float*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument RotationAngle");

    if (mxIsSingle(prhs[6]))
        in_Translation = (float*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument Translation");


    /******** Invoke computational function ********/
    ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_1to1_periodic_write(in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation)
 *
 * The original C interface is
 * int cg_1to1_periodic_write(int file_number, int B, int Z, int Ii, float const * RotationCenter, float const * RotationAngle, float const * Translation);
 */
EXTERN_C void cg_1to1_periodic_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    float * in_RotationCenter;
    float * in_RotationAngle;
    float * in_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 7)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (mxIsSingle(prhs[4]))
        in_RotationCenter = (float*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument RotationCenter");

    if (mxIsSingle(prhs[5]))
        in_RotationAngle = (float*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument RotationAngle");

    if (mxIsSingle(prhs[6]))
        in_Translation = (float*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting single-precision float matrix for argument Translation");


    /******** Invoke computational function ********/
    ierr = cg_1to1_periodic_write(in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_RotationCenter, out_RotationAngle, out_Translation, ierr] = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_1to1_periodic_read(int file_number, int B, int Z, int Ii, float * RotationCenter, float * RotationAngle, float * Translation);
 */
EXTERN_C void cg_1to1_periodic_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    float * out_RotationCenter;
    float * out_RotationAngle;
    float * out_Translation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 4 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    /******** Obtain fixed-size output arrays ********/
    plhs[0] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_RotationCenter = mxGetData(plhs[0]);

    plhs[1] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_RotationAngle = mxGetData(plhs[1]);

    plhs[2] = mxCreateNumericMatrix(3,1,mxSINGLE_CLASS, mxREAL);
    out_Translation = mxGetData(plhs[2]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_Ii, out_RotationCenter, out_RotationAngle, out_Translation);


    /******** Process output scalars and strings ********/
    plhs[3] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[3]) = ierr;
}

/* Gateway function
 * [out_AverageInterfaceType, ierr] = cg_conn_average_read(in_file_number, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_conn_average_read(int file_number, int B, int Z, int Ii, CG_AverageInterfaceType_t * AverageInterfaceType);
 */
EXTERN_C void cg_conn_average_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    CG_AverageInterfaceType_t out_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_conn_average_read(in_file_number, in_B, in_Z, in_Ii, &out_AverageInterfaceType);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_AverageInterfaceType;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_conn_average_write(in_file_number, in_B, in_Z, in_Ii, in_AverageInterfaceType)
 *
 * The original C interface is
 * int cg_conn_average_write(int file_number, int B, int Z, int Ii, CG_AverageInterfaceType_t AverageInterfaceType);
 */
EXTERN_C void cg_conn_average_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    CG_AverageInterfaceType_t in_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument AverageInterfaceType");
    in_AverageInterfaceType = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_conn_average_write(in_file_number, in_B, in_Z, in_Ii, in_AverageInterfaceType);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_1to1_average_write(in_file_number, in_B, in_Z, in_Ii, in_AverageInterfaceType)
 *
 * The original C interface is
 * int cg_1to1_average_write(int file_number, int B, int Z, int Ii, CG_AverageInterfaceType_t AverageInterfaceType);
 */
EXTERN_C void cg_1to1_average_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    CG_AverageInterfaceType_t in_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument AverageInterfaceType");
    in_AverageInterfaceType = _get_numeric_scalar_int32(prhs[4]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_average_write(in_file_number, in_B, in_Z, in_Ii, in_AverageInterfaceType);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_AverageInterfaceType, ierr] = cg_1to1_average_read(in_file_number, in_B, in_Z, in_Ii)
 *
 * The original C interface is
 * int cg_1to1_average_read(int file_number, int B, int Z, int Ii, CG_AverageInterfaceType_t * AverageInterfaceType);
 */
EXTERN_C void cg_1to1_average_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    int in_B;
    int in_Z;
    int in_Ii;
    CG_AverageInterfaceType_t out_AverageInterfaceType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 4)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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
        mexErrMsgTxt("Error in dimension of argument Ii");
    in_Ii = _get_numeric_scalar_int32(prhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_1to1_average_read(in_file_number, in_B, in_Z, in_Ii, &out_AverageInterfaceType);


    /******** Process output scalars and strings ********/
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
 * int cg_gopath(int file_number, const char * path);
 */
EXTERN_C void cg_gopath_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_file_number;
    char * in_path;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    in_path = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_gopath(in_file_number, in_path);


    /******** Free up input buffers. ********/
    _mxFreeString(in_path);

    /******** Process output scalars and strings ********/
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
 * [out_iterations, out_NormDefinitions, ierr] = cg_convergence_read()
 *
 * The original C interface is
 * int cg_convergence_read(int * iterations, char ** NormDefinitions);
 */
EXTERN_C void cg_convergence_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_iterations;
    char * out_NormDefinitions;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_convergence_read(&out_iterations, &out_NormDefinitions);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_iterations;
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_NormDefinitions);
    }
    cg_free(out_NormDefinitions);

    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_convergence_write(in_iterations, in_NormDefinitions)
 *
 * The original C interface is
 * int cg_convergence_write(int iterations, const char * NormDefinitions);
 */
EXTERN_C void cg_convergence_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_iterations;
    char * in_NormDefinitions;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument iterations");
    in_iterations = _get_numeric_scalar_int32(prhs[0]);

    in_NormDefinitions = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_convergence_write(in_iterations, in_NormDefinitions);


    /******** Free up input buffers. ********/
    _mxFreeString(in_NormDefinitions);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_StateDescription, ierr] = cg_state_read()
 *
 * The original C interface is
 * int cg_state_read(char ** StateDescription);
 */
EXTERN_C void cg_state_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * out_StateDescription;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_state_read(&out_StateDescription);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_StateDescription);
    cg_free(out_StateDescription);

    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_state_write(in_StateDescription)
 *
 * The original C interface is
 * int cg_state_write(const char * StateDescription);
 */
EXTERN_C void cg_state_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_StateDescription;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_StateDescription = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_state_write(in_StateDescription);


    /******** Free up input buffers. ********/
    _mxFreeString(in_StateDescription);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_EquationDimension, out_GoverningEquationsFlag, out_GasModelFlag, out_ViscosityModelFlag, out_ThermalConductivityModelFlag, out_TurbulenceClosureFlag, out_TurbulenceModelFlag, ierr] = cg_equationset_read()
 *
 * The original C interface is
 * int cg_equationset_read(int * EquationDimension, int * GoverningEquationsFlag, int * GasModelFlag, int * ViscosityModelFlag, int * ThermalConductivityModelFlag, int * TurbulenceClosureFlag, int * TurbulenceModelFlag);
 */
EXTERN_C void cg_equationset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
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


    /******** Process output scalars and strings ********/
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
 * int cg_equationset_chemistry_read(int * ThermalRelaxationFlag, int * ChemicalKineticsFlag);
 */
EXTERN_C void cg_equationset_chemistry_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_ThermalRelaxationFlag;
    int out_ChemicalKineticsFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_equationset_chemistry_read(&out_ThermalRelaxationFlag, &out_ChemicalKineticsFlag);


    /******** Process output scalars and strings ********/
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
 * int cg_equationset_elecmagn_read(int * ElecFldModelFlag, int * MagnFldModelFlag, int * ConductivityModelFlag);
 */
EXTERN_C void cg_equationset_elecmagn_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * io_ElecFldModelFlag;
    int * io_MagnFldModelFlag;
    int * io_ConductivityModelFlag;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_ElecFldModelFlag = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument ElecFldModelFlag");

    if (mxIsInt32(prhs[1]) || mxIsUint32(prhs[1]))
        io_MagnFldModelFlag = (int*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument MagnFldModelFlag");

    if (mxIsInt32(prhs[2]) || mxIsUint32(prhs[2]))
        io_ConductivityModelFlag = (int*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument ConductivityModelFlag");


    /******** Invoke computational function ********/
    ierr = cg_equationset_elecmagn_read(io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_equationset_write(in_EquationDimension)
 *
 * The original C interface is
 * int cg_equationset_write(int EquationDimension);
 */
EXTERN_C void cg_equationset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_EquationDimension;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument EquationDimension");
    in_EquationDimension = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_equationset_write(in_EquationDimension);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_EquationsType, ierr] = cg_governing_read()
 *
 * The original C interface is
 * int cg_governing_read(CG_GoverningEquationsType_t * EquationsType);
 */
EXTERN_C void cg_governing_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GoverningEquationsType_t out_EquationsType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_governing_read(&out_EquationsType);


    /******** Process output scalars and strings ********/
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
 * int cg_governing_write(CG_GoverningEquationsType_t Equationstype);
 */
EXTERN_C void cg_governing_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GoverningEquationsType_t in_Equationstype;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Equationstype");
    in_Equationstype = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_governing_write(in_Equationstype);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_diffusion_read(io_diffusion_model)
 *
 * The original C interface is
 * int cg_diffusion_read(int * diffusion_model);
 */
EXTERN_C void cg_diffusion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * io_diffusion_model;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_diffusion_model = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument diffusion_model");


    /******** Invoke computational function ********/
    ierr = cg_diffusion_read(io_diffusion_model);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_diffusion_write(in_diffusion_model)
 *
 * The original C interface is
 * int cg_diffusion_write(const int * diffusion_model);
 */
EXTERN_C void cg_diffusion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * in_diffusion_model;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        in_diffusion_model = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument diffusion_model");


    /******** Invoke computational function ********/
    ierr = cg_diffusion_write(in_diffusion_model);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ModelType, ierr] = cg_model_read(in_ModelLabel)
 *
 * The original C interface is
 * int cg_model_read(const char * ModelLabel, CG_ModelType_t * ModelType);
 */
EXTERN_C void cg_model_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_ModelLabel;
    CG_ModelType_t out_ModelType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_ModelLabel = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_model_read(in_ModelLabel, &out_ModelType);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ModelLabel);

    /******** Process output scalars and strings ********/
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
 * int cg_model_write(const char * ModelLabel, CG_ModelType_t ModelType);
 */
EXTERN_C void cg_model_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_ModelLabel;
    CG_ModelType_t in_ModelType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_ModelLabel = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument ModelType");
    in_ModelType = _get_numeric_scalar_int32(prhs[1]);


    /******** Invoke computational function ********/
    ierr = cg_model_write(in_ModelLabel, in_ModelType);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ModelLabel);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_narrays, ierr] = cg_narrays()
 *
 * The original C interface is
 * int cg_narrays(int * narrays);
 */
EXTERN_C void cg_narrays_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_narrays;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_narrays(&out_narrays);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_narrays;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_ArrayName, out_DataType, out_DataDimension, out_DimensionVector, ierr] = cg_array_info(in_A)
 *
 * The original C interface is
 * int cg_array_info(int A, char * ArrayName, CG_DataType_t * DataType, int * DataDimension, long long * DimensionVector);
 */
EXTERN_C void cg_array_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_A;
    char out_ArrayName[33];
    CG_DataType_t out_DataType;
    int out_DataDimension;
    long long * out_DimensionVector;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 5 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    /******** Obtain fixed-size output arrays ********/
    plhs[3] = mxCreateNumericMatrix(3,1,mxINT64_CLASS, mxREAL);
    out_DimensionVector = mxGetData(plhs[3]);


    /******** Invoke computational function ********/
    ierr = cg_array_info(in_A, out_ArrayName, &out_DataType, &out_DataDimension, out_DimensionVector);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_ArrayName);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_DataType;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_DataDimension;
    }
    if (nlhs > 3) {
        plhs[4] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[4]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_array_read(in_A, io_data)
 *
 * The original C interface is
 * int cg_array_read(int A, void * data);
 */
EXTERN_C void cg_array_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_A;
    void * io_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    io_data = mxGetData(prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_array_read(in_A, io_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_array_read_as(in_A, in_type, io_data)
 *
 * The original C interface is
 * int cg_array_read_as(int A, CG_DataType_t type, void * data);
 */
EXTERN_C void cg_array_read_as_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_A;
    CG_DataType_t in_type;
    void * io_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument type");
    in_type = _get_numeric_scalar_int32(prhs[1]);

    io_data = mxGetData(prhs[2]);

    /******** Invoke computational function ********/
    ierr = cg_array_read_as(in_A, in_type, io_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_array_general_read(in_A, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_data)
 *
 * The original C interface is
 * int cg_array_general_read(int A, const long long * s_rmin, const long long * s_rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dimvals, const long long * m_rmin, const long long * m_rmax, void * data);
 */
EXTERN_C void cg_array_general_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_A;
    long long * in_s_rmin;
    long long * in_s_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dimvals;
    long long * in_m_rmin;
    long long * in_m_rmax;
    void * io_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 9)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument A");
    in_A = _get_numeric_scalar_int32(prhs[0]);

    if (mxIsInt64(prhs[1]) || mxIsUint64(prhs[1]))
        in_s_rmin = (long long*)mxGetData(prhs[1]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmin");

    if (mxIsInt64(prhs[2]) || mxIsUint64(prhs[2]))
        in_s_rmax = (long long*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmax");

    if (_n_dims(prhs[3]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[3]);

    if (_n_dims(prhs[4]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[4]);

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_m_dimvals = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dimvals");

    if (mxIsInt64(prhs[6]) || mxIsUint64(prhs[6]))
        in_m_rmin = (long long*)mxGetData(prhs[6]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[7]) || mxIsUint64(prhs[7]))
        in_m_rmax = (long long*)mxGetData(prhs[7]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    io_data = mxGetData(prhs[8]);

    /******** Invoke computational function ********/
    ierr = cg_array_general_read(in_A, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_array_write(in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data)
 *
 * The original C interface is
 * int cg_array_write(const char * ArrayName, CG_DataType_t DataType, int DataDimension, const long long * DimensionVector, const void * Data);
 */
EXTERN_C void cg_array_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_ArrayName;
    CG_DataType_t in_DataType;
    int in_DataDimension;
    long long * in_DimensionVector;
    const void * in_Data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_DataDimension = _get_numeric_scalar_int32(prhs[2]);
    in_ArrayName = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataDimension");

    if (mxGetNumberOfElements(prhs[3]) < (int) (in_DataDimension) || _n_dims(prhs[3]) > 1)
        mexErrMsgTxt("Error in dimension of argument DimensionVector");
    if (mxIsInt64(prhs[3]) || mxIsUint64(prhs[3]))
        in_DimensionVector = (long long*)mxGetData(prhs[3]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument DimensionVector");

    in_Data = mxGetData(prhs[4]);

    /******** Invoke computational function ********/
    ierr = cg_array_write(in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data);


    /******** Free up input buffers. ********/
    _mxFreeString(in_ArrayName);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_array_general_write(in_arrayname, in_s_type, in_s_numdim, in_s_dimvals, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, in_data)
 *
 * The original C interface is
 * int cg_array_general_write(const char * arrayname, CG_DataType_t s_type, int s_numdim, const long long * s_dimvals, const long long * s_rmin, const long long * s_rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dimvals, const long long * m_rmin, const long long * m_rmax, const void * data);
 */
EXTERN_C void cg_array_general_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_arrayname;
    CG_DataType_t in_s_type;
    int in_s_numdim;
    long long * in_s_dimvals;
    long long * in_s_rmin;
    long long * in_s_rmax;
    CG_DataType_t in_m_type;
    int in_m_numdim;
    long long * in_m_dimvals;
    long long * in_m_rmin;
    long long * in_m_rmax;
    const void * in_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 12)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_arrayname = _mxGetString(prhs[0], NULL);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument s_type");
    in_s_type = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument s_numdim");
    in_s_numdim = _get_numeric_scalar_int32(prhs[2]);

    if (mxIsInt64(prhs[3]) || mxIsUint64(prhs[3]))
        in_s_dimvals = (long long*)mxGetData(prhs[3]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_dimvals");

    if (mxIsInt64(prhs[4]) || mxIsUint64(prhs[4]))
        in_s_rmin = (long long*)mxGetData(prhs[4]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmin");

    if (mxIsInt64(prhs[5]) || mxIsUint64(prhs[5]))
        in_s_rmax = (long long*)mxGetData(prhs[5]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument s_rmax");

    if (_n_dims(prhs[6]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_type");
    in_m_type = _get_numeric_scalar_int32(prhs[6]);

    if (_n_dims(prhs[7]) > 0)
        mexErrMsgTxt("Error in dimension of argument m_numdim");
    in_m_numdim = _get_numeric_scalar_int32(prhs[7]);

    if (mxIsInt64(prhs[8]) || mxIsUint64(prhs[8]))
        in_m_dimvals = (long long*)mxGetData(prhs[8]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_dimvals");

    if (mxIsInt64(prhs[9]) || mxIsUint64(prhs[9]))
        in_m_rmin = (long long*)mxGetData(prhs[9]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmin");

    if (mxIsInt64(prhs[10]) || mxIsUint64(prhs[10]))
        in_m_rmax = (long long*)mxGetData(prhs[10]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument m_rmax");

    in_data = mxGetData(prhs[11]);

    /******** Invoke computational function ********/
    ierr = cg_array_general_write(in_arrayname, in_s_type, in_s_numdim, in_s_dimvals, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, in_data);


    /******** Free up input buffers. ********/
    _mxFreeString(in_arrayname);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nuser_data, ierr] = cg_nuser_data()
 *
 * The original C interface is
 * int cg_nuser_data(int * nuser_data);
 */
EXTERN_C void cg_nuser_data_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nuser_data;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nuser_data(&out_nuser_data);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nuser_data;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_user_data_name, ierr] = cg_user_data_read(in_Index)
 *
 * The original C interface is
 * int cg_user_data_read(int Index, char * user_data_name);
 */
EXTERN_C void cg_user_data_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_Index;
    char out_user_data_name[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Index");
    in_Index = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_user_data_read(in_Index, out_user_data_name);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_user_data_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_user_data_write(in_user_data_name)
 *
 * The original C interface is
 * int cg_user_data_write(const char * user_data_name);
 */
EXTERN_C void cg_user_data_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_user_data_name;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_user_data_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_user_data_write(in_user_data_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_user_data_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nintegrals, ierr] = cg_nintegrals()
 *
 * The original C interface is
 * int cg_nintegrals(int * nintegrals);
 */
EXTERN_C void cg_nintegrals_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nintegrals;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nintegrals(&out_nintegrals);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_nintegrals;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_IntegralDataName, ierr] = cg_integral_read(in_IntegralDataIndex)
 *
 * The original C interface is
 * int cg_integral_read(int IntegralDataIndex, char * IntegralDataName);
 */
EXTERN_C void cg_integral_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_IntegralDataIndex;
    char out_IntegralDataName[33];
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument IntegralDataIndex");
    in_IntegralDataIndex = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_integral_read(in_IntegralDataIndex, out_IntegralDataName);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_IntegralDataName);
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_integral_write(in_IntegralDataName)
 *
 * The original C interface is
 * int cg_integral_write(const char * IntegralDataName);
 */
EXTERN_C void cg_integral_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_IntegralDataName;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_IntegralDataName = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_integral_write(in_IntegralDataName);


    /******** Free up input buffers. ********/
    _mxFreeString(in_IntegralDataName);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_rind_read(io_RindData)
 *
 * The original C interface is
 * int cg_rind_read(int * RindData);
 */
EXTERN_C void cg_rind_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * io_RindData;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_RindData = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument RindData");


    /******** Invoke computational function ********/
    ierr = cg_rind_read(io_RindData);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_rind_write(in_RindData)
 *
 * The original C interface is
 * int cg_rind_write(const int * RindData);
 */
EXTERN_C void cg_rind_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * in_RindData;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        in_RindData = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument RindData");


    /******** Invoke computational function ********/
    ierr = cg_rind_write(in_RindData);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ndescriptors, ierr] = cg_ndescriptors()
 *
 * The original C interface is
 * int cg_ndescriptors(int * ndescriptors);
 */
EXTERN_C void cg_ndescriptors_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_ndescriptors;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ndescriptors(&out_ndescriptors);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ndescriptors;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = ierr;
    }
}

/* Gateway function
 * [out_descr_name, out_descr_text, ierr] = cg_descriptor_read(in_descr_no)
 *
 * The original C interface is
 * int cg_descriptor_read(int descr_no, char * descr_name, char ** descr_text);
 */
EXTERN_C void cg_descriptor_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_descr_no;
    char out_descr_name[33];
    char * out_descr_text;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument descr_no");
    in_descr_no = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_descriptor_read(in_descr_no, out_descr_name, &out_descr_text);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_descr_name);
    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_descr_text);
    }
    cg_free(out_descr_text);

    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_descriptor_write(in_descr_name, in_descr_text)
 *
 * The original C interface is
 * int cg_descriptor_write(const char * descr_name, const char * descr_text);
 */
EXTERN_C void cg_descriptor_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_descr_name;
    char * in_descr_text;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_descr_name = _mxGetString(prhs[0], NULL);

    in_descr_text = _mxGetString(prhs[1], NULL);


    /******** Invoke computational function ********/
    ierr = cg_descriptor_write(in_descr_name, in_descr_text);


    /******** Free up input buffers. ********/
    _mxFreeString(in_descr_name);
    _mxFreeString(in_descr_text);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_nunits, ierr] = cg_nunits()
 *
 * The original C interface is
 * int cg_nunits(int * nunits);
 */
EXTERN_C void cg_nunits_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_nunits;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_nunits(&out_nunits);


    /******** Process output scalars and strings ********/
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
 * int cg_units_read(CG_MassUnits_t * mass, CG_LengthUnits_t * length, CG_TimeUnits_t * time, CG_TemperatureUnits_t * temperature, CG_AngleUnits_t * angle);
 */
EXTERN_C void cg_units_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_MassUnits_t out_mass;
    CG_LengthUnits_t out_length;
    CG_TimeUnits_t out_time;
    CG_TemperatureUnits_t out_temperature;
    CG_AngleUnits_t out_angle;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 6 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_units_read(&out_mass, &out_length, &out_time, &out_temperature, &out_angle);


    /******** Process output scalars and strings ********/
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
 * int cg_units_write(CG_MassUnits_t mass, CG_LengthUnits_t length, CG_TimeUnits_t time, CG_TemperatureUnits_t temperature, CG_AngleUnits_t angle);
 */
EXTERN_C void cg_units_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_MassUnits_t in_mass;
    CG_LengthUnits_t in_length;
    CG_TimeUnits_t in_time;
    CG_TemperatureUnits_t in_temperature;
    CG_AngleUnits_t in_angle;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_mass, out_length, out_time, out_temperature, out_angle, out_current, out_amount, out_intensity, ierr] = cg_unitsfull_read()
 *
 * The original C interface is
 * int cg_unitsfull_read(CG_MassUnits_t * mass, CG_LengthUnits_t * length, CG_TimeUnits_t * time, CG_TemperatureUnits_t * temperature, CG_AngleUnits_t * angle, CG_ElectricCurrentUnits_t * current, CG_SubstanceAmountUnits_t * amount, CG_LuminousIntensityUnits_t * intensity);
 */
EXTERN_C void cg_unitsfull_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_MassUnits_t out_mass;
    CG_LengthUnits_t out_length;
    CG_TimeUnits_t out_time;
    CG_TemperatureUnits_t out_temperature;
    CG_AngleUnits_t out_angle;
    CG_ElectricCurrentUnits_t out_current;
    CG_SubstanceAmountUnits_t out_amount;
    CG_LuminousIntensityUnits_t out_intensity;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 9 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_unitsfull_read(&out_mass, &out_length, &out_time, &out_temperature, &out_angle, &out_current, &out_amount, &out_intensity);


    /******** Process output scalars and strings ********/
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
 * int cg_unitsfull_write(CG_MassUnits_t mass, CG_LengthUnits_t length, CG_TimeUnits_t time, CG_TemperatureUnits_t temperature, CG_AngleUnits_t angle, CG_ElectricCurrentUnits_t current, CG_SubstanceAmountUnits_t amount, CG_LuminousIntensityUnits_t intensity);
 */
EXTERN_C void cg_unitsfull_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_MassUnits_t in_mass;
    CG_LengthUnits_t in_length;
    CG_TimeUnits_t in_time;
    CG_TemperatureUnits_t in_temperature;
    CG_AngleUnits_t in_angle;
    CG_ElectricCurrentUnits_t in_current;
    CG_SubstanceAmountUnits_t in_amount;
    CG_LuminousIntensityUnits_t in_intensity;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 8)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
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


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_DataType, ierr] = cg_exponents_info()
 *
 * The original C interface is
 * int cg_exponents_info(CG_DataType_t * DataType);
 */
EXTERN_C void cg_exponents_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t out_DataType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_exponents_info(&out_DataType);


    /******** Process output scalars and strings ********/
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
 * int cg_nexponents(int * numexp);
 */
EXTERN_C void cg_nexponents_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int * io_numexp;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt32(prhs[0]) || mxIsUint32(prhs[0]))
        io_numexp = (int*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 32-bit integer matrix for argument numexp");


    /******** Invoke computational function ********/
    ierr = cg_nexponents(io_numexp);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_exponents_read(io_exponents)
 *
 * The original C interface is
 * int cg_exponents_read(void * exponents);
 */
EXTERN_C void cg_exponents_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    void * io_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    io_exponents = mxGetData(prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_exponents_read(io_exponents);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_exponents_write(in_DataType, in_exponents)
 *
 * The original C interface is
 * int cg_exponents_write(CG_DataType_t DataType, const void * exponents);
 */
EXTERN_C void cg_exponents_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t in_DataType;
    const void * in_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_exponents = mxGetData(prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_exponents_write(in_DataType, in_exponents);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_expfull_read(io_exponents)
 *
 * The original C interface is
 * int cg_expfull_read(void * exponents);
 */
EXTERN_C void cg_expfull_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    void * io_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    io_exponents = mxGetData(prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_expfull_read(io_exponents);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_expfull_write(in_DataType, in_exponents)
 *
 * The original C interface is
 * int cg_expfull_write(CG_DataType_t DataType, const void * exponents);
 */
EXTERN_C void cg_expfull_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t in_DataType;
    const void * in_exponents;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_exponents = mxGetData(prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_expfull_write(in_DataType, in_exponents);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_DataType, ierr] = cg_conversion_info()
 *
 * The original C interface is
 * int cg_conversion_info(CG_DataType_t * DataType);
 */
EXTERN_C void cg_conversion_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t out_DataType;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_conversion_info(&out_DataType);


    /******** Process output scalars and strings ********/
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
 * int cg_conversion_read(void * ConversionFactors);
 */
EXTERN_C void cg_conversion_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    void * io_ConversionFactors;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    io_ConversionFactors = mxGetData(prhs[0]);

    /******** Invoke computational function ********/
    ierr = cg_conversion_read(io_ConversionFactors);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_conversion_write(in_DataType, in_ConversionFactors)
 *
 * The original C interface is
 * int cg_conversion_write(CG_DataType_t DataType, const void * ConversionFactors);
 */
EXTERN_C void cg_conversion_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataType_t in_DataType;
    const void * in_ConversionFactors;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument DataType");
    in_DataType = _get_numeric_scalar_int32(prhs[0]);

    in_ConversionFactors = mxGetData(prhs[1]);

    /******** Invoke computational function ********/
    ierr = cg_conversion_write(in_DataType, in_ConversionFactors);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_dataclass, ierr] = cg_dataclass_read()
 *
 * The original C interface is
 * int cg_dataclass_read(CG_DataClass_t * dataclass);
 */
EXTERN_C void cg_dataclass_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataClass_t out_dataclass;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_dataclass_read(&out_dataclass);


    /******** Process output scalars and strings ********/
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
 * int cg_dataclass_write(CG_DataClass_t dataclass);
 */
EXTERN_C void cg_dataclass_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_DataClass_t in_dataclass;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument dataclass");
    in_dataclass = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_dataclass_write(in_dataclass);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_GridLocation, ierr] = cg_gridlocation_read()
 *
 * The original C interface is
 * int cg_gridlocation_read(CG_GridLocation_t * GridLocation);
 */
EXTERN_C void cg_gridlocation_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GridLocation_t out_GridLocation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_gridlocation_read(&out_GridLocation);


    /******** Process output scalars and strings ********/
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
 * int cg_gridlocation_write(CG_GridLocation_t GridLocation);
 */
EXTERN_C void cg_gridlocation_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_GridLocation_t in_GridLocation;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument GridLocation");
    in_GridLocation = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_gridlocation_write(in_GridLocation);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_Ordinal, ierr] = cg_ordinal_read()
 *
 * The original C interface is
 * int cg_ordinal_read(int * Ordinal);
 */
EXTERN_C void cg_ordinal_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_Ordinal;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ordinal_read(&out_Ordinal);


    /******** Process output scalars and strings ********/
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
 * int cg_ordinal_write(int Ordinal);
 */
EXTERN_C void cg_ordinal_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int in_Ordinal;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument Ordinal");
    in_Ordinal = _get_numeric_scalar_int32(prhs[0]);


    /******** Invoke computational function ********/
    ierr = cg_ordinal_write(in_Ordinal);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_ptset_type, out_npnts, ierr] = cg_ptset_info()
 *
 * The original C interface is
 * int cg_ptset_info(CG_PointSetType_t * ptset_type, long long * npnts);
 */
EXTERN_C void cg_ptset_info_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_PointSetType_t out_ptset_type;
    long long out_npnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_ptset_info(&out_ptset_type, &out_npnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_ptset_type;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
        *(long long*)mxGetData(plhs[1]) = out_npnts;
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
 * int cg_ptset_write(CG_PointSetType_t ptset_type, long long npnts, const long long * pnts);
 */
EXTERN_C void cg_ptset_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    CG_PointSetType_t in_ptset_type;
    long long in_npnts;
    long long * in_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument ptset_type");
    in_ptset_type = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument npnts");
    in_npnts = _get_numeric_scalar_int64(prhs[1]);

    if (mxIsInt64(prhs[2]) || mxIsUint64(prhs[2]))
        in_pnts = (long long*)mxGetData(prhs[2]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_ptset_write(in_ptset_type, in_npnts, in_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_ptset_read(io_pnts)
 *
 * The original C interface is
 * int cg_ptset_read(long long * pnts);
 */
EXTERN_C void cg_ptset_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    long long * io_pnts;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    if (mxIsInt64(prhs[0]) || mxIsUint64(prhs[0]))
        io_pnts = (long long*)mxGetData(prhs[0]);
    else
        mexErrMsgTxt("Expecting 64-bit integer matrix for argument pnts");


    /******** Invoke computational function ********/
    ierr = cg_ptset_read(io_pnts);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * [out_path_length, ierr] = cg_is_link()
 *
 * The original C interface is
 * int cg_is_link(int * path_length);
 */
EXTERN_C void cg_is_link_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    int out_path_length;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 2 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_is_link(&out_path_length);


    /******** Process output scalars and strings ********/
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
 * int cg_link_read(char ** filename, char ** link_path);
 */
EXTERN_C void cg_link_read_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * out_filename;
    char * out_link_path;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 3 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    ierr = cg_link_read(&out_filename, &out_link_path);


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(out_filename);
    cg_free(out_filename);

    if (nlhs > 1) {
        plhs[1] = mxCreateString(out_link_path);
    }
    cg_free(out_link_path);

    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = ierr;
    }
}

/* Gateway function
 * ierr = cg_link_write(in_nodename, in_filename, in_name_in_file)
 *
 * The original C interface is
 * int cg_link_write(const char * nodename, const char * filename, const char * name_in_file);
 */
EXTERN_C void cg_link_write_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_nodename;
    char * in_filename;
    char * in_name_in_file;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 3)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_nodename = _mxGetString(prhs[0], NULL);

    in_filename = _mxGetString(prhs[1], NULL);

    in_name_in_file = _mxGetString(prhs[2], NULL);


    /******** Invoke computational function ********/
    ierr = cg_link_write(in_nodename, in_filename, in_name_in_file);


    /******** Free up input buffers. ********/
    _mxFreeString(in_nodename);
    _mxFreeString(in_filename);
    _mxFreeString(in_name_in_file);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * ierr = cg_delete_node(in_node_name)
 *
 * The original C interface is
 * int cg_delete_node(const char * node_name);
 */
EXTERN_C void cg_delete_node_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    char * in_node_name;
    int ierr;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 1)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input and inout arguments ********/
    in_node_name = _mxGetString(prhs[0], NULL);


    /******** Invoke computational function ********/
    ierr = cg_delete_node(in_node_name);


    /******** Free up input buffers. ********/
    _mxFreeString(in_node_name);

    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function
 * msg = cg_get_error()
 *
 * The original C interface is
 * const char * cg_get_error();
 */
EXTERN_C void cg_get_error_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
    const char * msg;

    /******** Check number of input and output arguments. ********/
    if (nlhs > 1 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    msg = cg_get_error();


    /******** Process output scalars and strings ********/
    plhs[0] = mxCreateString(msg);
}

/* Gateway function
 * cg_error_exit()
 *
 * The original C interface is
 * void cg_error_exit();
 */
EXTERN_C void cg_error_exit_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {

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
 * void cg_error_print();
 */
EXTERN_C void cg_error_print_MeX(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {

    /******** Check number of input and output arguments. ********/
    if (nlhs > 0 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");


    /******** Invoke computational function ********/
    cg_error_print();

}

#include "cgnslib_mex_ext.c"

/* Main gateway function */
EXTERN_C void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {

    typedef void (*C2mex_func_ptr)(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]);

    int  func_id;
    static C2mex_func_ptr  fptrs[] = {
        NULL,
        /* 1 */ cg_is_cgns_MeX,
        /* 2 */ cg_open_MeX,
        /* 3 */ cg_version_MeX,
        /* 4 */ cg_precision_MeX,
        /* 5 */ cg_close_MeX,
        /* 6 */ cg_save_as_MeX,
        /* 7 */ cg_set_file_type_MeX,
        /* 8 */ cg_get_file_type_MeX,
        /* 9 */ cg_root_id_MeX,
        /* 10 */ cg_get_cgio_MeX,
        /* 11 */ cg_configure_MeX,
        /* 12 */ cg_set_compress_MeX,
        /* 13 */ cg_get_compress_MeX,
        /* 14 */ cg_set_path_MeX,
        /* 15 */ cg_add_path_MeX,
        /* 16 */ cg_MassUnitsName_MeX,
        /* 17 */ cg_LengthUnitsName_MeX,
        /* 18 */ cg_TimeUnitsName_MeX,
        /* 19 */ cg_TemperatureUnitsName_MeX,
        /* 20 */ cg_AngleUnitsName_MeX,
        /* 21 */ cg_ElectricCurrentUnitsName_MeX,
        /* 22 */ cg_SubstanceAmountUnitsName_MeX,
        /* 23 */ cg_LuminousIntensityUnitsName_MeX,
        /* 24 */ cg_DataClassName_MeX,
        /* 25 */ cg_GridLocationName_MeX,
        /* 26 */ cg_BCDataTypeName_MeX,
        /* 27 */ cg_GridConnectivityTypeName_MeX,
        /* 28 */ cg_PointSetTypeName_MeX,
        /* 29 */ cg_GoverningEquationsTypeName_MeX,
        /* 30 */ cg_ModelTypeName_MeX,
        /* 31 */ cg_BCTypeName_MeX,
        /* 32 */ cg_DataTypeName_MeX,
        /* 33 */ cg_ElementTypeName_MeX,
        /* 34 */ cg_ZoneTypeName_MeX,
        /* 35 */ cg_RigidGridMotionTypeName_MeX,
        /* 36 */ cg_ArbitraryGridMotionTypeName_MeX,
        /* 37 */ cg_SimulationTypeName_MeX,
        /* 38 */ cg_WallFunctionTypeName_MeX,
        /* 39 */ cg_AreaTypeName_MeX,
        /* 40 */ cg_AverageInterfaceTypeName_MeX,
        /* 41 */ cg_nbases_MeX,
        /* 42 */ cg_base_read_MeX,
        /* 43 */ cg_base_id_MeX,
        /* 44 */ cg_base_write_MeX,
        /* 45 */ cg_cell_dim_MeX,
        /* 46 */ cg_nzones_MeX,
        /* 47 */ cg_zone_read_MeX,
        /* 48 */ cg_zone_type_MeX,
        /* 49 */ cg_zone_id_MeX,
        /* 50 */ cg_zone_write_MeX,
        /* 51 */ cg_index_dim_MeX,
        /* 52 */ cg_nfamilies_MeX,
        /* 53 */ cg_family_read_MeX,
        /* 54 */ cg_family_write_MeX,
        /* 55 */ cg_nfamily_names_MeX,
        /* 56 */ cg_family_name_read_MeX,
        /* 57 */ cg_family_name_write_MeX,
        /* 58 */ cg_node_family_write_MeX,
        /* 59 */ cg_node_nfamilies_MeX,
        /* 60 */ cg_node_family_read_MeX,
        /* 61 */ cg_node_family_name_write_MeX,
        /* 62 */ cg_node_nfamily_names_MeX,
        /* 63 */ cg_node_family_name_read_MeX,
        /* 64 */ cg_famname_read_MeX,
        /* 65 */ cg_famname_write_MeX,
        /* 66 */ cg_nmultifam_MeX,
        /* 67 */ cg_multifam_read_MeX,
        /* 68 */ cg_multifam_write_MeX,
        /* 69 */ cg_fambc_read_MeX,
        /* 70 */ cg_fambc_write_MeX,
        /* 71 */ cg_node_fambc_read_MeX,
        /* 72 */ cg_node_fambc_write_MeX,
        /* 73 */ cg_geo_read_MeX,
        /* 74 */ cg_geo_write_MeX,
        /* 75 */ cg_node_geo_read_MeX,
        /* 76 */ cg_node_geo_write_MeX,
        /* 77 */ cg_part_read_MeX,
        /* 78 */ cg_part_write_MeX,
        /* 79 */ cg_node_part_read_MeX,
        /* 80 */ cg_node_part_write_MeX,
        /* 81 */ cg_ngrids_MeX,
        /* 82 */ cg_grid_read_MeX,
        /* 83 */ cg_grid_write_MeX,
        /* 84 */ cg_grid_bounding_box_read_MeX,
        /* 85 */ cg_grid_bounding_box_write_MeX,
        /* 86 */ cg_ncoords_MeX,
        /* 87 */ cg_coord_info_MeX,
        /* 88 */ cg_coord_read_MeX,
        /* 89 */ cg_coord_general_read_MeX,
        /* 90 */ cg_coord_id_MeX,
        /* 91 */ cg_coord_write_MeX,
        /* 92 */ cg_coord_partial_write_MeX,
        /* 93 */ cg_coord_general_write_MeX,
        /* 94 */ cg_nsections_MeX,
        /* 95 */ cg_section_read_MeX,
        /* 96 */ cg_elements_read_MeX,
        /* 97 */ cg_poly_elements_read_MeX,
        /* 98 */ cg_section_write_MeX,
        /* 99 */ cg_poly_section_write_MeX,
        /* 100 */ cg_section_general_write_MeX,
        /* 101 */ cg_section_initialize_MeX,
        /* 102 */ cg_parent_data_write_MeX,
        /* 103 */ cg_npe_MeX,
        /* 104 */ cg_ElementDataSize_MeX,
        /* 105 */ cg_section_partial_write_MeX,
        /* 106 */ cg_elements_partial_write_MeX,
        /* 107 */ cg_elements_general_write_MeX,
        /* 108 */ cg_poly_elements_partial_write_MeX,
        /* 109 */ cg_poly_elements_general_write_MeX,
        /* 110 */ cg_parent_data_partial_write_MeX,
        /* 111 */ cg_elements_partial_read_MeX,
        /* 112 */ cg_poly_elements_partial_read_MeX,
        /* 113 */ cg_elements_general_read_MeX,
        /* 114 */ cg_poly_elements_general_read_MeX,
        /* 115 */ cg_parent_elements_general_read_MeX,
        /* 116 */ cg_parent_elements_position_general_read_MeX,
        /* 117 */ cg_ElementPartialSize_MeX,
        /* 118 */ cg_nsols_MeX,
        /* 119 */ cg_sol_info_MeX,
        /* 120 */ cg_sol_id_MeX,
        /* 121 */ cg_sol_write_MeX,
        /* 122 */ cg_sol_size_MeX,
        /* 123 */ cg_sol_ptset_info_MeX,
        /* 124 */ cg_sol_ptset_read_MeX,
        /* 125 */ cg_sol_ptset_write_MeX,
        /* 126 */ cg_nfields_MeX,
        /* 127 */ cg_field_info_MeX,
        /* 128 */ cg_field_read_MeX,
        /* 129 */ cg_field_general_read_MeX,
        /* 130 */ cg_field_id_MeX,
        /* 131 */ cg_field_write_MeX,
        /* 132 */ cg_field_partial_write_MeX,
        /* 133 */ cg_field_general_write_MeX,
        /* 134 */ cg_nsubregs_MeX,
        /* 135 */ cg_subreg_info_MeX,
        /* 136 */ cg_subreg_ptset_read_MeX,
        /* 137 */ cg_subreg_bcname_read_MeX,
        /* 138 */ cg_subreg_gcname_read_MeX,
        /* 139 */ cg_subreg_ptset_write_MeX,
        /* 140 */ cg_subreg_bcname_write_MeX,
        /* 141 */ cg_subreg_gcname_write_MeX,
        /* 142 */ cg_nzconns_MeX,
        /* 143 */ cg_zconn_read_MeX,
        /* 144 */ cg_zconn_write_MeX,
        /* 145 */ cg_zconn_get_MeX,
        /* 146 */ cg_zconn_set_MeX,
        /* 147 */ cg_nholes_MeX,
        /* 148 */ cg_hole_info_MeX,
        /* 149 */ cg_hole_read_MeX,
        /* 150 */ cg_hole_id_MeX,
        /* 151 */ cg_hole_write_MeX,
        /* 152 */ cg_nconns_MeX,
        /* 153 */ cg_conn_info_MeX,
        /* 154 */ cg_conn_read_MeX,
        /* 155 */ cg_conn_id_MeX,
        /* 156 */ cg_conn_write_MeX,
        /* 157 */ cg_conn_write_short_MeX,
        /* 158 */ cg_conn_read_short_MeX,
        /* 159 */ cg_n1to1_MeX,
        /* 160 */ cg_1to1_read_MeX,
        /* 161 */ cg_1to1_id_MeX,
        /* 162 */ cg_1to1_write_MeX,
        /* 163 */ cg_n1to1_global_MeX,
        /* 164 */ cg_1to1_read_global_MeX,
        /* 165 */ cg_nbocos_MeX,
        /* 166 */ cg_boco_info_MeX,
        /* 167 */ cg_boco_read_MeX,
        /* 168 */ cg_boco_id_MeX,
        /* 169 */ cg_boco_write_MeX,
        /* 170 */ cg_boco_normal_write_MeX,
        /* 171 */ cg_boco_gridlocation_read_MeX,
        /* 172 */ cg_boco_gridlocation_write_MeX,
        /* 173 */ cg_dataset_read_MeX,
        /* 174 */ cg_dataset_write_MeX,
        /* 175 */ cg_bcdataset_write_MeX,
        /* 176 */ cg_bcdataset_info_MeX,
        /* 177 */ cg_bcdataset_read_MeX,
        /* 178 */ cg_bcdata_write_MeX,
        /* 179 */ cg_ndiscrete_MeX,
        /* 180 */ cg_discrete_read_MeX,
        /* 181 */ cg_discrete_write_MeX,
        /* 182 */ cg_discrete_size_MeX,
        /* 183 */ cg_discrete_ptset_info_MeX,
        /* 184 */ cg_discrete_ptset_read_MeX,
        /* 185 */ cg_discrete_ptset_write_MeX,
        /* 186 */ cg_n_rigid_motions_MeX,
        /* 187 */ cg_rigid_motion_read_MeX,
        /* 188 */ cg_rigid_motion_write_MeX,
        /* 189 */ cg_n_arbitrary_motions_MeX,
        /* 190 */ cg_arbitrary_motion_read_MeX,
        /* 191 */ cg_arbitrary_motion_write_MeX,
        /* 192 */ cg_simulation_type_read_MeX,
        /* 193 */ cg_simulation_type_write_MeX,
        /* 194 */ cg_biter_read_MeX,
        /* 195 */ cg_biter_write_MeX,
        /* 196 */ cg_ziter_read_MeX,
        /* 197 */ cg_ziter_write_MeX,
        /* 198 */ cg_gravity_read_MeX,
        /* 199 */ cg_gravity_write_MeX,
        /* 200 */ cg_axisym_read_MeX,
        /* 201 */ cg_axisym_write_MeX,
        /* 202 */ cg_rotating_read_MeX,
        /* 203 */ cg_rotating_write_MeX,
        /* 204 */ cg_bc_wallfunction_read_MeX,
        /* 205 */ cg_bc_wallfunction_write_MeX,
        /* 206 */ cg_bc_area_read_MeX,
        /* 207 */ cg_bc_area_write_MeX,
        /* 208 */ cg_conn_periodic_read_MeX,
        /* 209 */ cg_conn_periodic_write_MeX,
        /* 210 */ cg_1to1_periodic_write_MeX,
        /* 211 */ cg_1to1_periodic_read_MeX,
        /* 212 */ cg_conn_average_read_MeX,
        /* 213 */ cg_conn_average_write_MeX,
        /* 214 */ cg_1to1_average_write_MeX,
        /* 215 */ cg_1to1_average_read_MeX,
        /* 216 */ cg_goto_MeX,
        /* 217 */ cg_gorel_MeX,
        /* 218 */ cg_gopath_MeX,
        /* 219 */ cg_golist_MeX,
        /* 220 */ cg_where_MeX,
        /* 221 */ cg_convergence_read_MeX,
        /* 222 */ cg_convergence_write_MeX,
        /* 223 */ cg_state_read_MeX,
        /* 224 */ cg_state_write_MeX,
        /* 225 */ cg_equationset_read_MeX,
        /* 226 */ cg_equationset_chemistry_read_MeX,
        /* 227 */ cg_equationset_elecmagn_read_MeX,
        /* 228 */ cg_equationset_write_MeX,
        /* 229 */ cg_governing_read_MeX,
        /* 230 */ cg_governing_write_MeX,
        /* 231 */ cg_diffusion_read_MeX,
        /* 232 */ cg_diffusion_write_MeX,
        /* 233 */ cg_model_read_MeX,
        /* 234 */ cg_model_write_MeX,
        /* 235 */ cg_narrays_MeX,
        /* 236 */ cg_array_info_MeX,
        /* 237 */ cg_array_read_MeX,
        /* 238 */ cg_array_read_as_MeX,
        /* 239 */ cg_array_general_read_MeX,
        /* 240 */ cg_array_write_MeX,
        /* 241 */ cg_array_general_write_MeX,
        /* 242 */ cg_nuser_data_MeX,
        /* 243 */ cg_user_data_read_MeX,
        /* 244 */ cg_user_data_write_MeX,
        /* 245 */ cg_nintegrals_MeX,
        /* 246 */ cg_integral_read_MeX,
        /* 247 */ cg_integral_write_MeX,
        /* 248 */ cg_rind_read_MeX,
        /* 249 */ cg_rind_write_MeX,
        /* 250 */ cg_ndescriptors_MeX,
        /* 251 */ cg_descriptor_read_MeX,
        /* 252 */ cg_descriptor_write_MeX,
        /* 253 */ cg_nunits_MeX,
        /* 254 */ cg_units_read_MeX,
        /* 255 */ cg_units_write_MeX,
        /* 256 */ cg_unitsfull_read_MeX,
        /* 257 */ cg_unitsfull_write_MeX,
        /* 258 */ cg_exponents_info_MeX,
        /* 259 */ cg_nexponents_MeX,
        /* 260 */ cg_exponents_read_MeX,
        /* 261 */ cg_exponents_write_MeX,
        /* 262 */ cg_expfull_read_MeX,
        /* 263 */ cg_expfull_write_MeX,
        /* 264 */ cg_conversion_info_MeX,
        /* 265 */ cg_conversion_read_MeX,
        /* 266 */ cg_conversion_write_MeX,
        /* 267 */ cg_dataclass_read_MeX,
        /* 268 */ cg_dataclass_write_MeX,
        /* 269 */ cg_gridlocation_read_MeX,
        /* 270 */ cg_gridlocation_write_MeX,
        /* 271 */ cg_ordinal_read_MeX,
        /* 272 */ cg_ordinal_write_MeX,
        /* 273 */ cg_ptset_info_MeX,
        /* 274 */ cg_ptset_write_MeX,
        /* 275 */ cg_ptset_read_MeX,
        /* 276 */ cg_is_link_MeX,
        /* 277 */ cg_link_read_MeX,
        /* 278 */ cg_link_write_MeX,
        /* 279 */ cg_delete_node_MeX,
        /* 280 */ cg_get_error_MeX,
        /* 281 */ cg_error_exit_MeX,
        /* 282 */ cg_error_print_MeX
    };

    /******** Check function selector argument. ********/
    if (nrhs < 1 || !mxIsInt32(prhs[0]) || mxGetNumberOfElements(prhs[0])!=1)
        mexErrMsgTxt("Invalid functiin selector.\n");

    func_id = *(int*)mxGetData(prhs[0]);

    if (func_id < 1 || func_id > 282)
        mexErrMsgTxt("Function selector is out of bound.\n");

    /******** Invoke the function. ********/
    (*fptrs[func_id])(nlhs, plhs, nrhs-1, &prhs[1]);
}
