function [out_ngrids, ierr] = cg_ngrids(in_file_number, in_B, in_Z)
% Gateway function for C function cg_ngrids.
%
% [ngrids, ierr] = cg_ngrids(file_number, B, Z)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          ngrids: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ngrids(int file_number, int B, int Z, int * ngrids);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);

% Invoke the actual MEX-function.
[out_ngrids, ierr] = cgnslib_mex(int32(81), in_file_number, in_B, in_Z);
