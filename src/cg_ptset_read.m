function [io_pnts, ierr] = cg_ptset_read(io_pnts)
% Gateway function for C function cg_ptset_read.
%
% [pnts, ierr] = cg_ptset_read(pnts)
%
% Input argument (required; type is auto-casted):
%
% In&Out argument (required as output; type is auto-casted):
%            pnts: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ptset_read(long * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end
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
ierr = cgnslib_mex(int32(249), io_pnts);
