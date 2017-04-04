function [io_ModelLabel, out_ModelType, ierr] = cg_model_read(io_ModelLabel)
% Gateway function for C function cg_model_read.
%
% [ModelLabel, ModelType, ierr] = cg_model_read(ModelLabel)
%
% Input argument (required; type is auto-casted): 
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%      ModelLabel: character string with default length 32 
%
% Output arguments (optional):
%       ModelType: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_model_read( char * ModelLabel, ModelType_t * ModelType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/equation.html">online documentation</a>.
%
if ( nargout < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<1
    io_ModelLabel=char(zeros(1,32));
elseif length(io_ModelLabel)<32
    %% Enlarge the array if necessary;
    io_ModelLabel=char([io_ModelLabel zeros(1,32-length(io_ModelLabel))]);
elseif ~isa(io_ModelLabel,'char');
    io_ModelLabel=char(io_ModelLabel);
else
    % Write to it to avoid sharing memory with other variables
    t=io_ModelLabel(1); io_ModelLabel(1)=t;
end


% Invoke the actual MEX-function.
[out_ModelType, ierr] =  cgnslib_mex(int32(162), io_ModelLabel);
