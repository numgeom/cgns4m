function ierr = cg_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements)
% Gateway function for C function cg_elements_partial_write.
%
% ierr = cg_elements_partial_write(fn, B, Z, S, start, end, elements)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%           start: 32-bit integer (int32), scalar
%             end: 32-bit integer (int32), scalar
%        elements: 32-bit integer (int32), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_elements_partial_write( int fn, int B, int Z, int S, int start, int end, int const * elements);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 7); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(76), in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements);
