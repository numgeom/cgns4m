function [io_iterations, out_NormDefinitions, ierr] = cg_convergence_read(io_iterations)
% Gateway function for C function cg_convergence_read.
%
% [iterations, NormDefinitions, ierr] = cg_convergence_read(iterations)
%
% Input argument (required; type is auto-casted):
%
% In&Out argument (required as output; type is auto-casted):
%      iterations: 32-bit integer (int32), array  (also required as input)
%
% Output arguments (optional):
%    NormDefinitions: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_convergence_read(int * iterations, char ** NormDefinitions);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_convergence_read, and the MEX function has deallocated the buffer by
% calling cg_free.
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end
io_iterations = int32(io_iterations);
basetype = 'int32';
if ~isa(io_iterations,basetype)
    io_iterations = cast(io_iterations, basetype);
elseif ~isempty(io_iterations)
    % Write to it to avoid sharing memory with other variables
    t=io_iterations(1); io_iterations(1)=t;
end


% Invoke the actual MEX-function.
[out_NormDefinitions, ierr] = cgnslib_mex(int32(195), io_iterations);
