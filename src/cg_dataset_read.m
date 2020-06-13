function [io_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cg_dataset_read(in_fn, in_B, in_Z, in_BC, in_DS, io_name)
% Gateway function for C function cg_dataset_read.
%
% [name, BCType, DirichletFlag, NeumannFlag, ierr] = cg_dataset_read(fn, B, Z, BC, DS, name)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%              DS: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%            name: character string with default length 32  (optional as input)
%
% Output arguments (optional):
%          BCType: 32-bit integer (int32), scalar
%    DirichletFlag: 32-bit integer (int32), scalar
%     NeumannFlag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_dataset_read(int fn, int B, int Z, int BC, int DS, char * name, CG_BCType_t * BCType, int * DirichletFlag, int * NeumannFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
in_DS = int32(in_DS);
if nargin<6
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
[io_name, out_BCType, out_DirichletFlag, out_NeumannFlag, ierr] = cgnslib_mex(int32(147), in_fn, in_B, in_Z, in_BC, in_DS, io_name);
