function [out_nsubreg, ierr] = cg_nsubregs(in_fn, in_B, in_Z)
% Gateway function for C function cg_nsubregs.
%
% [nsubreg, ierr] = cg_nsubregs(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         nsubreg: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nsubregs(int fn, int B, int Z, int * nsubreg);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);

% Invoke the actual MEX-function.
[out_nsubreg, ierr] = cgnslib_mex(int32(134), in_fn, in_B, in_Z);
