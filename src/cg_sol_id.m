function [out_sol_id, ierr] = cg_sol_id(in_fn, in_B, in_Z, in_S)
% Gateway function for C function cg_sol_id.
%
% [sol_id, ierr] = cg_sol_id(fn, B, Z, S)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          sol_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_id(int fn, int B, int Z, int S, double * sol_id);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);

% Invoke the actual MEX-function.
[out_sol_id, ierr] = cgnslib_mex(int32(112), in_fn, in_B, in_Z, in_S);
