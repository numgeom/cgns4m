function startup_cgns4m
% The startup script of CGNS4m. 

% It builds CGNS4m automatically if the directory 
% [cgns4mroot '/' computer] does not exist.
% If you need to rebuild CGNS4m, issue build_cgns4m command.
%
% Do not move this file elsewhere because it uses itself to
% determine the path of cgns4m.
%
% See also build_cgns4m.

% Determine the absolute path of cgns4m
cgns4mroot = fileparts(which('startup_cgns4m'));
if cgns4mroot == '.'
    cgns4mroot = pwd;
end

% Added mexUtil if exists
if exist([cgns4mroot '/mexUtil'], 'dir')
    addpath([cgns4mroot '/mexUtil']);
end

% Add cgns4mroot and its components into the path.
addpath(cgns4mroot);
addpath( [cgns4mroot '/src']);

% Build CGNS4m MEX-files if they do not exist
if isoctave
    more off;
    mexdir = [cgns4mroot '/' computer];

    if ~exist(mexdir,'dir'); mkdir(mexdir); end
    addpath(mexdir);
    addpath([cgns4mroot '/private']);
end
    
build_cgns4m(cgns4mroot);
