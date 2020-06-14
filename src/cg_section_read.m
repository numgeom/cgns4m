function [out_SectionName, out_type, out_start, out_end, out_nbndry, out_parent_flag, ierr] = cg_section_read(in_file_number, in_B, in_Z, in_S)
% Gateway function for C function cg_section_read.
%
% [SectionName, type, start, end, nbndry, parent_flag, ierr] = cg_section_read(file_number, B, Z, S)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     SectionName: character string
%            type: 32-bit integer (int32), scalar
%           start: 64-bit integer (int64), scalar
%             end: 64-bit integer (int64), scalar
%          nbndry: 32-bit integer (int32), scalar
%     parent_flag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_section_read(int file_number, int B, int Z, int S, char * SectionName, CG_ElementType_t * type, long long * start, long long * end, int * nbndry, int * parent_flag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);

% Invoke the actual MEX-function.
[out_SectionName, out_type, out_start, out_end, out_nbndry, out_parent_flag, ierr] = cgnslib_mex(int32(95), in_file_number, in_B, in_Z, in_S);
