function [out_discrete_name, ierr] = cg_discrete_read(in_file_number, in_B, in_Z, in_D)
% Gateway function for C function cg_discrete_read.
%
% [discrete_name, ierr] = cg_discrete_read(file_number, B, Z, D)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               D: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    discrete_name: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_read(int file_number, int B, int Z, int D, char * discrete_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_D = int32(in_D);

% Invoke the actual MEX-function.
[out_discrete_name, ierr] = cgnslib_mex(int32(180), in_file_number, in_B, in_Z, in_D);
