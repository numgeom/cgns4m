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
% int cg_exponents_write( DataType_t DataType, void const * exponents);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_DataType;
switch (datatype)
    case 2 % Integer
        in_exponents = int32(in_exponents);
    case 3 % RealSingle
        in_exponents = single(in_exponents);
    case 4 % RealDouble
        in_exponents = double(in_exponents);
    case 5 % Character
        in_exponents = [int8(in_exponents), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_DataType);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(196), in_DataType, in_exponents);
