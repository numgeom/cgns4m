function [out_type, out_coordname, ierr] = cg_coord_info(in_fn, in_B, in_Z, in_C)
% Gateway function for C function cg_coord_info.
%
% [type, coordname, ierr] = cg_coord_info(fn, B, Z, C)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               C: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            type: 32-bit integer (int32), scalar
%       coordname: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_info(int fn, int B, int Z, int C, CG_DataType_t * type, char * coordname);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_C = int32(in_C);

% Invoke the actual MEX-function.
[out_type, out_coordname, ierr] = cgnslib_mex(int32(73), in_fn, in_B, in_Z, in_C);
