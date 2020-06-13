function ret = cg_gorel(in_file_number, in_int )
% Gateway function for C function cg_gorel.
%
% ret = cg_gorel(file_number, int )
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%            int : unsupported type, scalar
%
% Output argument (optional):
%             ret: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gorel(int file_number, ... int );
%
% For detail, see the documentation of the original function.
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_int  = unknown(in_int );

% Invoke the actual MEX-function.
ret = cgnslib_mex(int32(168), in_file_number, in_int );
