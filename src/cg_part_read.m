function [io_part_name, ierr] = cg_part_read(in_file_number, in_B, in_F, in_G, in_P, io_part_name)
% Gateway function for C function cg_part_read.
%
% [part_name, ierr] = cg_part_read(file_number, B, F, G, P, part_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%               P: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%       part_name: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_part_read( int file_number, int B, int F, int G, int P, char * part_name);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/families.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5); 
    error('Incorrect number of input or output arguments.');
end
if nargin<6
    io_part_name=char(zeros(1,32));
elseif length(io_part_name)<32
    %% Enlarge the array if necessary;
    io_part_name=char([io_part_name zeros(1,32-length(io_part_name))]);
elseif ~isa(io_part_name,'char');
    io_part_name=char(io_part_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_part_name(1); io_part_name(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(52), in_file_number, in_B, in_F, in_G, in_P, io_part_name);
