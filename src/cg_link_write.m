function ierr = cg_link_write(in_nodename, in_filename, in_name_in_file)
% Gateway function for C function cg_link_write.
%
% ierr = cg_link_write(nodename, filename, name_in_file)
%
% Input arguments (required; type is auto-casted):
%        nodename: character string
%        filename: character string
%    name_in_file: character string
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_link_write( char const * nodename, char const * filename, char const * name_in_file);
%
% For detail, see the documentation of the original function.
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(213), in_nodename, in_filename, in_name_in_file);
