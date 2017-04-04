function [io_basename, out_cell_dim, out_phys_dim, ierr] = cg_base_read(in_file_number, in_B, io_basename)
% Gateway function for C function cg_base_read.
%
% [basename, cell_dim, phys_dim, ierr] = cg_base_read(file_number, B, basename)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%        basename: character string with default length 32 
%
% Output arguments (optional):
%        cell_dim: 32-bit integer (int32), scalar
%        phys_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_base_read( int file_number, int B, char * basename, int * cell_dim, int * phys_dim);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2); 
    error('Incorrect number of input or output arguments.');
end
if nargin<3
    io_basename=char(zeros(1,32));
elseif length(io_basename)<32
    %% Enlarge the array if necessary;
    io_basename=char([io_basename zeros(1,32-length(io_basename))]);
elseif ~isa(io_basename,'char');
    io_basename=char(io_basename);
else
    % Write to it to avoid sharing memory with other variables
    t=io_basename(1); io_basename(1)=t;
end


% Invoke the actual MEX-function.
[out_cell_dim, out_phys_dim, ierr] =  cgnslib_mex(int32(41), in_file_number, in_B, io_basename);
