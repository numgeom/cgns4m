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
%            rmin: 64-bit integer (int64), array
%            rmax: 64-bit integer (int64), array
%       field_ptr: dynamic type based on type
%
% Output arguments (optional):
%               F: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_partial_write(int fn, int B, int Z, int S, CG_DataType_t type, const char * fieldname, const int64_t * rmin, const int64_t * rmax, const void * field_ptr, int * F);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 9)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
in_type = int32(in_type);
in_fieldname = char(in_fieldname);
in_rmin = int64(in_rmin);
in_rmax = int64(in_rmax);

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        in_field_ptr = int32(in_field_ptr);
    case 3 % CG_RealSingle
        in_field_ptr = single(in_field_ptr);
    case 4 % CG_RealDouble
        in_field_ptr = double(in_field_ptr);
    case 5 % CG_Character
        in_field_ptr = [int8(in_field_ptr), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_field_ptr = int64(in_field_ptr);
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
[out_F, ierr] = cgnslib_mex(int32(106), in_fn, in_B, in_Z, in_S, in_type, in_fieldname, in_rmin, in_rmax, in_field_ptr);
