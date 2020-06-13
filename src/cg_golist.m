function [io_num, out_label, ret] = cg_golist(in_file_number, in_B, in_depth, io_num)
% Gateway function for C function cg_golist.
%
% [num, label, ret] = cg_golist(file_number, B, depth, num)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%           depth: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%             num: 32-bit integer (int32), array  (also required as input)
%
% Output arguments (optional):
%           label: character string
%             ret: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_golist(int file_number, int B, int depth, char ** label, int * num);
%
% For detail, see the documentation of the original function.
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_depth = int32(in_depth);
basetype = 'int32';
if ~isa(io_num,basetype)
    io_num = cast(io_num, basetype);
elseif ~isempty(io_num)
    % Write to it to avoid sharing memory with other variables
    t=io_num(1); io_num(1)=t;
end


% Invoke the actual MEX-function.
[out_label, ret] = cgnslib_mex(int32(170), in_file_number, in_B, in_depth, io_num);
