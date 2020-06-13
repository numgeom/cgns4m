function out_DataType = cgns_get_array_type(in_A)
% Helper function for cgns_array_read.
%
% DataType = cgns_get_array_type(A)
%
% Input argument: 
%        A: 32-bit integer (int32), scalar
%
% Output arguments:
%        DataType: 32-bit integer (int32), scalar

% Invoke the actual function.
[~, ~, out_DataType] =  cg_array_info(in_A);
