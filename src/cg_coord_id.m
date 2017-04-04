function [out_coord_id, ierr] = cg_coord_id(in_fn, in_B, in_Z, in_C)
% Gateway function for C function cg_coord_id.
%
% [coord_id, ierr] = cg_coord_id(fn, B, Z, C)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               C: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        coord_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_id( int fn, int B, int Z, int C, double * coord_id);
%
% For detail, see the documentation of the original function.
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_coord_id, ierr] =  cgnslib_mex(int32(60), in_fn, in_B, in_Z, in_C);
