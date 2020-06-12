function ierr = cg_units_write(in_mass, in_length, in_time, in_temperature, in_angle)
% Gateway function for C function cg_units_write.
%
% ierr = cg_units_write(mass, length, time, temperature, angle)
%
% Input arguments (required; type is auto-casted):
%            mass: 32-bit integer (int32), scalar
%          length: 32-bit integer (int32), scalar
%            time: 32-bit integer (int32), scalar
%     temperature: 32-bit integer (int32), scalar
%           angle: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_units_write(CG_MassUnits_t mass, CG_LengthUnits_t length, CG_TimeUnits_t time, CG_TemperatureUnits_t temperature, CG_AngleUnits_t angle);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_mass = int32(in_mass);
in_length = int32(in_length);
in_time = int32(in_time);
in_temperature = int32(in_temperature);
in_angle = int32(in_angle);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(229), in_mass, in_length, in_time, in_temperature, in_angle);
