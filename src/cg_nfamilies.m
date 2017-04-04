function [out_nfamilies, ierr] = cg_nfamilies(in_file_number, in_B)
% Gateway function for C function cg_nfamilies.
%
% [nfamilies, ierr] = cg_nfamilies(file_number, B)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       nfamilies: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nfamilies( int file_number, int B, int * nfamilies);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_nfamilies, ierr] =  cgnslib_mex(int32(51), in_file_number, in_B);
