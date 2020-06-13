function [out_ModelType, ierr] = cg_model_read(in_ModelLabel)
% Gateway function for C function cg_model_read.
%
% [ModelType, ierr] = cg_model_read(ModelLabel)
%
% Input argument (required; type is auto-casted):
%      ModelLabel: character string
%
% Output arguments (optional):
%       ModelType: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_model_read(const char * ModelLabel, CG_ModelType_t * ModelType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_ModelLabel = char(in_ModelLabel);

% Invoke the actual MEX-function.
[out_ModelType, ierr] = cgnslib_mex(int32(196), in_ModelLabel);
