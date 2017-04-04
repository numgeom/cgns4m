function ierr = cg_is_cgns(in_filename)
% Gateway function for C function cg_is_cgns.
%
% ierr = cg_is_cgns(filename)
%
% Input argument (required; type is auto-casted): 
%        filename: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_is_cgns( const char * filename);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(6), in_filename);
