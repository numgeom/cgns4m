function [out_I, ierr] = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform)
% Gateway function for C function cg_1to1_write.
%
% [I, ierr] = cg_1to1_write(fn, B, Z, connectname, donorname, range, donor_range, transform)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     connectname: character string
%       donorname: character string
%           range: 32-bit integer (int32), array
%     donor_range: 32-bit integer (int32), array
%       transform: 32-bit integer (int32), array
%
% Output arguments (optional):
%               I: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_write( int fn, int B, int Z, char const * connectname, char const * donorname, int const * range, int const * donor_range, int const * transform, int * I);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_I, ierr] =  cgnslib_mex(int32(105), in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform);
