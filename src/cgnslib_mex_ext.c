/*
 * This file was created manually for MATLAB & Octave from 
 * cgnslib_3.1/cgnslib.h by Xiangmin Jiao. 
 * For bug reports, email jiao@ams.sunysb.edu.
 */

#include "c2mex.h"   /* This includes "mex.h". */

#include "cgnslib_3.1/cgnslib.h"
#include <string.h>
#include <assert.h>

#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C
#endif

/* Gateway function 
 * [out_connectname, out_zonename, out_donorname, out_range, out_donor_range, out_transform, ierr] = cg_1to1_read_global(in_fn, in_B)
 *
 * The original C interface is 
 * int cg_1to1_read_global( int fn, int B, char ** connectname, char ** zonename, char ** donorname, int ** range, int ** donor_range, int ** transform);
 */
EXTERN_C void cg_1to1_read_global_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[])
{
    int in_fn;
    int in_B;
    char *buf_char, **ptr_connectname, **ptr_zonename, **ptr_donorname;
    int *buf_int, **ptr_transform;
    cgsize_t *buf_cgsize, **ptr_range, **ptr_donor_range;
    int ierr, i, n1to1;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 7 || nrhs != 2)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument fn");
    in_fn = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    ierr = cg_n1to1_global( in_fn, in_B, &n1to1);
    if (ierr) {
        mexErrMsgTxt("Error in calling cg_n1to1_global.");
    }

    buf_char = (char*)mxCalloc( 3*n1to1*33, sizeof(char));
    buf_cgsize = (cgsize_t*)mxCalloc( 2*n1to1*6, sizeof(cgsize_t));
    buf_int = (int*)mxCalloc( n1to1*6, sizeof(int));

    ptr_connectname = (char**)mxCalloc( 6*n1to1, sizeof(void *));
    ptr_zonename    = ptr_connectname + n1to1;
    ptr_donorname   = ptr_connectname + 2*n1to1;
    ptr_range       = (cgsize_t**)ptr_connectname + 3*n1to1;
    ptr_donor_range = (cgsize_t**)ptr_connectname + 4*n1to1;
    ptr_transform   = (int**)ptr_connectname + 5*n1to1;

    for (i=0; i<n1to1; ++i) {
        ptr_connectname[i] = buf_char + i*33;
        ptr_zonename[i]    = buf_char + (i+n1to1)*33;
        ptr_donorname[i]   = buf_char + (i+2*n1to1)*33;

        ptr_transform[i]   = buf_int + i*6;
        ptr_range[i]       = buf_cgsize + i*6;
        ptr_donor_range[i] = buf_cgsize + (i+n1to1)*6;
    }

    /******** Invoke computational function ********/
    ierr = cg_1to1_read_global(in_fn, in_B, ptr_connectname, ptr_zonename, ptr_donorname, 
                               ptr_range, ptr_donor_range, ptr_transform);

    /******** Process output arguments ********/
    plhs[0] = mxCreateCellMatrix(n1to1,1);

    for( i=0; i<n1to1; i++) {
        mxSetCell(plhs[0],i,mxCreateString(ptr_connectname[i]));
    }

    if (nlhs > 1) {
        plhs[1] = mxCreateCellMatrix(n1to1,1);

        for( i=0; i<n1to1; i++) {
            mxSetCell(plhs[1],i,mxCreateString(ptr_zonename[i]));
        }
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateCellMatrix(n1to1,1);

        for( i=0; i<n1to1; i++) {
            mxSetCell(plhs[2],i,mxCreateString(ptr_donorname[i]));
        }
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateCellMatrix(n1to1,1);

        for( i=0; i<n1to1; i++) {
            mxArray *arr = mxCreateNumericMatrix( 6,1, mxINT32_CLASS, mxREAL);
            mxSetCell(plhs[3],i,arr);
            memcpy( (cgsize_t*)mxGetData(arr), ptr_range[i], 6*sizeof(cgsize_t));
        }
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateCellMatrix(n1to1,1);

        for( i=0; i<n1to1; i++) {
            mxArray *arr = mxCreateNumericMatrix( 6,1, sizeof(cgsize_t)==8?mxINT64_CLASS:mxINT32_CLASS, mxREAL);
            mxSetCell(plhs[4],i,arr);
            memcpy( (cgsize_t*)mxGetData(arr), ptr_donor_range[i], 6*sizeof(cgsize_t));
        }
    }
    if (nlhs > 5) {
        plhs[5] = mxCreateCellMatrix(n1to1,1);

        for( i=0; i<n1to1; i++) {
            mxArray *arr = mxCreateNumericMatrix( 3,1, mxINT32_CLASS, mxREAL);
            mxSetCell(plhs[5],i,arr);
            memcpy( (int*)mxGetData(arr), ptr_transform[i], 3*sizeof(int));
        }
    }

    if (nlhs > 6) {
        plhs[6] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[6]) = ierr;
    }

    /******** Deallocate buffer space. ********/
    mxFree( buf_char);
    mxFree( buf_int);
    mxFree( buf_cgsize);
    mxFree( ptr_donor_range);
}

/* Gateway function 
 * [out_file_number, out_B, out_depth, out_label, out_num, ierr] = cg_where
 *
 * The original C interface is 
 * int cg_where( int * file_number, int * B, int * depth, char ** label, int * num);
 */
EXTERN_C void cg_where_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[])
{
    int out_file_number;
    int out_B;
    int out_depth;
    char buf_label[CG_MAX_GOTO_DEPTH][33], *ptr_label[CG_MAX_GOTO_DEPTH];
    int out_num[CG_MAX_GOTO_DEPTH];
    int i,ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 6 || nrhs != 0)
        mexErrMsgTxt("Wrong number of arguments to function ");

    memset(buf_label, 0, CG_MAX_GOTO_DEPTH*33);
    for (i=0; i<CG_MAX_GOTO_DEPTH; ++i) {
        ptr_label[i] = &buf_label[i][0];
    }

    /******** Invoke computational function ********/
    ierr = cg_where(&out_file_number, &out_B, &out_depth, ptr_label, out_num);


    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = out_file_number;
    if (nlhs > 1) {
        plhs[1] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[1]) = out_B;
    }
    if (nlhs > 2) {
        plhs[2] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[2]) = out_depth;
    }
    if (nlhs > 3) {
        plhs[3] = mxCreateCellMatrix(out_depth,1);

        for( i=0; i<out_depth; i++) {
            mxSetCell(plhs[3],i,mxCreateString(ptr_label[i]));
        }
    }
    if (nlhs > 4) {
        plhs[4] = mxCreateNumericMatrix(out_depth, 1, mxINT32_CLASS, mxREAL);
        memcpy( (int*)mxGetData(plhs[4]), out_num, out_depth*sizeof(int));
    }

    if (nlhs > 5) {
        plhs[5] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
        *(int*)mxGetData(plhs[5]) = ierr;
    }
}

/* Gateway function 
 * ierr = cg_goto(file_number, B, varargin)
 *
 * The original C interface is 
 * int cg_goto( int file_number, int B, ..., "end");
 */
EXTERN_C void cg_goto_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[])
{
#define MAX_DEPTH 4
    int in_file_number;
    int in_B;
    char *in_labels[MAX_DEPTH];
    int   in_indices[MAX_DEPTH];
    int   ierr;
    int   i, index, depth = (nrhs-2)/2;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs < 2 || depth>MAX_DEPTH)
        mexErrMsgTxt("Wrong number of arguments to function.");

    /******** If the number of input is odd, check whether end with "end". ********/ 
    if (nrhs % 2 == 1 && mxGetNumberOfElements(prhs[nrhs-1])) {
        char *endmark = _mxGetString(prhs[nrhs-1], NULL);
        if ( !strcmp(endmark, "end")) {
            _mxFreeString(endmark);
            mexErrMsgTxt("For odd-number of inputs, arguments must end with 'end'.");
        }
        _mxFreeString(endmark);
    }

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number.");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B.");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    index=2;
    for (i=0; i<depth; ++i) {
        in_labels[i] = _mxGetString(prhs[index++], NULL);
        
        if (_n_dims(prhs[index]) > 0)
            mexErrMsgTxt("Error in dimension of an index argument in varargin");
        in_indices[i] =  _get_numeric_scalar_int32(prhs[index++]);
    }

    /******** Invoke computational function ********/
    switch (depth) {
    case 0: 
        ierr = cg_goto(in_file_number, in_B, NULL); break;
    case 1:
        ierr = cg_goto(in_file_number, in_B, in_labels[0], in_indices[0], NULL); break;
    case 2:
        ierr = cg_goto(in_file_number, in_B, in_labels[0], in_indices[0], 
                       in_labels[1], in_indices[1],  NULL); break;
    case 3:
        ierr = cg_goto(in_file_number, in_B, in_labels[0], in_indices[0], 
                       in_labels[1], in_indices[1], in_labels[2], in_indices[2], 
                       NULL); break;
    case 4:
        ierr = cg_goto(in_file_number, in_B, in_labels[0], in_indices[0], 
                       in_labels[1], in_indices[1], in_labels[2], in_indices[2], 
                       in_labels[3], in_indices[3], NULL); break;
    default:
        assert(0); /* It should never reach here */
    }

    /******** free up input buffers. ********/
    for (i=0; i<depth; ++i) {
        _mxFreeString(in_labels[i]);
    }

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_gorel(file_number, varargin)
 *
 * The original C interface is 
 * int cg_gorel( int file_number, ..., "end");
 */
EXTERN_C void cg_gorel_MeX(int nlhs, mxArray *plhs[], 
    int nrhs, const mxArray *prhs[])
{
#define MAX_DEPTH 4
    int in_file_number;
    char *in_labels[MAX_DEPTH];
    int   in_indices[MAX_DEPTH];
    int   ierr;
    int   i, index, depth = (nrhs-1)/2;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs < 1 || depth>MAX_DEPTH)
        mexErrMsgTxt("Wrong number of arguments to function.");

    /******** If the number of input is odd, check whether end with "end". ********/ 
    if (nrhs % 2 == 0 && mxGetNumberOfElements(prhs[nrhs-1])) {
        char *endmark = _mxGetString(prhs[nrhs-1], NULL);
        if ( !strcmp(endmark, "end")) {
            _mxFreeString(endmark);
            mexErrMsgTxt("For even-number of inputs, arguments must end with 'end'.");
        }
        _mxFreeString(endmark);
    }

    /******** Obtain input arguments ********/
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number.");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    index=1;
    for (i=0; i<depth; ++i) {
        in_labels[i] = _mxGetString(prhs[index++], NULL);
        
        if (_n_dims(prhs[index]) > 0)
            mexErrMsgTxt("Error in dimension of an index argument in varargin");
        in_indices[i] =  _get_numeric_scalar_int32(prhs[index++]);
    }

    /******** Invoke computational function ********/
    switch (depth) {
    case 0: 
        ierr = cg_gorel(in_file_number, "end"); break;
    case 1:
        ierr = cg_gorel(in_file_number, in_labels[0], in_indices[0], "end"); break;
    case 2:
        ierr = cg_gorel(in_file_number, in_labels[0], in_indices[0], 
                        in_labels[1], in_indices[1],  "end"); break;
    case 3:
        ierr = cg_gorel(in_file_number, in_labels[0], in_indices[0], 
                        in_labels[1], in_indices[1], in_labels[2], in_indices[2], 
                        "end"); break;
    case 4:
        ierr = cg_gorel(in_file_number, in_labels[0], in_indices[0], 
                        in_labels[1], in_indices[1], in_labels[2], in_indices[2], 
                        in_labels[3], in_indices[3], "end"); break;
    default:
        assert(0); /* It should never reach here */
    }

    /******** free up input buffers. ********/
    for (i=0; i<depth; ++i) {
        _mxFreeString(in_labels[i]);
    }

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}

/* Gateway function 
 * ierr = cg_golist(in_file_number, in_B, in_depth, in_label, in_num) 
 *
 * The original C interface is 
 * int cg_golist( int file_number, int B, int depth, char ** label, int * num);
 */
EXTERN_C void cg_golist_MeX(int nlhs, mxArray *plhs[], int nrhs, 
    const mxArray *prhs[])
{
    int in_file_number;
    int in_B;
    int in_depth;
    char * in_label;
    int * in_num;
    int ierr;

    /******** Check number of input and output arguments. ********/ 
    if (nlhs > 1 || nrhs != 5)
        mexErrMsgTxt("Wrong number of arguments to function ");

    /******** Obtain input arguments ********/
    in_depth = _get_numeric_scalar_int32(prhs[2]);
    if (_n_dims(prhs[0]) > 0)
        mexErrMsgTxt("Error in dimension of argument file_number");
    in_file_number = _get_numeric_scalar_int32(prhs[0]);

    if (_n_dims(prhs[1]) > 0)
        mexErrMsgTxt("Error in dimension of argument B");
    in_B = _get_numeric_scalar_int32(prhs[1]);

    if (_n_dims(prhs[2]) > 0)
        mexErrMsgTxt("Error in dimension of argument depth");

    if (  (_dim(prhs[3], 0)) != (int) (in_depth) ||   (_dim(prhs[3], 1)) != (int) (32))
        mexErrMsgTxt("Error in dimension of argument label");
    in_label = _mxGetString(prhs[3], NULL);

    if (mxGetNumberOfElements(prhs[4]) < (int) (in_depth) || _n_dims(prhs[4]) > 1)
        mexErrMsgTxt("Error in dimension of argument num");
    if (mxIsInt32(prhs[4]) || mxIsUint32(prhs[4]))
        in_num = (int*)mxGetData(prhs[4]);
    else {
        in_num = (int*)mxCalloc(mxGetNumberOfElements(prhs[4]), sizeof (int));
        if (!_get_numeric_array_int32(prhs[4], in_num))
            mexErrMsgTxt("Expecting numeric matrix for argument num");
    }


    /******** Invoke computational function ********/
    ierr = cg_golist(in_file_number, in_B, in_depth, &in_label, in_num);


    /******** Free up input buffers. ********/
    _mxFreeString(in_label);
    if (!mxIsInt32(prhs[4]) && !mxIsUint32(prhs[4]))
        mxFree(in_num);

    /******** Process output arguments ********/
    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int*)mxGetData(plhs[0]) = ierr;
}
