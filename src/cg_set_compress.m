function ierr = cg_set_compress(in_compress)
% Gateway function for C function cg_set_compress.
%
% ierr = cg_set_compress(compress)
%
% Input argument (required; type is auto-casted): 
%        compress: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_set_compress( int compress);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(10), in_compress);
