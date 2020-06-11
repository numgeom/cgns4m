function [out_D, ierr] = cg_discrete_write(in_file_number, in_B, in_Z, in_discrete_name)
% Gateway function for C function cg_discrete_write.
%
% [D, ierr] = cg_discrete_write(file_number, B, Z, discrete_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%    discrete_name: character string
%
% Output arguments (optional):
%               D: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_write( int file_number, int B, int Z, char const * discrete_name, int * D);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_D, ierr] =  cgnslib_mex(int32(122), in_file_number, in_B, in_Z, in_discrete_name);
