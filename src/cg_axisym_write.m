function ierr = cg_axisym_write(in_file_number, in_B, in_ref_point, in_axis)
% Gateway function for C function cg_axisym_write.
%
% ierr = cg_axisym_write(file_number, B, ref_point, axis)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%       ref_point: single-precision (single), array
%            axis: single-precision (single), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_axisym_write( int file_number, int B, float const * ref_point, float const * axis);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(164), in_file_number, in_B, in_ref_point, in_axis);
