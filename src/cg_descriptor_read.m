function [io_descr_name, out_descr_text, ierr] = cg_descriptor_read(in_descr_no, io_descr_name)
% Gateway function for C function cg_descriptor_read.
%
% [descr_name, descr_text, ierr] = cg_descriptor_read(descr_no, descr_name)
%
% Input argument (required; type is auto-casted): 
%        descr_no: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%      descr_name: character string with default length 32 
%
% Output arguments (optional):
%      descr_text: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_descriptor_read( int descr_no, char * descr_name, char ** descr_text);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/descriptor.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_descriptor_read, and the MEX function has deallocated the buffer by 
% calling cg_free.
if ( nargout < 1 || nargin < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<2
    io_descr_name=char(zeros(1,32));
elseif length(io_descr_name)<32
    %% Enlarge the array if necessary;
    io_descr_name=char([io_descr_name zeros(1,32-length(io_descr_name))]);
elseif ~isa(io_descr_name,'char');
    io_descr_name=char(io_descr_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_descr_name(1); io_descr_name(1)=t;
end


% Invoke the actual MEX-function.
[out_descr_text, ierr] =  cgnslib_mex(int32(178), in_descr_no, io_descr_name);
