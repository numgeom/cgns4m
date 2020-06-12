function [io_diffusion_model, ierr] = cg_diffusion_read(io_diffusion_model)
% Gateway function for C function cg_diffusion_read.
%
% [diffusion_model, ierr] = cg_diffusion_read(diffusion_model)
%
% Input argument (required; type is auto-casted):
%
% In&Out argument (required as output; type is auto-casted):
%    diffusion_model: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_diffusion_read(int * diffusion_model);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end
io_diffusion_model = int32(io_diffusion_model);
basetype = 'int32';
if ~isa(io_diffusion_model,basetype)
    io_diffusion_model = cast(io_diffusion_model, basetype);
elseif ~isempty(io_diffusion_model)
    % Write to it to avoid sharing memory with other variables
    t=io_diffusion_model(1); io_diffusion_model(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(205), io_diffusion_model);
