function [io_connectname, io_donorname, io_range, io_donor_range, io_transform, ierr] = cg_1to1_read(in_fn, in_B, in_Z, in_I, io_connectname, io_donorname, io_range, io_donor_range, io_transform)
% Gateway function for C function cg_1to1_read.
%
% [connectname, donorname, range, donor_range, transform, ierr] = cg_1to1_read(fn, B, Z, I, connectname, donorname, range, donor_range, transform)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%     connectname: character string with default length 32 
%       donorname: character string with default length 32 
%           range: 64-bit or 32-bit integer (platform dependent), len=6 
%     donor_range: 64-bit or 32-bit integer (platform dependent), len=6 
%       transform: 32-bit integer (int32), len=3 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_read( int fn, int B, int Z, int I, char * connectname, char * donorname, ptrdiff_t * range, ptrdiff_t * donor_range, int * transform);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 5 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_connectname=char(zeros(1,32));
elseif length(io_connectname)<32
    %% Enlarge the array if necessary;
    io_connectname=char([io_connectname zeros(1,32-length(io_connectname))]);
elseif ~isa(io_connectname,'char');
    io_connectname=char(io_connectname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_connectname(1); io_connectname(1)=t;
end

if nargin<6
    io_donorname=char(zeros(1,32));
elseif length(io_donorname)<32
    %% Enlarge the array if necessary;
    io_donorname=char([io_donorname zeros(1,32-length(io_donorname))]);
elseif ~isa(io_donorname,'char');
    io_donorname=char(io_donorname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_donorname(1); io_donorname(1)=t;
end

if strfind(computer,'64');
    basetype='int64'; ptrdiff_t=@int64;
else
    basetype='int32'; ptrdiff_t=@int32;
end
if nargin<7
    io_range=zeros(1,6,basetype);
elseif length(io_range)<6
    % Enlarge the array if necessary;
    if size(io_range,2)==1;
        io_range=[io_range; zeros(6-length(io_range),1,basetype)];
    else
        io_range=[io_range, zeros(1,6-length(io_range),basetype)];
    end
elseif ~isa(io_range,basetype);
    io_range=ptrdiff_t(io_range);
elseif ~isempty(io_range);
    % Write to it to avoid sharing memory with other variables
    t=io_range(1); io_range(1)=t;
end

if strfind(computer,'64');
    basetype='int64'; ptrdiff_t=@int64;
else
    basetype='int32'; ptrdiff_t=@int32;
end
if nargin<8
    io_donor_range=zeros(1,6,basetype);
elseif length(io_donor_range)<6
    % Enlarge the array if necessary;
    if size(io_donor_range,2)==1;
        io_donor_range=[io_donor_range; zeros(6-length(io_donor_range),1,basetype)];
    else
        io_donor_range=[io_donor_range, zeros(1,6-length(io_donor_range),basetype)];
    end
elseif ~isa(io_donor_range,basetype);
    io_donor_range=ptrdiff_t(io_donor_range);
elseif ~isempty(io_donor_range);
    % Write to it to avoid sharing memory with other variables
    t=io_donor_range(1); io_donor_range(1)=t;
end

basetype='int32';
if nargin<9
    io_transform=zeros(1,3,basetype);
elseif length(io_transform)<3
    % Enlarge the array if necessary;
    if size(io_transform,2)==1;
        io_transform=[io_transform; zeros(3-length(io_transform),1,basetype)];
    else
        io_transform=[io_transform, zeros(1,3-length(io_transform),basetype)];
    end
elseif ~isa(io_transform,basetype);
    io_transform=int32(io_transform);
elseif ~isempty(io_transform);
    % Write to it to avoid sharing memory with other variables
    t=io_transform(1); io_transform(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(123), in_fn, in_B, in_Z, in_I, io_connectname, io_donorname, io_range, io_donor_range, io_transform);
