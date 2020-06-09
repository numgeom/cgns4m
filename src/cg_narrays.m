function [out_narrays, ierr] = cg_narrays()
% Gateway function for C function cg_narrays.
%
% [narrays, ierr] = cg_narrays()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%         narrays: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_narrays( int * narrays);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_narrays, ierr] =  cgnslib_mex(int32(172));
