function [out_Z, ierr] = cg_zone_write(in_fn, in_B, in_zonename, in_size, in_type)
% Gateway function for C function cg_zone_write.
%
% [Z, ierr] = cg_zone_write(fn, B, zonename, size, type)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%        zonename: character string
%            size: 64-bit integer (int64), len=9
%            type: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               Z: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zone_write(int fn, int B, const char * zonename, const long long * size, CG_ZoneType_t type, int * Z);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_zonename = char(in_zonename);
in_size = int64(in_size);
in_type = int32(in_type);

% Invoke the actual MEX-function.
[out_Z, ierr] = cgnslib_mex(int32(49), in_fn, in_B, in_zonename, in_size, in_type);
