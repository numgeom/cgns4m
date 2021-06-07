function ierr = cg_ziter_write(in_file_number, in_B, in_Z, in_zitername)
% Gateway function for C function cg_ziter_write.
%
% ierr = cg_ziter_write(file_number, B, Z, zitername)
%
% Input arguments (required; type is auto-casted):
%     file_number: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%       zitername: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ziter_write(int file_number, int B, int Z, const char * zitername);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_file_number = int32(in_file_number);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_zitername = char(in_zitername);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(197), in_file_number, in_B, in_Z, in_zitername);
