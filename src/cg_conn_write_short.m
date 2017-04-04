function [out_I, ierr] = cg_conn_write_short(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname)
% Gateway function for C function cg_conn_write_short.
%
% [I, ierr] = cg_conn_write_short(file_number, B, Z, connectname, location, type, ptset_type, npnts, pnts, donorname)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     connectname: character string
%        location: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 32-bit integer (int32), scalar
%            pnts: 32-bit integer (int32), array
%       donorname: character string
%
% Output arguments (optional):
%               I: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_write_short( int file_number, int B, int Z, char const * connectname, GridLocation_t location, GridConnectivityType_t type, PointSetType_t ptset_type, int npnts, int const * pnts, char const * donorname, int * I);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 10); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_I, ierr] =  cgnslib_mex(int32(100), in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname);
