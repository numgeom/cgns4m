function [io_boconame, io_NormalIndex, out_bocotype, out_ptset_type, out_npnts, out_NormalListFlag, out_NormalDataType, out_ndataset, ierr] = cg_boco_info(in_fn, in_B, in_Z, in_BC, io_boconame, io_NormalIndex)
% Gateway function for C function cg_boco_info.
%
% [boconame, NormalIndex, bocotype, ptset_type, npnts, NormalListFlag, NormalDataType, ndataset, ierr] = cg_boco_info(fn, B, Z, BC, boconame, NormalIndex)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%        boconame: character string with default length 32 
%     NormalIndex: 32-bit integer (int32), array  (also required as input)
%
% Output arguments (optional):
%        bocotype: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 32-bit integer (int32), scalar
%    NormalListFlag: 32-bit integer (int32), scalar
%    NormalDataType: 32-bit integer (int32), scalar
%        ndataset: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_info( int fn, int B, int Z, int BC, char * boconame, BCType_t * bocotype, PointSetType_t * ptset_type, int * npnts, int * NormalIndex, int * NormalListFlag, DataType_t * NormalDataType, int * ndataset);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 6); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_boconame=char(zeros(1,32));
elseif length(io_boconame)<32
    %% Enlarge the array if necessary;
    io_boconame=char([io_boconame zeros(1,32-length(io_boconame))]);
elseif ~isa(io_boconame,'char');
    io_boconame=char(io_boconame);
else
    % Write to it to avoid sharing memory with other variables
    t=io_boconame(1); io_boconame(1)=t;
end

if ~isa(io_NormalIndex,'int32');
    io_NormalIndex=int32(io_NormalIndex);
elseif ~isempty(io_NormalIndex);
    % Write to it to avoid sharing memory with other variables
    t=io_NormalIndex(1); io_NormalIndex(1)=t;
end


% Invoke the actual MEX-function.
[out_bocotype, out_ptset_type, out_npnts, out_NormalListFlag, out_NormalDataType, out_ndataset, ierr, io_boconame] =  cgnslib_mex(int32(109), in_fn, in_B, in_Z, in_BC, io_boconame, io_NormalIndex);
