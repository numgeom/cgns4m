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
% In&Out argument (required as output; type is auto-casted):
%            pnts: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_ptset_read(int fn, int B, int Z, int S, long * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
if strfind(computer,'64')  %#ok<STRIFCND>
    basetype = 'int64';
else
    basetype = 'int32';
end
if ~isa(io_pnts,basetype)
    io_pnts = cast(io_pnts, basetype);
elseif ~isempty(io_pnts)
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(98), in_fn, in_B, in_Z, in_S, io_pnts);
