function [out_Ordinal, ierr] = cg_ordinal_read()
% Gateway function for C function cg_ordinal_read.
%
% [Ordinal, ierr] = cg_ordinal_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%         Ordinal: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ordinal_read( int * Ordinal);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/descriptor.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_Ordinal, ierr] =  cgnslib_mex(int32(198));
