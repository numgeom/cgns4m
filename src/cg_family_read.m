function [io_family_name, out_nboco, out_ngeos, ierr] = cg_family_read(in_file_number, in_B, in_F, io_family_name)
% Gateway function for C function cg_family_read.
%
% [family_name, nboco, ngeos, ierr] = cg_family_read(file_number, B, F, family_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%     family_name: character string with default length 32 
%
% Output arguments (optional):
%           nboco: 32-bit integer (int32), scalar
%           ngeos: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_family_read( int file_number, int B, int F, char * family_name, int * nboco, int * ngeos);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 3); 
    error('Incorrect number of input or output arguments.');
end
if nargin<4
    io_family_name=char(zeros(1,32));
elseif length(io_family_name)<32
    %% Enlarge the array if necessary;
    io_family_name=char([io_family_name zeros(1,32-length(io_family_name))]);
elseif ~isa(io_family_name,'char');
    io_family_name=char(io_family_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_family_name(1); io_family_name(1)=t;
end


% Invoke the actual MEX-function.
[out_nboco, out_ngeos, ierr, io_family_name] =  cgnslib_mex(int32(49), in_file_number, in_B, in_F, io_family_name);
