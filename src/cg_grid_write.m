function [out_G, ierr] = cg_grid_write(in_file_number, in_B, in_Z, in_zcoorname)
% Gateway function for C function cg_grid_write.
%
% [G, ierr] = cg_grid_write(file_number, B, Z, zcoorname)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       zcoorname: character string
%
% Output arguments (optional):
%               G: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_grid_write(int file_number, int B, int Z, const char * zcoorname, int * G);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_zcoorname = char(in_zcoorname);

% Invoke the actual MEX-function.
[out_G, ierr] = cgnslib_mex(int32(83), in_file_number, in_B, in_Z, in_zcoorname);
