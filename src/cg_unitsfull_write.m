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
% int cg_unitsfull_write( CG_MassUnits_t mass, CG_LengthUnits_t length, CG_TimeUnits_t time, CG_TemperatureUnits_t temperature, CG_AngleUnits_t angle, CG_ElectricCurrentUnits_t current, CG_SubstanceAmountUnits_t amount, CG_LuminousIntensityUnits_t intensity);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(218), in_mass, in_length, in_time, in_temperature, in_angle, in_current, in_amount, in_intensity);
