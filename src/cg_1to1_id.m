function [out_one21_id, ierr] = cg_1to1_id(in_fn, in_B, in_Z, in_I)
% Gateway function for C function cg_1to1_id.
%
% [one21_id, ierr] = cg_1to1_id(fn, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        one21_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_id(int fn, int B, int Z, int I, double * one21_id);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);

% Invoke the actual MEX-function.
[out_one21_id, ierr] = cgnslib_mex(int32(124), in_fn, in_B, in_Z, in_I);
