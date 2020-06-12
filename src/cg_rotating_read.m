function [io_rot_rate, io_rot_center, ierr] = cg_rotating_read(io_rot_rate, io_rot_center)
% Gateway function for C function cg_rotating_read.
%
% [rot_rate, rot_center, ierr] = cg_rotating_read(rot_rate, rot_center)
%
% Input argument (required; type is auto-casted):
%
% In&Out arguments (required as output; type is auto-casted):
%        rot_rate: single-precision (single), array  (also required as input)
%      rot_center: single-precision (single), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rotating_read(float * rot_rate, float * rot_center);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
basetype = 'single';
if ~isa(io_rot_rate,basetype)
    io_rot_rate = cast(io_rot_rate, basetype);
elseif ~isempty(io_rot_rate)
    % Write to it to avoid sharing memory with other variables
    t=io_rot_rate(1); io_rot_rate(1)=t;
end

basetype = 'single';
if ~isa(io_rot_center,basetype)
    io_rot_center = cast(io_rot_center, basetype);
elseif ~isempty(io_rot_center)
    % Write to it to avoid sharing memory with other variables
    t=io_rot_center(1); io_rot_center(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(176), io_rot_rate, io_rot_center);
