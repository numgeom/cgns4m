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
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%            pnts: 32-bit integer (int32), array  (also required as input)
%      NormalList: dynamic type based on cgns_get_boco_type(fn,B,Z,BC)  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_read( int fn, int B, int Z, int BC, int * pnts, void * NormalList);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/bc.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 6); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = cgns_get_boco_type(in_fn, in_B, in_Z, in_BC);
switch (datatype)
    case 2 % Integer
        io_NormalList = int32(io_NormalList);
    case 3 % RealSingle
        io_NormalList = single(io_NormalList);
    case 4 % RealDouble
        io_NormalList = double(io_NormalList);
    case 5 % Character
        io_NormalList = [int8(io_NormalList), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', cgns_get_boco_type(in_fn, in_B, in_Z, in_BC));
end

if ~isa(io_pnts,'int32');
    io_pnts=int32(io_pnts);
elseif ~isempty(io_pnts);
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(104), in_fn, in_B, in_Z, in_BC, io_pnts, io_NormalList);

% Perform dynamic type casting
if datatype==5 % Character
    io_NormalList = char(io_NormalList(1:end-1));
end
