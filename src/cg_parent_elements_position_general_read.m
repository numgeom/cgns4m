function [io_parface, ierr] = cg_parent_elements_position_general_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parface)
% Gateway function for C function cg_parent_elements_position_general_read.
%
% [parface, ierr] = cg_parent_elements_position_general_read(file_number, B, Z, S, start, end, m_type, parface)
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
% In&Out argument (required as output; type is auto-casted):
%         parface: dynamic type based on m_type  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_parent_elements_position_general_read(int file_number, int B, int Z, int S, long long start, long long end, CG_DataType_t m_type, void * parface);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 8)
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
        io_parface = int32(io_parface);
    case 3 % CG_RealSingle
        io_parface = single(io_parface);
    case 4 % CG_RealDouble
        io_parface = double(io_parface);
    case 5 % CG_Character
        io_parface = [int8(io_parface), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_parface = int64(io_parface);
    case 7 % CG_ComplexSingle
        io_parface = complex64(io_parface);
    case 8 % CG_ComplexDouble
        io_parface = complex128(io_parface);
    otherwise
        error('Unknown data type %d', in_m_type);
end

if ~isempty(io_parface)
    % Write to it to unshare memory with other variables
    t=io_parface(1); io_parface(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(116), in_file_number, in_B, in_Z, in_S, in_start, in_end, in_m_type, io_parface);
