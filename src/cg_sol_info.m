function [io_solname, out_location, ierr] = cg_sol_info(in_fn, in_B, in_Z, in_S, io_solname)
% Gateway function for C function cg_sol_info.
%
% [solname, location, ierr] = cg_sol_info(fn, B, Z, S, solname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%         solname: character string with default length 32 
%
% Output arguments (optional):
%        location: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_info( int fn, int B, int Z, int S, char * solname, GridLocation_t * location);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_solname=char(zeros(1,32));
elseif length(io_solname)<32
    %% Enlarge the array if necessary;
    io_solname=char([io_solname zeros(1,32-length(io_solname))]);
elseif ~isa(io_solname,'char');
    io_solname=char(io_solname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_solname(1); io_solname(1)=t;
end


% Invoke the actual MEX-function.
[out_location, ierr, io_solname] =  cgnslib_mex(int32(81), in_fn, in_B, in_Z, in_S, io_solname);
