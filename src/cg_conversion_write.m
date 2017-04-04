function ierr = cg_conversion_write(in_DataType, in_ConversionFactors)
% Gateway function for C function cg_conversion_write.
%
% ierr = cg_conversion_write(DataType, ConversionFactors)
%
% Input arguments (required; type is auto-casted):
%        DataType: 32-bit integer (int32), scalar
%    ConversionFactors: dynamic type based on DataType
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conversion_write( DataType_t DataType, void const * ConversionFactors);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_DataType;
switch (datatype)
    case 2 % Integer
        in_ConversionFactors = int32(in_ConversionFactors);
    case 3 % RealSingle
        in_ConversionFactors = single(in_ConversionFactors);
    case 4 % RealDouble
        in_ConversionFactors = double(in_ConversionFactors);
    case 5 % Character
        in_ConversionFactors = [int8(in_ConversionFactors), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_DataType);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(193), in_DataType, in_ConversionFactors);
