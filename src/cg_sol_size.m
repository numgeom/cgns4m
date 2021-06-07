function [io_dim_vals, out_data_dim, ierr] = cg_sol_size(in_fn, in_B, in_Z, in_S, io_dim_vals)
% Gateway function for C function cg_sol_size.
%
% [dim_vals, data_dim, ierr] = cg_sol_size(fn, B, Z, S, dim_vals)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; type is auto-casted):
%        dim_vals: 64-bit integer (int64), array  (must be preallocated at input)
%
% Output arguments (optional):
%        data_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_size(int fn, int B, int Z, int S, int * data_dim, long long * dim_vals);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
basetype = 'int64';
if ~isa(io_dim_vals,basetype)
    io_dim_vals = cast(io_dim_vals, basetype);
elseif ~isempty(io_dim_vals)
    % Write to it to unshare memory with other variables
    t=io_dim_vals(1); io_dim_vals(1)=t;
end


% Invoke the actual MEX-function.
[out_data_dim, ierr] = cgnslib_mex(int32(122), in_fn, in_B, in_Z, in_S, io_dim_vals);
