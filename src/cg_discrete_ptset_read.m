function [io_pnts, ierr] = cg_discrete_ptset_read(in_fn, in_B, in_Z, in_D, io_pnts)
% Gateway function for C function cg_discrete_ptset_read.
%
% [pnts, ierr] = cg_discrete_ptset_read(fn, B, Z, D, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               D: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            pnts: 64-bit integer (int64), array  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_ptset_read(int fn, int B, int Z, int D, long long * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_D = int32(in_D);
basetype = 'int64';
if ~isa(io_pnts, basetype)
    io_pnts = cast(io_pnts, basetype);
elseif ~isempty(io_pnts)
    % Write to it to unshare memory with other variables
    t = io_pnts(1); io_pnts(1) = t;
end

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(158), in_fn, in_B, in_Z, in_D, io_pnts);
