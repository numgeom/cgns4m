function [out_nfamilies, ierr] = cg_node_nfamilies()
% Gateway function for C function cg_node_nfamilies.
%
% [nfamilies, ierr] = cg_node_nfamilies()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%       nfamilies: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_nfamilies(int * nfamilies);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nfamilies, ierr] = cgnslib_mex(int32(59));
