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
% In&Out arguments (required as output; type is auto-casted):
%        elements: 64-bit integer (int64), array  (must be preallocated at input)
%     parent_data: 64-bit integer (int64), array  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_elements_read(int file_number, int B, int Z, int S, long long * elements, long long * parent_data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
basetype = 'int64';
if ~isa(io_elements,basetype)
    io_elements = cast(io_elements, basetype);
elseif ~isempty(io_elements)
    % Write to it to unshare memory with other variables
    t=io_elements(1); io_elements(1)=t;
end

basetype = 'int64';
if ~isa(io_parent_data,basetype)
    io_parent_data = cast(io_parent_data, basetype);
elseif ~isempty(io_parent_data)
    % Write to it to unshare memory with other variables
    t=io_parent_data(1); io_parent_data(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(96), in_file_number, in_B, in_Z, in_S, io_elements, io_parent_data);
