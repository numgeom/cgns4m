function [io_F, ierr] = cg_node_family_write(in_family_name, io_F)
% Gateway function for C function cg_node_family_write.
%
% [F, ierr] = cg_node_family_write(family_name, F)
%
% Input argument (required; type is auto-casted):
%     family_name: character string
%
% In&Out argument (required as output; type is auto-casted):
%               F: 32-bit integer (int32), array  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_family_write(const char * family_name, int * F);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_family_name = char(in_family_name);
basetype = 'int32';
if ~isa(io_F,basetype)
    io_F = cast(io_F, basetype);
elseif ~isempty(io_F)
    % Write to it to unshare memory with other variables
    t=io_F(1); io_F(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(58), in_family_name, io_F);
