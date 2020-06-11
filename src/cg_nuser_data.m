function [out_nuser_data, ierr] = cg_nuser_data()
% Gateway function for C function cg_nuser_data.
%
% [nuser_data, ierr] = cg_nuser_data()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%      nuser_data: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nuser_data( int * nuser_data);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_nuser_data, ierr] =  cgnslib_mex(int32(177));
