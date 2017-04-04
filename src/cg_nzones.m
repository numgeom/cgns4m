function [out_nzones, ierr] = cg_nzones(in_fn, in_B)
% Gateway function for C function cg_nzones.
%
% [nzones, ierr] = cg_nzones(fn, B)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          nzones: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nzones( int fn, int B, int * nzones);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/structural.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nzones, ierr] =  cgnslib_mex(int32(36), in_fn, in_B);
