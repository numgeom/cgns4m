function ierr = cg_grid_bounding_box_write(in_file_number, in_B, in_Z, in_G, in_type, in_boundingbox)
% Gateway function for C function cg_grid_bounding_box_write.
%
% ierr = cg_grid_bounding_box_write(file_number, B, Z, G, type, boundingbox)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               G: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%     boundingbox: dynamic type based on type
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_grid_bounding_box_write(int file_number, int B, int Z, int G, CG_DataType_t type, void * boundingbox);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 6)
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
        in_boundingbox = int32(in_boundingbox);
    case 3 % CG_RealSingle
        in_boundingbox = single(in_boundingbox);
    case 4 % CG_RealDouble
        in_boundingbox = double(in_boundingbox);
    case 5 % CG_Character
        in_boundingbox = [int8(in_boundingbox), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_boundingbox = int64(in_boundingbox);
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(85), in_file_number, in_B, in_Z, in_G, in_type, in_boundingbox);
