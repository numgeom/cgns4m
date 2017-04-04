function [out_FileVersion, ierr] = cg_version(in_fn)
% Gateway function for C function cg_version.
%
% [FileVersion, ierr] = cg_version(fn)
%
% Input argument (required; type is auto-casted): 
%              fn: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     FileVersion: single-precision (single), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_version( int fn, float * FileVersion);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_FileVersion, ierr] =  cgnslib_mex(int32(2), in_fn);
