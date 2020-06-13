function [io_file_number, io_B, io_depth, io_num, out_label, ret] = cg_where(io_file_number, io_B, io_depth, io_num)
% Gateway function for C function cg_where.
%
% [file_number, B, depth, num, label, ret] = cg_where(file_number, B, depth, num)
%
% Input argument (required; type is auto-casted):
%
% In&Out arguments (required as output; type is auto-casted):
%     file_number: 32-bit integer (int32), array  (also required as input)
%               B: 32-bit integer (int32), array  (also required as input)
%           depth: 32-bit integer (int32), array  (also required as input)
%             num: 32-bit integer (int32), array  (also required as input)
%
% Output arguments (optional):
%           label: character string
%             ret: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_where(int * file_number, int * B, int * depth, char ** label, int * num);
%
% For detail, see the documentation of the original function.
if ( nargout < 4 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
basetype = 'int32';
if ~isa(io_file_number,basetype)
    io_file_number = cast(io_file_number, basetype);
elseif ~isempty(io_file_number)
    % Write to it to avoid sharing memory with other variables
    t=io_file_number(1); io_file_number(1)=t;
end

basetype = 'int32';
if ~isa(io_B,basetype)
    io_B = cast(io_B, basetype);
elseif ~isempty(io_B)
    % Write to it to avoid sharing memory with other variables
    t=io_B(1); io_B(1)=t;
end

basetype = 'int32';
if ~isa(io_depth,basetype)
    io_depth = cast(io_depth, basetype);
elseif ~isempty(io_depth)
    % Write to it to avoid sharing memory with other variables
    t=io_depth(1); io_depth(1)=t;
end

basetype = 'int32';
if ~isa(io_num,basetype)
    io_num = cast(io_num, basetype);
elseif ~isempty(io_num)
    % Write to it to avoid sharing memory with other variables
    t=io_num(1); io_num(1)=t;
end


% Invoke the actual MEX-function.
[out_label, ret] = cgnslib_mex(int32(171), io_file_number, io_B, io_depth, io_num);
