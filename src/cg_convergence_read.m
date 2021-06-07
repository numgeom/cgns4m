function [out_iterations, out_NormDefinitions, ierr] = cg_convergence_read()
% Gateway function for C function cg_convergence_read.
%
% [iterations, NormDefinitions, ierr] = cg_convergence_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%      iterations: 32-bit integer (int32), scalar
%    NormDefinitions: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_convergence_read(int * iterations, char ** NormDefinitions);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_convergence_read, and the MEX function has deallocated the buffer by
% calling cg_free.

% Invoke the actual MEX-function.
[out_iterations, out_NormDefinitions, ierr] = cgnslib_mex(int32(221));
