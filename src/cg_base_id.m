function [out_base_id, ierr] = cg_base_id(in_fn, in_B)
% Gateway function for C function cg_base_id.
%
% [base_id, ierr] = cg_base_id(fn, B)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         base_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_base_id( int fn, int B, double * base_id);
%
% For detail, see the documentation of the original function.
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_base_id, ierr] =  cgnslib_mex(int32(42), in_fn, in_B);
