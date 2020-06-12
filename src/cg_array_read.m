function [io_data, ierr] = cg_array_read(in_A, io_data)
% Gateway function for C function cg_array_read.
%
% [data, ierr] = cg_array_read(A, data)
%
% Input argument (required; type is auto-casted):
%               A: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            data: dynamic type based on cgns_get_array_type(A)  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_read(int A, void * data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_A = int32(in_A);

% Perform dynamic type casting
datatype = cgns_get_array_type(in_A);
switch (datatype)
    case 2 % CG_Integer
        io_data = int32(io_data);
    case 3 % CG_RealSingle
        io_data = single(io_data);
    case 4 % CG_RealDouble
        io_data = double(io_data);
    case 5 % CG_Character
        io_data = [int8(io_data), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_data = int64(io_data);
    otherwise
        error('Unknown data type %d', cgns_get_array_type(in_A));
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(211), in_A, io_data);
