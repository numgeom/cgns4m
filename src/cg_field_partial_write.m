function [out_F, ierr] = cg_field_partial_write(in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr)
% Gateway function for C function cg_field_partial_write.
%
% [F, ierr] = cg_field_partial_write(fn, B, Z, S, type, fieldname, rmin, rmax, field_ptr)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%       fieldname: character string
%            rmin: 32-bit integer (int32), array
%            rmax: 32-bit integer (int32), array
%       field_ptr: dynamic type based on type
%
% Output arguments (optional):
%               F: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_partial_write( int fn, int B, int Z, int S, DataType_t type, char const * fieldname, int * rmin, int * rmax, void const * field_ptr, int * F);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 9); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % Integer
        in_field_ptr = int32(in_field_ptr);
    case 3 % RealSingle
        in_field_ptr = single(in_field_ptr);
    case 4 % RealDouble
        in_field_ptr = double(in_field_ptr);
    case 5 % Character
        in_field_ptr = [int8(in_field_ptr), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
[out_F, ierr] =  cgnslib_mex(int32(89), in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr);
