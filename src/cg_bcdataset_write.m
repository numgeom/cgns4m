function ierr = cg_bcdataset_write(in_name, in_BCType, in_BCDataType)
% Gateway function for C function cg_bcdataset_write.
%
% ierr = cg_bcdataset_write(name, BCType, BCDataType)
%
% Input arguments (required; type is auto-casted):
%            name: character string with default length 32 
%          BCType: 32-bit integer (int32), scalar
%      BCDataType: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdataset_write( char const * name, BCType_t BCType, BCDataType_t BCDataType);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(116), in_name, in_BCType, in_BCDataType);
