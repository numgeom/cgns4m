function [out_ArrayName, out_DataType, out_DataDimension, out_DimensionVector, ierr] = cg_array_info(in_A)
% Gateway function for C function cg_array_info.
%
% [ArrayName, DataType, DataDimension, DimensionVector, ierr] = cg_array_info(A)
%
% Input argument (required; type is auto-casted):
%               A: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       ArrayName: character string
%        DataType: 32-bit integer (int32), scalar
%    DataDimension: 32-bit integer (int32), scalar
%    DimensionVector: 64-bit integer (int64), len=3
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_info(int A, char * ArrayName, CG_DataType_t * DataType, int * DataDimension, long long * DimensionVector);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_A = int32(in_A);

% Invoke the actual MEX-function.
[out_ArrayName, out_DataType, out_DataDimension, out_DimensionVector, ierr] = cgnslib_mex(int32(228), in_A);
