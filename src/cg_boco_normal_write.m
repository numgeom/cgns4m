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
% int cg_boco_normal_write( int file_number, int B, int Z, int BC, int const * NormalIndex, int NormalListFlag, DataType_t NormalDataType, void const * NormalList);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/bc.html">online documentation</a>.
%
if (nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_NormalDataType;
switch (datatype)
    case 2 % Integer
        in_NormalList = int32(in_NormalList);
    case 3 % RealSingle
        in_NormalList = single(in_NormalList);
    case 4 % RealDouble
        in_NormalList = double(in_NormalList);
    case 5 % Character
        in_NormalList = [int8(in_NormalList), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_NormalDataType);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(113), in_file_number, in_B, in_Z, in_BC, in_NormalIndex, in_NormalListFlag, in_NormalDataType, in_NormalList);
