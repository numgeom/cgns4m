function [out_S, ierr] = cg_subreg_bcname_write(in_fn, in_B, in_Z, in_regname, in_dimension, in_bcname)
% Gateway function for C function cg_subreg_bcname_write.
%
% [S, ierr] = cg_subreg_bcname_write(fn, B, Z, regname, dimension, bcname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%         regname: character string
%       dimension: 32-bit integer (int32), scalar
%          bcname: character string
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_subreg_bcname_write( int fn, int B, int Z, const char * regname, int dimension, const char * bcname, int * S);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 6); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_S, ierr] =  cgnslib_mex(int32(103), in_fn, in_B, in_Z, in_regname, in_dimension, in_bcname);
