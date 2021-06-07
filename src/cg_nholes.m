function [out_nholes, ierr] = cg_nholes(in_fn, in_B, in_Z)
% Gateway function for C function cg_nholes.
%
% [nholes, ierr] = cg_nholes(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          nholes: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nholes(int fn, int B, int Z, int * nholes);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);

% Invoke the actual MEX-function.
[out_nholes, ierr] = cgnslib_mex(int32(147), in_fn, in_B, in_Z);
