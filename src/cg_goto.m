function ierr = cg_goto(varargin)
% Gateway function for C function cg_goto.
%
% ierr = cg_goto(file_number, B, varargin)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%        varargin: pairs of character string ('CGNS_NodeLabel' or
%                  'CGNS_NodeName') and integer (index or 0).
%                  Unlike the native CGNS interface, the arguments need
%                  not end with a character string 'end', because this
%                  function would append 'end' automatically.
%    Note: This function currently support only up to depth 4. To
%    access a node with a deeper depth, use cg_gopath.
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_goto( int file_number, int B, ..., "end");
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/navigating.html">online documentation</a>.
%
% See also cg_gopath, cg_gorel, cg_where.

ierr = cgnslib_mex(MEX_CG_GOTO, varargin{:});
