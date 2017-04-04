function [out_mass, out_length, out_time, out_temperature, out_angle, out_current, out_amount, out_intensity, ierr] = cg_unitsfull_read()
% Gateway function for C function cg_unitsfull_read.
%
% [mass, length, time, temperature, angle, current, amount, intensity, ierr] = cg_unitsfull_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%            mass: 32-bit integer (int32), scalar
%          length: 32-bit integer (int32), scalar
%            time: 32-bit integer (int32), scalar
%     temperature: 32-bit integer (int32), scalar
%           angle: 32-bit integer (int32), scalar
%         current: 32-bit integer (int32), scalar
%          amount: 32-bit integer (int32), scalar
%       intensity: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_unitsfull_read( CG_MassUnits_t * mass, CG_LengthUnits_t * length, CG_TimeUnits_t * time, CG_TemperatureUnits_t * temperature, CG_AngleUnits_t * angle, CG_ElectricCurrentUnits_t * current, CG_SubstanceAmountUnits_t * amount, CG_LuminousIntensityUnits_t * intensity);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_mass, out_length, out_time, out_temperature, out_angle, out_current, out_amount, out_intensity, ierr] =  cgnslib_mex(int32(217));
