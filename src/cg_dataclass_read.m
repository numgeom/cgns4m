function [out_dataclass, ierr] = cg_dataclass_read()
% Gateway function for C function cg_dataclass_read.
%
% [dataclass, ierr] = cg_dataclass_read()
%
% Input argument (required; type is auto-casted): 
%
% Output arguments (optional):
%       dataclass: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_dataclass_read( CG_DataClass_t * dataclass);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_current/midlevel/physical.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_dataclass, ierr] =  cgnslib_mex(int32(228));
