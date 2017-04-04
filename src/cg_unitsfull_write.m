function ierr = cg_unitsfull_write(in_mass, in_length, in_time, in_temperature, in_angle, in_current, in_amount, in_intensity)
% Gateway function for C function cg_unitsfull_write.
%
% ierr = cg_unitsfull_write(mass, length, time, temperature, angle, current, amount, intensity)
%
% Input arguments (required; type is auto-casted):
%            mass: 32-bit integer (int32), scalar
%          length: 32-bit integer (int32), scalar
%            time: 32-bit integer (int32), scalar
%     temperature: 32-bit integer (int32), scalar
%           angle: 32-bit integer (int32), scalar
%         current: 32-bit integer (int32), scalar
%          amount: 32-bit integer (int32), scalar
%       intensity: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_unitsfull_write( MassUnits_t mass, LengthUnits_t length, TimeUnits_t time, TemperatureUnits_t temperature, AngleUnits_t angle, ElectricCurrentUnits_t current, SubstanceAmountUnits_t amount, LuminousIntensityUnits_t intensity);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%
if (nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(184), in_mass, in_length, in_time, in_temperature, in_angle, in_current, in_amount, in_intensity);
