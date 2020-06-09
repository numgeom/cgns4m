function [io_connectname, io_donorname, out_location, out_type, out_ptset_type, out_npnts, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr] = cg_conn_info(in_file_number, in_B, in_Z, in_I, io_connectname, io_donorname)
% Gateway function for C function cg_conn_info.
%
% [connectname, donorname, location, type, ptset_type, npnts, donor_zonetype, donor_ptset_type, donor_datatype, ndata_donor, ierr] = cg_conn_info(file_number, B, Z, I, connectname, donorname)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%     connectname: character string with default length 32 
%       donorname: character string with default length 32 
%
% Output arguments (optional):
%        location: 32-bit integer (int32), scalar
%            type: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 32-bit integer (int32), scalar
%    donor_zonetype: 32-bit integer (int32), scalar
%    donor_ptset_type: 32-bit integer (int32), scalar
%    donor_datatype: 32-bit integer (int32), scalar
%     ndata_donor: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_info( int file_number, int B, int Z, int I, char * connectname, GridLocation_t * location, GridConnectivityType_t * type, PointSetType_t * ptset_type, int * npnts, char * donorname, ZoneType_t * donor_zonetype, PointSetType_t * donor_ptset_type, DataType_t * donor_datatype, int * ndata_donor);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_connectname=char(zeros(1,32));
elseif length(io_connectname)<32
    %% Enlarge the array if necessary;
    io_connectname=char([io_connectname zeros(1,32-length(io_connectname))]);
elseif ~isa(io_connectname,'char');
    io_connectname=char(io_connectname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_connectname(1); io_connectname(1)=t;
end

if nargin<6
    io_donorname=char(zeros(1,32));
elseif length(io_donorname)<32
    %% Enlarge the array if necessary;
    io_donorname=char([io_donorname zeros(1,32-length(io_donorname))]);
elseif ~isa(io_donorname,'char');
    io_donorname=char(io_donorname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_donorname(1); io_donorname(1)=t;
end


% Invoke the actual MEX-function.
[out_location, out_type, out_ptset_type, out_npnts, out_donor_zonetype, out_donor_ptset_type, out_donor_datatype, out_ndata_donor, ierr, io_connectname, io_donorname] =  cgnslib_mex(int32(96), in_file_number, in_B, in_Z, in_I, io_connectname, io_donorname);
