function [out_S, ierr] = cg_sol_write(in_fn, in_B, in_Z, in_solname, in_location)
% Gateway function for C function cg_sol_write.
%
% [S, ierr] = cg_sol_write(fn, B, Z, solname, location)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%         solname: character string
%        location: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_write( int fn, int B, int Z, char const * solname, GridLocation_t location, int * S);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/solution.html">online documentation</a>.
%
if (nargin < 5); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_S, ierr] =  cgnslib_mex(int32(83), in_fn, in_B, in_Z, in_solname, in_location);
