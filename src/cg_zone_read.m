function [out_zonename, out_size, ierr] = cg_zone_read(in_fn, in_B, in_Z)
% Gateway function for C function cg_zone_read.
%
% [zonename, size, ierr] = cg_zone_read(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        zonename: character string
%            size: 64-bit integer (int64), len=9
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zone_read(int fn, int B, int Z, char * zonename, long long * size);
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
[out_zonename, out_size, ierr] = cgnslib_mex(int32(46), in_fn, in_B, in_Z);
