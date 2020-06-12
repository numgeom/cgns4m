function [io_coord_ptr, ierr] = cg_coord_general_read(in_fn, in_B, in_Z, in_coordname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_coord_ptr)
% Gateway function for C function cg_coord_general_read.
%
% [coord_ptr, ierr] = cg_coord_general_read(fn, B, Z, coordname, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax, coord_ptr)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       coordname: character string
%          s_rmin: 32-bit integer (int32), array
%          s_rmax: 32-bit integer (int32), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%       m_dimvals: 32-bit integer (int32), array
%          m_rmin: 32-bit integer (int32), array
%          m_rmax: 32-bit integer (int32), array
%
% In&Out argument (required as output; type is auto-casted):
%       coord_ptr: numeric array (passed by reference)  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_general_read(int fn, int B, int Z, const char * coordname, const int * s_rmin, const int * s_rmax, CG_DataType_t m_type, int m_numdim, const int * m_dimvals, const int * m_rmin, const int * m_rmax, void * coord_ptr);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 12)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_coordname = char(in_coordname);
in_s_rmin = int32(in_s_rmin);
in_s_rmax = int32(in_s_rmax);
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
in_m_dimvals = int32(in_m_dimvals);
in_m_rmin = int32(in_m_rmin);
in_m_rmax = int32(in_m_rmax);
io_coord_ptr = numeric(io_coord_ptr);
if ~isempty(io_coord_ptr)
    % Write to it to avoid sharing memory with other variables
    t=io_coord_ptr(1); io_coord_ptr(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(75), in_fn, in_B, in_Z, in_coordname, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_coord_ptr);
