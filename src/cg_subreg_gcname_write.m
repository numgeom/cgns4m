function [out_S, ierr] = cg_subreg_gcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_gcname)
% Gateway function for C function cg_subreg_gcname_write.
%
% [S, ierr] = cg_subreg_gcname_write(fn, B, Z, regname, dimension, gcname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%         regname: character string
%       dimension: 32-bit integer (int32), scalar
%          gcname: character string
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_subreg_gcname_write(int fn, int B, int Z, const char * regname, int dimension, const char * gcname, int * S);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_regname = char(in_regname);
in_dimension = int32(in_dimension);
in_gcname = char(in_gcname);

% Invoke the actual MEX-function.
[out_S, ierr] = cgnslib_mex(int32(133), in_fn, in_B, in_Z, in_regname, in_dimension, in_gcname);
