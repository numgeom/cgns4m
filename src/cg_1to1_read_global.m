function [io_range, io_donor_range, io_transform, out_connectname, out_zonename, out_donorname, ret] = cg_1to1_read_global(in_fn, in_B, io_range, io_donor_range, io_transform)
% Gateway function for C function cg_1to1_read_global.
%
% [range, donor_range, transform, connectname, zonename, donorname, ret] = cg_1to1_read_global(fn, B, range, donor_range, transform)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% In&Out arguments (required as output; type is auto-casted):
%           range: unsigned long (Equivalent to a pointer.), array  (also required as input)
%     donor_range: unsigned long (Equivalent to a pointer.), array  (also required as input)
%       transform: unsigned long (Equivalent to a pointer.), array  (also required as input)
%
% Output arguments (optional):
%     connectname: character string
%        zonename: character string
%       donorname: character string
%             ret: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_read_global(int fn, int B, char ** connectname, char ** zonename, char ** donorname,  ** range,  ** donor_range, int ** transform);
%
% For detail, see the documentation of the original function.
if ( nargout < 3 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
basetype = 'ulong (uint32 on 32-bit and uint64 on 64-bit machines. Equivalent to a pointer.)';
if ~isa(io_range,basetype)
    io_range = cast(io_range, basetype);
elseif ~isempty(io_range)
    % Write to it to avoid sharing memory with other variables
    t=io_range(1); io_range(1)=t;
end

basetype = 'ulong (uint32 on 32-bit and uint64 on 64-bit machines. Equivalent to a pointer.)';
if ~isa(io_donor_range,basetype)
    io_donor_range = cast(io_donor_range, basetype);
elseif ~isempty(io_donor_range)
    % Write to it to avoid sharing memory with other variables
    t=io_donor_range(1); io_donor_range(1)=t;
end

basetype = 'ulong (uint32 on 32-bit and uint64 on 64-bit machines. Equivalent to a pointer.)';
if ~isa(io_transform,basetype)
    io_transform = cast(io_transform, basetype);
elseif ~isempty(io_transform)
    % Write to it to avoid sharing memory with other variables
    t=io_transform(1); io_transform(1)=t;
end


% Invoke the actual MEX-function.
[out_connectname, out_zonename, out_donorname, ret] = cgnslib_mex(int32(117), in_fn, in_B, io_range, io_donor_range, io_transform);
