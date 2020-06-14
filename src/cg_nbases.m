function [io_nbases, ierr] = cg_nbases(in_fn, io_nbases)
% Gateway function for C function cg_nbases.
%
% [nbases, ierr] = cg_nbases(fn, nbases)
%
% Input argument (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%          nbases: 32-bit integer (int32), array  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nbases(int fn, int * nbases);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
basetype = 'int32';
if ~isa(io_nbases,basetype)
    io_nbases = cast(io_nbases, basetype);
elseif ~isempty(io_nbases)
    % Write to it to unshare memory with other variables
    t=io_nbases(1); io_nbases(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(40), in_fn, io_nbases);
