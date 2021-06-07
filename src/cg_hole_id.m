function [out_hole_id, ierr] = cg_hole_id(in_fn, in_B, in_Z, in_Ii)
% Gateway function for C function cg_hole_id.
%
% [hole_id, ierr] = cg_hole_id(fn, B, Z, Ii)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              Ii: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         hole_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_id(int fn, int B, int Z, int Ii, double * hole_id);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_Ii = int32(in_Ii);

% Invoke the actual MEX-function.
[out_hole_id, ierr] = cgnslib_mex(int32(150), in_fn, in_B, in_Z, in_Ii);
