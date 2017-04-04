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
% int cg_biter_write( int file_number, int B, char const * bitername, int nsteps);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(124), in_file_number, in_B, in_bitername, in_nsteps);
