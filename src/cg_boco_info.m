function [io_NormalIndex, io_NormalListSize, out_boconame, out_bocotype, out_ptset_type, out_npnts, out_NormalDataType, out_ndataset, ierr] = cg_boco_info(in_fn, in_B, in_Z, in_BC, io_NormalIndex, io_NormalListSize)
% Gateway function for C function cg_boco_info.
%
% [NormalIndex, NormalListSize, boconame, bocotype, ptset_type, npnts, NormalDataType, ndataset, ierr] = cg_boco_info(fn, B, Z, BC, NormalIndex, NormalListSize)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%     NormalIndex: 32-bit integer (int32), array  (must be preallocated at input)
%    NormalListSize: 64-bit integer (int64), array  (must be preallocated at input)
%
% Output arguments (optional):
%        boconame: character string
%        bocotype: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%    NormalDataType: 32-bit integer (int32), scalar
%        ndataset: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_info(int fn, int B, int Z, int BC, char * boconame, CG_BCType_t * bocotype, CG_PointSetType_t * ptset_type, long long * npnts, int * NormalIndex, long long * NormalListSize, CG_DataType_t * NormalDataType, int * ndataset);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_BC = int32(in_BC);
basetype = 'int32';
if ~isa(io_NormalIndex,basetype)
    io_NormalIndex = cast(io_NormalIndex, basetype);
elseif ~isempty(io_NormalIndex)
    % Write to it to unshare memory with other variables
    t=io_NormalIndex(1); io_NormalIndex(1)=t;
end

basetype = 'int64';
if ~isa(io_NormalListSize,basetype)
    io_NormalListSize = cast(io_NormalListSize, basetype);
elseif ~isempty(io_NormalListSize)
    % Write to it to unshare memory with other variables
    t=io_NormalListSize(1); io_NormalListSize(1)=t;
end


% Invoke the actual MEX-function.
[out_boconame, out_bocotype, out_ptset_type, out_npnts, out_NormalDataType, out_ndataset, ierr] = cgnslib_mex(int32(158), in_fn, in_B, in_Z, in_BC, io_NormalIndex, io_NormalListSize);
