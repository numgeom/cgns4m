function ierr = cg_diffusion_write(in_diffusion_model)
% Gateway function for C function cg_diffusion_write.
%
% ierr = cg_diffusion_write(diffusion_model)
%
% Input argument (required; type is auto-casted): 
%    diffusion_model: 32-bit integer (int32), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_diffusion_write( int const * diffusion_model);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/equation.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(169), in_diffusion_model);
