function ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation)
% Gateway function for C function cg_conn_periodic_write.
%
% ierr = cg_conn_periodic_write(file_number, B, Z, I, RotationCenter, RotationAngle, Translation)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%    RotationCenter: single-precision (single), array
%    RotationAngle: single-precision (single), array
%     Translation: single-precision (single), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_periodic_write( int file_number, int B, int Z, int I, float const * RotationCenter, float const * RotationAngle, float const * Translation);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 7); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(138), in_file_number, in_B, in_Z, in_I, in_RotationCenter, in_RotationAngle, in_Translation);
