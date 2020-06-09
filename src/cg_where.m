function [out_file_number, out_B, out_depth, out_label, out_num, ierr] = cg_where
% Gateway function for C function cg_where.
%
% [file_number, B, depth, label, num, ierr] = cg_where
%
% Output arguments (optional):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%           depth: 32-bit integer (int32), scalar
%           label: cell of character string of size depth
%             num: 32-bit integer (int32), len=depth
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_where( int * file_number, int * B, int * depth, char ** label, int * num);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/navigating.html">online documentation</a>.
%
% See also cg_gopath, cg_goto, cg_gorel.

[out_file_number, out_B, out_depth, out_label, out_num, ierr] = ...
    cgnslib_mex(MEX_CG_WHERE);
