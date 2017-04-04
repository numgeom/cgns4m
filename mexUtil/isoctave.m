function isoct = isoctave
% ISOCTAVE  Determine whether the system is Octave.

persistent isoct__;

if isempty(isoct__)
    isoct__ = exist('octave_config_info', 'builtin');
end

isoct = isoct__;
