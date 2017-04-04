function [out_I, ierr] = cg_hole_write(in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts)
% Gateway function for C function cg_hole_write.
%
% [I, ierr] = cg_hole_write(fn, B, Z, holename, location, ptset_type, nptsets, npnts, pnts)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%        holename: character string
%        location: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%         nptsets: 32-bit integer (int32), scalar
%           npnts: 64-bit or 32-bit integer (platform dependent), scalar
%            pnts: 64-bit or 32-bit integer (platform dependent), array
%
% Output arguments (optional):
%               I: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_write( int fn, int B, int Z, const char * holename, CG_GridLocation_t location, CG_PointSetType_t ptset_type, int nptsets, ptrdiff_t npnts, const ptrdiff_t * pnts, int * I);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/connectivity.html">online documentation</a>.
%
if (nargin < 9); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_I, ierr] =  cgnslib_mex(int32(114), in_fn, in_B, in_Z, in_holename, in_location, in_ptset_type, in_nptsets, in_npnts, in_pnts);
