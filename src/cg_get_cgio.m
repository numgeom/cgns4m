function [out_cgio_num, ierr] = cg_get_cgio(in_fn)
% Gateway function for C function cg_get_cgio.
%
% [cgio_num, ierr] = cg_get_cgio(fn)
%
% Input argument (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        cgio_num: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_get_cgio(int fn, int * cgio_num);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);

% Invoke the actual MEX-function.
[out_cgio_num, ierr] = cgnslib_mex(int32(10), in_fn);
