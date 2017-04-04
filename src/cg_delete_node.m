function [io_node_name, ierr] = cg_delete_node(io_node_name)
% Gateway function for C function cg_delete_node.
%
% [node_name, ierr] = cg_delete_node(node_name)
%
% Input argument (required; type is auto-casted): 
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%       node_name: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_delete_node( char * node_name);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/navigating.html">online documentation</a>.
%
if ( nargout < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<1
    io_node_name=char(zeros(1,32));
elseif length(io_node_name)<32
    %% Enlarge the array if necessary;
    io_node_name=char([io_node_name zeros(1,32-length(io_node_name))]);
elseif ~isa(io_node_name,'char');
    io_node_name=char(io_node_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_node_name(1); io_node_name(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(206), io_node_name);
