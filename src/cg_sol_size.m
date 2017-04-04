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
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%        dim_vals: 64-bit or 32-bit integer (platform dependent), array  (also required as input)
%
% Output arguments (optional):
%        data_dim: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_sol_size( int fn, int B, int Z, int S, int * data_dim, ptrdiff_t * dim_vals);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/solution.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 5); 
    error('Incorrect number of input or output arguments.');
end
if strfind(computer,'64');
    basetype='int64'; ptrdiff_t=@int64;
else
    basetype='int32'; ptrdiff_t=@int32;
end
if ~isa(io_dim_vals,basetype);
    io_dim_vals=ptrdiff_t(io_dim_vals);
elseif ~isempty(io_dim_vals);
    % Write to it to avoid sharing memory with other variables
    t=io_dim_vals(1); io_dim_vals(1)=t;
end


% Invoke the actual MEX-function.
[out_data_dim, ierr] =  cgnslib_mex(int32(87), in_fn, in_B, in_Z, in_S, io_dim_vals);
