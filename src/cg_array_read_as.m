function [io_data, ierr] = cg_array_read_as(in_A, in_type, io_data)
% Gateway function for C function cg_array_read_as.
%
% [data, ierr] = cg_array_read_as(A, type, data)
%
% Input arguments (required; type is auto-casted):
%               A: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            data: dynamic type based on type  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_read_as(int A, CG_DataType_t type, void * data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargout < 1 || nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_A = int32(in_A);
in_type = int32(in_type);

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        io_data = int32(io_data);
    case 3 % CG_RealSingle
        io_data = single(io_data);
    case 4 % CG_RealDouble
        io_data = double(io_data);
    case 5 % CG_Character
        io_data = [int8(io_data), int8(zeros(1, 1))];
    case 6 % CG_LongInteger
        io_data = int64(io_data);
    otherwise
        error('Unknown data type %d', in_type);
end

if ~isempty(io_data)
    % Write to it to unshare memory with other variables
    t = io_data(1); io_data(1) = t;
end

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(212), in_A, in_type, io_data);
