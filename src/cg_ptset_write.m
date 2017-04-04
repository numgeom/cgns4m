function ierr = cg_ptset_write(in_ptset_type, in_npnts, in_pnts)
% Gateway function for C function cg_ptset_write.
%
% ierr = cg_ptset_write(ptset_type, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%      ptset_type: 32-bit integer (int32), scalar
%           npnts: 32-bit integer (int32), scalar
%            pnts: 32-bit integer (int32), array
%
% Output argument (optional): 
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_ptset_write( PointSetType_t ptset_type, int npnts, int const * pnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/location.html">online documentation</a>.
%
if (nargin < 3); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
ierr =  cgnslib_mex(int32(201), in_ptset_type, in_npnts, in_pnts);
