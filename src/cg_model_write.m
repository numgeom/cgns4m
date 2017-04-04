function ierr = cg_model_write(in_ModelLabel, in_ModelType)
% Gateway function for C function cg_model_write.
%
% ierr = cg_model_write(ModelLabel, ModelType)
%
% Input arguments (required; type is auto-casted):
%      ModelLabel: character string
%       ModelType: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_model_write( char const * ModelLabel, ModelType_t ModelType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/equation.html">online documentation</a>.
%
if (nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(163), in_ModelLabel, in_ModelType);
