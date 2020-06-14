function [out_part_name, ierr] = cg_node_part_read(in_G, in_P)
% Gateway function for C function cg_node_part_read.
%
% [part_name, ierr] = cg_node_part_read(G, P)
%
% Input arguments (required; type is auto-casted):
%               G: 32-bit integer (int32), scalar
%               P: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       part_name: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_part_read(int G, int P, char * part_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_G = int32(in_G);
in_P = int32(in_P);

% Invoke the actual MEX-function.
[out_part_name, ierr] = cgnslib_mex(int32(79), in_G, in_P);
