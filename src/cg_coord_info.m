function [io_coordname, out_type, ierr] = cg_coord_info(in_fn, in_B, in_Z, in_C, io_coordname)
% Gateway function for C function cg_coord_info.
%
% [coordname, type, ierr] = cg_coord_info(fn, B, Z, C, coordname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               C: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%       coordname: character string with default length 32  (optional as input)
%
% Output arguments (optional):
%            type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_info(int fn, int B, int Z, int C, CG_DataType_t * type, char * coordname);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_C = int32(in_C);
io_coordname = char(io_coordname);
if nargin<5
    io_coordname=char(zeros(1,32));
elseif length(io_coordname)<32
    %% Enlarge the array if necessary;
    io_coordname=char([io_coordname zeros(1,32-length(io_coordname))]);
elseif ~isa(io_coordname,'char')
    io_coordname=char(io_coordname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_coordname(1); io_coordname(1)=t;
end


% Invoke the actual MEX-function.
[io_coordname, out_type, ierr] = cgnslib_mex(int32(73), in_fn, in_B, in_Z, in_C, io_coordname);
