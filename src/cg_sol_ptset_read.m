function [io_pnts, ierr] = cg_sol_ptset_read(in_fn, in_B, in_Z, in_S, io_pnts)
% Gateway function for C function cg_sol_ptset_read.
%
% [pnts, ierr] = cg_sol_ptset_read(fn, B, Z, S, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%            pnts: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_ptset_read( int fn, int B, int Z, int S, ptrdiff_t * pnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5); 
    error('Incorrect number of input or output arguments.');
end
if strfind(computer,'64');
    basetype='int64'; ptrdiff_t=@int64;
else
    basetype='int32'; ptrdiff_t=@int32;
end
if ~isa(io_pnts,basetype);
    io_pnts=ptrdiff_t(io_pnts);
elseif ~isempty(io_pnts);
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(89), in_fn, in_B, in_Z, in_S, io_pnts);
