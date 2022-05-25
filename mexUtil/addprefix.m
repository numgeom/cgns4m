function list = addprefix(list, pref)
% Add prefix to the list of blank-space separated elements

% Convert list into cells
list_cells = regexp(list, '\S+', 'match');
list = char(zeros(1, length(list) + length(list_cells) * (length(pref))));

c = 1;
for i = 1:length(list_cells)
    s = [pref list_cells{i} ' '];
    c1 = c + length(s); list(c:c1 - 1) = s; c = c1;
end
