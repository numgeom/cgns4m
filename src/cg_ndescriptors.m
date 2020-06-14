function [out_ndescriptors, ierr] = cg_ndescriptors()
% Gateway function for C function cg_ndescriptors.
%
% [ndescriptors, ierr] = cg_ndescriptors()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%    ndescriptors: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ndescriptors(int * ndescriptors);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_ndescriptors, ierr] = cgnslib_mex(int32(242));
