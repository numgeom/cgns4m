function [out_AverageInterfaceType, ierr] = cg_1to1_average_read(in_file_number, in_B, in_Z, in_I)
% Gateway function for C function cg_1to1_average_read.
%
% [AverageInterfaceType, ierr] = cg_1to1_average_read(file_number, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    AverageInterfaceType: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_average_read( int file_number, int B, int Z, int I, AverageInterfaceType_t * AverageInterfaceType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_AverageInterfaceType, ierr] =  cgnslib_mex(int32(144), in_file_number, in_B, in_Z, in_I);
