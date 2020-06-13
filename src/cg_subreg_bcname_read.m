function [io_bcname, ierr] = cg_subreg_bcname_read(in_fn, in_B, in_Z, in_S, io_bcname)
% Gateway function for C function cg_subreg_bcname_read.
%
% [bcname, ierr] = cg_subreg_bcname_read(fn, B, Z, S, bcname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%          bcname: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_subreg_bcname_read(int fn, int B, int Z, int S, char * bcname);
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
    io_bcname=char(zeros(1,32));
elseif length(io_bcname)<32
    %% Enlarge the array if necessary;
    io_bcname=char([io_bcname zeros(1,32-length(io_bcname))]);
elseif ~isa(io_bcname,'char')
    io_bcname=char(io_bcname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_bcname(1); io_bcname(1)=t;
end


% Invoke the actual MEX-function.
[io_bcname, ierr] = cgnslib_mex(int32(100), in_fn, in_B, in_Z, in_S, io_bcname);
