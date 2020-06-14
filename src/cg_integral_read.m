function [out_IntegralDataName, ierr] = cg_integral_read(in_IntegralDataIndex)
% Gateway function for C function cg_integral_read.
%
% [IntegralDataName, ierr] = cg_integral_read(IntegralDataIndex)
%
% Input argument (required; type is auto-casted):
%    IntegralDataIndex: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    IntegralDataName: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_integral_read(int IntegralDataIndex, char * IntegralDataName);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_IntegralDataIndex = int32(in_IntegralDataIndex);

% Invoke the actual MEX-function.
[out_IntegralDataName, ierr] = cgnslib_mex(int32(207), in_IntegralDataIndex);
