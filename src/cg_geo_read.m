function [out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cg_geo_read(in_file_number, in_B, in_F, in_G)
% Gateway function for C function cg_geo_read.
%
% [geo_name, geo_file, CAD_name, npart, ierr] = cg_geo_read(file_number, B, F, G)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        geo_name: character string
%        geo_file: character string
%        CAD_name: character string
%           npart: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_geo_read(int file_number, int B, int F, int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_geo_read, and the MEX function has deallocated the buffer by
% calling cg_free.
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_F = int32(in_F);
in_G = int32(in_G);

% Invoke the actual MEX-function.
[out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cgnslib_mex(int32(65), in_file_number, in_B, in_F, in_G);
