function [out_name, out_family, ierr] = cg_family_name_read(in_file_number, in_B, in_F, in_N)
% Gateway function for C function cg_family_name_read.
%
% [name, family, ierr] = cg_family_name_read(file_number, B, F, N)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%               N: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            name: character string
%          family: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_family_name_read(int file_number, int B, int F, int N, char * name, char * family);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_N = int32(in_N);

% Invoke the actual MEX-function.
[out_name, out_family, ierr] = cgnslib_mex(int32(56), in_file_number, in_B, in_F, in_N);
