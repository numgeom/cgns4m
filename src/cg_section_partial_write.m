function [out_S, ierr] = cg_section_partial_write(in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry)
% Gateway function for C function cg_section_partial_write.
%
% [S, ierr] = cg_section_partial_write(file_number, B, Z, SectionName, type, start, end, nbndry)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     SectionName: character string
%            type: 32-bit integer (int32), scalar
%           start: 64-bit or 32-bit integer (platform dependent), scalar
%             end: 64-bit or 32-bit integer (platform dependent), scalar
%          nbndry: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_section_partial_write( int file_number, int B, int Z, const char * SectionName, CG_ElementType_t type, ptrdiff_t start, ptrdiff_t end, int nbndry, int * S);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_S, ierr] =  cgnslib_mex(int32(78), in_file_number, in_B, in_Z, in_SectionName, in_type, in_start, in_end, in_nbndry);
