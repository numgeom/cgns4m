function ierr = cg_bcdataset_write(in_name, in_BCType, in_BCDataType)
% Gateway function for C function cg_bcdataset_write.
%
% ierr = cg_bcdataset_write(name, BCType, BCDataType)
%
% Input arguments (required; type is auto-casted):
%            name: character string
%          BCType: 32-bit integer (int32), scalar
%      BCDataType: 32-bit integer (int32), scalar
%
% Output argument (optional):
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_bcdataset_write(const char * name, CG_BCType_t BCType, CG_BCDataType_t BCDataType);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 3)
    error('Incorrect number of input or output arguments.');
end
in_name = char(in_name);
in_BCType = int32(in_BCType);
in_BCDataType = int32(in_BCDataType);

% Invoke the actual MEX-function.
ierr = cgnslib_mex(int32(175), in_name, in_BCType, in_BCDataType);
