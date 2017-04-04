function [io_RotationCenter, io_RotationAngle, io_Translation, ierr] = cg_conn_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation)
% Gateway function for C function cg_conn_periodic_read.
%
% [RotationCenter, RotationAngle, Translation, ierr] = cg_conn_periodic_read(file_number, B, Z, I, RotationCenter, RotationAngle, Translation)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%    RotationCenter: single-precision (single), len=3 
%    RotationAngle: single-precision (single), len=3 
%     Translation: single-precision (single), len=3 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_periodic_read( int file_number, int B, int Z, int I, float * RotationCenter, float * RotationAngle, float * Translation);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 3 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_RotationCenter=zeros(1,3,'single');
elseif length(io_RotationCenter)<3
    % Enlarge the array if necessary;
    if size(io_RotationCenter,2)==1;
        io_RotationCenter=[io_RotationCenter; zeros(3-length(io_RotationCenter),1,'single')];
    else
        io_RotationCenter=[io_RotationCenter, zeros(1,3-length(io_RotationCenter),'single')];
    end
elseif ~isa(io_RotationCenter,'single');
    io_RotationCenter=single(io_RotationCenter);
elseif ~isempty(io_RotationCenter);
    % Write to it to avoid sharing memory with other variables
    t=io_RotationCenter(1); io_RotationCenter(1)=t;
end

if nargin<6
    io_RotationAngle=zeros(1,3,'single');
elseif length(io_RotationAngle)<3
    % Enlarge the array if necessary;
    if size(io_RotationAngle,2)==1;
        io_RotationAngle=[io_RotationAngle; zeros(3-length(io_RotationAngle),1,'single')];
    else
        io_RotationAngle=[io_RotationAngle, zeros(1,3-length(io_RotationAngle),'single')];
    end
elseif ~isa(io_RotationAngle,'single');
    io_RotationAngle=single(io_RotationAngle);
elseif ~isempty(io_RotationAngle);
    % Write to it to avoid sharing memory with other variables
    t=io_RotationAngle(1); io_RotationAngle(1)=t;
end

if nargin<7
    io_Translation=zeros(1,3,'single');
elseif length(io_Translation)<3
    % Enlarge the array if necessary;
    if size(io_Translation,2)==1;
        io_Translation=[io_Translation; zeros(3-length(io_Translation),1,'single')];
    else
        io_Translation=[io_Translation, zeros(1,3-length(io_Translation),'single')];
    end
elseif ~isa(io_Translation,'single');
    io_Translation=single(io_Translation);
elseif ~isempty(io_Translation);
    % Write to it to avoid sharing memory with other variables
    t=io_Translation(1); io_Translation(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(137), in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation);
