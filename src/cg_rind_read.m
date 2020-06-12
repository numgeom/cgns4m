function [io_RindData, ierr] = cg_rind_read(io_RindData)
% Gateway function for C function cg_rind_read.
%
% [RindData, ierr] = cg_rind_read(RindData)
%
% Input argument (required; type is auto-casted):
%
% In&Out argument (required as output; type is auto-casted):
%        RindData: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rind_read(int * RindData);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end
io_RindData = int32(io_RindData);
basetype = 'int32';
if ~isa(io_RindData,basetype)
    io_RindData = cast(io_RindData, basetype);
elseif ~isempty(io_RindData)
    % Write to it to avoid sharing memory with other variables
    t=io_RindData(1); io_RindData(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(222), io_RindData);
