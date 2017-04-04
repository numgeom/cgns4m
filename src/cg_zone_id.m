function [out_zone_id, ierr] = cg_zone_id(in_fn, in_B, in_Z)
% Gateway function for C function cg_zone_id.
%
% [zone_id, ierr] = cg_zone_id(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         zone_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zone_id( int fn, int B, int Z, double * zone_id);
%
% For detail, see the documentation of the original function.
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_zone_id, ierr] =  cgnslib_mex(int32(48), in_fn, in_B, in_Z);
