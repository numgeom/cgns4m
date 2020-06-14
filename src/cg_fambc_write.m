function [out_BC, ierr] = cg_fambc_write(in_file_number, in_B, in_F, in_fambc_name, in_bocotype)
% Gateway function for C function cg_fambc_write.
%
% [BC, ierr] = cg_fambc_write(file_number, B, F, fambc_name, bocotype)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%      fambc_name: character string
%        bocotype: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%              BC: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_fambc_write(int file_number, int B, int F, const char * fambc_name, CG_BCType_t bocotype, int * BC);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_fambc_name = char(in_fambc_name);
in_bocotype = int32(in_bocotype);

% Invoke the actual MEX-function.
[out_BC, ierr] = cgnslib_mex(int32(70), in_file_number, in_B, in_F, in_fambc_name, in_bocotype);
