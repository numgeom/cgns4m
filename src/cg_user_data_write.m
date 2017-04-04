function ierr = cg_user_data_write(in_user_data_name)
% Gateway function for C function cg_user_data_write.
%
% ierr = cg_user_data_write(user_data_name)
%
% Input argument (required; type is auto-casted): 
%    user_data_name: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_user_data_write( char const * user_data_name);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(179), in_user_data_name);
