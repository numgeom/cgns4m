function [out_nfields, ierr] = cg_nfields(in_fn, in_B, in_Z, in_S)
% Gateway function for C function cg_nfields.
%
% [nfields, ierr] = cg_nfields(fn, B, Z, S)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         nfields: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nfields( int fn, int B, int Z, int S, int * nfields);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nfields, ierr] =  cgnslib_mex(int32(91), in_fn, in_B, in_Z, in_S);
