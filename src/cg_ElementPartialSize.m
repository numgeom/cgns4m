function [out_ElementDataSize, ierr] = cg_ElementPartialSize(in_file_number, in_B, in_Z, in_S, in_start, in_end)
% Gateway function for C function cg_ElementPartialSize.
%
% [ElementDataSize, ierr] = cg_ElementPartialSize(file_number, B, Z, S, start, end)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%           start: 64-bit integer (int64), scalar
%             end: 64-bit integer (int64), scalar
%
% Output arguments (optional):
%    ElementDataSize: 64-bit integer (int64), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ElementPartialSize(int file_number, int B, int Z, int S, long long start, long long end, long long * ElementDataSize);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
in_start = int64(in_start);
in_end = int64(in_end);

% Invoke the actual MEX-function.
[out_ElementDataSize, ierr] = cgnslib_mex(int32(82), in_file_number, in_B, in_Z, in_S, in_start, in_end);
