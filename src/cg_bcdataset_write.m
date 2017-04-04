function [io_name, ierr] = cg_bcdataset_write(in_BCType, in_BCDataType, io_name)
% Gateway function for C function cg_bcdataset_write.
%
% [name, ierr] = cg_bcdataset_write(BCType, BCDataType, name)
%
% Input arguments (required; type is auto-casted):
%          BCType: 32-bit integer (int32), scalar
%      BCDataType: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%            name: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdataset_write( char * name, BCType_t BCType, BCDataType_t BCDataType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2); 
    error('Incorrect number of input or output arguments.');
end
if nargin<3
    io_name=char(zeros(1,32));
elseif length(io_name)<32
    %% Enlarge the array if necessary;
    io_name=char([io_name zeros(1,32-length(io_name))]);
elseif ~isa(io_name,'char');
    io_name=char(io_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_name(1); io_name(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(110), in_BCType, in_BCDataType, io_name);
