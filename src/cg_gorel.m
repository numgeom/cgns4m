function ierr = cg_gorel(varargin)
% Gateway function for C function cg_goto.
%
% ierr = cg_gorel(file_number, varargin)
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
% int cg_gorel( int file_number, ..., "end");
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/navigating.html">online documentation</a>.
% 
% See also cg_gopath, cg_goto, cg_where.

ierr = cgnslib_mex(MEX_CG_GOREL,varargin{:});
