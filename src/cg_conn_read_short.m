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
% In&Out argument (required as output; type is auto-casted):
%            pnts: 64-bit integer (int64), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_conn_read_short(int file_number, int B, int Z, int I, long long * pnts);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_I = int32(in_I);
basetype = 'int64';
if ~isa(io_pnts,basetype)
    io_pnts = cast(io_pnts, basetype);
elseif ~isempty(io_pnts)
    % Write to it to avoid sharing memory with other variables
    t=io_pnts(1); io_pnts(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(121), in_file_number, in_B, in_Z, in_I, io_pnts);
