function [io_pnts, ierr] = cg_hole_read(in_fn, in_B, in_Z, in_Ii, io_pnts)
% Gateway function for C function cg_hole_read.
%
% [pnts, ierr] = cg_hole_read(fn, B, Z, Ii, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              Ii: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            pnts: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_read(int fn, int B, int Z, int Ii, int * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_Ii = int32(in_Ii);
io_pnts = int32(io_pnts);
basetype='int32';
if ~isa(io_pnts,basetype)
    io_pnts=int32(io_pnts);
elseif ~isempty(io_pnts)
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(123), in_fn, in_B, in_Z, in_Ii, io_pnts);
