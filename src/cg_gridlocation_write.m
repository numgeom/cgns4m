function ierr = cg_gridlocation_write(in_GridLocation)
% Gateway function for C function cg_gridlocation_write.
%
% ierr = cg_gridlocation_write(GridLocation)
%
% Input argument (required; type is auto-casted): 
%    GridLocation: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gridlocation_write( GridLocation_t GridLocation);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/location.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(197), in_GridLocation);
