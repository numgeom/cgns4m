function cg_error_print()
% Gateway function for C function cg_error_print.
%
% cg_error_print()
%
% Input argument (required; type is auto-casted): 
%
% Output argument (optional): 
%
% The original C function is:
% void cg_error_print( );
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/error.html">online documentation</a>.
%

% Invoke the actual MEX-function.
 cgnslib_mex(int32(243));
