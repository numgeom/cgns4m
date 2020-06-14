function [out_connectname, out_donorname, out_range, out_donor_range, out_transform, ierr] = cg_1to1_read(in_fn, in_B, in_Z, in_Ii)
% Gateway function for C function cg_1to1_read.
%
% [connectname, donorname, range, donor_range, transform, ierr] = cg_1to1_read(fn, B, Z, Ii)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              Ii: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%     connectname: character string
%       donorname: character string
%           range: 64-bit integer (int64), len=6
%     donor_range: 64-bit integer (int64), len=6
%       transform: 32-bit integer (int32), len=3
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_1to1_read(int fn, int B, int Z, int Ii, char * connectname, char * donorname, long long * range, long long * donor_range, int * transform);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 4)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_Ii = int32(in_Ii);

% Invoke the actual MEX-function.
[out_connectname, out_donorname, out_range, out_donor_range, out_transform, ierr] = cgnslib_mex(int32(134), in_fn, in_B, in_Z, in_Ii);
