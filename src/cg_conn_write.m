function [out_Ii, ierr] = cg_conn_write(in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data)
% Gateway function for C function cg_conn_write.
%
% [Ii, ierr] = cg_conn_write(file_number, B, Z, connectname, location, type, ptset_type, npnts, pnts, donorname, donor_zonetype, donor_ptset_type, donor_datatype, ndata_donor, donor_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     connectname: character string
%        location: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%            pnts: 64-bit integer (int64), array
%       donorname: character string
%    donor_zonetype: 32-bit integer (int32), scalar
%    donor_ptset_type: 32-bit integer (int32), scalar
%    donor_datatype: 32-bit integer (int32), scalar
%     ndata_donor: 64-bit integer (int64), scalar
%      donor_data: dynamic type based on donor_datatype
%
% Output arguments (optional):
%              Ii: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_write(int file_number, int B, int Z, const char * connectname, CG_GridLocation_t location, CG_GridConnectivityType_t type, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, const char * donorname, CG_ZoneType_t donor_zonetype, CG_PointSetType_t donor_ptset_type, CG_DataType_t donor_datatype, long long ndata_donor, const long long * donor_data, int * Ii);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 15)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_connectname = char(in_connectname);
in_location = int32(in_location);
in_type = int32(in_type);
in_ptset_type = int32(in_ptset_type);
in_npnts = int64(in_npnts);
in_pnts = int64(in_pnts);
in_donorname = char(in_donorname);
in_donor_zonetype = int32(in_donor_zonetype);
in_donor_ptset_type = int32(in_donor_ptset_type);
in_donor_datatype = int32(in_donor_datatype);
in_ndata_donor = int64(in_ndata_donor);

% Perform dynamic type casting
datatype = in_donor_datatype;
switch (datatype)
    case 2 % CG_Integer
        in_donor_data = int32(in_donor_data);
    case 3 % CG_RealSingle
        in_donor_data = single(in_donor_data);
    case 4 % CG_RealDouble
        in_donor_data = double(in_donor_data);
    case 5 % CG_Character
        in_donor_data = [int8(in_donor_data), int8(zeros(1, 1))];
    case 6 % CG_LongInteger
        in_donor_data = int64(in_donor_data);
    otherwise
        error('Unknown data type %d', in_donor_datatype);
end

% Invoke the actual MEX-function.
[out_Ii, ierr] = cgnslib_mex(int32(130), in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname, in_donor_zonetype, in_donor_ptset_type, in_donor_datatype, in_ndata_donor, in_donor_data);
