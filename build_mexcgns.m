function build_mexcgns(mexcgnsroot)
% Script for building CGNS4M.
%
% See also startup_mexcgns.

SRCDIR = 'cgnslib_3.0';
HDF_VERSION = 'hdf5-1.8.21';
oldpwd = pwd;
if nargin<1
    mexcgnsroot = fileparts(which('build_mexcgns.m'));
end

% We must build in the CGNS4m directory. Change the directory first.
if ~strcmp(mexcgnsroot,'.') && ~strcmp(mexcgnsroot,pwd)
    cd(mexcgnsroot);
else
    mexcgnsroot = pwd;
end

if isoctave
    mexfile = [computer '/cgnslib_mex.' mexext];
    if ~exist(computer, 'dir')
        mkdir(computer)
    end
else
    mexfile = ['cgnslib_mex.' mexext];
end

% Compile the file if the C code is newer than the MEX file.
if ~isnewer( 'src/cgnslib_mex.c', mexfile) && ...
        ~isnewer('src/cgnslib_mex_ext.c', mexfile) && ...
        ~isnewer([SRCDIR '/cgnslib.c'], mexfile)
    cd(oldpwd);
    return;
end

% Compile all the C-files into MEX functions
cgnsfiles = ['cgnslib.c cgns_internals.c cgns_io.c cgns_error.c '...
    'adf/adf_cond.c adf/ADF_interface.c adf/ADF_internals.c'];
cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];

if ~exist(HDF_VERSION, 'dir')
    if ~exist([HDF_VERSION '.tgz'], 'file')
        % Download HDF5, unzip, and set path
        fprintf(['Downloading ' HDF_VERSION ' from http://www.hdfgroup.org. Please wait...']);
        url = ['https://support.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8/' ...
            HDF_VERSION '/src/' HDF_VERSION '.tar.gz'];
        if exist('websave', 'file')
            websave([HDF_VERSION '.tgz'], url);
        else
            urlwrite(url, [HDF_VERSION '.tgz']); %#ok<*URLWR>
        end
        disp('Done.');
    end
    untar([HDF_VERSION '.tgz']);
end

hdf5lib = ['-L' matlabroot '/bin/' lower(computer) ' -lhdf5'];
hdf5inc = ['-I' SRCDIR '/adfh -I' HDF_VERSION '/include -DBUILD_HDF5'];

if ~exist([HDF_VERSION '/lib/libhdf5.a'], 'file')
    fprintf('Building HDF5 from source. Please wait. This may take a few minutes...');
    if ~isempty(strfind(computer, '64')) %#ok<STREMP>
        CFLAGS='-m64';
    else
        CFLAGS='-m32';
    end
    system(['cd ' HDF_VERSION '; ./configure ' ...
        '--enable-shared=no CFLAGS="' CFLAGS ' -fPIC" ' ...
        '--prefix=$PWD; make install']);
    disp('Done.');
    hdf5lib = [HDF_VERSION '/lib/libhdf5.a -L' HDF_VERSION '/lib -ldl -lz'];
end

disp(['Building CGNS4m with the HDF5 library ' HDF_VERSION '.']);
cgnsfiles = addprefix(cgnsfiles, [SRCDIR '/']);

if isoctave
    command = ['mkoctfile --mex -Isrc -I. -I' SRCDIR ' -I' SRCDIR '/adf ' ...
        hdf5inc ' -o ' mexfile ' src/cgnslib_mex.c ' cgnsfiles hdf5lib];
    
    disp(command); fflush(1);
    try
        [status,output]=system(command);
        if status
            cd(oldpwd);
            error('Output is %s\n. Return status is %d\n', output, status);
        end
    catch %#ok<*CTCH>
        cd(oldpwd);
        error('Error during compilation: %s.', lasterr); %#ok<*LERR>
    end
else % MATLAB
    command = ['mex -O -Isrc -I. -I' SRCDIR ' -I' SRCDIR '/adf ' ...
        hdf5inc ' -output ' mexfile ' src/cgnslib_mex.c ' cgnsfiles hdf5lib];
    
    try
        disp(command); eval(command);
    catch
        cd(oldpwd);
        error('Error during compilation with err %s.', lasterr);
    end
end

% Change directory back.
if ~strcmp(mexcgnsroot,'.') && ~strcmp(mexcgnsroot,oldpwd)
    cd(oldpwd);
end

% Perform testing
if isoctave
    rehash;
    success=test('readcgns_unstr');
else
    rehash('path');
    success=mtest('readcgns_unstr');
end

if success==0
    fprintf(2,'\nThere seems to be some error in building CGNS4m.\n');
else
    disp('CGNS4m was built successfully.');
    if exist(HDF_VERSION, 'dir')
        rmdir(HDF_VERSION, 's');
    end
end
