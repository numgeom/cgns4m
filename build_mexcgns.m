function build_mexcgns(mexcgnsroot, hdfopt)
% Script for building CGNS4M.
%
% See also startup_mexcgns.

srcdir = 'cgnslib_3.1';
hdfroot = 'hdf5-1.8.17';

if ~isoctave
    buildhdf5frmsrc = false;
    if nargin>1 && strncmp(hdfopt,'--with-hdf5=',12)
        hdfroot=hdfopt(13:end);
    else
        zipoutdir = hdfroot;
        switch computer
            case 'PCWIN'
                url = ['https://support.hdfgroup.org/ftp/HDF5/releases/' hdfroot ...
                       '/bin/windows/' hdfroot '-win32-vs2013-shared.zip'];
            case 'PCWIN64'
                url = ['https://support.hdfgroup.org/ftp/HDF5/releases/' hdfroot ...
                       '/bin/windows/' hdfroot '-win64-vs2013-shared.zip'];
            otherwise
                buildhdf5frmsrc = true;
                url = ['https://support.hdfgroup.org/ftp/HDF5/releases/' hdfroot ...
                       '/src/' hdfroot '.tar.gz'];
        end
    end
else
    hdfroot = '';
end

oldpwd = pwd;
if nargin<1
    mexcgnsroot = which('build_mexcgns.m'); 
    mexcgnsroot(end-length('build_mexcgns.m'):end)=[];
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
        ~isnewer( 'src/cgnslib_mex_ext.c', mexfile) && ...
        ~isnewer( 'cgnslib_3.1/cgnslib.c', mexfile)
    cd(oldpwd);
    return;
end

% Compile all the C-files into MEX functions
cgnsfiles = ['cgnslib.c cgns_internals.c cgns_io.c cgns_error.c '...
    'adf/ADF_interface.c adf/ADF_internals.c'];
if ~isempty(hdfroot) && ~isoctave
    disp(['Building CGNS4m with the HDF5 library in ' hdfroot '.']);

    cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];
    hdf5inc = ['-I' srcdir '/adfh -I' hdfroot '/include -DBUILD_HDF5'];
    if hdfroot(1)=='/'
        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lz'];
    elseif ispc
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.zip'], 'file')
                % Download HDF5, unzip, and set path
                disp('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                urlwrite(url, [hdfroot '.zip']);
            end
            unzip([hdfroot '.zip'], zipoutdir);
        end

        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lszip -lzlib'];
    else
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.tgz'], 'file')
                % Download HDF5, unzip, and set path
                fprintf('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                system(['curl -L -s -o ' hdfroot '.tgz ' url]);
                fprintf('Done.\n');
            end
            untar([hdfroot '.tgz']);
        end

        hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -ldl -lsz -lz'];

        if buildhdf5frmsrc
            fprintf('Building HDF5 from source. Please wait. This may take a few minutes...');
            if contains( computer, '64')
                CFLAGS='-m64';
            else
                CFLAGS='-m32';
            end
            system(['cd ' hdfroot '; ./configure ' ...
                    '--enable-shared=no CFLAGS="' CFLAGS ' -fPIC" ' ...
                    '--prefix=$PWD; make install']);
            fprintf('Done.\n');
            hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -ldl -lz'];
        end
    end
    
    disp(['Building CGNS4m with the HDF5 library ' hdfroot '.']);
elseif isoctave
    disp('Building CGNS4m with default HDF5 library.');
    
    cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];
    if exist('__octave_config_info__', 'builtin')
        octave_config_info = eval('@__octave_config_info__');
    end
    hdf5inc = [octave_config_info('HDF5_CPPFLAGS') ' ' ...
              '-I' srcdir '/adfh -DBUILD_HDF5'];
    hdf5lib = [octave_config_info('HDF5_LDFLAGS') ' ' ...
               octave_config_info('HDF5_LIBS')];
else
    hdf5inc = '';
    hdf5lib = '';

    disp('Did not find HDF5 library in the path. Building CGNS4m without HDF5 support.');
end
cgnsfiles = addprefix( cgnsfiles, [srcdir '/']);

if isoctave
    command = ['mkoctfile --mex -Isrc -I. -I' srcdir ' -I' srcdir '/adf ' ...
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
    command = ['mex -O -Isrc -I. -I' srcdir ' -I' srcdir '/adf ' ...
        hdf5inc ' -output ' mexfile ' src/cgnslib_mex.c ' cgnsfiles hdf5lib];

    try
        disp(command); eval(command);
        rmdir(hdfroot, 's');
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
    fprintf(1,'CGNS4m was built successfully.\n');
end
