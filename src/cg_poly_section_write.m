function [out_S, ierr] = cg_poly_section_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, in_connect_offset)
% Gateway function for C function cg_poly_section_write.
%
% [S, ierr] = cg_poly_section_write(file_number, B, Z, SectionName, type, start, end, nbndry, elements, connect_offset)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     SectionName: character string
%            type: 32-bit integer (int32), scalar
%           start: 64-bit integer (int64), scalar
%             end: 64-bit integer (int64), scalar
%          nbndry: 32-bit integer (int32), scalar
%        elements: 64-bit integer (int64), array
%    connect_offset: 64-bit integer (int64), array
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_poly_section_write(int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, long long start, long long end, int nbndry, const long long * elements, const long long * connect_offset, int * S);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 10)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_SectionName = char(in_SectionName);
in_type = int32(in_type);
in_start = int64(in_start);
in_end = int64(in_end);
in_nbndry = int32(in_nbndry);
in_elements = int64(in_elements);
in_connect_offset = int64(in_connect_offset);

% Invoke the actual MEX-function.
[out_S, ierr] = cgnslib_mex(int32(99), in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry, in_elements, in_connect_offset);
