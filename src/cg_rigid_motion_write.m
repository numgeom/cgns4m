function [out_R, ierr] = cg_rigid_motion_write(in_file_number, in_B, in_Z, in_name, in_type)
% Gateway function for C function cg_rigid_motion_write.
%
% [R, ierr] = cg_rigid_motion_write(file_number, B, Z, name, type)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%            name: character string
%            type: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%               R: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_rigid_motion_write(int file_number, int B, int Z, const char * name, CG_RigidGridMotionType_t type, int * R);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_name = char(in_name);
in_type = int32(in_type);

% Invoke the actual MEX-function.
[out_R, ierr] = cgnslib_mex(int32(162), in_file_number, in_B, in_Z, in_name, in_type);
