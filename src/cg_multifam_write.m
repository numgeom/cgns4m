function ierr = cg_multifam_write(in_name, in_family)
% Gateway function for C function cg_multifam_write.
%
% ierr = cg_multifam_write(name, family)
%
% Input arguments (required; type is auto-casted):
%            name: character string
%          family: character string
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_multifam_write(const char * name, const char * family);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/families.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_name = char(in_name);
in_family = char(in_family);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(62), in_name, in_family);
