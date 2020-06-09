function ierr = cg_integral_write(in_IntegralDataName)
% Gateway function for C function cg_integral_write.
%
% ierr = cg_integral_write(IntegralDataName)
%
% Input argument (required; type is auto-casted): 
%    IntegralDataName: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_integral_write( char const * IntegralDataName);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(182), in_IntegralDataName);
