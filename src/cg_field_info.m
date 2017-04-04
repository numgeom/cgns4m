function [io_fieldname, out_type, ierr] = cg_field_info(in_fn, in_B, in_Z, in_S, in_F, io_fieldname)
% Gateway function for C function cg_field_info.
%
% [fieldname, type, ierr] = cg_field_info(fn, B, Z, S, F, fieldname)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%               F: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%       fieldname: character string with default length 32 
%
% Output arguments (optional):
%            type: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_field_info( int fn, int B, int Z, int S, int F, DataType_t * type, char * fieldname);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5); 
    error('Incorrect number of input or output arguments.');
end
if nargin<6
    io_fieldname=char(zeros(1,32));
elseif length(io_fieldname)<32
    %% Enlarge the array if necessary;
    io_fieldname=char([io_fieldname zeros(1,32-length(io_fieldname))]);
elseif ~isa(io_fieldname,'char');
    io_fieldname=char(io_fieldname);
else
    % Write to it to avoid sharing memory with other variables
    t=io_fieldname(1); io_fieldname(1)=t;
end


% Invoke the actual MEX-function.
[out_type, ierr] =  cgnslib_mex(int32(79), in_fn, in_B, in_Z, in_S, in_F, io_fieldname);
