function ierr = cg_save_as(in_fn, in_filename, in_file_type, in_follow_links)
% Gateway function for C function cg_save_as.
%
% ierr = cg_save_as(fn, filename, file_type, follow_links)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%        filename: character string
%       file_type: 32-bit integer (int32), scalar
%    follow_links: 32-bit integer (int32), scalar
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_save_as( int fn, const char * filename, int file_type, int follow_links);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(5), in_fn, in_filename, in_file_type, in_follow_links);
