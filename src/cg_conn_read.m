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
% In&Out arguments (required as output; also required as input if specified; type is auto-casted):
%            pnts: 32-bit integer (int32), array  (also required as input)
%      donor_data: dynamic type based on donor_datatype  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_read( int file_number, int B, int Z, int I, int * pnts, DataType_t donor_datatype, void * donor_data);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 2 || nargin < 7); 
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = in_donor_datatype;
switch (datatype)
    case 2 % Integer
        io_donor_data = int32(io_donor_data);
    case 3 % RealSingle
        io_donor_data = single(io_donor_data);
    case 4 % RealDouble
        io_donor_data = double(io_donor_data);
    case 5 % Character
        io_donor_data = [int8(io_donor_data), int8(zeros(1,1))];
    otherwise
        error('Unknown data type %d', in_donor_datatype);
end

if ~isa(io_pnts,'int32');
    io_pnts=int32(io_pnts);
elseif ~isempty(io_pnts);
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(97), in_file_number, in_B, in_Z, in_I, in_donor_datatype, io_pnts, io_donor_data);

% Perform dynamic type casting
if datatype==5 % Character
    io_donor_data = char(io_donor_data(1:end-1));
end
