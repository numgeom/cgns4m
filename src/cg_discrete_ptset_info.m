function [out_ptset_type, out_npnts, ierr] = cg_discrete_ptset_info(in_fn, in_B, in_Z, in_D)
% Gateway function for C function cg_discrete_ptset_info.
%
% [ptset_type, npnts, ierr] = cg_discrete_ptset_info(fn, B, Z, D)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               D: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit or 32-bit integer (platform dependent), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_ptset_info( int fn, int B, int Z, int D, CG_PointSetType_t * ptset_type, ptrdiff_t * npnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_ptset_type, out_npnts, ierr] =  cgnslib_mex(int32(146), in_fn, in_B, in_Z, in_D);
