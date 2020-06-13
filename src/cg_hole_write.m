function [out_Ii, ierr] = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts)
% Gateway function for C function cg_hole_write.
%
% [Ii, ierr] = cg_hole_write(fn, B, Z, holename, location, ptset_type, nptsets, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%        holename: character string
%        location: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%         nptsets: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%            pnts: 64-bit integer (int64), array
%
% Output arguments (optional):
%              Ii: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_write(int fn, int B, int Z, const char * holename, CG_GridLocation_t location, CG_PointSetType_t ptset_type, int nptsets, long long npnts, const long long * pnts, int * Ii);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 9)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_holename = char(in_holename);
in_location = int32(in_location);
in_ptset_type = int32(in_ptset_type);
in_nptsets = int32(in_nptsets);
in_npnts = int64(in_npnts);
in_pnts = int64(in_pnts);

% Invoke the actual MEX-function.
[out_Ii, ierr] = cgnslib_mex(int32(125), in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts);
