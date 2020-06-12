function [out_file_type, ierr] = cg_is_cgns(in_filename)
% Gateway function for C function cg_is_cgns.
%
% [file_type, ierr] = cg_is_cgns(filename)
%
% Input argument (required; type is auto-casted):
%        filename: character string
%
% Output arguments (optional):
%       file_type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_is_cgns(const char * filename, int * file_type);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_filename = char(in_filename);

% Invoke the actual MEX-function.
[out_file_type, ierr] = cgnslib_mex(int32(1), in_filename);
