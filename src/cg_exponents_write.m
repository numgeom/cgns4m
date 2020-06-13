function ierr = cg_exponents_write(in_DataType, in_exponents)
% Gateway function for C function cg_exponents_write.
%
% ierr = cg_exponents_write(DataType, exponents)
%
% Input arguments (required; type is auto-casted):
%        DataType: 32-bit integer (int32), scalar
%       exponents: dynamic type based on DataType
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_exponents_write(CG_DataType_t DataType, const void * exponents);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_DataType = int32(in_DataType);

% Perform dynamic type casting
datatype = in_DataType;
switch (datatype)
    case 2 % CG_Integer
        in_exponents = int32(in_exponents);
    case 3 % CG_RealSingle
        in_exponents = single(in_exponents);
    case 4 % CG_RealDouble
        in_exponents = double(in_exponents);
    case 5 % CG_Character
        in_exponents = [int8(in_exponents), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_exponents = int64(in_exponents);
    otherwise
        error('Unknown data type %d', in_DataType);
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(222), in_DataType, in_exponents);
