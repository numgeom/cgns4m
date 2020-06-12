function ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis)
% Gateway function for C function cg_axisym_write.
%
% ierr = cg_axisym_write(file_number, B, ref_point, axis)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%       ref_point: single-precision (single), array
%            axis: single-precision (single), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_axisym_write(int file_number, int B, float const * ref_point, float const * axis);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_ref_point = single(in_ref_point);
in_axis = single(in_axis);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(175), in_file_number, in_B, in_ref_point, in_axis);
