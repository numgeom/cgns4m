function [out_StateDescription, ierr] = cg_state_read()
% Gateway function for C function cg_state_read.
%
% [StateDescription, ierr] = cg_state_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%    StateDescription: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_state_read( char ** StateDescription);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/auxiliary.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_state_read, and the MEX function has deallocated the buffer by 
% calling cg_free.

% Invoke the actual MEX-function.
[out_StateDescription, ierr] =  cgnslib_mex(int32(152));
