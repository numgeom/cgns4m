function [io_fambc_name, out_bocotype, ierr] = cg_fambc_read(in_file_number, in_B, in_F, in_BC, io_fambc_name)
% Gateway function for C function cg_fambc_read.
%
% [fambc_name, bocotype, ierr] = cg_fambc_read(file_number, B, F, BC, fambc_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%      fambc_name: character string with default length 32 
%
% Output arguments (optional):
%        bocotype: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_fambc_read( int file_number, int B, int F, int BC, char * fambc_name, BCType_t * bocotype);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/families.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_fambc_name=char(zeros(1,32));
elseif length(io_fambc_name)<32
    %% Enlarge the array if necessary;
    io_fambc_name=char([io_fambc_name zeros(1,32-length(io_fambc_name))]);
elseif ~isa(io_fambc_name,'char');
    io_fambc_name=char(io_fambc_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_fambc_name(1); io_fambc_name(1)=t;
end


% Invoke the actual MEX-function.
[out_bocotype, ierr] =  cgnslib_mex(int32(48), in_file_number, in_B, in_F, in_BC, io_fambc_name);
