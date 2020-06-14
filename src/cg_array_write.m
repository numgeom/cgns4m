function ierr = cg_array_write(in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data)
% Gateway function for C function cg_array_write.
%
% ierr = cg_array_write(ArrayName, DataType, DataDimension, DimensionVector, Data)
%
% Input arguments (required; type is auto-casted):
%       ArrayName: character string
%        DataType: 32-bit integer (int32), scalar
%    DataDimension: 32-bit integer (int32), scalar
%    DimensionVector: 64-bit integer (int64), len=DataDimension
%            Data: dynamic type based on DataType
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_write(const char * ArrayName, CG_DataType_t DataType, int DataDimension, const long long * DimensionVector, const void * Data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_ArrayName = char(in_ArrayName);
in_DataType = int32(in_DataType);
in_DataDimension = int32(in_DataDimension);
in_DimensionVector = int64(in_DimensionVector);

% Perform dynamic type casting
datatype = in_DataType;
switch (datatype)
    case 2 % CG_Integer
        in_Data = int32(in_Data);
    case 3 % CG_RealSingle
        in_Data = single(in_Data);
    case 4 % CG_RealDouble
        in_Data = double(in_Data);
    case 5 % CG_Character
        in_Data = [int8(in_Data), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_Data = int64(in_Data);
    otherwise
        error('Unknown data type %d', in_DataType);
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(232), in_ArrayName, in_DataType, in_DataDimension, in_DimensionVector, in_Data);
