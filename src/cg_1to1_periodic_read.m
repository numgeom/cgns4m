function [out_RotationCenter, out_RotationAngle, out_Translation, ierr] = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_I)
% Gateway function for C function cg_1to1_periodic_read.
%
% [RotationCenter, RotationAngle, Translation, ierr] = cg_1to1_periodic_read(file_number, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    RotationCenter: single-precision (single), len=3
%    RotationAngle: single-precision (single), len=3
%     Translation: single-precision (single), len=3
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_periodic_read(int file_number, int B, int Z, int I, float * RotationCenter, float * RotationAngle, float * Translation);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);

% Invoke the actual MEX-function.
[out_RotationCenter, out_RotationAngle, out_Translation, ierr] = cgnslib_mex(int32(174), in_file_number, in_B, in_Z, in_I);
