function [out_bitername, out_nsteps, ierr] = cg_biter_read(in_file_number, in_B)
% Gateway function for C function cg_biter_read.
%
% [bitername, nsteps, ierr] = cg_biter_read(file_number, B)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       bitername: character string
%          nsteps: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_biter_read(int file_number, int B, char * bitername, int * nsteps);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);

% Invoke the actual MEX-function.
[out_bitername, out_nsteps, ierr] = cgnslib_mex(int32(194), in_file_number, in_B);
