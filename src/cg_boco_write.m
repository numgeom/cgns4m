function [out_BC, ierr] = cg_boco_write(in_file_number, in_B, in_Z, in_boconame, in_bocotype, in_ptset_type, in_npnts, in_pnts)
% Gateway function for C function cg_boco_write.
%
% [BC, ierr] = cg_boco_write(file_number, B, Z, boconame, bocotype, ptset_type, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%        boconame: character string
%        bocotype: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%            pnts: 64-bit integer (int64), array
%
% Output arguments (optional):
%              BC: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_write(int file_number, int B, int Z, const char * boconame, CG_BCType_t bocotype, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, int * BC);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 8)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_boconame = char(in_boconame);
in_bocotype = int32(in_bocotype);
in_ptset_type = int32(in_ptset_type);
in_npnts = int64(in_npnts);
in_pnts = int64(in_pnts);

% Invoke the actual MEX-function.
[out_BC, ierr] = cgnslib_mex(int32(143), in_file_number, in_B, in_Z, in_boconame, in_bocotype, in_ptset_type, in_npnts, in_pnts);
