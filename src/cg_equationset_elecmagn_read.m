function [io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag, ierr] = cg_equationset_elecmagn_read(io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag)
% Gateway function for C function cg_equationset_elecmagn_read.
%
% [ElecFldModelFlag, MagnFldModelFlag, ConductivityModelFlag, ierr] = cg_equationset_elecmagn_read(ElecFldModelFlag, MagnFldModelFlag, ConductivityModelFlag)
%
% Input argument (required; type is auto-casted): 
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%    ElecFldModelFlag: 32-bit integer (int32), array  (also required as input)
%    MagnFldModelFlag: 32-bit integer (int32), array  (also required as input)
%    ConductivityModelFlag: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_equationset_elecmagn_read( int * ElecFldModelFlag, int * MagnFldModelFlag, int * ConductivityModelFlag);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/equation.html">online documentation</a>.
%
if ( nargout < 3 || nargin < 3); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_ElecFldModelFlag,'int32');
    io_ElecFldModelFlag=int32(io_ElecFldModelFlag);
elseif ~isempty(io_ElecFldModelFlag);
    % Write to it to avoid sharing memory with other variables
    t=io_ElecFldModelFlag(1); io_ElecFldModelFlag(1)=t;
end

if ~isa(io_MagnFldModelFlag,'int32');
    io_MagnFldModelFlag=int32(io_MagnFldModelFlag);
elseif ~isempty(io_MagnFldModelFlag);
    % Write to it to avoid sharing memory with other variables
    t=io_MagnFldModelFlag(1); io_MagnFldModelFlag(1)=t;
end

if ~isa(io_ConductivityModelFlag,'int32');
    io_ConductivityModelFlag=int32(io_ConductivityModelFlag);
elseif ~isempty(io_ConductivityModelFlag);
    % Write to it to avoid sharing memory with other variables
    t=io_ConductivityModelFlag(1); io_ConductivityModelFlag(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(164), io_ElecFldModelFlag, io_MagnFldModelFlag, io_ConductivityModelFlag);
