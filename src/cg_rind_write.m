function ierr = cg_rind_write(in_RindData)
% Gateway function for C function cg_rind_write.
%
% ierr = cg_rind_write(RindData)
%
% Input argument (required; type is auto-casted):
%        RindData: 32-bit integer (int32), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rind_write(const int * RindData);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_RindData = int32(in_RindData);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(249), in_RindData);
