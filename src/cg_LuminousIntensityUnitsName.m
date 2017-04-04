function name = cg_LuminousIntensityUnitsName(in_type)
% Gateway function for C function cg_LuminousIntensityUnitsName.
%
% name = cg_LuminousIntensityUnitsName(type)
%
% Input argument (required; type is auto-casted): 
%            type: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            name: character string
%
% The original C function is:
% const char * cg_LuminousIntensityUnitsName( LuminousIntensityUnits_t type);
%
% For detail, see the documentation of the original function.
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
name =  cgnslib_mex(int32(14), in_type);
