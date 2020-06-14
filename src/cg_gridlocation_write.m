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
% int cg_gridlocation_write(CG_GridLocation_t GridLocation);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_GridLocation = int32(in_GridLocation);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(262), in_GridLocation);
