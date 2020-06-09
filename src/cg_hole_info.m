function [io_holename, out_location, out_ptset_type, out_nptsets, out_npnts, ierr] = cg_hole_info(in_fn, in_B, in_Z, in_I, io_holename)
% Gateway function for C function cg_hole_info.
%
% [holename, location, ptset_type, nptsets, npnts, ierr] = cg_hole_info(fn, B, Z, I, holename)
%
% Input arguments (required; type is auto-casted):
%              fn: 32-bit integer (int32), scalar
%               B: 32-bit integer (int32), scalar
%               Z: 32-bit integer (int32), scalar
%               I: 32-bit integer (int32), scalar
%
% In&Out argument (required as output; also required as input if specified; type is auto-casted):
%        holename: character string with default length 32 
%
% Output arguments (optional):
%        location: 32-bit integer (int32), scalar
%      ptset_type: 32-bit integer (int32), scalar
%         nptsets: 32-bit integer (int32), scalar
%           npnts: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_hole_info( int fn, int B, int Z, int I, char * holename, GridLocation_t * location, PointSetType_t * ptset_type, int * nptsets, int * npnts);
%
% For detail, see <a href="http://www.grc.nasa.gov/WWW/cgns/midlevel/connectivity.html">online documentation</a>.
%
if ( nargout < 1 || nargin < 4); 
    error('Incorrect number of input or output arguments.');
end
if nargin<5
    io_holename=char(zeros(1,32));
elseif length(io_holename)<32
    %% Enlarge the array if necessary;
    io_holename=char([io_holename zeros(1,32-length(io_holename))]);
elseif ~isa(io_holename,'char');
    io_holename=char(io_holename);
else
    % Write to it to avoid sharing memory with other variables
    t=io_holename(1); io_holename(1)=t;
end


% Invoke the actual MEX-function.
[out_location, out_ptset_type, out_nptsets, out_npnts, ierr, io_holename] =  cgnslib_mex(int32(91), in_fn, in_B, in_Z, in_I, io_holename);
