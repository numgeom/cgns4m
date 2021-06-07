function [io_elements, io_connect_offset, ierr] = cg_poly_elements_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements, io_connect_offset)
% Gateway function for C function cg_poly_elements_general_read.
%
% [elements, connect_offset, ierr] = cg_poly_elements_general_read(file_number, B, Z, S, start, end, m_type, elements, connect_offset)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%           start: 64-bit integer (int64), scalar
%             end: 64-bit integer (int64), scalar
%          m_type: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%        elements: dynamic type based on m_type  (must be preallocated at input)
%    connect_offset: numeric array (passed by reference)  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_poly_elements_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * elements, void * connect_offset);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 9)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
in_start = int64(in_start);
in_end = int64(in_end);
in_m_type = int32(in_m_type);

% Perform dynamic type casting
datatype = in_m_type;
switch (datatype)
    case 2 % CG_Integer
        io_elements = int32(io_elements);
    case 3 % CG_RealSingle
        io_elements = single(io_elements);
    case 4 % CG_RealDouble
        io_elements = double(io_elements);
    case 5 % CG_Character
        io_elements = [int8(io_elements), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_elements = int64(io_elements);
    case 7 % CG_ComplexSingle
        io_elements = complex64(io_elements);
    case 8 % CG_ComplexDouble
        io_elements = complex128(io_elements);
    otherwise
        error('Unknown data type %d', in_m_type);
end

if ~isempty(io_elements)
    % Write to it to unshare memory with other variables
    t=io_elements(1); io_elements(1)=t;
end

if ~isempty(io_connect_offset)
    % Write to it to unshare memory with other variables
    t=io_connect_offset(1); io_connect_offset(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(114), in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_elements, io_connect_offset);
