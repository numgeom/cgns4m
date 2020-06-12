function out_DataType = cgns_configure_type(in_what)
% Helper function for cgns_configure.
%
% DataType = cgns_configure_type(what)
%
% Input argument: 
%            what: 32-bit integer (int32), scalar
%
% Output arguments:
%        DataType: 32-bit integer (int32), scalar
%
% Supported options include CG_CONFIG_COMPRESS, CG_CONFIG_HDF5_COMPRESS
% CG_CONFIG_SET_PATH, CG_CONFIG_ADD_PATH, CG_CONFIG_FILE, and
% CG_CONFIG_ERROR.

switch in_what
    case {CG_CONFIG_COMPRESS,CG_CONFIG_HDF5_COMPRESS,CG_CONFIG_FILE_TYPE}
        out_DataType = Integer;
    case {CG_CONFIG_ERROR,CG_CONFIG_SET_PATH,CG_CONFIG_ADD_PATH}
        out_DataType = Character;
    otherwise
        error('Unsupported option.');
end
