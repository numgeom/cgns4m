function [io_file_type, ierr] = cg_get_file_type(in_fn, io_file_type)
% Gateway function for C function cg_get_file_type.
%
% [file_type, ierr] = cg_get_file_type(fn, file_type)
%
% Input argument (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%       file_type: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_get_file_type(int fn, int * file_type);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
basetype = 'int32';
if ~isa(io_file_type,basetype)
    io_file_type = cast(io_file_type, basetype);
elseif ~isempty(io_file_type)
    % Write to it to avoid sharing memory with other variables
    t=io_file_type(1); io_file_type(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(8), in_fn, io_file_type);
