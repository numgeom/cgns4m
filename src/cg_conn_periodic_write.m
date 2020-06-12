function ierr = cg_conn_periodic_write(in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation)
% Gateway function for C function cg_conn_periodic_write.
%
% ierr = cg_conn_periodic_write(file_number, B, Z, Ii, RotationCenter, RotationAngle, Translation)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              Ii: 32-bit integer (int32), scalar
%    RotationCenter: single-precision (single), array
%    RotationAngle: single-precision (single), array
%     Translation: single-precision (single), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_periodic_write(int file_number, int B, int Z, int Ii, float const * RotationCenter, float const * RotationAngle, float const * Translation);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 7)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_Ii = int32(in_Ii);
in_RotationCenter = single(in_RotationCenter);
in_RotationAngle = single(in_RotationAngle);
in_Translation = single(in_Translation);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(183), in_file_number, in_B, in_Z, in_Ii, in_RotationCenter, in_RotationAngle, in_Translation);
