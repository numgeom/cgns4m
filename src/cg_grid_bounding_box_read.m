function [io_boundingbox, ierr] = cg_grid_bounding_box_read(in_file_number, in_B, in_Z, in_G, in_type, io_boundingbox)
% Gateway function for C function cg_grid_bounding_box_read.
%
% [boundingbox, ierr] = cg_grid_bounding_box_read(file_number, B, Z, G, type, boundingbox)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%     boundingbox: dynamic type based on type  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_grid_bounding_box_read(int file_number, int B, int Z, int G, CG_DataType_t type, void * boundingbox);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 6)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_G = int32(in_G);
in_type = int32(in_type);

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        io_boundingbox = int32(io_boundingbox);
    case 3 % CG_RealSingle
        io_boundingbox = single(io_boundingbox);
    case 4 % CG_RealDouble
        io_boundingbox = double(io_boundingbox);
    case 5 % CG_Character
        io_boundingbox = [int8(io_boundingbox), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_boundingbox = int64(io_boundingbox);
    otherwise
        error('Unknown data type %d', in_type);
end

if ~isempty(io_boundingbox)
    % Write to it to unshare memory with other variables
    t=io_boundingbox(1); io_boundingbox(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(84), in_file_number, in_B, in_Z, in_G, in_type, io_boundingbox);
