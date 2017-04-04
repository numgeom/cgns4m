function out_NormalDataType = cgns_get_boco_type(in_fn, in_B, in_Z, in_BC)
% Helper function for cg_boco_read.
%
% NormalDataType = cgns_get_boco_type(fn, B, Z, BC)
%
% Input arguments:
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% Output arguments:
%   NormalDataType: 32-bit integer (int32), scalar
%

if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

io_boconame=char(zeros(1,32));
io_NormalIndex=int32([0 0 0]); 

% Invoke the actual MEX-function.
[out_bocotype, out_ptset_type, out_npnts, out_NormalListFlag, out_NormalDataType] =  ...
    cgnslib_mex(int32(103), in_fn, in_B, in_Z, in_BC, io_boconame, io_NormalIndex); %#ok<*ASGLU>
