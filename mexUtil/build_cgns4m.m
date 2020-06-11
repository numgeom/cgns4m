function build_cgns4m(cgns4m_root)
% Script for building CGNS4M.
%
% See also startup_cgns4m.

SRCDIR = 'cgnslib_3.0';
oldpwd = pwd;
if nargin<1
    cgns4m_root = fileparts(which('startup_cgns4m.m'));
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

if ispc
    HDF_VERSION = 'hdf5-1.8.21';
    sys_hdfroot = ['C:\Program Files\HDF_Group\HDF5\' HDF_VERSION(6:end)];
    if ~exist([sys_hdfroot '\lib'], 'dir')
        url = ['https://support.hdfgroup.org/ftp/HDF5/current18/bin/' ...
                   HDF_VERSION '-Std-win7_64-vs14.zip'];

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
    
    hdf5inc = ['-I' SRCDIR '/adfh -I"' sys_hdfroot '/include" -DBUILD_HDF5'];
    hdf5lib = ['"' sys_hdfroot '\lib\libhdf5.lib" "' ...
        sys_hdfroot '\lib\libszip.lib" "' ...
        sys_hdfroot '\lib\libzlib.lib"'];
elseif isoctave
    if exist('__octave_config_info__', 'builtin')
        octave_config_info = eval('@__octave_config_info__');
    end
    hdf5inc = [octave_config_info('HDF5_CPPFLAGS') ' ' ...
              '-I' SRCDIR '/adfh -DBUILD_HDF5'];
    hdf5lib = [octave_config_info('HDF5_LDFLAGS') ' ' ...
               octave_config_info('HDF5_LIBS')];
   HDF_VERSION = '';
else
    % Try to the same version as MATLAB's built-in version
    [major, minor, release] = H5.get_libversion();
    if major == 1 && minor == 8
        HDF_VERSION = sprintf('hdf5-%d.%d.%d', major, minor, release);
    else
        HDF_VERSION = 'hdf5-1.8.21';
    end
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
if ~strcmp(cgns4m_root,'.') && ~strcmp(cgns4m_root,oldpwd)
    cd(oldpwd);
end

% Perform testing
if isoctave
    rehash;
    success=test('readcgns');
else
    rehash('path');
    success=mtest('readcgns');
end

if success==0
    fprintf(2,'\nThere seems to be some error in building CGNS4m.\n');
else
    disp('CGNS4m was built successfully.');
    if exist(HDF_VERSION, 'dir')
        rmdir(HDF_VERSION, 's');
    end
end
