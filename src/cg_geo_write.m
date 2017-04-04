function [out_G, ierr] = cg_geo_write(in_file_number, in_B, in_F, in_geo_name, in_filename, in_CADname)
% Gateway function for C function cg_geo_write.
%
% [G, ierr] = cg_geo_write(file_number, B, F, geo_name, filename, CADname)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%        geo_name: character string
%        filename: character string
%         CADname: character string
%
% Output arguments (optional):
%               G: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_geo_write( int file_number, int B, int F, const char * geo_name, const char * filename, const char * CADname, int * G);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 6); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_G, ierr] =  cgnslib_mex(int32(59), in_file_number, in_B, in_F, in_geo_name, in_filename, in_CADname);
