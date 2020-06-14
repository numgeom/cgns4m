function [out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cg_node_geo_read(in_G)
% Gateway function for C function cg_node_geo_read.
%
% [geo_name, geo_file, CAD_name, npart, ierr] = cg_node_geo_read(G)
%
% Input argument (required; type is auto-casted):
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
% int cg_node_geo_read(int G, char * geo_name, char ** geo_file, char * CAD_name, int * npart);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_node_geo_read, and the MEX function has deallocated the buffer by
% calling cg_free.
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_G = int32(in_G);

% Invoke the actual MEX-function.
[out_geo_name, out_geo_file, out_CAD_name, out_npart, ierr] = cgnslib_mex(int32(75), in_G);
