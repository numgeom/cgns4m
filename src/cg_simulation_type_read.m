function [out_type, ierr] = cg_simulation_type_read(in_file_number, in_B)
% Gateway function for C function cg_simulation_type_read.
%
% [type, ierr] = cg_simulation_type_read(file_number, B)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%            type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_simulation_type_read(int file_number, int B, CG_SimulationType_t * type);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);

% Invoke the actual MEX-function.
[out_type, ierr] = cgnslib_mex(int32(155), in_file_number, in_B);
