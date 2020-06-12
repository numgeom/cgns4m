function [out_B, ierr] = cg_base_write(in_file_number, in_basename, in_cell_dim, in_phys_dim)
% Gateway function for C function cg_base_write.
%
% [B, ierr] = cg_base_write(file_number, basename, cell_dim, phys_dim)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%        basename: character string
%        cell_dim: 32-bit integer (int32), scalar
%        phys_dim: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               B: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_base_write(int file_number, const char * basename, int cell_dim, int phys_dim, int * B);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_basename = char(in_basename);
in_cell_dim = int32(in_cell_dim);
in_phys_dim = int32(in_phys_dim);

% Invoke the actual MEX-function.
[out_B, ierr] = cgnslib_mex(int32(44), in_file_number, in_basename, in_cell_dim, in_phys_dim);
