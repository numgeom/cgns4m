function ierr = cg_set_file_type(in_file_type)
% Gateway function for C function cg_set_file_type.
%
% ierr = cg_set_file_type(file_type)
%
% Input argument (required; type is auto-casted): 
%       file_type: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_set_file_type( int file_type);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(6), in_file_type);
