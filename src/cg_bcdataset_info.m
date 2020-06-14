function [out_n_dataset, ierr] = cg_bcdataset_info()
% Gateway function for C function cg_bcdataset_info.
%
% [n_dataset, ierr] = cg_bcdataset_info()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%       n_dataset: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdataset_info(int * n_dataset);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_n_dataset, ierr] = cgnslib_mex(int32(168));
