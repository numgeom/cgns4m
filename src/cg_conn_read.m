function [io_pnts, io_donor_data, ierr] = cg_conn_read(in_file_number, in_B, in_Z, in_I, in_donor_datatype, io_pnts, io_donor_data)
% Gateway function for C function cg_conn_read.
%
% [pnts, donor_data, ierr] = cg_conn_read(file_number, B, Z, I, donor_datatype, pnts, donor_data)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%    donor_datatype: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%            pnts: 64-bit integer (int64), array  (also required as input)
%      donor_data: dynamic type based on donor_datatype  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_read(int file_number, int B, int Z, int I, long long * pnts, CG_DataType_t donor_datatype, long long * donor_data);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 7)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);
in_donor_datatype = int32(in_donor_datatype);

% Perform dynamic type casting
datatype = in_donor_datatype;
switch (datatype)
    case 2 % CG_Integer
        io_donor_data = int32(io_donor_data);
    case 3 % CG_RealSingle
        io_donor_data = single(io_donor_data);
    case 4 % CG_RealDouble
        io_donor_data = double(io_donor_data);
    case 5 % CG_Character
        io_donor_data = [int8(io_donor_data), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_donor_data = int64(io_donor_data);
    otherwise
        error('Unknown data type %d', in_donor_datatype);
end

basetype = 'int64';
if ~isa(io_pnts,basetype)
    io_pnts = cast(io_pnts, basetype);
elseif ~isempty(io_pnts)
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(117), in_file_number, in_B, in_Z, in_I, in_donor_datatype, io_pnts, io_donor_data);
