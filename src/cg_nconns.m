function [out_nconns, ierr] = cg_nconns(in_fn, in_B, in_Z)
% Gateway function for C function cg_nconns.
%
% [nconns, ierr] = cg_nconns(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          nconns: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nconns( int fn, int B, int Z, int * nconns);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nconns, ierr] =  cgnslib_mex(int32(89), in_fn, in_B, in_Z);
