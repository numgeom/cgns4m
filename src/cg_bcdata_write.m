function ierr = cg_bcdata_write(in_file_number, in_B, in_Z, in_BC, in_Dset, in_BCDataType)
% Gateway function for C function cg_bcdata_write.
%
% ierr = cg_bcdata_write(file_number, B, Z, BC, Dset, BCDataType)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%            Dset: 32-bit integer (int32), scalar
%      BCDataType: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset, CG_BCDataType_t BCDataType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
in_Dset = int32(in_Dset);
in_BCDataType = int32(in_BCDataType);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(152), in_file_number, in_B, in_Z, in_BC, in_Dset, in_BCDataType);
