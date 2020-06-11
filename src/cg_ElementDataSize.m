function [out_ElementDataSize, ierr] = cg_ElementDataSize(in_file_number, in_B, in_Z, in_S)
% Gateway function for C function cg_ElementDataSize.
%
% [ElementDataSize, ierr] = cg_ElementDataSize(file_number, B, Z, S)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    ElementDataSize: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ElementDataSize( int file_number, int B, int Z, int S, int * ElementDataSize);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_ElementDataSize, ierr] =  cgnslib_mex(int32(74), in_file_number, in_B, in_Z, in_S);
