function [io_exponents, ierr] = cg_expfull_read(io_exponents)
% Gateway function for C function cg_expfull_read.
%
% [exponents, ierr] = cg_expfull_read(exponents)
%
% Input argument (required; type is auto-casted):
%
% In&Out argument (required as output; type is auto-casted):
%       exponents: dynamic type based on cg_exponents_info()  (must be preallocated at input)
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_expfull_read(void * exponents);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 1)
    error('Incorrect number of input or output arguments.');
end

% Perform dynamic type casting
datatype = cg_exponents_info();
switch (datatype)
    case 2 % CG_Integer
        io_exponents = int32(io_exponents);
    case 3 % CG_RealSingle
        io_exponents = single(io_exponents);
    case 4 % CG_RealDouble
        io_exponents = double(io_exponents);
    case 5 % CG_Character
        io_exponents = [int8(io_exponents), int8(zeros(1,1))];
    case 6 % CG_LongInteger
        io_exponents = int64(io_exponents);
    case 7 % CG_ComplexSingle
        io_exponents = complex64(io_exponents);
    case 8 % CG_ComplexDouble
        io_exponents = complex128(io_exponents);
    otherwise
        error('Unknown data type %d', cg_exponents_info());
end

if ~isempty(io_exponents)
    % Write to it to unshare memory with other variables
    t=io_exponents(1); io_exponents(1)=t;
end


% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(262), io_exponents);
