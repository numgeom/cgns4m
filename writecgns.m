There are more end-statements than blocks!
There are more end - statements than blocks !
function writecgns(file_name, ps, elems, typestr, var_nodes, var_cells)
% Write out a structured or unstructured mesh with node/cell-centered values to CGNS file.
%
% WRITECGNS(FILENAME, XS, ELEMS, TYPESTR, VAR_NODES, VAR_CELLS)
%
% Arguments:
%   FILENAME is a character string, specifying the output file. The
%       default format is HDF5. If the filename extension is .adf,
%       then the ADF format will be used.
%
%   XS is nxd array containing nodal coordinates, where d is the dimension
%       of the space (in general d is 2 or 3).
%
%   ELEMS (unstructured mesh) is mxd. For a regular unstructured mesh, m
%       is the number of elements, and d is the number of vertices per element.
%       For a mesh with mixed types of elements, where each element is
%       given by first listing the number of vertices per element and then
%       the vertex IDs within the element, so d is 1 and m is the element
%       data size. For example, a mesh with a triangle, a quadrilateral,
%       and five vertices is given by ELEMS=[3 1 2 3, 4 2 3 4 5]'.
%
%   ELEMS (structured mesh) is 1x6. Instead of storing connectivity, ELEMS
%       stores the dimensions of your structured grid in terms of vertices,
%       the origin of the structured grid. For example, for a structured
%       grid that is a 27x15x6 box, with origin at (-0.035, -0.005, 0),
%       ELEMS=[27 15 6 -0.035 -0.005 0].
%
%   TYPESTR is a character string specifying the element type, and it
%       is used to resolve ambiguities when different element types
%       have the same number of vertices per element. For a regular mesh,
%       only the first character is used in resolving ambiguities (e.g.,
%       't...' for triangle and 'q...' for quadrilateral). For mixed
%       meshes, TYPESTR must use 'MIXED2' or 'MIXED3' (case insensitive)
%       for surface and volume meshes, respectively.
%
%   TYPESTR (structured mesh) is a character string specifying the element
%       type.  For structured meshes, there are types 'STRUCT2' for a
%       2-dimensional mesh, and 'STRUCT3' for a 3-dimensional mesh.
%
%   VAR_NODES is a MATLAB structure, of which each field corresponds to a
%       nodal value to be written. The structure can contain an arbitrary
%       number of fields. The field names of the MATLAB structure are
%       mapped to the field names in the CGNS file. If there is no nodal
%       variable to be written, then leave out the argument or use [].
%
%   VAR_CELLS is a MATLAB structure containing elemental values to be
%       written. Its usage is similar to VAR_NODES.
%
% Example usage
%     var_nodes.vdisp = disp;   % Define two nodal variables
%     var_nodes.vnrms = vnrms;
%     var_cells.fnrms = fnrms;  % Define one elemental variables
%     % Write out nodal and elemental variables
%     writecgns('test.cgns', xs, elems, '', var_nodes, var_cells);
%     % Write out nodal and elemental variables
%     writecgns('test.cgns', xs, elems, '', var_nodes);
%     % Write out only elemental variables
%     writecgns('test.cgns', xs, elems, '', [], var_cells);
%
% Note that a field in VAR_NODES (and similarly in VAR_CELLS) is
% an nxd matrix with d>=1. If d>1, each column of the field will
% be written as an individual variable in the CGNS file with a
% variable name "<fieldname>-<column>" (e.g., "disp-1").
%
% See also READCGNS.
%

% Note: This function will be generalized to support structured meshes in
%   the future. At that time, it will be renamed to writecgns and its arguments
%   will change to include a mesh structure.
% Authors:
%        Xiangmin Jiao (jiao@ams.sunysb.edu)
%        Ying Chen (yingchen@ams.sunysb.edu)
%        Bryan Clark (blclark@ams.sunysb.edu)

if ~exist('cgnslib_mex', 'file')
    warning('CGNS does not appear to be compiled  properly. Try to run build_cgns4m.'); %#ok<WNTAG>
    build_cgns4m;
end

if (nargin < 3)
    error('Requires at least three input arguments: filename, coordinates, elements.');
elseif (nargin > 6)
    error('Too many input arguments.');
end

if nargin < 4; typestr = []; end
if nargin < 5; var_nodes = []; end
if nargin < 6; var_cells = []; end

if strcmp(typestr, 'struct2') || strcmp(typestr, 'Struct2')
    typestr = 'STRUCT2';
elseif strcmp(typestr, 'struct3') || strcmp(typestr, 'Struct3')
    typestr = 'STRUCT3';
end

if strcmp(typestr, 'STRUCT2') || strcmp(typestr, 'STRUCT3') % Structured

    % Determine physical dimension
    if elems(3) == 0
        iphysdim = 2;
    else
        iphysdim = 3;
    end

    ni = elems(1);
    nj = elems(2);
    if iphysdim == 3
        nk = elems(3);
    elseif iphysdim == 2
        nk = 0;
    else
        error('physical dimension must be 2 or 3')
    end

    % Set file type to HDF5 or ADF
    if strcmp(file_name(end - 3:end), '.adf')
        ierr = cg_set_file_type(CG_FILE_ADF); chk_error(ierr);
    else
        ierr = cg_set_file_type(CG_FILE_HDF5); chk_error(ierr);
    end

    % WRITE X, Y, Z GRID POINTS TO CGNS FILE
    % Open the CGNS file.
    [index_file, ierr] = cg_open(file_name, CG_MODE_WRITE); chk_error(ierr);

    % Set cell dimension
    if iphysdim == 3
        icelldim = 3;
    elseif iphysdim == 2
        icelldim = 2;
    else
        error('physical dimension must be 2 or 3')
    end

    % Create base
    [index_base, ierr] = cg_base_write(index_file, 'Base', icelldim, iphysdim); chk_error(ierr);

    % Create isize
    isize = [ni, nj, nk, ni - 1, nj - 1, nk - 1, 0, 0, 0];

    % Create zone
    [index_zone, ierr] = cg_zone_write(index_file, index_base, 'Zone 1', isize, Structured); chk_error(ierr);

    %write grid coordinates (user must use SIDS-standard names here)
    if iphysdim == 3
        xs = ps(:, :, :, 1);
        ys = ps(:, :, :, 2);
        zs = ps(:, :, :, 3);
    elseif iphysdim == 2
        xs = ps(:, :, 1);
        ys = ps(:, :, 2);
    else
        error('physical dimension must be 2 or 3')
    end

    if iphysdim == 3
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateX', xs(:, :, :)); chk_error(ierr);
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateY', ys(:, :, :)); chk_error(ierr);
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateZ', zs(:, :, :)); chk_error(ierr);
    elseif iphysdim == 2
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateX', xs(:, :)); chk_error(ierr);
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateY', ys(:, :)); chk_error(ierr);
    else
        error('physical dimension must be 2 or 3')
    end

    % get number of variables
    if isempty(var_nodes)
        n_vn = 0;
    else
        n_vn = length(fieldnames(var_nodes));
    end

    if isempty(var_cells)
        n_vf = 0;
    else
        n_vf = length(fieldnames(var_cells));
    end

    % Write node-centered variables
    if (n_vn ~= 0)
        solname = 'NodeCenteredSolutions';
        [index_sol, ierr] = cg_sol_write(index_file, index_base, index_zone, ...
            solname, Vertex); chk_error(ierr);

        write_variables_struct(index_file, index_base, index_zone, index_sol, var_nodes, iphysdim);
    end

    % Write cell-centered variables
    if (n_vf ~= 0)
        solname = 'CellCenteredSolutions';
        [index_sol, ierr] = cg_sol_write(index_file, index_base, index_zone, ...
            solname, CellCenter); chk_error(ierr);

        write_variables_struct(index_file, index_base, index_zone, index_sol, var_cells, iphysdim);
    end

else % Unstructured

    nelems = size(elems, 1);

    % elems is nxd, where d is 3 for triangle etc.
    if isempty(elems)
        type = NODE;
        icelldim = 1;
    else
        % get elems_type from elems
        [type, icelldim] = get_elemtype(size(elems, 2), typestr, elems);
        if type == MIXED
            [elems, nelems, offsets] = convert_mixed_elements(elems, icelldim);
        end
    end

    % Set file type to HDF5 or ADF
    if strcmp(file_name(end - 3:end), '.adf')
        ierr = cg_set_file_type(CG_FILE_ADF); chk_error(ierr);
    else
        ierr = cg_set_file_type(CG_FILE_HDF5); chk_error(ierr);
    end

    % Open the CGNS file.
    [index_file, ierr] = cg_open(file_name, CG_MODE_WRITE); chk_error(ierr);

    % Create base.
    iphysdim = size(ps, 2);

    [index_base, ierr] = cg_base_write(index_file, 'Base', icelldim, iphysdim); chk_error(ierr);

    % Number of vertices and elements
    isize = [size(ps, 1), nelems, zeros(1, 7)];
    % Create zone
    [index_zone, ierr] = cg_zone_write(index_file, index_base, 'Zone1', isize, ...
        Unstructured); chk_error(ierr);

    % Write grid coordinates (must use SIDS-standard names here)
    [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
        RealDouble, 'CoordinateX', ps(:, 1)); chk_error(ierr); %#ok<*ASGLU>
    [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
        RealDouble, 'CoordinateY', ps(:, 2)); chk_error(ierr);

    if iphysdim == 3
        [index_coor, ierr] = cg_coord_write(index_file, index_base, index_zone, ...
            RealDouble, 'CoordinateZ', ps(:, 3)); chk_error(ierr);
    end

    if type == MIXED && exist('cg_poly_section_write', 'file')
        % Write element connectivity. We must permute elems, but we don't need to
        % cast the data type to integer explicitly (MEX function does it for us).
        [index_sec, ierr] = cg_poly_section_write(index_file, index_base, index_zone, 'Elements', ...
            type, 1, nelems, 0, elems', offsets); chk_error(ierr);
    else
        % Write element connectivity. We must permute elems, but we don't need to
        % cast the data type to integer explicitly (MEX function does it for us).
        [index_sec, ierr] = cg_section_write(index_file, index_base, index_zone, 'Elements', ...
            type, 1, nelems, 0, elems'); chk_error(ierr);
    end

    % get number of variables
    if isempty(var_nodes)
        n_vn = 0;
    else
        n_vn = length(fieldnames(var_nodes));
    end

    if isempty(var_cells)
        n_vf = 0;
    else
        n_vf = length(fieldnames(var_cells));
    end

    % Write node-centered variables
    if (n_vn ~= 0)
        solname = 'NodeCenteredSolutions';
        [index_sol, ierr] = cg_sol_write(index_file, index_base, index_zone, ...
            solname, Vertex); chk_error(ierr);

        write_variables(index_file, index_base, index_zone, index_sol, var_nodes);
    end

    % Write cell-centered variables
    if (n_vf ~= 0)
        solname = 'CellCenteredSolutions';
        [index_sol, ierr] = cg_sol_write(index_file, index_base, index_zone, ...
            solname, CellCenter); chk_error(ierr);

        write_variables(index_file, index_base, index_zone, index_sol, var_cells);
    end
end

% Close the CGNS file.
ierr = cg_close(index_file); chk_error(ierr);
end

function type = get_cgns_datatype(arr)
% Obtain the corresponding CGNS data type for a given array
if isinteger(arr)
    type = Integer;
elseif ischar(arr)
    type = Character;
elseif isa(arr, 'single')
    type = RealSingle;
else
    type = RealDouble;
end
end

function write_variables_struct(index_file, index_base, index_zone, index_sol, struct, iphysdim)
% Subfunction for writing out variable names.
fldlist2 = fieldnames(struct);
fldlist = regexprep(fldlist2, '_dOt_', '.');
fldlist = regexprep(fldlist, '_dSh_', '-');
fldlist = regexprep(fldlist, '_bLk_', ' ');

for ii = 1:length(fldlist)
    if ~strcmp(fldlist{ii}, fldlist2{ii})
        fprintf(2, 'Info: field variable %s is renamed to %s.\n', fldlist2{ii}, fldlist{ii});
    end

    ncol = size(struct.(fldlist2{ii}), iphysdim + 1);
    arr = struct.(fldlist2{ii});
    % type = get_cgns_datatype(arr);
    type = RealDouble;

    if iphysdim == 2
        if ncol == 1
            varname = fldlist{ii};
            [index_field, ierr] = cg_field_write(index_file, index_base, ...
                index_zone, index_sol, type, varname, arr); chk_error(ierr);
        elseif ncol == 2
            % For naming convention, see https://cgns.github.io/CGNS_docs_current/sids/dataname.html
            suffix = ['X'; 'Y']; % Vector

            for jj = 1:ncol
                [index_field, ierr] = cg_field_write(index_file, index_base, index_zone, ...
                    index_sol, type, [fldlist{ii}, suffix(jj, :)], arr(:, :, jj)); chk_error(ierr);
            end
        else
            error('Physical dimension not supported.');
        end

    elseif iphysdim == 3
        if ncol == 1
            varname = fldlist{ii};
            [index_field, ierr] = cg_field_write(index_file, index_base, ...
                index_zone, index_sol, type, varname, arr); chk_error(ierr);
        elseif ncol <= 3 || ncol == 6
            % For naming convention, see https://cgns.github.io/CGNS_docs_current/sids/dataname.html
            if ncol <= 3 % Vector
                suffix = ['X'; 'Y'; 'Z'];
            else % Tensor
                suffix = ['XX'; 'XY'; 'XZ'; 'YY'; 'YZ'; 'ZZ'];
            end

            for jj = 1:ncol
                [index_field, ierr] = cg_field_write(index_file, index_base, index_zone, ...
                    index_sol, type, [fldlist{ii}, suffix(jj, :)], arr(:, :, :, jj)); chk_error(ierr);
            end
        else
            for jj = 1:ncol
                % Store variable as var-<jj>
                varname = sprintf('%s_%d', fldlist{ii}, jj);

                [index_field, ierr] = cg_field_write(index_file, index_base, ...
                    index_zone, index_sol, type, varname, arr(:, :, :, jj)); chk_error(ierr);
            end
        end
    else
        error('Physical dimension not supported.');
    end
end
end

function write_variables(index_file, index_base, index_zone, index_sol, struct)
% Subfunction for writing out variable names.
fldlist2 = fieldnames(struct);
fldlist = regexprep(fldlist2, '_dOt_', '.');
fldlist = regexprep(fldlist, '_dSh_', '-');
fldlist = regexprep(fldlist, '_bLk_', ' ');

for ii = 1:length(fldlist)
    if ~strcmp(fldlist{ii}, fldlist2{ii})
        fprintf(2, 'Info: field variable %s is renamed to %s.\n', fldlist2{ii}, fldlist{ii});
    end

    ncol = size(struct.(fldlist2{ii}), 2);
    arr = struct.(fldlist2{ii});
    type = get_cgns_datatype(arr);

    if ncol == 1
        varname = fldlist{ii};
        [index_field, ierr] = cg_field_write(index_file, index_base, ...
            index_zone, index_sol, type, varname, arr); chk_error(ierr);
    elseif ncol <= 3 || ncol == 6
        % For naming convention, see https://cgns.github.io/CGNS_docs_current/sids/dataname.html
        if ncol <= 3 % Vector
            suffix = ['X'; 'Y'; 'Z'];
        else % Tensor
            suffix = ['XX'; 'XY'; 'XZ'; 'YY'; 'YZ'; 'ZZ'];
        end

        for jj = 1:ncol
            [index_field, ierr] = cg_field_write(index_file, index_base, index_zone, ...
                index_sol, type, [fldlist{ii}, suffix(jj, :)], arr(:, jj)); chk_error(ierr);
        end
    else
        for jj = 1:ncol
            % Store variable as var-<jj>
            varname = sprintf('%s_%d', fldlist{ii}, jj);

            [index_field, ierr] = cg_field_write(index_file, index_base, ...
                index_zone, index_sol, type, varname, arr(:, jj)); chk_error(ierr);
        end
    end
end
end

function [type, icelldim] = get_elemtype(npe, typestr, elems)
% Obtain the element-type ID and dimension of elements
switch (npe)
    case 1
        type = MIXED;

        if strcmpi(typestr, 'MIXED2')
            icelldim = 2;
        elseif strcmpi(typestr, 'MIXED3')
            icelldim = 3;
        else
            try
                convert_mixed_elements(elems, 3);
                icelldim = 3;
            catch %#ok<CTCH>
                icelldim = 2;
            end
        end
    case 2
        type = BAR_2;
        icelldim = 1;
    case 3
        if ~isempty(typestr) && upper(typestr(1)) == 'B'
            type = BAR_3;
            icelldim = 1;
        else
            type = TRI_3;
            icelldim = 2;
        end
    case 4
        if ~isempty(typestr) && upper(typestr(1)) == 'Q'
            type = QUAD_4;
            icelldim = 2;
        else
            type = TETRA_4;
            icelldim = 3;
        end
    case 5
        type = PYRA_5;
        icelldim = 3;
    case 6
        if (~isempty(typestr) && upper(typestr(1)) == 'P')
            type = PENTA_6;
            icelldim = 3;
        else
            type = TRI_6;
            icelldim = 2;
        end
    case 8
        if ~isempty(typestr) && upper(typestr(1)) == 'Q'
            type = QUAD_8;
            icelldim = 2;
        else
            type = HEXA_8;
            icelldim = 3;
        end
    case 9
        type = QUAD_9;
        icelldim = 2;
    case 10
        type = TETRA_10;
        icelldim = 3;
    case 13
        type = PYRA_13;
        icelldim = 3;
    case 14
        type = PYRA_14;
        icelldim = 3;
    case 15
        type = PENTA_15;
        icelldim = 3;
    case 18
        type = PENTA_18;
        icelldim = 3;
    case 20
        type = HEXA_20;
        icelldim = 3;
    case 27
        type = HEXA_27;
        icelldim = 3;
    otherwise
        error('ERROR: unknown element type with %d nodes.', npe);
end
end

function [elems, nelems, offsets] = convert_mixed_elements(elems, dim)
% Convert from the number of vertices per element into
% element_type in the connecitvity table.
es = size(elems, 1);
offsets = zeros(es + 1, 1);

ii = 1;
nelems = 0;
if dim == 2
    % Convert 2-D elements
    while (ii < es)
        nvpe = elems(ii);
        switch nvpe
            case 3
                elems(ii) = TRI_3;
            case 4
                elems(ii) = QUAD_4;
            case 6
                elems(ii) = TRI_6;
            case 8
                elems(ii) = QUAD_8;
            case 9
                elems(ii) = QUAD_9;
            otherwise
                error('ERROR: unknown element type with %d nodes.', nvpe);
        end

        ii = ii + nvpe + 1;
        nelems = nelems + 1;
        offsets(nelems + 1) = ii - 1;
    end
else
    % Convert 3-D elements
    assert(dim == 3);
    while (ii < es)
        nvpe = elems(ii);
        switch nvpe
            case 4
                elems(ii) = TETRA_4;
            case 5
                elems(ii) = PYRA_5;
            case 6
                elems(ii) = PENTA_6;
            case 8
                elems(ii) = HEXA_8;
            case 10
                elems(ii) = TETRA_10;
            case 13
                elems(ii) = PYRA_13;
            case 14
                elems(ii) = PYRA_14;
            case 15
                elems(ii) = PENTA_15;
            case 18
                elems(ii) = PENTA_18;
            case 20
                elems(ii) = HEXA_20;
            case 27
                elems(ii) = HEXA_27;
            otherwise
                error('ERROR: unknown element type with %d nodes.', nvpe);
        end
        ii = ii + nvpe + 1;
        nelems = nelems + 1;
        offsets(nelems + 1) = ii - 1;
    end
end

offsets = offsets(1:nelems + 1);
end

function chk_error(ierr)
% Check whether CGNS returned an error code. If so, get error message
if ierr
    error(['Error: ', cg_get_error()]);
end
end

%% Integrated test block. Run these tests by issuing command
% "test_mcode writecgns" in Octave or MATLAB.

%% Test to write a triangular mesh
%!shared xs, tris, elems
%! xs = [0 0 0; 1 0 0; 1 1 0; 0 1 0];
%! tris = [1 2 3; 3 4 1];
%! elems = [3 1 2 3, 3 3 4 1]';
%!test
%! writecgns('test1_tri.adf', xs, tris);
%! writecgns('test1_tri.adf', xs, tris, []);
%! delete test1_tri.adf;

%!test
%! writecgns('test1_tri.cgns', xs, tris);
%! writecgns('test1_tri.cgns', xs, tris, []);
%! delete test1_tri.cgns;

%% Test to write a mixed mesh
%!test
%! writecgns('test1_mixed.adf', xs, elems, 'MIXED2');
%! writecgns('test1_mixed.adf', xs, elems, 'MIXED2', []);
%! delete test1_mixed.adf;

%!test
%! writecgns('test1_mixed.cgns', xs, elems, 'MIXED2');
%! writecgns('test1_mixed.cgns', xs, elems, 'MIXED2', []);
%! delete test1_mixed.cgns;

%% Test to write nodal variables
%!test
%! nodal_vars.vec = xs;
%! nodal_vars.sca = xs(:,1);
%! writecgns('test1_tri.adf', xs, tris, [], nodal_vars);
%! writecgns('test1_mixed.adf', xs, elems, 'MIXED2', nodal_vars);
%! delete test1_tri.adf;
%! delete test1_mixed.adf;

%!test
%! nodal_vars.vec = xs;
%! nodal_vars.sca = xs(:,1);
%! writecgns('test1_tri.cgns', xs, tris, [], nodal_vars);
%! writecgns('test1_mixed.cgns', xs, elems, 'MIXED2', nodal_vars);
%! delete test1_tri.cgns;
%! delete test1_mixed.cgns;

%% Test to write elemental variables
%!test
%! eleml_vars.vec = tris;
%! eleml_vars.sca = int32(tris(:,1));
%! writecgns('test1_tri.adf', xs, tris, [], [], eleml_vars);
%! writecgns('test1_mixed.adf', xs, elems, 'MIXED2', [], eleml_vars);
%! delete test1_tri.adf;
%! delete test1_mixed.adf;

%!test
%! eleml_vars.vec = tris;
%! eleml_vars.sca = int32(tris(:,1));
%! writecgns('test1_tri.cgns', xs, tris, [], [], eleml_vars);
%! writecgns('test1_mixed.cgns', xs, elems, 'MIXED2', [], eleml_vars);
%! delete test1_tri.cgns;
%! delete test1_mixed.cgns;

%% Test to write both nodal and elemental variables
%!test
%! nodal_vars.vec = xs;
%! nodal_vars.sca = xs(:,1);
%! eleml_vars.vec = tris;
%! eleml_vars.sca = int32(tris(:,1));
%! writecgns('test1_tri.adf', xs, tris, [], nodal_vars, eleml_vars);
%! writecgns('test1_mixed.adf', xs, elems, 'MIXED2', nodal_vars, eleml_vars);
%! delete test1_tri.adf;
%! delete test1_mixed.adf;

%!test
%! nodal_vars.vec = xs;
%! nodal_vars.sca = xs(:,1);
%! eleml_vars.vec = tris;
%! eleml_vars.sca = int32(tris(:,1));
%! writecgns('test1_tri.cgns', xs, tris, [], nodal_vars, eleml_vars);
%! writecgns('test1_mixed.cgns', xs, elems, 'MIXED2', nodal_vars, eleml_vars);
%! delete test1_tri.cgns;
%! delete test1_mixed.cgns;
