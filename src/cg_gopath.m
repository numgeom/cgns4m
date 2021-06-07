function ierr = cg_gopath(in_file_number, in_path)
% Gateway function for C function cg_gopath.
%
% ierr = cg_gopath(file_number, path)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%            path: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gopath(int file_number, const char * path);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_path = char(in_path);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(218), in_file_number, in_path);
