function [out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS)
% Gateway function for C function cg_dataset_read.
%
% [name, BCType, DirichletFlag, NeumannFlag, ierr] = cg_dataset_read(fn, B, Z, BC, DS)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%              DS: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            name: character string
%          BCType: 32-bit integer (int32), scalar
%    DirichletFlag: 32-bit integer (int32), scalar
%     NeumannFlag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_dataset_read(int fn, int B, int Z, int BC, int DS, char * name, CG_BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
in_DS = int32(in_DS);

% Invoke the actual MEX-function.
[out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cgnslib_mex(int32(147), in_fn, in_B, in_Z, in_BC, in_DS);
