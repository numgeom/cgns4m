function [io_RotationCenter, io_RotationAngle, io_Translation, ierr] = cg_1to1_periodic_read(in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation)
% Gateway function for C function cg_1to1_periodic_read.
%
% [RotationCenter, RotationAngle, Translation, ierr] = cg_1to1_periodic_read(file_number, B, Z, I, RotationCenter, RotationAngle, Translation)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%    RotationCenter: single-precision (single), len=3  (optional as input)
%    RotationAngle: single-precision (single), len=3  (optional as input)
%     Translation: single-precision (single), len=3  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_periodic_read(int file_number, int B, int Z, int I, float * RotationCenter, float * RotationAngle, float * Translation);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 3 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);
basetype = 'single';
if nargin<5
    io_RotationCenter = zeros(1,3,basetype);
elseif length(io_RotationCenter)<3
    % Enlarge the array if necessary;
    if size(io_RotationCenter,2)==1
        io_RotationCenter=[io_RotationCenter; zeros(3-length(io_RotationCenter),1,basetype)];
    else
        io_RotationCenter=[io_RotationCenter, zeros(1,3-length(io_RotationCenter),basetype)];
    end
elseif ~isa(io_RotationCenter,basetype)
    io_RotationCenter = cast(io_RotationCenter, basetype);
elseif ~isempty(io_RotationCenter)
    % Write to it to avoid sharing memory with other variables
    t=io_RotationCenter(1); io_RotationCenter(1)=t;
end

basetype = 'single';
if nargin<6
    io_RotationAngle = zeros(1,3,basetype);
elseif length(io_RotationAngle)<3
    % Enlarge the array if necessary;
    if size(io_RotationAngle,2)==1
        io_RotationAngle=[io_RotationAngle; zeros(3-length(io_RotationAngle),1,basetype)];
    else
        io_RotationAngle=[io_RotationAngle, zeros(1,3-length(io_RotationAngle),basetype)];
    end
elseif ~isa(io_RotationAngle,basetype)
    io_RotationAngle = cast(io_RotationAngle, basetype);
elseif ~isempty(io_RotationAngle)
    % Write to it to avoid sharing memory with other variables
    t=io_RotationAngle(1); io_RotationAngle(1)=t;
end

basetype = 'single';
if nargin<7
    io_Translation = zeros(1,3,basetype);
elseif length(io_Translation)<3
    % Enlarge the array if necessary;
    if size(io_Translation,2)==1
        io_Translation=[io_Translation; zeros(3-length(io_Translation),1,basetype)];
    else
        io_Translation=[io_Translation, zeros(1,3-length(io_Translation),basetype)];
    end
elseif ~isa(io_Translation,basetype)
    io_Translation = cast(io_Translation, basetype);
elseif ~isempty(io_Translation)
    % Write to it to avoid sharing memory with other variables
    t=io_Translation(1); io_Translation(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(174), in_file_number, in_B, in_Z, in_I, io_RotationCenter, io_RotationAngle, io_Translation);
