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
%            rmin: 64-bit integer (int64), array
%            rmax: 64-bit integer (int64), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%          m_dims: 64-bit integer (int64), array
%          m_rmin: 64-bit integer (int64), array
%          m_rmax: 64-bit integer (int64), array
%       coord_ptr: dynamic type based on m_type
%
% Output arguments (optional):
%               C: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_general_write(int fn, int B, int Z, const char * coordname, CG_DataType_t s_type, const long long * rmin, const long long * rmax, CG_DataType_t m_type, int m_numdim, const long long * m_dims, const long long * m_rmin, const long long * m_rmax, const void * coord_ptr, int * C);
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
        in_coord_ptr = int32(in_coord_ptr);
    case 3 % CG_RealSingle
        in_coord_ptr = single(in_coord_ptr);
    case 4 % CG_RealDouble
        in_coord_ptr = double(in_coord_ptr);
    case 5 % CG_Character
        in_coord_ptr = [int8(in_coord_ptr), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_coord_ptr = int64(in_coord_ptr);
    otherwise
        error('Unknown data type %d', in_m_type);
end


% Invoke the actual MEX-function.
[out_C, ierr] = cgnslib_mex(int32(93), in_fn, in_B, in_Z, in_coordname, in_s_type, in_rmin, in_rmax, in_m_type, in_m_numdim, in_m_dims, in_m_rmin, in_m_rmax, in_coord_ptr);
