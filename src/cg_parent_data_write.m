function ierr = cg_parent_data_write(in_file_number, in_B, in_Z, in_S, in_parent_data)
% Gateway function for C function cg_parent_data_write.
%
% ierr = cg_parent_data_write(file_number, B, Z, S, parent_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%     parent_data: 32-bit integer (int32), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_parent_data_write( int file_number, int B, int Z, int S, int const * parent_data);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if (nargin < 5); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(67), in_file_number, in_B, in_Z, in_S, in_parent_data);
