function [io_ArrayName, io_DimensionVector, out_DataType, out_DataDimension, ierr] = cg_array_info(in_A, io_ArrayName, io_DimensionVector)
% Gateway function for C function cg_array_info.
%
% [ArrayName, DimensionVector, DataType, DataDimension, ierr] = cg_array_info(A, ArrayName, DimensionVector)
%
% Input argument (required; type is auto-casted): 
%               A: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%       ArrayName: character string with default length 32 
%    DimensionVector: 32-bit integer (int32), len=3 
%
% Output arguments (optional):
%        DataType: 32-bit integer (int32), scalar
%    DataDimension: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_array_info( int A, char * ArrayName, DataType_t * DataType, int * DataDimension, int * DimensionVector);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<2
    io_ArrayName=char(zeros(1,32));
elseif length(io_ArrayName)<32
    %% Enlarge the array if necessary;
    io_ArrayName=char([io_ArrayName zeros(1,32-length(io_ArrayName))]);
elseif ~isa(io_ArrayName,'char');
    io_ArrayName=char(io_ArrayName);
else
    % Write to it to avoid sharing memory with other variables
    t=io_ArrayName(1); io_ArrayName(1)=t;
end

if nargin<3
    io_DimensionVector=zeros(1,3,'int32');
elseif length(io_DimensionVector)<3
    % Enlarge the array if necessary;
    if size(io_DimensionVector,2)==1;
        io_DimensionVector=[io_DimensionVector; zeros(3-length(io_DimensionVector),1,'int32')];
    else
        io_DimensionVector=[io_DimensionVector, zeros(1,3-length(io_DimensionVector),'int32')];
    end
elseif ~isa(io_DimensionVector,'int32');
    io_DimensionVector=int32(io_DimensionVector);
elseif ~isempty(io_DimensionVector);
    % Write to it to avoid sharing memory with other variables
    t=io_DimensionVector(1); io_DimensionVector(1)=t;
end


% Invoke the actual MEX-function.
[out_DataType, out_DataDimension, ierr, io_ArrayName] =  cgnslib_mex(int32(173), in_A, io_ArrayName, io_DimensionVector);
