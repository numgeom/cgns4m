function ierr = cg_ziter_write(in_file_number, in_B, in_Z, in_zitername)
% Gateway function for C function cg_ziter_write.
%
% ierr = cg_ziter_write(file_number, B, Z, zitername)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       zitername: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ziter_write( int file_number, int B, int Z, const char * zitername);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(160), in_file_number, in_B, in_Z, in_zitername);
