function [out_P, ierr] = cg_part_write(in_file_number, in_B, in_F, in_G, in_part_name)
% Gateway function for C function cg_part_write.
%
% [P, ierr] = cg_part_write(file_number, B, F, G, part_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%       part_name: character string
%
% Output arguments (optional):
%               P: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_part_write(int file_number, int B, int F, int G, const char * part_name, int * P);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_G = int32(in_G);
in_part_name = char(in_part_name);

% Invoke the actual MEX-function.
[out_P, ierr] = cgnslib_mex(int32(68), in_file_number, in_B, in_F, in_G, in_part_name);
