function ierr = cg_zconn_set(in_fn, in_B, in_Z, in_C)
% Gateway function for C function cg_zconn_set.
%
% ierr = cg_zconn_set(fn, B, Z, C)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               C: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zconn_set(int fn, int B, int Z, int C);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_C = int32(in_C);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(109), in_fn, in_B, in_Z, in_C);
