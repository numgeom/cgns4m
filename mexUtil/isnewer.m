function b = isnewer( file1, varargin)
% ISNEWER   Returns true if file1 is the newest file among all the input.
%  B = isnewer( file1, file2, ...)

a1 = dir(file1);
if isempty(a1)
    b = false; return;
end

for k = 1:length(varargin)
    a2 = dir(varargin{k});
    if ~isempty(a2) && a1.datenum<a2.datenum
        b = false; return;
    end
end

b = true; return;
