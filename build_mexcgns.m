function build_mexcgns(mexcgnsroot, hdfopt)
% Script for building mexCGNS.
%
% See also startup_mexcgns.

srcdir = 'cgnslib_3.0';
if ~isoctave
    if nargin>1 && strncmp(hdfopt,'--with-hdf5=',12)
        hdfroot=hdfopt(13:end);
    else
        urlroot = 'http://www.hdfgroup.org/ftp/HDF5/prev-releases/hdf5-1.8.5/bin/';
        switch computer
            case 'PCWIN'
                hdfroot = 'hdf5-1.8.5-win32';
                url = [urlroot 'windows/hdf5-1.8.5-win32.zip'];
            case 'PCWIN64'
                hdfroot = 'hdf5-1.8.5-win64';
                url = [urlroot 'windows/hdf5-1.8.5-win64.zip'];
            case 'MACI64'
                hdfroot = 'hdf5-1.8.5-macosx64-static';
                url = [urlroot 'macosx/hdf5-1.8.5-macosx64-static.tar.gz'];
            case 'MACI'
                hdfroot = 'hdf5-1.8.5-macosx32-static';
                url = [urlroot 'macosx/hdf5-1.8.5-macosx32-static.tar.gz'];
            case 'GLNX86'
                hdfroot = 'hdf5-1.8.5-linux-static';
                url = [urlroot 'linux/hdf5-1.8.5-linux-static.tar.gz'];
            case 'GLNXA64'
                hdfroot = 'hdf5-1.8.5-linux-x86_64-static-fpic';
                url = [urlroot 'linux-x86_64/hdf5-1.8.5-linux-x86_64-static-fpic.tar.gz'];
            otherwise
                hdfroot = 'hdf5-1.8.5';
                url = [urlroot '../src/hdf5-1.8.5.tar.gz'];
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
        ~isnewer( 'cgnslib_3.0/cgnslib.c', mexfile)
    cd(oldpwd);
    return;
end

% Compile all the C-files into MEX functions
cgnsfiles = ['cgnslib.c cgns_internals.c cgns_io.c cgns_error.c '...
    'adf/adf_cond.c adf/ADF_interface.c adf/ADF_internals.c'];
if ~isempty(hdfroot) && ~isoctave
    disp(['Building mexCGNS with the HDF5 library in ' hdfroot '.']);
    
    cgnsfiles = [cgnsfiles ' adfh/ADFH.c'];
    hdf5inc = ['-I' srcdir '/adfh -I' hdfroot '/include -DBUILD_HDF5'];
    if hdfroot(1)=='/'
        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lz'];
    elseif ispc
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.zip'])
                % Download HDF5, unzip, and set path
                disp('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                urlwrite(url, [hdfroot '.zip']);
            end
            unzip([hdfroot '.zip']);
        end

        hdf5lib = ['-L' hdfroot '/lib -lhdf5 -lszip -lzlib'];
    else
        if ~exist(hdfroot, 'dir')
            if ~exist([hdfroot '.tgz'])
                % Download HDF5, unzip, and set path
                disp('Downloading HDF5 from http://www.hdfgroup.org. Please wait...');
                urlwrite(url, [hdfroot '.tgz']);
            end
            untar([hdfroot '.tgz']);
        end

        hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -lsz -lz'];

        if isequal(hdfroot,'hdf5-1.8.5')
            disp('Building HDF5. Please wait. This may take a few minutes...');
            [status,result] = system(['cd ' hdfroot '; ./configure --enable-shared=no CFLAGS="-m64 -fPIC" --prefix=$PWD; make install']);
            hdf5lib = [hdfroot '/lib/libhdf5.a -L' hdfroot '/lib -lz'];
        end
    end
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
