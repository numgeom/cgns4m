function [io_coord, ierr] = cg_coord_read(in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord)
% Gateway function for C function cg_coord_read.
%
% [coord, ierr] = cg_coord_read(fn, B, Z, coordname, type, rmin, rmax, coord)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       coordname: character string
%            type: 32-bit integer (int32), scalar
%            rmin: 64-bit or 32-bit integer (platform dependent), array
%            rmax: 64-bit or 32-bit integer (platform dependent), array
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%           coord: dynamic type based on type  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_coord_read( int fn, int B, int Z, const char * coordname, CG_DataType_t type, const ptrdiff_t * rmin, const ptrdiff_t * rmax, void * coord);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 8); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_type;
switch (datatype)
    case 2 % CG_Integer
        io_coord = int32(io_coord);
    case 3 % CG_RealSingle
        io_coord = single(io_coord);
    case 4 % CG_RealDouble
        io_coord = double(io_coord);
    case 5 % CG_Character
        io_coord = [int8(io_coord), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_coord = int64(io_coord);
    otherwise
        error('Unknown data type %d', in_type);
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(67), in_fn, in_B, in_Z, in_coordname, in_type, in_rmin, in_rmax, io_coord);

% Perform dynamic type casting
if datatype==5 % CG_Character
    io_coord = char(io_coord(1:end-1));
end
