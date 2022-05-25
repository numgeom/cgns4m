function [out_F, ierr] = cg_field_general_write(in_fn, in_B, in_Z, in_S, in_fieldname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_field_ptr)
% Gateway function for C function cg_field_general_write.
%
% [F, ierr] = cg_field_general_write(fn, B, Z, S, fieldname, s_type, rmin, rmax, m_type, m_numdim, m_dims, m_rmin, m_rmax, field_ptr)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%       fieldname: character string
%          s_type: 32-bit integer (int32), scalar
%            rmin: 64-bit integer (int64), array
%            rmax: 64-bit integer (int64), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%          m_dims: 64-bit integer (int64), array
%          m_rmin: 64-bit integer (int64), array
%          m_rmax: 64-bit integer (int64), array
%       field_ptr: dynamic type based on m_type
%
% Output arguments (optional):
%               F: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_general_write(int fn, int B, int Z, int S, const char * fieldname, CG_DataType_t s_type, const long long * rmin, const long long * rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dims, const long long * m_rmin, const long long * m_rmax, const void * field_ptr, int * F);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 14)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
in_fieldname = char(in_fieldname);
in_s_type = int32(in_s_type);
in_rmin = int64(in_rmin);
in_rmax = int64(in_rmax);
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
in_m_dims = int64(in_m_dims);
in_m_rmin = int64(in_m_rmin);
in_m_rmax = int64(in_m_rmax);

% Perform dynamic type casting
datatype = in_m_type;
switch (datatype)
    case 2 % CG_Integer
        in_field_ptr = int32(in_field_ptr);
    case 3 % CG_RealSingle
        in_field_ptr = single(in_field_ptr);
    case 4 % CG_RealDouble
        in_field_ptr = double(in_field_ptr);
    case 5 % CG_Character
        in_field_ptr = [int8(in_field_ptr), int8(zeros(1, 1))];
    case 6 % CG_LongInteger
        in_field_ptr = int64(in_field_ptr);
    otherwise
        error('Unknown data type %d', in_m_type);
end

% Invoke the actual MEX-function.
[out_F, ierr] = cgnslib_mex(int32(107), in_fn, in_B, in_Z, in_S, in_fieldname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_field_ptr);
