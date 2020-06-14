function ierr = cg_gravity_write(in_file_number, in_B, in_gravity_vector)
% Gateway function for C function cg_gravity_write.
%
% ierr = cg_gravity_write(file_number, B, gravity_vector)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%    gravity_vector: single-precision (single), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gravity_write(int file_number, int B, float const * gravity_vector);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_gravity_vector = single(in_gravity_vector);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(191), in_file_number, in_B, in_gravity_vector);
