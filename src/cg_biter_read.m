function [io_bitername, out_nsteps, ierr] = cg_biter_read(in_file_number, in_B, io_bitername)
% Gateway function for C function cg_biter_read.
%
% [bitername, nsteps, ierr] = cg_biter_read(file_number, B, bitername)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%       bitername: character string with default length 32  (optional as input)
%
% Output arguments (optional):
%          nsteps: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_biter_read(int file_number, int B, char * bitername, int * nsteps);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
if nargin<3
    io_bitername=char(zeros(1,32));
elseif length(io_bitername)<32
    %% Enlarge the array if necessary;
    io_bitername=char([io_bitername zeros(1,32-length(io_bitername))]);
elseif ~isa(io_bitername,'char')
    io_bitername=char(io_bitername);
else
    % Write to it to avoid sharing memory with other variables
    t=io_bitername(1); io_bitername(1)=t;
end


% Invoke the actual MEX-function.
[io_bitername, out_nsteps, ierr] = cgnslib_mex(int32(168), in_file_number, in_B, io_bitername);
