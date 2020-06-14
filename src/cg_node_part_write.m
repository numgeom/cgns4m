function [out_P, ierr] = cg_node_part_write(in_G, in_part_name)
% Gateway function for C function cg_node_part_write.
%
% [P, ierr] = cg_node_part_write(G, part_name)
%
% Input arguments (required; type is auto-casted):
%               G: 32-bit integer (int32), scalar
%       part_name: character string
%
% Output arguments (optional):
%               P: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_part_write(int G, const char * part_name, int * P);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_G = int32(in_G);
in_part_name = char(in_part_name);

% Invoke the actual MEX-function.
[out_P, ierr] = cgnslib_mex(int32(80), in_G, in_part_name);
