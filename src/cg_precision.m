function [out_precision, ierr] = cg_precision(in_fn)
% Gateway function for C function cg_precision.
%
% [precision, ierr] = cg_precision(fn)
%
% Input argument (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%       precision: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_precision(int fn, int * precision);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);

% Invoke the actual MEX-function.
[out_precision, ierr] = cgnslib_mex(int32(4), in_fn);
