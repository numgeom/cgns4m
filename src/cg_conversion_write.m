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
% int cg_conversion_write( CG_DataType_t DataType, const void * ConversionFactors);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_DataType;
switch (datatype)
    case 2 % CG_Integer
        in_ConversionFactors = int32(in_ConversionFactors);
    case 3 % CG_RealSingle
        in_ConversionFactors = single(in_ConversionFactors);
    case 4 % CG_RealDouble
        in_ConversionFactors = double(in_ConversionFactors);
    case 5 % CG_Character
        in_ConversionFactors = [int8(in_ConversionFactors), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_ConversionFactors = int64(in_ConversionFactors);
    otherwise
        error('Unknown data type %d', in_DataType);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(227), in_DataType, in_ConversionFactors);
