function [out_I, ierr] = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data)
% Gateway function for C function cg_conn_write.
%
% [I, ierr] = cg_conn_write(file_number, B, Z, connectname, location, type, ptset_type, npnts, pnts, donorname, donor_zonetype, donor_ptset_type, donor_datatype, ndata_donor, donor_data)
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
%    donor_zonetype: 32-bit integer (int32), scalar
%    donor_ptset_type: 32-bit integer (int32), scalar
%    donor_datatype: 32-bit integer (int32), scalar
%     ndata_donor: 32-bit integer (int32), scalar
%      donor_data: dynamic type based on donor_datatype
%
% Output arguments (optional):
%               I: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_write( int file_number, int B, int Z, char const * connectname, GridLocation_t location, GridConnectivityType_t type, PointSetType_t ptset_type, int npnts, int const * pnts, char const * donorname, ZoneType_t donor_zonetype, PointSetType_t donor_ptset_type, DataType_t donor_datatype, int ndata_donor, void const * donor_data, int * I);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 15); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_donor_datatype;
switch (datatype)
    case 2 % Integer
        in_donor_data = int32(in_donor_data);
    case 3 % RealSingle
        in_donor_data = single(in_donor_data);
    case 4 % RealDouble
        in_donor_data = double(in_donor_data);
    case 5 % Character
        in_donor_data = [int8(in_donor_data), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_donor_datatype);
end


% Invoke the actual MEX-function.
[out_I, ierr] =  cgnslib_mex(int32(93), in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data);
