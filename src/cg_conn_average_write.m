function ierr = cg_conn_average_write(in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType)
% Gateway function for C function cg_conn_average_write.
%
% ierr = cg_conn_average_write(file_number, B, Z, I, AverageInterfaceType)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%    AverageInterfaceType: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_average_write( int file_number, int B, int Z, int I, CG_AverageInterfaceType_t AverageInterfaceType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 5); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(176), in_file_number, in_B, in_Z, in_I, in_AverageInterfaceType);
