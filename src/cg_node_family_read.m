function [out_family_name, out_nFamBC, out_nGeo, ierr] = cg_node_family_read(in_F)
% Gateway function for C function cg_node_family_read.
%
% [family_name, nFamBC, nGeo, ierr] = cg_node_family_read(F)
%
% Input argument (required; type is auto-casted):
%               F: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     family_name: character string
%          nFamBC: 32-bit integer (int32), scalar
%            nGeo: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_node_family_read(int F, char * family_name, int * nFamBC, int * nGeo);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_F = int32(in_F);

% Invoke the actual MEX-function.
[out_family_name, out_nFamBC, out_nGeo, ierr] = cgnslib_mex(int32(60), in_F);
