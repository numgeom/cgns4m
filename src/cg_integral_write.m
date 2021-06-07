function ierr = cg_integral_write(in_IntegralDataName)
% Gateway function for C function cg_integral_write.
%
% ierr = cg_integral_write(IntegralDataName)
%
% Input argument (required; type is auto-casted):
%    IntegralDataName: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_integral_write(const char * IntegralDataName);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_IntegralDataName = char(in_IntegralDataName);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(247), in_IntegralDataName);
