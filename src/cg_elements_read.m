function [io_elements, io_parent_data, ierr] = cg_elements_read(in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data)
% Gateway function for C function cg_elements_read.
%
% [elements, parent_data, ierr] = cg_elements_read(file_number, B, Z, S, elements, parent_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%        elements: 32-bit integer (int32), array  (also required as input)
%     parent_data: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_elements_read( int file_number, int B, int Z, int S, int * elements, int * parent_data);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 6); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_elements,'int32');
    io_elements=int32(io_elements);
elseif ~isempty(io_elements);
    % Write to it to avoid sharing memory with other variables
    t=io_elements(1); io_elements(1)=t;
end

if ~isa(io_parent_data,'int32');
    io_parent_data=int32(io_parent_data);
elseif ~isempty(io_parent_data);
    % Write to it to avoid sharing memory with other variables
    t=io_parent_data(1); io_parent_data(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(70), in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data);
