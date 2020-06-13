function [io_ref_point, io_axis, ierr] = cg_axisym_read(in_file_number, in_B, io_ref_point, io_axis)
% Gateway function for C function cg_axisym_read.
%
% [ref_point, axis, ierr] = cg_axisym_read(file_number, B, ref_point, axis)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%       ref_point: single-precision (single), array  (also required as input)
%            axis: single-precision (single), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_axisym_read(int file_number, int B, float * ref_point, float * axis);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
basetype = 'single';
if ~isa(io_ref_point,basetype)
    io_ref_point = cast(io_ref_point, basetype);
elseif ~isempty(io_ref_point)
    % Write to it to avoid sharing memory with other variables
    t=io_ref_point(1); io_ref_point(1)=t;
end

basetype = 'single';
if ~isa(io_axis,basetype)
    io_axis = cast(io_axis, basetype);
elseif ~isempty(io_axis)
    % Write to it to avoid sharing memory with other variables
    t=io_axis(1); io_axis(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(174), in_file_number, in_B, io_ref_point, io_axis);
