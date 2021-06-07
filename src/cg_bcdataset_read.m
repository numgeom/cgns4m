function [out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_bcdataset_read(in_index)
% Gateway function for C function cg_bcdataset_read.
%
% [name, BCType, DirichletFlag, NeumannFlag, ierr] = cg_bcdataset_read(index)
%
% Input argument (required; type is auto-casted):
%           index: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            name: character string
%          BCType: 32-bit integer (int32), scalar
%    DirichletFlag: 32-bit integer (int32), scalar
%     NeumannFlag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdataset_read(int index, char * name, CG_BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_index = int32(in_index);

% Invoke the actual MEX-function.
[out_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cgnslib_mex(int32(177), in_index);
