function [io_dim_vals, out_data_dim, ierr] = cg_discrete_size(in_fn, in_B, in_Z, in_D, io_dim_vals)
% Gateway function for C function cg_discrete_size.
%
% [dim_vals, data_dim, ierr] = cg_discrete_size(fn, B, Z, D, dim_vals)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               D: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%        dim_vals: 32-bit integer (int32), array  (also required as input)
%
% Output arguments (optional):
%        data_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_discrete_size(int fn, int B, int Z, int D, int * data_dim, int * dim_vals);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_D = int32(in_D);
io_dim_vals = int32(io_dim_vals);
basetype='int32';
if ~isa(io_dim_vals,basetype)
    io_dim_vals=int32(io_dim_vals);
elseif ~isempty(io_dim_vals)
    % Write to it to avoid sharing memory with other variables
    t=io_dim_vals(1); io_dim_vals(1)=t;
end


% Invoke the actual MEX-function.
[out_data_dim, ierr] = cgnslib_mex(int32(156), in_fn, in_B, in_Z, in_D, io_dim_vals);
