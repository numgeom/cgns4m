function [out_AreaType, out_SurfaceArea, out_RegionName, ierr] = cg_bc_area_read(in_file_number, in_B, in_Z, in_BC)
% Gateway function for C function cg_bc_area_read.
%
% [AreaType, SurfaceArea, RegionName, ierr] = cg_bc_area_read(file_number, B, Z, BC)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        AreaType: 32-bit integer (int32), scalar
%     SurfaceArea: single-precision (single), scalar
%      RegionName: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bc_area_read(int file_number, int B, int Z, int BC, CG_AreaType_t * AreaType, float * SurfaceArea, char * RegionName);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);

% Invoke the actual MEX-function.
[out_AreaType, out_SurfaceArea, out_RegionName, ierr] = cgnslib_mex(int32(180), in_file_number, in_B, in_Z, in_BC);
