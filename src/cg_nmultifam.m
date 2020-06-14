function [out_nfams, ierr] = cg_nmultifam()
% Gateway function for C function cg_nmultifam.
%
% [nfams, ierr] = cg_nmultifam()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%           nfams: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nmultifam(int * nfams);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nfams, ierr] = cgnslib_mex(int32(66));
