function ierr = cg_node_family_name_write(in_node_name, in_family_name)
% Gateway function for C function cg_node_family_name_write.
%
% ierr = cg_node_family_name_write(node_name, family_name)
%
% Input arguments (required; type is auto-casted):
%       node_name: character string
%     family_name: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_family_name_write(const char * node_name, const char * family_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_node_name = char(in_node_name);
in_family_name = char(in_family_name);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(61), in_node_name, in_family_name);
