function [out_mass, out_length, out_time, out_temperature, out_angle, ierr] = cg_units_read()
% Gateway function for C function cg_units_read.
%
% [mass, length, time, temperature, angle, ierr] = cg_units_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%            mass: 32-bit integer (int32), scalar
%          length: 32-bit integer (int32), scalar
%            time: 32-bit integer (int32), scalar
%     temperature: 32-bit integer (int32), scalar
%           angle: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_units_read( MassUnits_t * mass, LengthUnits_t * length, TimeUnits_t * time, TemperatureUnits_t * temperature, AngleUnits_t * angle);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_mass, out_length, out_time, out_temperature, out_angle, ierr] =  cgnslib_mex(int32(189));
