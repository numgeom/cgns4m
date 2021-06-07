function ierr = cg_configure(in_what, in_value)
% Gateway function for C function cg_configure.
%
% ierr = cg_configure(what, value)
%
% Input arguments (required; type is auto-casted):
%            what: 32-bit integer (int32), scalar
%           value: dynamic type based on cgns_configure_type(what)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_configure(int what, void * value);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html">online documentation</a>.
%
if (nargin < 2)
    error('Incorrect number of input or output arguments.');
end
in_what = int32(in_what);

% Perform dynamic type casting
datatype = cgns_configure_type(in_what);
switch (datatype)
    case 2 % CG_Integer
        in_value = int32(in_value);
    case 3 % CG_RealSingle
        in_value = single(in_value);
    case 4 % CG_RealDouble
        in_value = double(in_value);
    case 5 % CG_Character
        in_value = [int8(in_value), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        in_value = int64(in_value);
    case 7 % CG_ComplexSingle
        in_value = complex64(in_value);
    case 8 % CG_ComplexDouble
        in_value = complex128(in_value);
    otherwise
        error('Unknown data type %d', cgns_configure_type(in_what));
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(11), in_what, in_value);
