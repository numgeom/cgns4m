function [io_index_dim, ierr] = cg_index_dim(in_fn, in_B, in_Z, io_index_dim)
% Gateway function for C function cg_index_dim.
%
% [index_dim, ierr] = cg_index_dim(fn, B, Z, index_dim)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%       index_dim: 32-bit integer (int32), len=3  (optional as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_index_dim(int fn, int B, int Z, int * index_dim);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/structural.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
basetype = 'int32';
if nargin<4
    io_index_dim = zeros(1,3,basetype);
elseif length(io_index_dim)<3
    % Enlarge the array if necessary;
    if size(io_index_dim,2)==1
        io_index_dim=[io_index_dim; zeros(3-length(io_index_dim),1,basetype)];
    else
        io_index_dim=[io_index_dim, zeros(1,3-length(io_index_dim),basetype)];
    end
elseif ~isa(io_index_dim,basetype)
    io_index_dim = cast(io_index_dim, basetype);
elseif ~isempty(io_index_dim)
    % Write to it to avoid sharing memory with other variables
    t=io_index_dim(1); io_index_dim(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(51), in_fn, in_B, in_Z, io_index_dim);
