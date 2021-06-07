function [out_name, out_type, ierr] = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A)
% Gateway function for C function cg_arbitrary_motion_read.
%
% [name, type, ierr] = cg_arbitrary_motion_read(file_number, B, Z, A)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               A: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            name: character string
%            type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_arbitrary_motion_read(int file_number, int B, int Z, int A, char * name, CG_ArbitraryGridMotionType_t * type);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_A = int32(in_A);

% Invoke the actual MEX-function.
[out_name, out_type, ierr] = cgnslib_mex(int32(190), in_file_number, in_B, in_Z, in_A);
