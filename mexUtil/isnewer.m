function b = isnewer( file1, file2, file3, file4)
% ISNEWER   Returns true if file1 is the newest file among all the input.
%  B = isnewer( file1, file2).
%  B = isnewer( file1, file2, file3).
%  B = isnewer( file1, file2, file3, file4).

a1 = dir(file1);
if isempty(a1); b=0; return; end
a2 = dir(file2);
if ~isempty(a2) && a1.datenum<a2.datenum
    b=0; return;
end

if nargin>2; 
    a3 = dir(file3); 
    if ~isempty(a3) && a1.datenum<a3.datenum
        b=0; return;
    end
end

if nargin>3; 
    a4 = dir(file4); 
    if ~isempty(a4) && a1.datenum<a4.datenum
        b=0; return;
    end
end

b = 1; return;
