function [out_BC, ierr] = cg_node_fambc_write(in_fambc_name, in_bocotype)
% Gateway function for C function cg_node_fambc_write.
%
% [BC, ierr] = cg_node_fambc_write(fambc_name, bocotype)
%
% Input arguments (required; type is auto-casted):
%      fambc_name: character string
%        bocotype: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%              BC: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_fambc_write(const char * fambc_name, CG_BCType_t bocotype, int * BC);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_fambc_name = char(in_fambc_name);
in_bocotype = int32(in_bocotype);

% Invoke the actual MEX-function.
[out_BC, ierr] = cgnslib_mex(int32(72), in_fambc_name, in_bocotype);
