function [out_npe, ierr] = cg_npe(in_type)
% Gateway function for C function cg_npe.
%
% [npe, ierr] = cg_npe(type)
%
% Input argument (required; type is auto-casted):
%            type: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%             npe: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_npe(CG_ElementType_t type, int * npe);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_type = int32(in_type);

% Invoke the actual MEX-function.
[out_npe, ierr] = cgnslib_mex(int32(85), in_type);
