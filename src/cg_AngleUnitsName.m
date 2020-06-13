function name = cg_AngleUnitsName(in_type)
% Gateway function for C function cg_AngleUnitsName.
%
% name = cg_AngleUnitsName(type)
%
% Input argument (required; type is auto-casted):
%            type: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            name: character string
%
% The original C function is:
% const char * cg_AngleUnitsName(CG_AngleUnits_t type);
%
% For detail, see the documentation of the original function.
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_type = int32(in_type);

% Invoke the actual MEX-function.
name = cgnslib_mex(int32(19), in_type);
