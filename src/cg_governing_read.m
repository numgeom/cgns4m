function [out_EquationsType, ierr] = cg_governing_read()
% Gateway function for C function cg_governing_read.
%
% [EquationsType, ierr] = cg_governing_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%    EquationsType: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_governing_read(CG_GoverningEquationsType_t * EquationsType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_EquationsType, ierr] = cgnslib_mex(int32(221));
