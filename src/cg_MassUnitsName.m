function name = cg_MassUnitsName(in_type)
% Gateway function for C function cg_MassUnitsName.
%
% name = cg_MassUnitsName(type)
%
% Input argument (required; type is auto-casted):
%            type: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            name: character string
%
% The original C function is:
% const char * cg_MassUnitsName(CG_MassUnits_t type);
%
% For detail, see the documentation of the original function.
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_type = int32(in_type);

% Invoke the actual MEX-function.
name = cgnslib_mex(int32(16), in_type);
