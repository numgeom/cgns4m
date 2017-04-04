function ierr = cg_dataclass_write(in_dataclass)
% Gateway function for C function cg_dataclass_write.
%
% ierr = cg_dataclass_write(dataclass)
%
% Input argument (required; type is auto-casted): 
%       dataclass: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_dataclass_write( DataClass_t dataclass);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%
if (nargin < 1); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(195), in_dataclass);
