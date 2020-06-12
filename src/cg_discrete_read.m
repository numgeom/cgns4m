function [io_discrete_name, ierr] = cg_discrete_read(in_file_number, in_B, in_Z, in_D, io_discrete_name)
% Gateway function for C function cg_discrete_read.
%
% [discrete_name, ierr] = cg_discrete_read(file_number, B, Z, D, discrete_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               D: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%    discrete_name: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_read(int file_number, int B, int Z, int D, char * discrete_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_D = int32(in_D);
io_discrete_name = char(io_discrete_name);
if nargin<5
    io_discrete_name=char(zeros(1,32));
elseif length(io_discrete_name)<32
    %% Enlarge the array if necessary;
    io_discrete_name=char([io_discrete_name zeros(1,32-length(io_discrete_name))]);
elseif ~isa(io_discrete_name,'char')
    io_discrete_name=char(io_discrete_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_discrete_name(1); io_discrete_name(1)=t;
end


% Invoke the actual MEX-function.
[io_discrete_name, ierr] = cgnslib_mex(int32(154), in_file_number, in_B, in_Z, in_D, io_discrete_name);
