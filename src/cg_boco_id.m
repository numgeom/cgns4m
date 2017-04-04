function [out_boco_id, ierr] = cg_boco_id(in_fn, in_B, in_Z, in_BC)
% Gateway function for C function cg_boco_id.
%
% [boco_id, ierr] = cg_boco_id(fn, B, Z, BC)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%              BC: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%         boco_id: double-precision (double), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_boco_id( int fn, int B, int Z, int BC, double * boco_id);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/bc.html">online documentation</a>.
%
if (nargin < 4); 
    error('Incorrect number of input or output arguments.');
end

% Invoke the actual MEX-function.
[out_boco_id, ierr] =  cgnslib_mex(int32(131), in_fn, in_B, in_Z, in_BC);
