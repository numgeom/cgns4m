function [io_pnts, ierr] = cg_conn_read_short(in_file_number, in_B, in_Z, in_I, io_pnts)
% Gateway function for C function cg_conn_read_short.
%
% [pnts, ierr] = cg_conn_read_short(file_number, B, Z, I, pnts)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%            pnts: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_read_short( int file_number, int B, int Z, int I, int * pnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_pnts,'int32');
    io_pnts=int32(io_pnts);
elseif ~isempty(io_pnts);
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(101), in_file_number, in_B, in_Z, in_I, io_pnts);
