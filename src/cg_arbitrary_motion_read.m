function [io_name, out_type, ierr] = cg_arbitrary_motion_read(in_file_number, in_B, in_Z, in_A, io_name)
% Gateway function for C function cg_arbitrary_motion_read.
%
% [name, type, ierr] = cg_arbitrary_motion_read(file_number, B, Z, A, name)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               A: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            name: character string with default length 32  (optional as input)
%
% Output arguments (optional):
%            type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_arbitrary_motion_read(int file_number, int B, int Z, int A, char * name, CG_ArbitraryGridMotionType_t * type);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_A = int32(in_A);
io_name = char(io_name);
if nargin<5
    io_name=char(zeros(1,32));
elseif length(io_name)<32
    %% Enlarge the array if necessary;
    io_name=char([io_name zeros(1,32-length(io_name))]);
elseif ~isa(io_name,'char')
    io_name=char(io_name);
else
    % Write to it to avoid sharing memory with other variables
    t=io_name(1); io_name(1)=t;
end


% Invoke the actual MEX-function.
[io_name, out_type, ierr] = cgnslib_mex(int32(164), in_file_number, in_B, in_Z, in_A, io_name);
