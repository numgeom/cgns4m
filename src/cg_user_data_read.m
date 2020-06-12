function [io_user_data_name, ierr] = cg_user_data_read(in_Index, io_user_data_name)
% Gateway function for C function cg_user_data_read.
%
% [user_data_name, ierr] = cg_user_data_read(Index, user_data_name)
%
% Input argument (required; type is auto-casted):
%           Index: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%    user_data_name: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_user_data_read(int Index, char * user_data_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_Index = int32(in_Index);
io_user_data_name = char(io_user_data_name);
if nargin<2
    io_user_data_name=char(zeros(1,32));
elseif length(io_user_data_name)<32
    %% Enlarge the array if necessary;
    io_user_data_name=char([io_user_data_name zeros(1,32-length(io_user_data_name))]);
elseif ~isa(io_user_data_name,'char')
    io_user_data_name=char(io_user_data_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_user_data_name(1); io_user_data_name(1)=t;
end


% Invoke the actual MEX-function.
[io_user_data_name, ierr] = cgnslib_mex(int32(217), in_Index, io_user_data_name);
