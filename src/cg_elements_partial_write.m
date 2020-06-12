function ierr = cg_elements_partial_write(in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements)
% Gateway function for C function cg_elements_partial_write.
%
% ierr = cg_elements_partial_write(fn, B, Z, S, start, end, elements)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%           start: 64-bit or 32-bit integer (platform dependent), scalar
%             end: 64-bit or 32-bit integer (platform dependent), scalar
%        elements: 64-bit or 32-bit integer (platform dependent), array
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_elements_partial_write(int fn, int B, int Z, int S, long start, long end, const long * elements);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/grid.html">online documentation</a>.
%
if (nargin < 7)
    error('Incorrect number of input or output arguments.');
end
in_fn = int32(in_fn);
in_B = int32(in_B);
in_Z = int32(in_Z);
in_S = int32(in_S);
if strfind(computer,'64') %#ok<STRIFCND>
    in_start = int64(in_start);
else
    in_start = int32(in_start);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_end = int64(in_end);
else
    in_end = int32(in_end);
end
if strfind(computer,'64') %#ok<STRIFCND>
    in_elements = int64(in_elements);
else
    in_elements = int32(in_elements);
end

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(88), in_fn, in_B, in_Z, in_S, in_start, in_end, in_elements);
