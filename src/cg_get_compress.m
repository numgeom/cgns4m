function [out_compress, ierr] = cg_get_compress()
% Gateway function for C function cg_get_compress.
%
% [compress, ierr] = cg_get_compress()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%        compress: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_get_compress( int * compress);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/fileops.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_compress, ierr] =  cgnslib_mex(int32(11));
