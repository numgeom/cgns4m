% A testing tool for MATLAB based on the test function in Octave.
%
% -- Function File:  mtest NAME
% -- Function File:  mtest NAME quiet|normal|verbose
% -- Function File:  mtest ('NAME', 'quiet|normal|verbose', FID)
% -- Function File:  mtest ([], 'explain', FID)
% -- Function File: SUCCESS = mtest (...)
% -- Function File: [N, MAX] = mtest (...)
% -- Function File: [CODE, IDX] = mtest ('NAME','grabdemo')
%    Perform tests from the first file in the loadpath matching NAME.
%      `test' can be called as a command or as a function. Called with a
%      single argument NAME, the tests are run interactively and stop
%      after the first error is encountered.
%
%      With a second argument the tests which are performed and the
%      amount of output is selected.
%
%     'quiet'
%           Don't report all the tests as they happen, just the errors.
%
%     'normal'
%           Report all tests as they happen, but don't do tests which
%           require user interaction.
%
%     'verbose'
%           Do tests which require user interaction.
%
%      The argument FID can be used to allow batch processing. Errors can
%      be written to the already open file defined by FID, and hopefully
%      when octave crashes this file will tell you what was happening
%      when it did. You can use 1 if you want to see the results as
%      they happen.  You can also give a file name rather than an FID, in
%      which case the contents of the file will be replaced with the log
%      from the current test.
%
%      Called with a single output argument SUCCESS, `test' returns true
%      if all of the tests were successful. Called with two output
%      arguments N and MAX, the number of successful tests and the total
%      number of tests in the file NAME are returned.
%
%      If the second argument is the string 'grabdemo', the contents of
%      the demo blocks are extracted but not executed. Code for all code
%      blocks is concatenated and returned as CODE with IDX being a
%      vector of positions of the ends of the demo blocks.
%
%      If the second argument is 'explain', then NAME is ignored and an
%      explanation of the line markers used is written to the file FID.
%
% Note: When running in Octave, please use the native 'test' instead.
% See <a
% href="http://www.gnu.org/software/octave/doc/interpreter/Test-Functions.html">online documentation</a> of test.

% Copyright (C) 2005, 2006, 2007 Paul Kienzle
%
% This file is part of Octave.
%
% Octave is free software; you can redistribute it and/or modify it
% under the terms of the GNU General Public License as published by
% the Free Software Foundation; either version 3 of the License, or (at
% your option) any later version.
%
% Octave is distributed in the hope that it will be useful, but
% WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
% General Public License for more details.
%
% You should have received a copy of the GNU General Public License
% along with Octave; see the file COPYING.  If not, see
% <http://www.gnu.org/licenses/>.

% Copyright (C) 2009 Xiangmin Jiao
% Adaped by Xiangmin Jiao to work with both MATLAB and Octave.
%
% This function is different from the Octave test function in the following aspsects:
% - Leading insignificant characters before %! are ignored by mtest.
% - Only basic directives (test, xtest, shared, assert and fail) are supported.

function [ret1__, ret2__, ret3__, ret4__] = mtest (name__, flag__, fid__)
%% information from test will be introduced by 'key'
persistent signal_fail__;
persistent signal_empty__;
persistent signal_block__;
persistent signal_file__;
persistent signal_skip__;

if isempty(signal_fail__); signal_fail__ = '%%%%! '; end
if isempty(signal_empty__); signal_empty__ = '????? '; end
if isempty(signal_block__); signal_block__ = '  ***** '; end
if isempty(signal_file__); signal_file__ = '>>>>> '; end
if isempty(signal_skip__); signal_skip__ = '----- '; end

xfail__ = 0;
xskip__ = 0;

if (nargin < 2 || isempty (flag__))
    flag__ = 'quiet';
end
if (nargin < 3)
    fid__ = [];
end
if (nargin < 1 || nargin > 3 || (~ischar (name__) && ~isempty (name__)) || ~ischar(flag__))
    error('Incorrect input arguments');
end
if (isempty (name__) && (nargin ~= 3 || ~strcmp (flag__, 'explain')))
    error('Incorrect input arguments');
end
batch__ = (~isempty (fid__));

%% decide if error messages should be collected
close_fid__ = 0;
if (batch__)
    if (ischar (fid__))
        fid__ = fopen (fid__, 'wt');
        if (fid__ < 0)
            error ('could not open log file');
        end
        close_fid__ = 1;
    end
    fprintf (fid__, '%sprocessing %s\n', signal_file__, name__);
else
    fid__ = 1;
end

if (strcmp (flag__, 'normal'))
    grabdemo__ = 0;
    rundemo__ = 0;
    verbose__ = batch__;
elseif (strcmp (flag__, 'quiet'))
    grabdemo__ = 0;
    rundemo__ = 0;
    verbose__ = 0;
elseif (strcmp (flag__, 'verbose'))
    grabdemo__ = 0;
    rundemo__ = 1;
    verbose__ = 1;
elseif (strcmp (flag__, 'grabdemo'))
    grabdemo__ = 1;
    rundemo__ = 0;
    verbose__ = 0;
    demo_code__ = '';
    demo_idx__ = 1;
elseif (strcmp (flag__, 'explain'))
    fprintf (fid__, '%% %s new test file\n', signal_file__);
    fprintf (fid__, '%% %s no tests in file\n', signal_empty__);
    fprintf (fid__, '%% %s test had an unexpected result\n', signal_fail__);
    fprintf (fid__, '%% %s code for the test\n', signal_block__);
    fprintf (fid__, '%% Search for the unexpected results in the file\n');
    fprintf (fid__, '%% then page back to find the file name which caused it.\n');
    fprintf (fid__, '%% The result may be an unexpected failure (in which\n');
    fprintf (fid__, '%% case an error will be reported) or an unexpected\n');
    fprintf (fid__, '%% success (in which case no error will be reported).\n');
    if (close_fid__)
        fclose(fid__);
    end
    return;
else
    error ('test unknown flag "%s"', flag__);
end

%% locate the file to test
if ~strcmp(name__(end - 1:end), '.m')
    name__ = [name__ '.m'];
end
if exist('./test', 'dir')
    addpath('./test');
    path_changed = true;
else
    path_changed = false;
end
file__ = which (name__);
if path_changed; rmpath('./test'); end

if (isempty (file__))
    if (grabdemo__)
        ret1__ = '';
        ret2__ = [];
    else
        fprintf (fid__, '%s%s does not exist in path\n', signal_empty__, name__);
        if (nargout > 0)
            ret1__ = 0; ret2__ = 0;
        end
    end
    if (close_fid__)
        fclose(fid__);
    end
    return;
end
%% grab the test code from the file
body__ = extract_test_code (file__);

if (isempty (body__))
    if (grabdemo__)
        ret1__ = '';
        ret2__ = [];
    else
        fprintf (fid__, '%s%s has no tests available\n', signal_empty__, file__);
        if (nargout > 0)
            ret1__ = 0; ret2__ = 0;
        end
    end
    if (close_fid__)
        fclose(fid__);
    end
    return;
else
    %% add a dummy comment block to the end for ease of indexing
    if (body__ (length(body__)) == newline)
        body__ = sprintf ('\n%s%%', body__);
    else
        body__ = sprintf ('\n%s\n%%', body__);
    end
end

%% chop it up into blocks for evaluation
lineidx__ = find (body__ == newline);
blockidx__ = lineidx__(~isspace (body__(lineidx__ + 1))) + 1;

%% ready to start tests ... if in batch mode, tell us what is happening
if (verbose__)
    disp (strcat (signal_file__, file__));
end

%% assume all tests will pass
all_success__ = 1;

%% process each block separately, initially with no shared variables
tests__ = 0; successes__ = 0;
shared__ = ' ';
shared_r__ = ' ';
clear__ = '';
for i__ = 1:length(blockidx__) - 1

    %% extract the block
    block__ = body__(blockidx__(i__):blockidx__(i__ + 1) - 2);

    %% let the user/logfile know what is happening
    if (verbose__)
        fprintf (fid__, '%s%s\n', signal_block__, block__);
    end

    %% split block into type and code
    idx__ = find (~isletter (block__));
    if (isempty (idx__))
        type__ = block__;
        code__ = '';
    else
        type__ = block__(1:idx__(1) - 1);
        code__ = block__(idx__(1):length(block__));
    end

    %% assume the block will succeed;
    success__ = 1;
    msg__ = [];

    %% DEMO
    %% If in grabdemo mode, then don't process any other block type.
    %% So that the other block types don't have to worry about
    %% this grabdemo mode, the demo block processor grabs all block
    %% types and skips those which aren't demo blocks.
    isdemo__ = strcmp (type__, 'demo');
    if (grabdemo__ || isdemo__)
        istest__ = 0;

        if (grabdemo__ && isdemo__)
            if (isempty(demo_code__))
                demo_code__ = code__;
                demo_idx__ = [1, length(demo_code__) + 1];
            else
                demo_code__ = strcat(demo_code__, code__);
                demo_idx__ = [demo_idx__, length(demo_code__) + 1]; %#ok<*AGROW>
            end

        elseif (rundemo__ && isdemo__)
            try
                % In MATLAB, one cannot create a function using eval, so we
                % have to create a function for the test.
                clear test_run_demo;
                fid_m__ = fopen('test_run_demo.m', 'w');
                fprintf (fid_m__, 'function test_run_demo()\n%s\nend', code__);
                fclose(fid_m__); rehash;
                test_run_demo;
                input ('Press <enter> to continue: ', 's');
                delete test_run_demo.m;
            catch ex
                delete test_run_demo.m;
                success__ = 0;
                msg__ = sprintf ('%sdemo failed\n%s', signal_fail__, ex.message);
            end
        end
        code__ = ''; % code already processed

        %% shared
    elseif strcmp (type__, 'shared')
        istest__ = 0;

        %% separate initialization code from variables
        idx__ = find (code__ == newline);
        if (isempty (idx__))
            vars__ = code__;
            code__ = '';
        else
            vars__ = code__ (1:idx__(1) - 1);
            code__ = code__ (idx__(1):length(code__));
        end

        %% strip comments off the variables
        idx__ = find (vars__ == '%' | vars__ == '%');
        if (~isempty (idx__))
            vars__ = vars__(1:idx__(1) - 1);
        end

        %% assign default values to variables
        try
            vars__ = deblank (vars__);
            if (~isempty (vars__))
                eval (strcat (strrep (vars__, ',', '=[];'), '=[];'));
                shared__ = vars__;
                shared_r__ = strcat ('[ ', vars__, '] = ');
            else
                shared__ = ' ';
                shared_r__ = ' ';
            end
        catch ex
            code__ = ''; % couldn't declare, so don't initialize
            success__ = 0;
            msg__ = sprintf ('%sshared variable initialization failed\n%s', signal_fail__, ex.message);
        end

        %% clear shared function definitions
        eval (clear__, '');
        clear__ = '';

        %% initialization code will be evaluated below

        %% FUNCTION
    elseif (strcmp (type__, 'function'))
        istest__ = 0;

        name_position__ = function_name (block__);
        if (isempty (name_position__))
            success__ = 0;
            msg__ = sprintf ('%stest failed: missing function name\n', signal_fail__);
        else
            name__ = block__(name_position__(1):name_position__(2));
            code__ = block__;
            try
                eval(code__); % % Define the function
                clear__ = sprintf ('%sclear %s;\n', clear__, name__);
            catch ex
                success__ = 0;
                msg__ = sprintf ('%stest failed: syntax error\n%s', signal_fail__, ex.message);
            end
        end
        code__ = '';

        %% ASSERT/FAIL
    elseif (strcmp (type__, 'assert'))
        istest__ = 1;
        code__ = block__; % put the keyword back on the code
        %% the code will be evaluated below as a test block

        %% FAIL
    elseif (strcmp (type__, 'fail'))
        istest__ = 1;
        code__ = ''; % Ignore the fail command

        %% ERROR/WARNING
    elseif (strcmp (type__, 'error') || strcmp(type__, 'warning'))
        istest__ = 1;
        warning__ = strcmp (type__, 'warning');
        [pattern__, code__] = getpattern (code__);

        success__ = 0;
        warnstate__ = warning ('query', 'quiet');
        warning ('on', 'quiet');
        try
            % In MATLAB, one cannot create a function using eval, so we
            % have to create a function for the test.
            clear test_run_error;
            fid_m__ = fopen('test_run_error.m', 'w');
            fprintf (fid_m__, 'function test_run_error(%s)\n%s\nend', shared__, code__);
            fclose(fid_m__); rehash;
            eval (sprintf ('test_run_error(%s);', shared__));
            delete test_run_error.m;

            if (~warning__)
                msg__ = sprintf ('%sexpected <%s> but got no error\n', signal_fail__, pattern__);
            else
                err__ = trimerr (lastwarn, 'warning');
                warning (warnstate__.state, 'quiet');
                if (isempty (err__))
                    msg__ = sprintf ('%sexpected <%s> but got no warning\n', signal_fail__, pattern__);
                elseif (isempty (regexp (err__, pattern__, 'once')))
                    msg__ = sprintf ('%sexpected <%s> but got %s\n', signal_fail__, pattern__, err__);
                else
                    success__ = 1;
                end
            end

        catch ex
            delete test_run_error.m;

            err__ = trimerr (ex.message, 'error');
            warning (warnstate__.state, 'quiet');
            if (warning__)
                msg__ = sprintf ('%sexpected warning <%s> but got error %s\n', signal_fail__, pattern__, err__);
            elseif (isempty (regexp (err__, pattern__, 'once')))
                msg__ = sprintf ('%sexpected <%s> but got %s\n', signal_fail__, pattern__, err__);
            else
                success__ = 1;
            end
        end

        code__ = ''; % code already processed

        %% TESTIF
    elseif (strcmp (type__, 'testif'))
        [e__, feat__] = regexp (code__, '^\s*([^\s]+)', 'end', 'tokens');
        if exist('__octave_config_info__', 'builtin')
            % octave_config_info is depreciated in 4.2.1
            octave_config_info = eval('@__octave_config_info__'); %#ok<*EVLCS>
        end

        if (isoctave && ...
                isempty(strfind(octave_config_info('DEFS'), feat__{1}{1})))
            xskip__ = xskip__ + 1;
            success__ = 0;
            istest__ = 0;
            code__ = ''; % skip the code
            msg__ = sprintf ('%sskipped test\n', signal_skip__);
        else
            istest__ = 1;
            code__ = code__(e__ + 1:end);
        end

        %% TEST
    elseif (strcmp (type__, 'test') || strcmp (type__, 'xtest'))
        istest__ = 1;
        %% code__ will be evaluated below

        %% comment block
    elseif (strcmp (block__(1:1), '%'))
        istest__ = 0;
        code__ = ''; % skip the code

    else
        %% unknown block
        istest__ = 1;
        success__ = 0;
        msg__ = sprintf ('%sunknown test type!\n', signal_fail__);
        code__ = ''; % skip the code
    end

    %% evaluate code for test, shared, and assert.
    if (~isempty(code__))
        try
            % In MATLAB, one cannot create a function using eval, so we
            % have to create a function for the test.
            clear test_run_temp;
            fid_m__ = fopen('test_run_temp.m', 'w');
            fprintf (fid_m__, 'function %stest_run_temp(%s)\n%s\nend', shared_r__, shared__, code__);
            fclose(fid_m__); rehash;
        catch err
            if (isempty (err.message))
                error ('empty error text, probably Ctrl-C --- aborting');
            else
                rethrow(err);
            end
        end
        try
            eval (sprintf ('%stest_run_temp(%s);', shared_r__, shared__));
        catch e
            msg__ = [e.message newline];
            success__ = 0;
        end
        delete test_run_temp.m;
    end

    %% All done.  Remember if we were successful and print any messages
    if (~isempty (msg__))
        %% make sure the user knows what caused the error
        if (~verbose__)
            fprintf (fid__, '%s%s\n', signal_block__, block__);
        end
        fprintf (fid__ + (fid__ == 1), msg__);
    end
    if (success__ == 0)
        all_success__ = 0;
        %% stop after one error if not in batch mode
        if (~batch__)
            if (nargout > 0)
                ret1__ = 0; ret2__ = 0;
            end
            if (close_fid__)
                fclose(fid__);
            end
            return;
        end
    end
    tests__ = tests__ + istest__;
    successes__ = successes__ + success__ * istest__;
end
eval (clear__, ''); %#ok<*EV2IN>

if (nargout == 0)
    if (xfail__)
        fprintf(fid__, 'PASSES %d out of %d tests (%d expected failures)\n', ...
            successes__, tests__, xfail__); %#ok<UNRCH>
    else
        fprintf(fid__, 'PASSES %d out of %d tests\n', successes__, tests__);
    end
    if (xskip__)
        fprintf (fid__, 'Skipped %d tests due to missing features\n', xskip__);
    end
elseif (grabdemo__)
    ret1__ = demo_code__;
    ret2__ = demo_idx__;
elseif (nargout == 1)
    ret1__ = all_success__;
else
    ret1__ = successes__;
    ret2__ = tests__;
    ret3__ = xfail__;
    ret4__ = xskip__;
end
end

%% find [start,end] of fn in 'function [a,b] = fn'
function pos = function_name (def)
pos = [];

%% Find the end of the name
right = find (def == '(', 1);
if (isempty (right))
    return;
end
right = find (def(1:right - 1) ~= ' ', 1, 'last');

%% Find the beginning of the name
left = max ([find(def(1:right) == ' ', 1, 'last'), ...
    find(def(1:right) == '=', 1, 'last')]);
if (isempty (left))
    return;
end
left = left + 1;

%% Return the end points of the name
pos = [left, right];
end

%% strip <pattern> from '<pattern> code'
function [pattern, rest] = getpattern (str)
pattern = '.';
rest = str;
str = trimleft (str);
if (~isempty (str) && str(1) == '<')
    close = strfind (str, '>');
    if ~isempty(close)
        pattern = str(2:close(1) - 1);
        rest = str(close(1) + 1:end);
    end
end
end

%% strip '.*prefix:' from '.*prefix: msg\n' and strip trailing blanks
function msg = trimerr (msg, prefix)
idx = strfind (msg, strcat (prefix, ':'));
if ~isempty(idx)
    msg(1:idx(1) + length(prefix)) = [];
end
msg = trimleft (deblank (msg));
end

%% strip leading blanks from string
function str = trimleft (str)
idx = find (isspace (str));
leading = find (idx == 1:length(idx));
if (~isempty (leading))
    str = str(leading(end) + 1:end);
end
end

function body = extract_test_code (nm)
fid = fopen (nm, 'rt');
body = [];
if (fid >= 0)
    while (~feof (fid))
        ln = strtrim(fgetl (fid));
        if (length (ln) >= 2 && strcmp (ln(1:2), '%!'))
            body = sprintf('%s\n%s', char(body), ln(3:end));
        end
    end
    fclose (fid);
end
end

%% Test for a known failure
%!xtest error('This test is known to fail\n')

%%% example from toeplitz
%!shared msg
%!test  assert (isequal(toeplitz ([1,2,3], [1,4]), [1,4; 2,1; 3,2]));
%!demo  toeplitz ([1,2,3,4],[1,5,6])

%%% example from kron
%!%error kron  % FIXME suppress these until we can handle output
%!%error kron(1,2,3)
%!test assert (isempty (kron ([], rand(3, 4))))
%!test assert (isempty (kron (rand (3, 4), [])))
%!test assert (isempty (kron ([], [])))
%!shared A, B
%!test
%! A = [1, 2, 3; 4, 5, 6];
%! B = [1, -1; 2, -2];
%!assert (isequal(kron (pi, A), pi*A))
%!assert (isequal(kron ([1, 2, 3], A), [ A, 2*A, 3*A ]))
%!assert (isequal(kron ([1; 2; 3], A), [ A; 2*A; 3*A ]))
%!assert (isequal(kron ([1, 2; 3, 4], A), [ A, 2*A; 3*A, 4*A ]))
%!test
%! res = [1,-1,2,-2,3,-3; 2,-2,4,-4,6,-6; 4,-4,5,-5,6,-6; 8,-8,10,-10,12,-12];
%! assert (isequal(kron (A, B), res))

%%% an extended demo from specgram
%!%demo
%! %% Speech spectrogram
%! [x, Fs] = auload(file_in_loadpath('sample.wav')); % audio file
%! step = fix(5*Fs/1000);     % one spectral slice every 5 ms
%! window = fix(40*Fs/1000);  % 40 ms data window
%! fftn = 2^nextpow2(window); % next highest power of 2
%! [S, f, t] = specgram(x, fftn, Fs, window, window-step);
%! S = abs(S(2:fftn*4000/Fs,:)); % magnitude in range 0<f<=4000 Hz.
%! S = S/max(max(S));         % normalize magnitude so that max is 0 dB.
%! S = max(S, 10^(-40/10));   % clip below -40 dB.
%! S = min(S, 10^(-3/10));    % clip above -3 dB.
%! imagesc(flipud(20*log10(S)), 1);
%! % you should now see a spectrogram in the image window

%%% now test test itself

%!%% usage and error testing
% !fail ('test','usage.*test')           % no args, generates usage()
% !fail ('test(1,2,3,4)','usage.*test')  % too many args, generates usage()
%!fail ('test('test', 'bogus')','unknown flag')      % incorrect args
%!fail ('garbage','garbage.*undefined')  % usage on nonexistent function should be
