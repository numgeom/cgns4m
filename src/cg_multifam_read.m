function [out_name, out_family, ierr] = cg_multifam_read(in_N)
% Gateway function for C function cg_multifam_read.
%
% [name, family, ierr] = cg_multifam_read(N)
%
% Input argument (required; type is auto-casted):
%               N: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            name: character string
%          family: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_multifam_read(int N, char * name, char * family);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_N = int32(in_N);

% Invoke the actual MEX-function.
[out_name, out_family, ierr] = cgnslib_mex(int32(67), in_N);
