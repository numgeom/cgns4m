function [io_zitername, ierr] = cg_ziter_read(in_file_number, in_B, in_Z, io_zitername)
% Gateway function for C function cg_ziter_read.
%
% [zitername, ierr] = cg_ziter_read(file_number, B, Z, zitername)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%       zitername: character string with default length 32  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ziter_read(int file_number, int B, int Z, char * zitername);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
if nargin<4
    io_zitername=char(zeros(1,32));
elseif length(io_zitername)<32
    %% Enlarge the array if necessary;
    io_zitername=char([io_zitername zeros(1,32-length(io_zitername))]);
elseif ~isa(io_zitername,'char')
    io_zitername=char(io_zitername);
else
    % Write to it to avoid sharing memory with other variables
    t=io_zitername(1); io_zitername(1)=t;
end


% Invoke the actual MEX-function.
[io_zitername, ierr] = cgnslib_mex(int32(159), in_file_number, in_B, in_Z, io_zitername);
