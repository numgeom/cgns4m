function ret = cg_goto(in_file_number, in_B, in_int )
% Gateway function for C function cg_goto.
%
% ret = cg_goto(file_number, B, int )
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%            int : unsupported type, scalar
%
% Output argument (optional):
%             ret: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_goto(int file_number, int B, ... int );
%
% For detail, see the documentation of the original function.
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_int  = unknown(in_int );

% Invoke the actual MEX-function.
ret = cgnslib_mex(int32(167), in_file_number, in_B, in_int );
