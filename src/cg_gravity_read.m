function [io_gravity_vector, ierr] = cg_gravity_read(in_file_number, in_B, io_gravity_vector)
% Gateway function for C function cg_gravity_read.
%
% [gravity_vector, ierr] = cg_gravity_read(file_number, B, gravity_vector)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%    gravity_vector: single-precision (single), array  (also required as input)
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_gravity_read( int file_number, int B, float * gravity_vector);
%
% For detail, see <a href="http://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 3); 
    error('Incorrect number of input or output arguments.');
end
if ~isa(io_gravity_vector,'single');
    io_gravity_vector=single(io_gravity_vector);
elseif ~isempty(io_gravity_vector);
    % Write to it to avoid sharing memory with other variables
    t=io_gravity_vector(1); io_gravity_vector(1)=t;
end


% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(135), in_file_number, in_B, io_gravity_vector);
