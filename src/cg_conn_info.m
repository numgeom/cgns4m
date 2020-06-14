function [out_connectname, out_location, out_type, out_ptset_type, out_npnts, out_donorname, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr] = cg_conn_info(in_file_number, in_B, in_Z, in_Ii)
% Gateway function for C function cg_conn_info.
%
% [connectname, location, type, ptset_type, npnts, donorname, donor_zonetype, donor_ptset_type, donor_datatype, ndata_donor, ierr] = cg_conn_info(file_number, B, Z, Ii)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              Ii: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     connectname: character string
%        location: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 64-bit integer (int64), scalar
%       donorname: character string
%    donor_zonetype: 32-bit integer (int32), scalar
%    donor_ptset_type: 32-bit integer (int32), scalar
%    donor_datatype: 32-bit integer (int32), scalar
%     ndata_donor: 64-bit integer (int64), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_info(int file_number, int B, int Z, int Ii, char * connectname, CG_GridLocation_t * location, CG_GridConnectivityType_t * type, CG_PointSetType_t * ptset_type, long long * npnts, char * donorname, CG_ZoneType_t * donor_zonetype, CG_PointSetType_t * donor_ptset_type, CG_DataType_t * donor_datatype, long long * ndata_donor);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_Ii = int32(in_Ii);

% Invoke the actual MEX-function.
[out_connectname, out_location, out_type, out_ptset_type, out_npnts, out_donorname, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr] = cgnslib_mex(int32(127), in_file_number, in_B, in_Z, in_Ii);
