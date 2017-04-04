function [out_n1to1_global, ierr] = cg_n1to1_global(in_fn, in_B)
% Gateway function for C function cg_n1to1_global.
%
% [n1to1_global, ierr] = cg_n1to1_global(fn, B)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    n1to1_global: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_n1to1_global( int fn, int B, int * n1to1_global);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_n1to1_global, ierr] =  cgnslib_mex(int32(126), in_fn, in_B);
