function [out_Ii, ierr] = cg_1to1_write(in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform)
% Gateway function for C function cg_1to1_write.
%
% [Ii, ierr] = cg_1to1_write(fn, B, Z, connectname, donorname, range, donor_range, transform)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%     connectname: character string
%       donorname: character string
%           range: 64-bit integer (int64), array
%     donor_range: 64-bit integer (int64), array
%       transform: 32-bit integer (int32), array
%
% Output arguments (optional):
%              Ii: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_write(int fn, int B, int Z, const char * connectname, const char * donorname, const long long * range, const long long * donor_range, const int * transform, int * Ii);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 8)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_connectname = char(in_connectname);
in_donorname = char(in_donorname);
in_range = int64(in_range);
in_donor_range = int64(in_donor_range);
in_transform = int32(in_transform);

% Invoke the actual MEX-function.
[out_Ii, ierr] = cgnslib_mex(int32(136), in_fn, in_B, in_Z, in_connectname, in_donorname, in_range, in_donor_range, in_transform);
