function ierr = cg_bc_area_write(in_file_number, in_B, in_Z, in_BC, in_AreaType, in_SurfaceArea, in_RegionName)
% Gateway function for C function cg_bc_area_write.
%
% ierr = cg_bc_area_write(file_number, B, Z, BC, AreaType, SurfaceArea, RegionName)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%        AreaType: 32-bit integer (int32), scalar
%     SurfaceArea: single-precision (single), scalar
%      RegionName: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bc_area_write( int file_number, int B, int Z, int BC, AreaType_t AreaType, float SurfaceArea, char const * RegionName);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 7); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(144), in_file_number, in_B, in_Z, in_BC, in_AreaType, in_SurfaceArea, in_RegionName);
