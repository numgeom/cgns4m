function [io_name, ierr] = cg_zconn_read(in_fn, in_B, in_Z, in_C, io_name)
% Gateway function for C function cg_zconn_read.
%
% [name, ierr] = cg_zconn_read(fn, B, Z, C, name)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               C: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            name: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_zconn_read(int fn, int B, int Z, int C, char * name);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_C = int32(in_C);
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
[io_name, ierr] = cgnslib_mex(int32(117), in_fn, in_B, in_Z, in_C, io_name);
