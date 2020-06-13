function [out_nintegrals, ierr] = cg_nintegrals()
% Gateway function for C function cg_nintegrals.
%
% [nintegrals, ierr] = cg_nintegrals()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%      nintegrals: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nintegrals(int * nintegrals);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nintegrals, ierr] = cgnslib_mex(int32(206));
