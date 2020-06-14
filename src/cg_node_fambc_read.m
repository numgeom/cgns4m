function [out_fambc_name, out_bocotype, ierr] = cg_node_fambc_read(in_BC)
% Gateway function for C function cg_node_fambc_read.
%
% [fambc_name, bocotype, ierr] = cg_node_fambc_read(BC)
%
% Input argument (required; type is auto-casted):
%              BC: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%      fambc_name: character string
%        bocotype: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_fambc_read(int BC, char * fambc_name, CG_BCType_t * bocotype);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_BC = int32(in_BC);

% Invoke the actual MEX-function.
[out_fambc_name, out_bocotype, ierr] = cgnslib_mex(int32(71), in_BC);
