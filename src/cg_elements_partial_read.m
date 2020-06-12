function [io_elements, io_parent_data, ierr] = cg_elements_partial_read(in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data)
% Gateway function for C function cg_elements_partial_read.
%
% [elements, parent_data, ierr] = cg_elements_partial_read(file_number, B, Z, S, start, end, elements, parent_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%           start: 64-bit or 32-bit integer (platform dependent), scalar
%             end: 64-bit or 32-bit integer (platform dependent), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%        elements: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%     parent_data: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_elements_partial_read(int file_number, int B, int Z, int S, long start, long end, long * elements, long * parent_data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 8)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
if strfind(computer,'64') %#ok<STRIFCND>
    in_start = int64(in_start);
else
    in_start = int32(in_start);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_end = int64(in_end);
else
    in_end = int32(in_end);
end
if strfind(computer,'64') %#ok<STRIFCND>
    io_elements = int64(io_elements);
else
    io_elements = int32(io_elements);
end
if strfind(computer,'64') %#ok<STRIFCND>
    io_parent_data = int64(io_parent_data);
else
    io_parent_data = int32(io_parent_data);
end
if strfind(computer,'64')  %#ok<STRIFCND>
    basetype = 'int64';
else
    basetype = 'int32';
end
if ~isa(io_elements,basetype)
    io_elements = cast(io_elements, basetype);
elseif ~isempty(io_elements)
    % Write to it to avoid sharing memory with other variables
    t=io_elements(1); io_elements(1)=t;
end

if strfind(computer,'64')  %#ok<STRIFCND>
    basetype = 'int64';
else
    basetype = 'int32';
end
if ~isa(io_parent_data,basetype)
    io_parent_data = cast(io_parent_data, basetype);
elseif ~isempty(io_parent_data)
    % Write to it to avoid sharing memory with other variables
    t=io_parent_data(1); io_parent_data(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(90), in_file_number, in_B, in_Z, in_S, in_start, in_end, io_elements, io_parent_data);
