function [out_Dset, ierr] = cg_dataset_write(in_file_number, in_B, in_Z, in_BC, in_name, in_BCType)
% Gateway function for C function cg_dataset_write.
%
% [Dset, ierr] = cg_dataset_write(file_number, B, Z, BC, name, BCType)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%            name: character string
%          BCType: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            Dset: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_dataset_write(int file_number, int B, int Z, int BC, const char * name, CG_BCType_t BCType, int * Dset);
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
in_name = char(in_name);
in_BCType = int32(in_BCType);

% Invoke the actual MEX-function.
[out_Dset, ierr] = cgnslib_mex(int32(148), in_file_number, in_B, in_Z, in_BC, in_name, in_BCType);
