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
%           npnts: 64-bit integer (int64), scalar
%            pnts: 64-bit integer (int64), array
%       donorname: character string
%
% Output arguments (optional):
%               I: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_write_short(int file_number, int B, int Z, const char * connectname, CG_GridLocation_t location, CG_GridConnectivityType_t type, CG_PointSetType_t ptset_type, long long npnts, const long long * pnts, const char * donorname, int * I);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 10)
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

% Invoke the actual MEX-function.
[out_I, ierr] = cgnslib_mex(int32(120), in_file_number, in_B, in_Z, in_connectname, in_location, in_type, in_ptset_type, in_npnts, in_pnts, in_donorname);
