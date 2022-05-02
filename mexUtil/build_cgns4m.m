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

olddir = pwd;
cd(cgns4m_root);
clearup = onCleanup(@()cd(olddir));

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
HDF_VERSION = 'hdf5-1.10.8';

if isoctave
    if exist('__octave_config_info__', 'builtin')
        octave_config_info = eval('@__octave_config_info__'); %#ok<EVLCS>
    end
    hdf5inc = [octave_config_info('HDF5_CPPFLAGS') ' ' ...
        '-I' SRCDIR '/adfh -DBUILD_HDF5'];
    hdf5lib = [octave_config_info('HDF5_LDFLAGS') ' ' ...
        octave_config_info('HDF5_LIBS')];
    HDF_VERSION = '';
elseif ispc && ~contains(lower(mex.getCompilerConfigurations('c').Name), 'mingw')
    % Windows with VC
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
    hdf5inc = ['-I' SRCDIR '/adfh -I"' sys_hdfroot '/include" -DBUILD_HDF5'];
else
    if ~exist(HDF_VERSION, 'dir')
        try
            fprintf(['Trying to download prebuilt ' HDF_VERSION ' library. Please wait...']);
            untar(['https://github.com/xmjiao/libhdf5-static-pic/raw/main/' ...
                HDF_VERSION '-' computer('arch') '.tgz']);
            disp('Done.');
        catch
            % Download HDF5, unzip, and set path
            fprintf(['Failed to download it.\nDownloading ' HDF_VERSION ' from http://www.hdfgroup.org. Please wait...']);
            url = ['https://support.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.10/' ...
                HDF_VERSION '/src/' HDF_VERSION '.tar.gz'];
            untar(url);
            disp('Done.');

            disp('Building HDF5 from source. Please wait. This may take a few minutes...');
            status = system(['cd ' HDF_VERSION '; CC=cc ./configure ' ...
                '--disable-shared --prefix=$PWD CFLAGS="-m64 -fPIC"; make install']);
            if status
                error(['Error in installing ' HDF_VERSION '.'])
            else
                disp('Done.');
            end
        end
    end

    hdf5inc = ['-I' SRCDIR '/adfh -I' HDF_VERSION '/include -DBUILD_HDF5'];
    if ispc
        libz = fullfile(fileparts(fileparts(mex.getCompilerConfigurations('c').LinkerName)), ...
            'x86_64-w64-mingw32', 'lib', 'libz.a');
        hdf5lib = ['"' HDF_VERSION '\lib\libhdf5.a" "' libz '"'];
    else
        hdf5lib = [HDF_VERSION '/lib/libhdf5.a -ldl -lz'];
    end
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

% Perform testing
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
