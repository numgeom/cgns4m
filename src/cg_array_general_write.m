function ierr = cg_array_general_write(in_arrayname, in_s_type, in_s_numdim, in_s_dimvals, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, in_data)
% Gateway function for C function cg_array_general_write.
%
% ierr = cg_array_general_write(arrayname, s_type, s_numdim, s_dimvals, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax, data)
%
% Input arguments (required; type is auto-casted):
%       arrayname: character string
%          s_type: 32-bit integer (int32), scalar
%        s_numdim: 32-bit integer (int32), scalar
%       s_dimvals: 64-bit or 32-bit integer (platform dependent), array
%          s_rmin: 64-bit or 32-bit integer (platform dependent), array
%          s_rmax: 64-bit or 32-bit integer (platform dependent), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%       m_dimvals: 64-bit or 32-bit integer (platform dependent), array
%          m_rmin: 64-bit or 32-bit integer (platform dependent), array
%          m_rmax: 64-bit or 32-bit integer (platform dependent), array
%            data: numeric array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_general_write(const char * arrayname, CG_DataType_t s_type, int s_numdim, const long * s_dimvals, const long * s_rmin, const long * s_rmax, CG_DataType_t m_type, int m_numdim, const long * m_dimvals, const long * m_rmin, const long * m_rmax, const void * data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if (nargin < 12)
    error('Incorrect number of input or output arguments.');
end
in_arrayname = char(in_arrayname);
in_s_type = int32(in_s_type);
in_s_numdim = int32(in_s_numdim);
if strfind(computer,'64') %#ok<STRIFCND>
    in_s_dimvals = int64(in_s_dimvals);
else
    in_s_dimvals = int32(in_s_dimvals);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_s_rmin = int64(in_s_rmin);
else
    in_s_rmin = int32(in_s_rmin);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_s_rmax = int64(in_s_rmax);
else
    in_s_rmax = int32(in_s_rmax);
end
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
if strfind(computer,'64') %#ok<STRIFCND>
    in_m_dimvals = int64(in_m_dimvals);
else
    in_m_dimvals = int32(in_m_dimvals);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_m_rmin = int64(in_m_rmin);
else
    in_m_rmin = int32(in_m_rmin);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_m_rmax = int64(in_m_rmax);
else
    in_m_rmax = int32(in_m_rmax);
end
in_data = numeric(in_data);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(215), in_arrayname, in_s_type, in_s_numdim, in_s_dimvals, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, in_data);
