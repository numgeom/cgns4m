function [out_filename, out_link_path, ierr] = cg_link_read()
% Gateway function for C function cg_link_read.
%
% [filename, link_path, ierr] = cg_link_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%        filename: character string
%       link_path: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_link_read(char ** filename, char ** link_path);
%
% For detail, see the documentation of the original function.

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_link_read, and the MEX function has deallocated the buffer by
% calling cg_free.

% Invoke the actual MEX-function.
[out_filename, out_link_path, ierr] = cgnslib_mex(int32(277));
