function isoct = isoctave
% ISOCTAVE  Determine whether the system is Octave.

persistent isoct__;

if isempty(isoct__)
    isoct__ = exist('OCTAVE_VERSION', 'builtin') > 0;
end

isoct = isoct__;
