function ierr = cg_delete_node(in_node_name)
% Gateway function for C function cg_delete_node.
%
% ierr = cg_delete_node(node_name)
%
% Input argument (required; type is auto-casted): 
%       node_name: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_delete_node( char const *node_name);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/navigating.html">online documentation</a>.
%
if ( nargout < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(214), in_node_name);
