function [io_field_ptr, ierr] = cg_field_read(in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr)
% Gateway function for C function cg_field_read.
%
% [field_ptr, ierr] = cg_field_read(fn, B, Z, S, fieldname, type, rmin, rmax, field_ptr)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%       fieldname: character string
%            type: 32-bit integer (int32), scalar
%            rmin: 64-bit or 32-bit integer (platform dependent), array
%            rmax: 64-bit or 32-bit integer (platform dependent), array
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%       field_ptr: dynamic type based on type  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_read( int fn, int B, int Z, int S, const char * fieldname, CG_DataType_t type, const ptrdiff_t * rmin, const ptrdiff_t * rmax, void * field_ptr);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 9); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        io_field_ptr = int32(io_field_ptr);
    case 3 % CG_RealSingle
        io_field_ptr = single(io_field_ptr);
    case 4 % CG_RealDouble
        io_field_ptr = double(io_field_ptr);
    case 5 % CG_Character
        io_field_ptr = [int8(io_field_ptr), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_field_ptr = int64(io_field_ptr);
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(93), in_fn, in_B, in_Z, in_S, in_fieldname, in_type, in_rmin, in_rmax, io_field_ptr);

% Perform dynamic type casting
if datatype==5 % CG_Character
    io_field_ptr = char(io_field_ptr(1:end-1));
end
