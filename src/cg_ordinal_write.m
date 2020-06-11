function ierr = cg_ordinal_write(in_Ordinal)
% Gateway function for C function cg_ordinal_write.
%
% ierr = cg_ordinal_write(Ordinal)
%
% Input argument (required; type is auto-casted): 
%         Ordinal: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ordinal_write( int Ordinal);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(207), in_Ordinal);
