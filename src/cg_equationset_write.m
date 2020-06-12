function ierr = cg_equationset_write(in_EquationDimension)
% Gateway function for C function cg_equationset_write.
%
% ierr = cg_equationset_write(EquationDimension)
%
% Input argument (required; type is auto-casted):
%    EquationDimension: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_equationset_write(int EquationDimension);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_EquationDimension = int32(in_EquationDimension);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(202), in_EquationDimension);
