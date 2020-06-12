function [out_C, ierr] = cg_coord_general_write(in_fn, in_B, in_Z, in_coordname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_coord_ptr)
% Gateway function for C function cg_coord_general_write.
%
% [C, ierr] = cg_coord_general_write(fn, B, Z, coordname, s_type, rmin, rmax, m_type, m_numdim, m_dims, m_rmin, m_rmax, coord_ptr)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       coordname: character string
%          s_type: 32-bit integer (int32), scalar
%            rmin: 32-bit integer (int32), array
%            rmax: 32-bit integer (int32), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%          m_dims: 32-bit integer (int32), array
%          m_rmin: 32-bit integer (int32), array
%          m_rmax: 32-bit integer (int32), array
%       coord_ptr: numeric array
%
% Output arguments (optional):
%               C: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_general_write(int fn, int B, int Z, const char * coordname, CG_DataType_t s_type, const int * rmin, const int * rmax, CG_DataType_t m_type, int m_numdim, const int * m_dims, const int * m_rmin, const int * m_rmax, const void * coord_ptr, int * C);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 13)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_coordname = char(in_coordname);
in_s_type = int32(in_s_type);
in_rmin = int32(in_rmin);
in_rmax = int32(in_rmax);
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
in_m_dims = int32(in_m_dims);
in_m_rmin = int32(in_m_rmin);
in_m_rmax = int32(in_m_rmax);
in_coord_ptr = numeric(in_coord_ptr);

% Invoke the actual MEX-function.
[out_C, ierr] = cgnslib_mex(int32(79), in_fn, in_B, in_Z, in_coordname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_coord_ptr);
