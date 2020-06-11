function ierr = cg_golist(varargin)
% Gateway function for C function cg_golist.
%
% ierr = cg_golist(file_number, B, depth, label, num)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%           depth: 32-bit integer (int32), scalar
%           label: character string
%             num: 32-bit integer (int32), len=depth
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_golist( int file_number, int B, int depth, char ** label, int * num);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/navigating.html">online documentation</a>.
%

ierr = cgnslib_mex(MEX_CG_GOLIST,varargin{:});
