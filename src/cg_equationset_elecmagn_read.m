function [io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag, ierr] = cg_equationset_elecmagn_read(io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag)
% Gateway function for C function cg_equationset_elecmagn_read.
%
% [ElecFldModelFlag, MagnFldModelFlag, ConductivityModelFlag, ierr] = cg_equationset_elecmagn_read(ElecFldModelFlag, MagnFldModelFlag, ConductivityModelFlag)
%
% Input argument (required; type is auto-casted):
%
% In&Out arguments (required as output; type is auto-casted):
%    ElecFldModelFlag: 32-bit integer (int32), array  (must be preallocated at input)
%    MagnFldModelFlag: 32-bit integer (int32), array  (must be preallocated at input)
%    ConductivityModelFlag: 32-bit integer (int32), array  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_equationset_elecmagn_read(int * ElecFldModelFlag, int * MagnFldModelFlag, int * ConductivityModelFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%
if ( nargout < 3 || nargin < 3)
    error('Incorrect number of input or output arguments.');
end
basetype = 'int32';
if ~isa(io_ElecFldModelFlag,basetype)
    io_ElecFldModelFlag = cast(io_ElecFldModelFlag, basetype);
elseif ~isempty(io_ElecFldModelFlag)
    % Write to it to unshare memory with other variables
    t=io_ElecFldModelFlag(1); io_ElecFldModelFlag(1)=t;
end

basetype = 'int32';
if ~isa(io_MagnFldModelFlag,basetype)
    io_MagnFldModelFlag = cast(io_MagnFldModelFlag, basetype);
elseif ~isempty(io_MagnFldModelFlag)
    % Write to it to unshare memory with other variables
    t=io_MagnFldModelFlag(1); io_MagnFldModelFlag(1)=t;
end

basetype = 'int32';
if ~isa(io_ConductivityModelFlag,basetype)
    io_ConductivityModelFlag = cast(io_ConductivityModelFlag, basetype);
elseif ~isempty(io_ConductivityModelFlag)
    % Write to it to unshare memory with other variables
    t=io_ConductivityModelFlag(1); io_ConductivityModelFlag(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(201), io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag);
