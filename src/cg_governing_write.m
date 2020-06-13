function ierr = cg_governing_write(in_Equationstype)
% Gateway function for C function cg_governing_write.
%
% ierr = cg_governing_write(Equationstype)
%
% Input argument (required; type is auto-casted):
%    Equationstype: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_governing_write(CG_GoverningEquationsType_t Equationstype);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_Equationstype = int32(in_Equationstype);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(204), in_Equationstype);
