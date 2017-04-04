function [out_nsections, ierr] = cg_nsections(in_file_number, in_B, in_Z)
% Gateway function for C function cg_nsections.
%
% [nsections, ierr] = cg_nsections(file_number, B, Z)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       nsections: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nsections( int file_number, int B, int Z, int * nsections);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nsections, ierr] =  cgnslib_mex(int32(68), in_file_number, in_B, in_Z);
