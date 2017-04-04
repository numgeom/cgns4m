function build_mexcgns(mexcgnsroot, hdfopt)
% Script for building mexCGNS.
%
% See also startup_mexcgns.

srcdir = 'cgnslib_3.1';
if ~isoctave
    buildhdf5frmsrc = false;
    if nargin>1 && strncmp(hdfopt,'--with-hdf5=',12)
        hdfroot=hdfopt(13:end);
    else
        switch computer
            case 'PCWIN'
                hdfroot = 'hdf5-1.8.6-win32';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.6/bin/windows/hdf5-1.8.6-win32.zip';
                zipoutdir = hdfroot;
            case 'PCWIN64'
                hdfroot = 'hdf5-1.8.6-win64';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.6/bin/windows/hdf5-1.8.6-win64.zip';
                zipoutdir = hdfroot;
            case 'MACI64'
                hdfroot = 'hdf5-1.8.8-mac-intel-x86_64-static';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.8/bin/mac-intel-x86_64/hdf5-1.8.8-mac-intel-x86_64-static.tar.gz';
            case 'MACI'
                hdfroot = 'hdf5-1.8.7-mac-intel-static';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.7/bin/mac-intel/hdf5-1.8.7-mac-intel-static.tar.gz';
            case 'GLNX86'
                hdfroot = 'hdf5-1.8.8-linux-static';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.8/bin/linux/hdf5-1.8.8-linux-static.tar.gz';
            case 'GLNXA64'
                % Use a custom-built version with -fpic enabled
                hdfroot = 'hdf5-1.8.8-linux-x86_64-static';
                url = 'http://dl.dropbox.com/u/11812729/hdf5-1.8.8-linux-x86_64-static.tgz';
            otherwise
                buildhdf5frmsrc = true;
                hdfroot = 'hdf5-1.8.8';
                url = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.8.tar.gz';
        end
    end
else
    hdfroot = '';
end

oldpwd = pwd;
if nargin<1
    mexcgnsroot = which('build_mexcgns'); mexcgnsroot(end-15:end)=[];
end

% We must build in the mexCGNS directory. Change the directory first.
if ~strcmp(mexcgnsroot,'.') && ~strcmp(mexcgnsroot,pwd)
    cd(mexcgnsroot);
else
    mexcgnsroot = pwd;
end

if isoctave
    mexfile = [computer '/cgnslib_mex.' mexext];
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
    cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];
    hdf5inc = ['-I' srcdir '/adfh -I' hdfroot '/include -DBUILD_HDF5'];
    if hdfroot(1)=='/'
        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lz'];
    elseif ispc
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.zip'], 'file')
                % Download HDF5, unzip, and set path
                fprintf('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                urlwrite(url, [hdfroot '.zip']);
                fprintf('Done\n');
            end
            unzip([hdfroot '.zip'], zipoutdir);
        end

        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lszip -lzlib'];
    else
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.tgz'], 'file')
                % Download HDF5, unzip, and set path
                fprintf('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                urlwrite(url, [hdfroot '.tgz']);
                fprintf('Done.\n');
            end
            untar([hdfroot '.tgz']);
        end

        hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -lsz -lz'];

        if buildhdf5frmsrc
            fprintf('Building HDF5 from source. Please wait. This may take a few minutes...');
            if ~isempty(strfind( computer, '64'))
                CFLAGS='-m64';
            else
                CFLAGS='-m32';
            end
            system(['cd ' hdfroot '; ./configure ' ...
                    '--enable-shared=no CFLAGS="' CFLAGS ' -fPIC" ' ...
                    '--prefix=$PWD; make install']);
            fprintf('Done.\n');
            hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -lz'];
        end
    end
    
    disp(['Building mexCGNS with the HDF5 library ' hdfroot '.']);
elseif isoctave
    disp('Building mexCGNS with default HDF5 library.');
    
    cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];
    hdf5inc = ['-I' srcdir '/adfh -DBUILD_HDF5'];
    hdf5lib = '-lhdf5 -lz';
else
    hdf5inc = '';
    hdf5lib = '';

    disp('Did not find HDF5 library in the path. Building mexCGNS without HDF5 support.');
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
    success=test_mcode('readcgns_unstr');
end

if success==0
    fprintf(2,'\nThere seems to be some error in building mexCGNS. Please email jiao@ams.sunysb.edu to report bug.\n');
else
    fprintf(1,'mexCGNS was built successfully.\n');
end
