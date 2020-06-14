function [out_family_name, ierr] = cg_famname_read()
% Gateway function for C function cg_famname_read.
%
% [family_name, ierr] = cg_famname_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%     family_name: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_famname_read(char * family_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_family_name, ierr] = cgnslib_mex(int32(58));
