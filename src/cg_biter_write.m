function ierr = cg_biter_write(in_file_number, in_B, in_bitername, in_nsteps)
% Gateway function for C function cg_biter_write.
%
% ierr = cg_biter_write(file_number, B, bitername, nsteps)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%       bitername: character string
%          nsteps: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_biter_write(int file_number, int B, const char * bitername, int nsteps);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_bitername = char(in_bitername);
in_nsteps = int32(in_nsteps);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(195), in_file_number, in_B, in_bitername, in_nsteps);
