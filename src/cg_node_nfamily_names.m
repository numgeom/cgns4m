function [out_nnames, ierr] = cg_node_nfamily_names()
% Gateway function for C function cg_node_nfamily_names.
%
% [nnames, ierr] = cg_node_nfamily_names()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%          nnames: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_nfamily_names(int * nnames);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nnames, ierr] = cgnslib_mex(int32(62));
