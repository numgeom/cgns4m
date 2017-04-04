function out_DataType = cgns_get_array_type(in_A)
% Helper function for cgns_array_read.
%
% DataType = cgns_get_array_type(A)
%
% Input argument: 
%               A: 32-bit integer (int32), scalar
%
% Output arguments:
%        DataType: 32-bit integer (int32), scalar
%

io_ArrayName=char(zeros(1,32));
io_DimensionVector=int32(zeros(9,1)); 

% Invoke the actual MEX-function.
out_DataType =  cgnslib_mex(int32(199), in_A, io_ArrayName, io_DimensionVector);
