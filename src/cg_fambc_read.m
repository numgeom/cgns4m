function [out_fambc_name, out_bocotype, ierr] = cg_fambc_read(in_file_number, in_B, in_F, in_BC)
% Gateway function for C function cg_fambc_read.
%
% [fambc_name, bocotype, ierr] = cg_fambc_read(file_number, B, F, BC)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%      fambc_name: character string
%        bocotype: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_fambc_read(int file_number, int B, int F, int BC, char * fambc_name, CG_BCType_t * bocotype);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_BC = int32(in_BC);

% Invoke the actual MEX-function.
[out_fambc_name, out_bocotype, ierr] = cgnslib_mex(int32(69), in_file_number, in_B, in_F, in_BC);
