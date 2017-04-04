function [io_numexp, ierr] = cg_nexponents(io_numexp)
% Gateway function for C function cg_nexponents.
%
% [numexp, ierr] = cg_nexponents(numexp)
%
% Input argument (required; type is auto-casted): 
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%          numexp: 32-bit integer (int32), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_nexponents( int * numexp);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_numexp,'int32');
    io_numexp=int32(io_numexp);
elseif ~isempty(io_numexp);
    % Write to it to avoid sharing memory with other variables
    t=io_numexp(1); io_numexp(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(186), io_numexp);
