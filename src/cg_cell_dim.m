function [out_cell_dim, ierr] = cg_cell_dim(in_fn, in_B)
% Gateway function for C function cg_cell_dim.
%
% [cell_dim, ierr] = cg_cell_dim(fn, B)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        cell_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_cell_dim( int fn, int B, int * cell_dim);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_cell_dim, ierr] =  cgnslib_mex(int32(44), in_fn, in_B);
