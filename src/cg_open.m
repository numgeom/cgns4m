function [out_fn, ierr] = cg_open(in_filename, in_mode)
% Gateway function for C function cg_open.
%
% [fn, ierr] = cg_open(filename, mode)
%
% Input arguments (required; type is auto-casted):
%        filename: character string
%            mode: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%              fn: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_open( char const * filename, int mode, int * fn);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_fn, ierr] =  cgnslib_mex(int32(2), in_filename, in_mode);
