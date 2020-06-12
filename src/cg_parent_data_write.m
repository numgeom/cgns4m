function ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data)
% Gateway function for C function cg_parent_data_write.
%
% ierr = cg_parent_data_write(file_number, B, Z, S, parent_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%     parent_data: 64-bit or 32-bit integer (platform dependent), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_parent_data_write(int file_number, int B, int Z, int S, const long * parent_data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
if strfind(computer,'64') %#ok<STRIFCND>
    in_parent_data = int64(in_parent_data);
else
    in_parent_data = int32(in_parent_data);
end

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(84), in_file_number, in_B, in_Z, in_S, in_parent_data);
