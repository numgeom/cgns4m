function [out_nholes, ierr] = cg_nholes(in_fn, in_B, in_Z)
% Gateway function for C function cg_nholes.
%
% [nholes, ierr] = cg_nholes(fn, B, Z)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          nholes: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nholes( int fn, int B, int Z, int * nholes);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nholes, ierr] =  cgnslib_mex(int32(110), in_fn, in_B, in_Z);
