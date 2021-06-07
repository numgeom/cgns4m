function ierr = cg_boco_normal_write(in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList)
% Gateway function for C function cg_boco_normal_write.
%
% ierr = cg_boco_normal_write(file_number, B, Z, BC, NormalIndex, NormalListFlag, NormalDataType, NormalList)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%     NormalIndex: 32-bit integer (int32), array
%    NormalListFlag: 32-bit integer (int32), scalar
%    NormalDataType: 32-bit integer (int32), scalar
%      NormalList: dynamic type based on NormalDataType
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_normal_write(int file_number, int B, int Z, int BC, const int * NormalIndex, int NormalListFlag, CG_DataType_t NormalDataType, const void * NormalList);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 8)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
in_NormalIndex = int32(in_NormalIndex);
in_NormalListFlag = int32(in_NormalListFlag);
in_NormalDataType = int32(in_NormalDataType);

% Perform dynamic type casting
datatype = in_NormalDataType;
switch (datatype)
    case 2 % CG_Integer
        in_NormalList = int32(in_NormalList);
    case 3 % CG_RealSingle
        in_NormalList = single(in_NormalList);
    case 4 % CG_RealDouble
        in_NormalList = double(in_NormalList);
    case 5 % CG_Character
        in_NormalList = [int8(in_NormalList), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_NormalList = int64(in_NormalList);
    case 7 % CG_ComplexSingle
        in_NormalList = complex64(in_NormalList);
    case 8 % CG_ComplexDouble
        in_NormalList = complex128(in_NormalList);
    otherwise
        error('Unknown data type %d', in_NormalDataType);
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(170), in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList);
