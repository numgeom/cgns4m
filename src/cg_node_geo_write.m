function [out_G, ierr] = cg_node_geo_write(in_geo_name, in_filename, in_CADname)
% Gateway function for C function cg_node_geo_write.
%
% [G, ierr] = cg_node_geo_write(geo_name, filename, CADname)
%
% Input arguments (required; type is auto-casted):
%        geo_name: character string
%        filename: character string
%         CADname: character string
%
% Output arguments (optional):
%               G: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_geo_write(const char * geo_name, const char * filename, const char * CADname, int * G);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_geo_name = char(in_geo_name);
in_filename = char(in_filename);
in_CADname = char(in_CADname);

% Invoke the actual MEX-function.
[out_G, ierr] = cgnslib_mex(int32(76), in_geo_name, in_filename, in_CADname);
