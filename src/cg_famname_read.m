function [io_family_name, ierr] = cg_famname_read(io_family_name)
% Gateway function for C function cg_famname_read.
%
% [family_name, ierr] = cg_famname_read(family_name)
%
% Input argument (required; type is auto-casted): 
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%     family_name: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_famname_read( char * family_name);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if ( nargout < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<1
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
[ierr, io_family_name] =  cgnslib_mex(int32(51), io_family_name);
