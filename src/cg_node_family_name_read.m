function [out_node_name, out_family_name, ierr] = cg_node_family_name_read(in_N)
% Gateway function for C function cg_node_family_name_read.
%
% [node_name, family_name, ierr] = cg_node_family_name_read(N)
%
% Input argument (required; type is auto-casted):
%               N: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       node_name: character string
%     family_name: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_family_name_read(int N, char * node_name, char * family_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_N = int32(in_N);

% Invoke the actual MEX-function.
[out_node_name, out_family_name, ierr] = cgnslib_mex(int32(63), in_N);
