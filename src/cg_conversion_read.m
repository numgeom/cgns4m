function [io_ConversionFactors, ierr] = cg_conversion_read(io_ConversionFactors)
% Gateway function for C function cg_conversion_read.
%
% [ConversionFactors, ierr] = cg_conversion_read(ConversionFactors)
%
% Input argument (required; type is auto-casted): 
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%    ConversionFactors: dynamic type based on cg_conversion_info()  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conversion_read( void * ConversionFactors);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = cg_conversion_info();
switch (datatype)
    case 2 % CG_Integer
        io_ConversionFactors = int32(io_ConversionFactors);
    case 3 % CG_RealSingle
        io_ConversionFactors = single(io_ConversionFactors);
    case 4 % CG_RealDouble
        io_ConversionFactors = double(io_ConversionFactors);
    case 5 % CG_Character
        io_ConversionFactors = [int8(io_ConversionFactors), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_ConversionFactors = int64(io_ConversionFactors);
    otherwise
        error('Unknown data type %d', cg_conversion_info());
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(226), io_ConversionFactors);

% Perform dynamic type casting
if datatype==5 % CG_Character
    io_ConversionFactors = char(io_ConversionFactors(1:end-1));
end
