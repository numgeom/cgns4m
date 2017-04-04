function name = cg_GridConnectivityTypeName(in_type)
% Gateway function for C function cg_GridConnectivityTypeName.
%
% name = cg_GridConnectivityTypeName(type)
%
% Input argument (required; type is auto-casted): 
%            type: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            name: character string
%
% The original C function is:
% const char * cg_GridConnectivityTypeName( GridConnectivityType_t type);
%
% For detail, see the documentation of the original function.
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
name =  cgnslib_mex(int32(18), in_type);
