function build_mexcgns(mexcgnsroot)
% Script for building mexCGNS.
%
% See also startup_mexcgns.

srcdir = 'cgnslib_2.5';

oldpwd = pwd;
if nargin<1
    mexcgnsroot = which('build_mexcgns'); mexcgnsroot(end-15:end)=[];
end

% We must build in the mexCGNS directory. Change the directory first.
if ~strcmp(mexcgnsroot,'.') && ~strcmp(mexcgnsroot,pwd)
    disp(['Changing to directory ' mexcgnsroot]);
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
        ~isnewer( 'src/cgnslib_mex_ext.c', mexfile); 
    return; 
end

% Compile all the C-files into MEX functions
CGNSFILES = ['cg_ftoc.c cgnslib.c adf_cond.c cgns_error.c cgns_internals.c '...
    'adf/ADF_fortran_2_c.c adf/ADF_interface.c adf/ADF_internals.c'];
CGNSFILES = addprefix( CGNSFILES, [srcdir '/']);


if isoctave
    command = ['mkoctfile --mex -Isrc -I. -I' srcdir ' -I' srcdir '/adf -o ' ...
        mexfile ' src/cgnslib_mex.c ' CGNSFILES];

    disp(command); fflush(1);
    try
        [status,output]=system(command);
        if status
            error('Output is %s\n. Return status is %d\n', output, status);
        end
    catch
        error('Error during compilation: %s.', lasterr);
    end
else % MATLAB
    command = ['mex -O -Isrc -I. -I' srcdir ' -I' srcdir '/adf -output ' ...
        mexfile ' src/cgnslib_mex.c ' CGNSFILES];

    try
        disp(command); eval(command);
    catch
        error('Error during compilation with err %s.', lasterr);
    end
end

% Change directory back.
if ~strcmp(mexcgnsroot,'.') && ~strcmp(mexcgnsroot,oldpwd)
    disp(['Changing back to directory ' oldpwd]);
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
