function [io_gcname, ierr] = cg_subreg_gcname_read(in_fn, in_B, in_Z, in_S, io_gcname)
% Gateway function for C function cg_subreg_gcname_read.
%
% [gcname, ierr] = cg_subreg_gcname_read(fn, B, Z, S, gcname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%          gcname: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_subreg_gcname_read(int fn, int B, int Z, int S, char * gcname);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
if nargin<5
    io_gcname=char(zeros(1,32));
elseif length(io_gcname)<32
    %% Enlarge the array if necessary;
    io_gcname=char([io_gcname zeros(1,32-length(io_gcname))]);
elseif ~isa(io_gcname,'char')
    io_gcname=char(io_gcname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_gcname(1); io_gcname(1)=t;
end


% Invoke the actual MEX-function.
[io_gcname, ierr] = cgnslib_mex(int32(101), in_fn, in_B, in_Z, in_S, io_gcname);
