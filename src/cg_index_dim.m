function [out_index_dim, ierr] = cg_index_dim(in_fn, in_B, in_Z)
% Gateway function for C function cg_index_dim.
%
% [index_dim, ierr] = cg_index_dim(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       index_dim: 32-bit integer (int32), len=3
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_index_dim(int fn, int B, int Z, int * index_dim);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);

% Invoke the actual MEX-function.
[out_index_dim, ierr] = cgnslib_mex(int32(50), in_fn, in_B, in_Z);
