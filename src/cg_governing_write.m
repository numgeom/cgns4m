function ierr = cg_governing_write(in_Equationstype)
% Gateway function for C function cg_governing_write.
%
% ierr = cg_governing_write(Equationstype)
%
% Input argument (required; type is auto-casted): 
%    Equationstype: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_governing_write( GoverningEquationsType_t Equationstype);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/equation.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(167), in_Equationstype);
