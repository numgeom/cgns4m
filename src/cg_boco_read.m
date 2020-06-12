function [io_pnts, io_NormalList, ierr] = cg_boco_read(in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList)
% Gateway function for C function cg_boco_read.
%
% [pnts, NormalList, ierr] = cg_boco_read(fn, B, Z, BC, pnts, NormalList)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%            pnts: 64-bit integer (int64), array  (also required as input)
%      NormalList: dynamic type based on cgns_get_boco_type(fn,B,Z,BC)  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_read(int fn, int B, int Z, int BC, int64_t * pnts, void * NormalList);
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

% Perform dynamic type casting
datatype = cgns_get_boco_type(in_fn, in_B, in_Z, in_BC);
switch (datatype)
    case 2 % CG_Integer
        io_NormalList = int32(io_NormalList);
    case 3 % CG_RealSingle
        io_NormalList = single(io_NormalList);
    case 4 % CG_RealDouble
        io_NormalList = double(io_NormalList);
    case 5 % CG_Character
        io_NormalList = [int8(io_NormalList), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_NormalList = int64(io_NormalList);
    otherwise
        error('Unknown data type %d', cgns_get_boco_type(in_fn, in_B, in_Z, in_BC));
end

basetype = 'int64';
if ~isa(io_pnts,basetype)
    io_pnts = cast(io_pnts, basetype);
elseif ~isempty(io_pnts)
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(141), in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList);
