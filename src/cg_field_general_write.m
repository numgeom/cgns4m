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
%            rmin: 32-bit integer (int32), array
%            rmax: 32-bit integer (int32), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%          m_dims: 32-bit integer (int32), array
%          m_rmin: 32-bit integer (int32), array
%          m_rmax: 32-bit integer (int32), array
%       field_ptr: numeric array
%
% Output arguments (optional):
%               F: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_general_write(int fn, int B, int Z, int S, const char * fieldname, CG_DataType_t s_type, const int * rmin, const int * rmax, CG_DataType_t m_type, int m_numdim, const int * m_dims, const int * m_rmin, const int * m_rmax, const void * field_ptr, int * F);
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
in_rmin = int32(in_rmin);
in_rmax = int32(in_rmax);
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
in_m_dims = int32(in_m_dims);
in_m_rmin = int32(in_m_rmin);
in_m_rmax = int32(in_m_rmax);
in_field_ptr = numeric(in_field_ptr);

% Invoke the actual MEX-function.
[out_F, ierr] = cgnslib_mex(int32(107), in_fn, in_B, in_Z, in_S, in_fieldname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_field_ptr);
