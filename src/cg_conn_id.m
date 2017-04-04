function [out_conn_id, ierr] = cg_conn_id(in_fn, in_B, in_Z, in_I)
% Gateway function for C function cg_conn_id.
%
% [conn_id, ierr] = cg_conn_id(fn, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         conn_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_id( int fn, int B, int Z, int I, double * conn_id);
%
% For detail, see the documentation of the original function.
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_conn_id, ierr] =  cgnslib_mex(int32(92), in_fn, in_B, in_Z, in_I);
