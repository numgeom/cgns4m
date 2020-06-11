function [io_IntegralDataName, ierr] = cg_integral_read(in_IntegralDataIndex, io_IntegralDataName)
% Gateway function for C function cg_integral_read.
%
% [IntegralDataName, ierr] = cg_integral_read(IntegralDataIndex, IntegralDataName)
%
% Input argument (required; type is auto-casted): 
%    IntegralDataIndex: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%    IntegralDataName: character string with default length 32 
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_integral_read( int IntegralDataIndex, char * IntegralDataName);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1); 
    error('Incorrect number of input or output arguments.');
end
if nargin<2
    io_IntegralDataName=char(zeros(1,32));
elseif length(io_IntegralDataName)<32
    %% Enlarge the array if necessary;
    io_IntegralDataName=char([io_IntegralDataName zeros(1,32-length(io_IntegralDataName))]);
elseif ~isa(io_IntegralDataName,'char');
    io_IntegralDataName=char(io_IntegralDataName);
else
    % Write to it to avoid sharing memory with other variables
    t=io_IntegralDataName(1); io_IntegralDataName(1)=t;
end


% Invoke the actual MEX-function.
[ierr, io_IntegralDataName] =  cgnslib_mex(int32(181), in_IntegralDataIndex, io_IntegralDataName);
