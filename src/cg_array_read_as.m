function [io_Data, ierr] = cg_array_read_as(in_A, in_type, io_Data)
% Gateway function for C function cg_array_read_as.
%
% [Data, ierr] = cg_array_read_as(A, type, Data)
%
% Input arguments (required; type is auto-casted):
%               A: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            Data: dynamic type based on type  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_read_as(int A, CG_DataType_t type, void * Data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_A = int32(in_A);
in_type = int32(in_type);

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        io_Data = int32(io_Data);
    case 3 % CG_RealSingle
        io_Data = single(io_Data);
    case 4 % CG_RealDouble
        io_Data = double(io_Data);
    case 5 % CG_Character
        io_Data = [int8(io_Data), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_Data = int64(io_Data);
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(201), in_A, in_type, io_Data);
