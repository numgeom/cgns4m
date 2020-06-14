function [out_C, ierr] = cg_zconn_write(in_fn, in_B, in_Z, in_name)
% Gateway function for C function cg_zconn_write.
%
% [C, ierr] = cg_zconn_write(fn, B, Z, name)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%            name: character string
%
% Output arguments (optional):
%               C: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zconn_write(int fn, int B, int Z, const char * name, int * C);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_name = char(in_name);

% Invoke the actual MEX-function.
[out_C, ierr] = cgnslib_mex(int32(136), in_fn, in_B, in_Z, in_name);
