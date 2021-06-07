function [out_ref_point, out_axis, ierr] = cg_axisym_read(in_file_number, in_B)
% Gateway function for C function cg_axisym_read.
%
% [ref_point, axis, ierr] = cg_axisym_read(file_number, B)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       ref_point: single-precision (single), len=2
%            axis: single-precision (single), len=2
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_axisym_read(int file_number, int B, float * ref_point, float * axis);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);

% Invoke the actual MEX-function.
[out_ref_point, out_axis, ierr] = cgnslib_mex(int32(200), in_file_number, in_B);
