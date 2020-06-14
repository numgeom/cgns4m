function [out_user_data_name, ierr] = cg_user_data_read(in_Index)
% Gateway function for C function cg_user_data_read.
%
% [user_data_name, ierr] = cg_user_data_read(Index)
%
% Input argument (required; type is auto-casted):
%           Index: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    user_data_name: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_user_data_read(int Index, char * user_data_name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_Index = int32(in_Index);

% Invoke the actual MEX-function.
[out_user_data_name, ierr] = cgnslib_mex(int32(235), in_Index);
