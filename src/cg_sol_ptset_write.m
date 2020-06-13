function [out_S, ierr] = cg_sol_ptset_write(in_fn, in_B, in_Z, in_solname, in_location, in_ptset_type, in_npnts, in_pnts)
% Gateway function for C function cg_sol_ptset_write.
%
% [S, ierr] = cg_sol_ptset_write(fn, B, Z, solname, location, ptset_type, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%         solname: character string
%        location: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%            pnts: 64-bit integer (int64), array
%
% Output arguments (optional):
%               S: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_ptset_write(int fn, int B, int Z, const char * solname, CG_GridLocation_t location, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * S);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if (nargin < 8)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_solname = char(in_solname);
in_location = int32(in_location);
in_ptset_type = int32(in_ptset_type);
in_npnts = int64(in_npnts);
in_pnts = int64(in_pnts);

% Invoke the actual MEX-function.
[out_S, ierr] = cgnslib_mex(int32(90), in_fn, in_B, in_Z, in_solname, in_location, in_ptset_type, in_npnts, in_pnts);
