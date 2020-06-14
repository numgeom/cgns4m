function [out_holename, out_location, out_ptset_type, out_nptsets, out_npnts, ierr] = cg_hole_info(in_fn, in_B, in_Z, in_I)
% Gateway function for C function cg_hole_info.
%
% [holename, location, ptset_type, nptsets, npnts, ierr] = cg_hole_info(fn, B, Z, I)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%        holename: character string
%        location: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%         nptsets: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_info(int fn, int B, int Z, int I, char * holename, CG_GridLocation_t * location, CG_PointSetType_t * ptset_type, int * nptsets, long long * npnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);

% Invoke the actual MEX-function.
[out_holename, out_location, out_ptset_type, out_nptsets, out_npnts, ierr] = cgnslib_mex(int32(111), in_fn, in_B, in_Z, in_I);
