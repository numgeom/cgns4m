function ierr = cg_family_name_write(in_file_number, in_B, in_F, in_name, in_family)
% Gateway function for C function cg_family_name_write.
%
% ierr = cg_family_name_write(file_number, B, F, name, family)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%            name: character string
%          family: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_family_name_write(int file_number, int B, int F, const char * name, const char * family);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_name = char(in_name);
in_family = char(in_family);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(57), in_file_number, in_B, in_F, in_name, in_family);
