function cg_error_exit()
% Gateway function for C function cg_error_exit.
%
% cg_error_exit()
%
% Input argument (required; type is auto-casted): 
%
% Output argument (optional): 
%
% The original C function is:
% void cg_error_exit( );
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/error.html">online documentation</a>.
%

% Invoke the actual MEX-function.
 cgnslib_mex(int32(216));
