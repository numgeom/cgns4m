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

if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[~, ~, ~, ~, ~, ~, out_NormalDataType] = cg_boco_info(in_fn, in_B, in_Z, in_BC);
