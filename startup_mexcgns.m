function startup_mexcgns
% The startup script of mexCGNS. 

% It builds mexCGNS automatically if the directory 
% [mexcgnsroot '/' computer] does not exist.
% If you need to rebuild mexCGNS, issue build_mexcgns command.
%
% Do not move this file elsewhere because it uses itself to
% determine the path of mexcgns.
%
% See also build_mexcgns.

% Determine the absolute path of mexcgns
mexcgnsroot = which('startup_mexcgns');
mexcgnsroot = mexcgnsroot(1:end-18);
if mexcgnsroot == '.'
    mexcgnsroot = pwd;
end

% Added mexUtil if exists
if exist([mexcgnsroot '/mexUtil'], 'dir')
    addpath([mexcgnsroot '/mexUtil']);
end

% Add mexcgnsroot and its components into the path.
addpath(mexcgnsroot);
addpath( [mexcgnsroot '/src']);

% Build mexCGNS MEX-files if they do not exist
if isoctave
    more off;
    mexdir = [mexcgnsroot '/' computer];

    if ~exist(mexdir,'dir'); mkdir(mexdir); end
    addpath(mexdir);
    addpath([mexcgnsroot '/private']);
end
    
build_mexcgns(mexcgnsroot);
