function [out_hole_id, ierr] = cg_hole_id(in_fn, in_B, in_Z, in_I)
% Gateway function for C function cg_hole_id.
%
% [hole_id, ierr] = cg_hole_id(fn, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         hole_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_id( int fn, int B, int Z, int I, double * hole_id);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_hole_id, ierr] =  cgnslib_mex(int32(93), in_fn, in_B, in_Z, in_I);
