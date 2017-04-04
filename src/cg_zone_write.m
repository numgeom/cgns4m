function [out_Z, ierr] = cg_zone_write(in_fn, in_B, in_zonename, in_size, in_type)
% Gateway function for C function cg_zone_write.
%
% [Z, ierr] = cg_zone_write(fn, B, zonename, size, type)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%        zonename: character string
%            size: 32-bit integer (int32), len=9
%            type: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               Z: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zone_write( int fn, int B, char const * zonename, int const * size, ZoneType_t type, int * Z);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/structural.html">online documentation</a>.
%
if (nargin < 5); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_Z, ierr] =  cgnslib_mex(int32(40), in_fn, in_B, in_zonename, in_size, in_type);
