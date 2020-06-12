function [io_geo_name, io_CAD_name, out_geo_file, out_npart, ierr] = cg_geo_read(in_file_number, in_B, in_F, in_G, io_geo_name, io_CAD_name)
% Gateway function for C function cg_geo_read.
%
% [geo_name, CAD_name, geo_file, npart, ierr] = cg_geo_read(file_number, B, F, G, geo_name, CAD_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%        geo_name: character string with default length 32  (optional as input)
%        CAD_name: character string with default length 32  (optional as input)
%
% Output arguments (optional):
%        geo_file: character string
%           npart: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_geo_read(int file_number, int B, int F, int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_geo_read, and the MEX function has deallocated the buffer by
% calling cg_free.
if ( nargout < 2 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_G = int32(in_G);
io_geo_name = char(io_geo_name);
io_CAD_name = char(io_CAD_name);
if nargin<5
    io_geo_name=char(zeros(1,32));
elseif length(io_geo_name)<32
    %% Enlarge the array if necessary;
    io_geo_name=char([io_geo_name zeros(1,32-length(io_geo_name))]);
elseif ~isa(io_geo_name,'char')
    io_geo_name=char(io_geo_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_geo_name(1); io_geo_name(1)=t;
end

if nargin<6
    io_CAD_name=char(zeros(1,32));
elseif length(io_CAD_name)<32
    %% Enlarge the array if necessary;
    io_CAD_name=char([io_CAD_name zeros(1,32-length(io_CAD_name))]);
elseif ~isa(io_CAD_name,'char')
    io_CAD_name=char(io_CAD_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_CAD_name(1); io_CAD_name(1)=t;
end


% Invoke the actual MEX-function.
[io_geo_name, io_CAD_name, out_geo_file, out_npart, ierr] = cgnslib_mex(int32(65), in_file_number, in_B, in_F, in_G, io_geo_name, io_CAD_name);
