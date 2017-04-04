function [out_F, ierr] = cg_family_write(in_file_number, in_B, in_family_name)
% Gateway function for C function cg_family_write.
%
% [F, ierr] = cg_family_write(file_number, B, family_name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%     family_name: character string
%
% Output arguments (optional):
%               F: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_family_write( int file_number, int B, const char * family_name, int * F);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_F, ierr] =  cgnslib_mex(int32(53), in_file_number, in_B, in_family_name);
