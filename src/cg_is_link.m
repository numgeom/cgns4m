function [out_path_length, ierr] = cg_is_link()
% Gateway function for C function cg_is_link.
%
% [path_length, ierr] = cg_is_link()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%     path_length: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_is_link(int * path_length);
%
% For detail, see the documentation of the original function.

% Invoke the actual MEX-function.
[out_path_length, ierr] = cgnslib_mex(int32(237));
