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
%           start: 32-bit integer (int32), scalar
%             end: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%    ElementDataSize: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ElementPartialSize( int file_number, int B, int Z, int S, int start, int end, int * ElementDataSize);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if (nargin < 6); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_ElementDataSize, ierr] =  cgnslib_mex(int32(79), in_file_number, in_B, in_Z, in_S, in_start, in_end);
