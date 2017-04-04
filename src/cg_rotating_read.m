function [io_rot_rate, io_rot_center, ierr] = cg_rotating_read(io_rot_rate, io_rot_center)
% Gateway function for C function cg_rotating_read.
%
% [rot_rate, rot_center, ierr] = cg_rotating_read(rot_rate, rot_center)
%
% Input argument (required; type is auto-casted): 
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%        rot_rate: single-precision (single), array  (also required as input)
%      rot_center: single-precision (single), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rotating_read( float * rot_rate, float * rot_center);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 2); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_rot_rate,'single');
    io_rot_rate=single(io_rot_rate);
elseif ~isempty(io_rot_rate);
    % Write to it to avoid sharing memory with other variables
    t=io_rot_rate(1); io_rot_rate(1)=t;
end

if ~isa(io_rot_center,'single');
    io_rot_center=single(io_rot_center);
elseif ~isempty(io_rot_center);
    % Write to it to avoid sharing memory with other variables
    t=io_rot_center(1); io_rot_center(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(139), io_rot_rate, io_rot_center);
