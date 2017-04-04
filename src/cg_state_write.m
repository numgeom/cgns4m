function ierr = cg_state_write(in_StateDescription)
% Gateway function for C function cg_state_write.
%
% ierr = cg_state_write(StateDescription)
%
% Input argument (required; type is auto-casted): 
%    StateDescription: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_state_write( const char * StateDescription);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(187), in_StateDescription);
