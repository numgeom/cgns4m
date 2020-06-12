function [io_data, ierr] = cg_array_general_read(in_A, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_data)
% Gateway function for C function cg_array_general_read.
%
% [data, ierr] = cg_array_general_read(A, s_rmin, s_rmax, m_type, m_numdim, m_dimvals, m_rmin, m_rmax, data)
%
% Input arguments (required; type is auto-casted):
%               A: 32-bit integer (int32), scalar
%          s_rmin: 32-bit integer (int32), array
%          s_rmax: 32-bit integer (int32), array
%          m_type: 32-bit integer (int32), scalar
%        m_numdim: 32-bit integer (int32), scalar
%       m_dimvals: 32-bit integer (int32), array
%          m_rmin: 32-bit integer (int32), array
%          m_rmax: 32-bit integer (int32), array
%
% In&Out argument (required as output; type is auto-casted):
%            data: numeric array (passed by reference)  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_general_read(int A, const int * s_rmin, const int * s_rmax, CG_DataType_t m_type, int m_numdim, const int * m_dimvals, const int * m_rmin, const int * m_rmax, void * data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 9)
    error('Incorrect number of input or output arguments.');
end
in_A = int32(in_A);
in_s_rmin = int32(in_s_rmin);
in_s_rmax = int32(in_s_rmax);
in_m_type = int32(in_m_type);
in_m_numdim = int32(in_m_numdim);
in_m_dimvals = int32(in_m_dimvals);
in_m_rmin = int32(in_m_rmin);
in_m_rmax = int32(in_m_rmax);
io_data = numeric(io_data);
if ~isempty(io_data)
    % Write to it to avoid sharing memory with other variables
    t=io_data(1); io_data(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(213), in_A, in_s_rmin, in_s_rmax, in_m_type, in_m_numdim, in_m_dimvals, in_m_rmin, in_m_rmax, io_data);
