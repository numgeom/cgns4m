function ierr = cg_bc_wallfunction_write(in_file_number, in_B, in_Z, in_BC, in_WallFunctionType)
% Gateway function for C function cg_bc_wallfunction_write.
%
% ierr = cg_bc_wallfunction_write(file_number, B, Z, BC, WallFunctionType)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%    WallFunctionType: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bc_wallfunction_write(int file_number, int B, int Z, int BC, CG_WallFunctionType_t WallFunctionType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
in_WallFunctionType = int32(in_WallFunctionType);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(197), in_file_number, in_B, in_Z, in_BC, in_WallFunctionType);
