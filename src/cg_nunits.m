function [out_nunits, ierr] = cg_nunits()
% Gateway function for C function cg_nunits.
%
% [nunits, ierr] = cg_nunits()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%          nunits: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nunits( int * nunits);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nunits, ierr] =  cgnslib_mex(int32(188));
