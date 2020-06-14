function [out_descr_name, out_descr_text, ierr] = cg_descriptor_read(in_descr_no)
% Gateway function for C function cg_descriptor_read.
%
% [descr_name, descr_text, ierr] = cg_descriptor_read(descr_no)
%
% Input argument (required; type is auto-casted):
%        descr_no: 32-bit integer (int32), scalar
%
% Output arguments (optional):
%      descr_name: character string
%      descr_text: character string
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_descriptor_read(int descr_no, char * descr_name, char ** descr_text);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html">online documentation</a>.
%

% NOTE: Some buffer space for out char(s) was allocated by C function
% cg_descriptor_read, and the MEX function has deallocated the buffer by
% calling cg_free.
if (nargin < 1)
    error('Incorrect number of input or output arguments.');
end
in_descr_no = int32(in_descr_no);

% Invoke the actual MEX-function.
[out_descr_name, out_descr_text, ierr] = cgnslib_mex(int32(212), in_descr_no);
