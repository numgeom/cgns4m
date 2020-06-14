function [out_basename, out_cell_dim, out_phys_dim, ierr] = cg_base_read(in_file_number, in_B)
% Gateway function for C function cg_base_read.
%
% [basename, cell_dim, phys_dim, ierr] = cg_base_read(file_number, B)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        basename: character string
%        cell_dim: 32-bit integer (int32), scalar
%        phys_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_base_read(int file_number, int B, char * basename, int * cell_dim, int * phys_dim);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);

% Invoke the actual MEX-function.
[out_basename, out_cell_dim, out_phys_dim, ierr] = cgnslib_mex(int32(42), in_file_number, in_B);
