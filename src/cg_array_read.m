function [io_Data, ierr] = cg_array_read(in_A, io_Data)
% Gateway function for C function cg_array_read.
%
% [Data, ierr] = cg_array_read(A, Data)
%
% Input argument (required; type is auto-casted): 
%               A: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%            Data: dynamic type based on cgns_get_array_type(A)  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_read( int A, void * Data);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = cgns_get_array_type(in_A);
switch (datatype)
    case 2 % Integer
        io_Data = int32(io_Data);
    case 3 % RealSingle
        io_Data = single(io_Data);
    case 4 % RealDouble
        io_Data = double(io_Data);
    case 5 % Character
        io_Data = [int8(io_Data), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', cgns_get_array_type(in_A));
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(174), in_A, io_Data);

% Perform dynamic type casting
if datatype==5 % Character
    io_Data = char(io_Data(1:end-1));
end
