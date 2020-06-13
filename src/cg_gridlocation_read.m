function [out_GridLocation, ierr] = cg_gridlocation_read()
% Gateway function for C function cg_gridlocation_read.
%
% [GridLocation, ierr] = cg_gridlocation_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%    GridLocation: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gridlocation_read(CG_GridLocation_t * GridLocation);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_GridLocation, ierr] = cgnslib_mex(int32(230));
