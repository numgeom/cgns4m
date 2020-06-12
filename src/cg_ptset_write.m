function ierr = cg_ptset_write(in_ptset_type, in_npnts, in_pnts)
% Gateway function for C function cg_ptset_write.
%
% ierr = cg_ptset_write(ptset_type, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit or 32-bit integer (platform dependent), scalar
%            pnts: 64-bit or 32-bit integer (platform dependent), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ptset_write(CG_PointSetType_t ptset_type, long npnts, const long * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/location.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_ptset_type = int32(in_ptset_type);
if strfind(computer,'64') %#ok<STRIFCND>
    in_npnts = int64(in_npnts);
else
    in_npnts = int32(in_npnts);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_pnts = int64(in_pnts);
else
    in_pnts = int32(in_pnts);
end

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(248), in_ptset_type, in_npnts, in_pnts);
