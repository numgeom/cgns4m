function ierr = cg_rotating_write(in_rot_rate, in_rot_center)
% Gateway function for C function cg_rotating_write.
%
% ierr = cg_rotating_write(rot_rate, rot_center)
%
% Input arguments (required; type is auto-casted):
%        rot_rate: single-precision (single), array
%      rot_center: single-precision (single), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rotating_write( float const * rot_rate, float const * rot_center);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(140), in_rot_rate, in_rot_center);
