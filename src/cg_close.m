function ierr = cg_close(in_fn)
% Gateway function for C function cg_close.
%
% ierr = cg_close(fn)
%
% Input argument (required; type is auto-casted): 
%              fn: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_close( int fn);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(4), in_fn);
