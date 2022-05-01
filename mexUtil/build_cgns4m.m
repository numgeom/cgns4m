function build_cgns4m(force)
% Script for building CGNS4M.
%
% See also startup_cgns4m.

CGNS_VERSION = '3.4.1';
SRCDIR = ['cgnslib_' CGNS_VERSION];
oldpwd = pwd;
cgns4m_root = fileparts(which('startup_cgns4m.m'));

if nargin==0
    force = false;
else
    force = ~isempty(force) && ~isequal(force, 0);
end

% We must build in the CGNS4m directory. Change the directory first.
if ~strcmp(cgns4m_root,'.') && ~strcmp(cgns4m_root,pwd)
    cd(cgns4m_root);
else
    cgns4m_root = pwd;
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
if ~force && ~isnewer( 'src/cgnslib_mex.c', mexfile) && ...
        ~isnewer('src/cgnslib_mex_ext.c', mexfile) && ...
        ~isnewer([SRCDIR '/cgnslib.c'], mexfile)
    cd(oldpwd);
    return;
end

% Compile all the C-files into MEX functions
cgnsfiles = ['cgnslib.c cgns_internals.c cgns_io.c cgns_error.c '...
    'adf/ADF_interface.c adf/ADF_internals.c'];
cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];

if isoctave
    if exist('__octave_config_info__', 'builtin')
        octave_config_info = eval('@__octave_config_info__'); %#ok<EVLCS>
    end
    hdf5inc = [octave_config_info('HDF5_CPPFLAGS') ' ' ...
        '-I' SRCDIR '/adfh -DBUILD_HDF5'];
    hdf5lib = [octave_config_info('HDF5_LDFLAGS') ' ' ...
        octave_config_info('HDF5_LIBS')];
    HDF_VERSION = '';
elseif ispc
    HDF_VERSION = 'hdf5-1.10.8';
    cmp = mex.getCompilerConfigurations('c');
    if contains(lower(cmp.Name), 'mingw')
        untar(['https://github.com/xmjiao/libhdf5-mingw/raw/main/' HDF_VERSION '-mingw64.tgz']);
        sys_hdfroot = HDF_VERSION;
        libz = fullfile(fileparts(fileparts(cmp.LinkerName)), 'x86_64-w64-mingw32', 'lib', 'libz.a');
        hdf5lib = ['"' sys_hdfroot '\lib\libhdf5.a" "' libz '"'];
    else
        sys_hdfroot = ['C:\Program Files\HDF_Group\HDF5\' HDF_VERSION(6:end)];
        if ~exist(fullfile(sys_hdfroot, 'lib', 'libhdf5.a'), 'file')
            url = ['https://support.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.10/' ...
                HDF_VERSION 'bin/windows/' HDF_VERSION '-Std-win7_64-vs14.zip'];

            if ~exist([HDF_VERSION '.zip'], 'file')
                % Download HDF5, unzip, and set path
                fprintf(['Downloading ' HDF_VERSION ' from http://www.hdfgroup.org. Please wait...']);
                websave([HDF_VERSION '.zip'], url);
                disp('Done.');
            end
            unzip([HDF_VERSION '.zip'], HDF_VERSION);
            disp(['Please follow the prompt to install HDF5 under ' sys_hdfroot]);
            status = system([HDF_VERSION '\hdf\' HDF_VERSION '-win64.msi']);
            if status || ~exist([sys_hdfroot '\lib'], 'dir')
                error(['Error in installing ' HDF_VERSION '.'])
            end
        end
        hdf5lib = ['"' sys_hdfroot '\lib\libhdf5.a"' ...
            sys_hdfroot '\lib\libszip.lib" "' ...
            sys_hdfroot '\lib\libzlib.lib"'];
    end

    hdf5inc = ['-I' SRCDIR '/adfh -I"' sys_hdfroot '/include" -DBUILD_HDF5'];
else
    % Try to the same version as MATLAB's built-in version
    [major, minor, release] = H5.get_libversion();
    if major == 1 && minor == 10
        HDF_VERSION = sprintf('hdf5-%d.%d.%d', major, minor, release);
    else
        HDF_VERSION = 'hdf5-1.10.8';
    end
    if ~exist(HDF_VERSION, 'dir')
        % Download HDF5, unzip, and set path
        fprintf(['Downloading ' HDF_VERSION ' from http://www.hdfgroup.org. Please wait...']);
        url = ['https://support.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.10/' ...
            HDF_VERSION '/src/' HDF_VERSION '.tar.gz'];
        untar(url);
        disp('Done.');
    end

    if ~exist([HDF_VERSION '/lib/libhdf5.a'], 'file')
        disp('Building HDF5 from source. Please wait. This may take a few minutes...');
        if ~isempty(strfind(computer, '64')) %#ok<STREMP>
            CFLAGS='-m64';
        else
            CFLAGS='-m32';
        end
        status = system(['cd ' HDF_VERSION '; CC=cc ./configure ' ...
            '--enable-shared=no CFLAGS="' CFLAGS ' -fPIC" ' ...
            '--prefix=$PWD; make install']);
        if status
            error(['Error in installing ' HDF_VERSION '.'])
        else
            disp('Done.');
        end
    end

    hdf5inc = ['-I' SRCDIR '/adfh -I' HDF_VERSION '/include -DBUILD_HDF5'];
    hdf5lib = [HDF_VERSION '/lib/libhdf5.a -L' HDF_VERSION '/lib -ldl -lz'];
end

disp(['Building CGNS4m with HDF5 library ' HDF_VERSION '.']);
cgnsfiles = addprefix(cgnsfiles, [SRCDIR '/']);

if isoctave
    command = ['mkoctfile --mex -g -ImexUtil -Isrc -I. -I' SRCDIR ' -I' SRCDIR '/adf ' ...
        hdf5inc ' -o ' mexfile ' src/cgnslib_mex.c ' cgnsfiles hdf5lib];

    disp(command); fflush(1);
    try
        [status,output]=system(command);
        if exist('cgnslib.o', 'file'); delete *.o; end
        if status
            cd(oldpwd);
            error('Output is %s\n. Return status is %d\n', output, status);
        end
    catch %#ok<*CTCH>
        if exist('cgnslib.o', 'file'); delete *.o; end
        cd(oldpwd);
        error('Error during compilation: %s.', lasterr); %#ok<*LERR>
    end
else % MATLAB
    command = ['mex -g -ImexUtil -Isrc -I. -I' SRCDIR ' -I' SRCDIR '/adf ' ...
        hdf5inc ' -output ' mexfile ' src/cgnslib_mex.c ' cgnsfiles hdf5lib];

    try
        disp(command); eval(command);
    catch
        cd(oldpwd);
        error('Error during compilation with err %s.', lasterr);
    end
end

% Change directory back.
if ~strcmp(cgns4m_root,'.') && ~strcmp(cgns4m_root,oldpwd)
    cd(oldpwd);
end

% Perform testing
if ~force
    disp('Running tests.');
    success=mtest('readcgns');
    if ~success
        disp('CGNS4m was built but some tests have failed.');
    else
        disp('CGNS4m was built and tested successfully.');
        if exist(HDF_VERSION, 'dir')
            rmdir(HDF_VERSION, 's');
        end
    end
else
    disp('CGNS4m was built successfully but not yet tested.');
    disp('You should test it by running mtest(''readcgns'').');
end
