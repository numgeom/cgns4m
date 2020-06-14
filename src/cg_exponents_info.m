function [out_DataType, ierr] = cg_exponents_info()
% Gateway function for C function cg_exponents_info.
%
% [DataType, ierr] = cg_exponents_info()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%        DataType: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_exponents_info(CG_DataType_t * DataType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_DataType, ierr] = cgnslib_mex(int32(250));
