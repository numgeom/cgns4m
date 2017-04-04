function [out_pnts, ierr] = cg_ptset_read()
% Gateway function for C function cg_ptset_read.
%
% [pnts, ierr] = cg_ptset_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%            pnts: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ptset_read( int * pnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/location.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_pnts, ierr] =  cgnslib_mex(int32(210));
