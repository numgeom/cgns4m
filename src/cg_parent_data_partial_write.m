function ierr = cg_parent_data_partial_write(in_fn, in_B, in_Z, in_S, in_rmin, in_rmax, in_ParentData)
% Gateway function for C function cg_parent_data_partial_write.
%
% ierr = cg_parent_data_partial_write(fn, B, Z, S, rmin, rmax, ParentData)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               S: 32-bit integer (int32), scalar
%            rmin: 32-bit integer (int32), scalar
%            rmax: 32-bit integer (int32), scalar
%      ParentData: 32-bit integer (int32), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_parent_data_partial_write( int fn, int B, int Z, int S, int rmin, int rmax, int const * ParentData);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/grid.html">online documentation</a>.
%
if (nargin < 7); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(71), in_fn, in_B, in_Z, in_S, in_rmin, in_rmax, in_ParentData);
