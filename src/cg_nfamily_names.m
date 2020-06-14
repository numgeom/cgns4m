function [out_nnames, ierr] = cg_nfamily_names(in_file_number, in_B, in_F)
% Gateway function for C function cg_nfamily_names.
%
% [nnames, ierr] = cg_nfamily_names(file_number, B, F)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%          nnames: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nfamily_names(int file_number, int B, int F, int * nnames);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);

% Invoke the actual MEX-function.
[out_nnames, ierr] = cgnslib_mex(int32(55), in_file_number, in_B, in_F);
