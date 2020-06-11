function msg = cg_get_error()
% Gateway function for C function cg_get_error.
%
% msg = cg_get_error()
%
% Input argument (required; type is auto-casted): 
%
% Output argument (optional): 
%             msg: character string
%
% The original C function is:
% const char * cg_get_error( );
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/error.html">online documentation</a>.
%

% Invoke the actual MEX-function.
msg =  cgnslib_mex(int32(215));
