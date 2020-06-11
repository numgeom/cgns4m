function [out_n1to1, ierr] = cg_n1to1(in_fn, in_B, in_Z)
% Gateway function for C function cg_n1to1.
%
% [n1to1, ierr] = cg_n1to1(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%           n1to1: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_n1to1( int fn, int B, int Z, int * n1to1);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_n1to1, ierr] =  cgnslib_mex(int32(102), in_fn, in_B, in_Z);
