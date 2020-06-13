function [out_connectname, out_zonename, out_donorname, out_range, out_donor_range, out_transform, ierr] = cg_1to1_read_global(varargin)
% Gateway function for C function cg_1to1_read_global.
%
% [connectname, zonename, donorname, range, donor_range, transform, ierr] = cg_1to1_read_global(fn, B)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     connectname: cell of character string
%        zonename: cell of character string
%       donorname: cell of character string
%           range: cell of 32-bit integer (int32), array
%     donor_range: cell of 32-bit integer (int32), array
%       transform: cell of 32-bit integer (int32), array
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_read_global( int fn, int B, char ** connectname, char ** zonename, char ** donorname, int ** range, int ** donor_range, int ** transform);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%

[out_connectname, out_zonename, out_donorname, out_range, out_donor_range, ...
 out_transform, ierr] = cgnslib_mex(MEX_CG_1TO1_READ_GLOBAL,varargin{:});
