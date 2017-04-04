function [out_n_arbitrary_motions, ierr] = cg_n_arbitrary_motions(in_file_number, in_B, in_Z)
% Gateway function for C function cg_n_arbitrary_motions.
%
% [n_arbitrary_motions, ierr] = cg_n_arbitrary_motions(file_number, B, Z)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    n_arbitrary_motions: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_n_arbitrary_motions( int file_number, int B, int Z, int * n_arbitrary_motions);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_n_arbitrary_motions, ierr] =  cgnslib_mex(int32(120), in_file_number, in_B, in_Z);
