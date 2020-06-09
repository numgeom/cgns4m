function [io_zonename, io_size, ierr] = cg_zone_read(in_fn, in_B, in_Z, io_zonename, io_size)
% Gateway function for C function cg_zone_read.
%
% [zonename, size, ierr] = cg_zone_read(fn, B, Z, zonename, size)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%        zonename: character string with default length 32 
%            size: 32-bit integer (int32), len=9 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zone_read( int fn, int B, int Z, char * zonename, int * size);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/structural.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 3); 
    error('Incorrect number of input or output arguments.');
end
if nargin<4
    io_zonename=char(zeros(1,32));
elseif length(io_zonename)<32
    %% Enlarge the array if necessary;
    io_zonename=char([io_zonename zeros(1,32-length(io_zonename))]);
elseif ~isa(io_zonename,'char');
    io_zonename=char(io_zonename);
else
    % Write to it to avoid sharing memory with other variables
    t=io_zonename(1); io_zonename(1)=t;
end

if nargin<5
    io_size=zeros(1,9,'int32');
elseif length(io_size)<9
    % Enlarge the array if necessary;
    if size(io_size,2)==1;
        io_size=[io_size; zeros(9-length(io_size),1,'int32')];
    else
        io_size=[io_size, zeros(1,9-length(io_size),'int32')];
    end
elseif ~isa(io_size,'int32');
    io_size=int32(io_size);
elseif ~isempty(io_size);
    % Write to it to avoid sharing memory with other variables
    t=io_size(1); io_size(1)=t;
end


% Invoke the actual MEX-function.
[ierr, io_zonename] =  cgnslib_mex(int32(44), in_fn, in_B, in_Z, io_zonename, io_size);
