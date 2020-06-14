package cmex;

############################ MATLAB Control parameters ######################
$outdir = '.';   # Default directory for the other files that
                 # we have to create.

$language = ::language();

#
# Various typemaps:
#

#
# Get the value of an argument which is guaranteed to be a scalar, and put
# it into a C variable.
#
# All functions in this hash are called with three arguments:
# 1) The $function_def{args}{$argname} associative array.
#    The C variable the value is stored in is $args->{c_var_name}.
# 2) The name of the argument.
# 3) The type of the argument.
#
$typemap_get_scalar{'double'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_double($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'float'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    $arg->{c_var_name} = _get_numeric_scalar_float($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'long long'} = $typemap_get_scalar{'int64_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_int64($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'unsigned long long'} = $typemap_get_scalar{'uint64_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_uint64($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'long'} = $typemap_get_scalar{'ptrdiff_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    if (sizeof($arg->{basic_type})==8)\n"
    ."        $arg->{c_var_name} = _get_numeric_scalar_int64($arg->{mat_expr_in});\n"
    ."    else\n"
    ."        $arg->{c_var_name} = _get_numeric_scalar_int32($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'unsigned long'} = $typemap_get_scalar{'size_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    if (sizeof($arg->{basic_type})==8)\n"
    ."        $arg->{c_var_name} = _get_numeric_scalar_uint64($arg->{mat_expr_in});\n"
    ."    else\n"
    ."        $arg->{c_var_name} = _get_numeric_scalar_uint32($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'int'} = $typemap_get_scalar{'int32_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    $arg->{c_var_name} = _get_numeric_scalar_int32($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'unsigned int'} = $typemap_get_scalar{'unsigned'} =
    $typemap_get_scalar{'uint32_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_uint32($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'short'} = $typemap_get_scalar{'int16_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    $arg->{c_var_name} = _get_numeric_scalar_int16($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'unsigned short'} = $typemap_get_scalar{'uint16_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_uint16($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'int8_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ("    $arg->{c_var_name} = _get_numeric_scalar_int8($arg->{mat_expr_in});\n");
};

$typemap_get_scalar{'uint8_t'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    ( "    $arg->{c_var_name} = _get_numeric_scalar_uint8($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'char'} = $typemap_get_scalar{'unsigned char'} = sub {
    my ( $arg, $argname ) = @_;              # Name the arguments.

    (
"    if (!mxIsChar($arg->{mat_expr_in}) || mxGetNumberOfElements($arg->{mat_expr_in})<1)\n"
          . "        mexErrMsgTxt(\"Expecting string for argument $argname\");\n"
          . "    $arg->{c_var_name} = *(mxChar*)mxGetData($arg->{mat_expr_in});\n"
    );
};

$typemap_get_scalar{'char *'} = $typemap_get_scalar{'unsigned char *'} = sub {
    my ( $arg, $argname ) = @_;              # Name the arguments.
    ( $arg->{fstrlen} )
      ? "    $arg->{c_var_name} = _mxGetString($arg->{mat_expr_in}, & $arg->{fstrlen});\n"
      : "    $arg->{c_var_name} = _mxGetString($arg->{mat_expr_in}, NULL);\n";
};

#
# Get the value of a potentially vector argument and put it into a C variable.
# The dimensions are guaranteed to be proper.  Type checking should be done.
# All functions in this hash are called with three arguments:
# 1) The $function_def{args}{$argname} associative array.
#    The C variable the value is stored in is $args->{c_var_name}.
# 2) The name of the argument.
# 3) The type of the argument.
#

$typemap_get_ptr{'double'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    (       "    if ( mxIsDouble($arg->{mat_expr_in}) )\n"
          . "        $arg->{c_var_name} = (double*)mxGetData($arg->{mat_expr_in});\n"
          . "    else\n"
          . "        mexErrMsgTxt(\"Expecting double matrix for argument $argname\");\n");
  };

$typemap_get_ptr{'float'} =  sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    (       "    if (mxIsSingle($arg->{mat_expr_in}))\n"
          . "        $arg->{c_var_name} = (float*)mxGetData($arg->{mat_expr_in});\n"
          . "    else\n"
          . "        mexErrMsgTxt(\"Expecting single-precision float matrix for argument $argname\");\n");
  };

$typemap_get_ptr{'long long'} = $typemap_get_ptr{'unsigned long long'} =
  $typemap_get_ptr{'int'} = $typemap_get_ptr{'unsigned int'} = $typemap_get_ptr{'unsigned'} =
  $typemap_get_ptr{'short'} = $typemap_get_ptr{'unsigned short'} =
  $typemap_get_ptr{'int64_t'} = $typemap_get_ptr{'uint64_t'} =
  $typemap_get_ptr{'int32_t'} = $typemap_get_ptr{'uint32_t'} =
  $typemap_get_ptr{'int16_t'} = $typemap_get_ptr{'uint16_t'} =
  $typemap_get_ptr{'int8_t'} = $typemap_get_ptr{'uint8_t'} =

  # Must be an integer or an integer array.
  sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    my $ilen = (
        ( $argtype =~ /long$/ || $argtype =~ /int64/ ) ? '64'
        : ( ( $argtype =~ /short$/ || $argtype =~ /int16/ ) ? '16' :
            ( $argtype =~ /int8/ ? '8' : '32' ))
    );

    # Which Matlab subroutines to call to check
    # for 16 or 32 bit integers.
    ("    if (mxIsInt$ilen($arg->{mat_expr_in}) || mxIsUint$ilen($arg->{mat_expr_in}))\n"
          . "        $arg->{c_var_name} = ($arg->{basic_type}*)mxGetData($arg->{mat_expr_in});\n"
          . "    else\n"
          . "        mexErrMsgTxt(\"Expecting $ilen-bit integer matrix for argument $argname\");\n");
  };

$typemap_get_ptr{'long'} = $typemap_get_ptr{'unsigned long'} =
    $typemap_get_ptr{'ptrdiff_t'} = $typemap_get_ptr{'size_t'} =

  # Must be long or unsigned long.
  sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    (       "    if (sizeof($arg->{basic_type})==8) {\n"
          . "        if (mxIsInt64($arg->{mat_expr_in}) || mxIsUint64($arg->{mat_expr_in}))\n"
          . "            $arg->{c_var_name} = ($arg->{basic_type}*)mxGetData($arg->{mat_expr_in});\n"
          . "        else\n"
          . "            mexErrMsgTxt(\"Expecting 64-bit integer matrix for argument $argname\");\n"
          . "    }\n"
          . "    else {\n"
          . "        if (mxIsInt32($arg->{mat_expr_in}) || mxIsUint32($arg->{mat_expr_in}))\n"
          . "            $arg->{c_var_name} = ($arg->{basic_type}*)mxGetData($arg->{mat_expr_in});\n"
          . "        else\n"
          . "            mexErrMsgTxt(\"Expecting 32-bit integer matrix for argument $argname\");\n"
          . "    }\n" );
  };

$typemap_get_ptr{'char *'} = sub {
    die("$::progname: arrays of strings are not yet supported\n");
};    # Arrays of strings are not yet supported.

$typemap_get_ptr{'char'} = $typemap_get_ptr{'unsigned char'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    $arg->{fstrlen}
      ? "    $arg->{c_var_name} = _mxGetString($arg->{mat_expr_in}, &$arg->{fstrlen});\n"
      : "    $arg->{c_var_name} = _mxGetString($arg->{mat_expr_in}, NULL);\n";
};

#
# Free temporary space allocated for C variable.
#

$typemap_free_ptr{'double'} = sub {
    my ( $arg, $argname ) = @_;              # Name the arguments.
    ("    if (!mxIsDouble($arg->{mat_expr_in})) mxFree($arg->{c_var_name});\n");
};

$typemap_free_ptr{'float'} = sub {
    my ( $arg, $argname ) = @_;              # Name the arguments.
    ("    if (!mxIsSingle($arg->{mat_expr_in})) mxFree($arg->{c_var_name});\n");
};

$typemap_free_ptr{'long long'} = $typemap_free_ptr{'unsigned long long'} =
  $typemap_free_ptr{'int'} = $typemap_free_ptr{'unsigned int'} = $typemap_free_ptr{'unsigned'} =
  $typemap_free_ptr{'short'} = $typemap_free_ptr{'unsigned short'} =
  $typemap_free_ptr{'int64_t'} = $typemap_free_ptr{'uint64_t'} =
  $typemap_free_ptr{'int32_t'} = $typemap_free_ptr{'uint32_t'} =
  $typemap_free_ptr{'int16_t'} = $typemap_free_ptr{'uint16_t'} =
  $typemap_free_ptr{'int8_t'}  = $typemap_free_ptr{'uint8_t'} =

  # Must be an integer or an integer array.
  sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    my $ilen = (
        ( $argtype =~ /long$/ || $argtype =~ /int64/ ) ? '64'
        : ( ( $argtype =~ /short$/ || $argtype =~ /int16/ ) ? '16' :
            ( $argtype =~ /int8/ ? '8' : '32' ))
    );

    # Which Matlab subroutines to call to check
    # for 16 or 32 bit integers.
    (
"    if (!mxIsInt$ilen($arg->{mat_expr_in}) && !mxIsUint$ilen($arg->{mat_expr_in}))\n"
          . "        mxFree($arg->{c_var_name});\n" );
  };

$typemap_free_ptr{'long'} = $typemap_free_ptr{'unsigned long'} =
    $typemap_free_ptr{'ptrdiff_t'} = $typemap_free_ptr{'size_t'} =

  # Must be long or unsigned long.
  sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    (       "    if (sizeof($arg->{basic_type})==8) {\n"
          . "        if (!mxIsInt64($arg->{mat_expr_in}) && !mxIsUint64($arg->{mat_expr_in}))\n"
          . "            mxFree($arg->{c_var_name});\n"
          . "    } else {\n"
          . "        if (!mxIsInt32($arg->{mat_expr_in}) && !mxIsUint32($arg->{mat_expr_in}))\n"
          . "            mxFree($arg->{c_var_name});\n"
          . "    }\n" );
  };

$typemap_free_ptr{'char'} = $typemap_free_ptr{'unsigned char'} = sub {
    my ( $arg, $argname, $argtype ) = @_;    # Name the arguments.
    "    _mxFreeString($arg->{c_var_name});\n";
};

$typemap_output_array_make{'char'} =
  $typemap_output_array_make{'unsigned char'} = sub {
    my ( $arg, $argname, $n_dims, $c_dim_arr ) = @_;    # Name the arguments.

    (
"    $arg->{mat_expr_in} = mxCreateCharArray(MAX_ARG2($n_dims, 2), $c_dim_arr);\n"
          .

          # Make the array.
"    $arg->{c_var_name} = ($arg->{basic_type} *)mxCalloc(mxGetNumberOfElements($arg->{mat_expr_in}), sizeof ($arg->{basic_type}));\n"
    );

    # Allocate temporary space for the string.
    # Matlab stores strings as uint16 characters,
    # which is definitely not what we want to use.
  };

#
# Create a scalar value for output.  Arguments:
# 1) The associative array describing the argument.
# 2) A C expression for the argument.
#
$typemap_output_scalar_make{'double'} = $typemap_output_scalar_make{'float'} =
  $typemap_output_scalar_make{'long long'} = $typemap_output_scalar_make{'unsigned long long'} =
  $typemap_output_scalar_make{'int'} = $typemap_output_scalar_make{'unsigned'} =
  $typemap_output_scalar_make{'short'} = $typemap_output_scalar_make{'unsigned short'} =
  $typemap_output_scalar_make{'int64_t'} = $typemap_output_scalar_make{'uint64_t'} =
  $typemap_output_scalar_make{'int32_t'} = $typemap_output_scalar_make{'uint32_t'} =
  $typemap_output_scalar_make{'int16_t'} = $typemap_output_scalar_make{'uint16_t'} =
  $typemap_output_scalar_make{'int8_t'}  = $typemap_output_scalar_make{'uint8_t'} =
  sub {
    "    $_[1] = mxCreateNumericMatrix(1, 1, mx"
    . uc( matlab_typename( $_[0]->{basic_type} ) )
    . "_CLASS, mxREAL);\n";    # Create the matrix for output.
  };

$typemap_output_scalar_make{'ptrdiff_t'} =
  sub {
      "    $_[1] = mxCreateNumericMatrix(1, 1, sizeof(ptrdiff_t)==8?mxINT64_CLASS:mxINT32_CLASS, mxREAL);\n";    # Create the matrix for output.
  };

$typemap_output_scalar_make{'size_t'} =
  sub {
      "    $_[1] = mxCreateNumericMatrix(1, 1, sizeof(size_t)==8?mxINT64_CLASS:mxINT32_CLASS, mxREAL);\n";    # Create the matrix for output.
  };

$typemap_output_scalar_make{'long'} =
  sub {
      "    $_[1] = mxCreateNumericMatrix(1, 1, sizeof(long)==8?mxINT64_CLASS:mxINT32_CLASS, mxREAL);\n";    # Create the matrix for output.
  };

$typemap_output_scalar_make{'unsigned long'} =
  sub {
      "    $_[1] = mxCreateNumericMatrix(1, 1, sizeof(long)==8?mxUINT64_CLASS:mxUINT32_CLASS, mxREAL);\n";    # Create the matrix for output.
  };

$typemap_output_scalar_make{'char'} = sub {
    if ( !defined($output_scalar_dimensions) ) {    # Did we output the scalar
                                                    # dimension constants?
        print OUTFILE "
static mwSize scalar_dimensions[] = {1,1}; // A value to pass to give the
                                // dimensions of a scalar.

";

        # Output with print so it goes before the
        # function we are wrapping.
        $output_scalar_dimensions = 1;              # Don't output it again.
    }

    "    $_[1] = mxCreateCharArray(1, scalar_dimensions);\n";
};

$typemap_output_scalar_make{'char *'} = sub { ''; };

# Nothing to do for string scalars.

#
# Set the value of an output argument which is guaranteed to be a
# scalar.  All functions in this hash are called with three arguments:
# 1) The $function_def{args}{$argname} associative array.
# 2) A C expression for the argument.
#
$typemap_put_scalar{'double'}  = $typemap_put_scalar{'float'} =
  $typemap_put_scalar{'long long'} = $typemap_put_scalar{'unsigned long long'} =
  $typemap_put_scalar{'long'} = $typemap_put_scalar{'unsigned long'} =
  $typemap_put_scalar{'int'}   = $typemap_put_scalar{'unsigned'} =
  $typemap_put_scalar{'short'} = $typemap_put_scalar{'unsigned short'} =
  $typemap_put_scalar{'ptrdiff_t'} = $typemap_put_scalar{'size_t'} =
  $typemap_put_scalar{'int64_t'} = $typemap_put_scalar{'uint64_t'} =
  $typemap_put_scalar{'int32_t'} = $typemap_put_scalar{'uint32_t'} =
  $typemap_put_scalar{'int16_t'} = $typemap_put_scalar{'uint16_t'} =
  $typemap_put_scalar{'int8_t'}  = $typemap_put_scalar{'uint8_t'} =
  sub {
    my ( $arg, $matexpr ) = @_;    # Name the arguments.
    "    *($arg->{basic_type}*)mxGetData($matexpr) = $arg->{c_var_name};\n";
  };

$typemap_put_scalar{'char'} = sub {
    my ( $arg, $mat_expr_in ) = @_;    # Name the arguments.
    "    *(mxChar *)mxGetData($mat_expr_in) = $arg->{c_var_name};\n";
};

$typemap_put_scalar{'char *'} = sub {
    my ( $arg, $mat_expr_in ) = @_;    # Name the arguments.
    "    $mat_expr_in = mxCreateString($arg->{c_var_name});\n";
};

#
# Set the value of an output argument which may be an array.
# The type and dimensions are guaranteed to be proper.
#

$typemap_put_ptr{'char'} = $typemap_put_ptr{'unsigned char'} = sub {
    my ($arg) = @_;                 # Name the arguments.
    "    $arg->{mat_expr_out} = mxCreateString($arg->{c_var_name});\n" .
    "    _mxFreeString($arg->{c_var_name});\n";
};

############################ MATLAB Wrapper functions ##################
#
# arg_pass(\%function_def, $argname)
#
# A C expression used to pass the argument to another function
# which does not know anything about the type of the argument.  For
# example, in the MATLAB module this function returns an expression for
# the mxArray type for a given argument.
#
sub arg_pass {
    my ( $faa, $argname ) = @_;          # Name the arguments.
    $faa->{args}{$argname}{mat_expr_in};    # Return the MATLAB expression.
}

#
# arg_declare("arg_name_in_arglist")
#
# This returns a C declaration appropriate for the argument passed
# using arg_pass.  For example, in the MATLAB module this function returns
# "mxArray *arg_name_in_arglist".
#
sub arg_declare {
    "const mxArray *$_[0]";
}

#
# error_dimension(\%function_def, $argname)
#
# A C statement (including the final semicolon, if not surrounded by braces)
# which indicates that an error has occurred because the dimension of argument
# $argname was wrong.
#
sub error_dimension {
    my ( $faa, $argname ) = @_;    # Name the arguments.
    "mexErrMsgTxt(\"Error in dimension of argument $argname\");";
}

#
# finish()
#
# Called after all functions have been wrapped, to close the output file and do
# whatever other cleanup is necessary.
#
# For MATLAB, we now have to dispatch to the appropriate wrapper function
# that we have created.
#
sub finish {
    my ($ccode) = @_;    # Name the arguments.

    print OUTFILE $ccode;    # Print out the C routines.

    close(OUTFILE);          # Done with this file.
}

#
# Generate a MEX gateway function for different cases
#
sub switch_gateway {
    my ($function_names) = @_;    # Extract function name

    my $ccode = "/* Main gateway function */
EXTERN_C void mexFunction(int nlhs, mxArray *plhs\[\],\n    int nrhs, const mxArray *prhs\[\]) {

    typedef void (*C2mex_func_ptr)(int nlhs, mxArray *plhs\[\],\n    int nrhs, const mxArray *prhs\[\]);

    int  func_id;
    static C2mex_func_ptr  fptrs[] = {
        NULL";

    my $count = 0;
    foreach (@$function_names) {
        ++$count;
        $ccode .= ",\n        /* $count */ ${_}_MeX";
    }

    $ccode .= "
    };

    /******** Check function selector argument. ********/
    if (nrhs < 1 || !mxIsInt32(prhs[0]) || mxGetNumberOfElements(prhs[0])!=1)
        mexErrMsgTxt(\"Invalid functiin selector.\\n\");

    func_id = *(int*)mxGetData(prhs[0]);

    if (func_id < 1 || func_id > $count)
        mexErrMsgTxt(\"Function selector is out of bound.\\n\");

    /******** Invoke the function. ********/
    (*fptrs[func_id])(nlhs, plhs, nrhs-1, &prhs[1]);
}
";
}

#
# Begin the definition of a function.  Arguments:
# 1) The %function_def array.
#
sub function_start {
    my ($faa) = @_;    # Access the argument.

    # Compute the name from MATLAB.
    my $fname = $faa->{script_name} || $faa->{name};

    # Associate each argument to the function with an index:
    #
    my $argno = 0;    # Start numbering input/inout arguments at 0.

    foreach ( @{ $faa->{inputs} }, @{ $faa->{inouts} } ) {
        my $arg = $faa->{args}{$_};    # Point to the argument array.
        $arg->{mat_expr_in} = "prhs[" . $argno++ . "]";
    }

    $argno = 0;    # Output arguments are numbered starting at 0.
    foreach ( @{ $faa->{iostrs} }, @{ $faa->{outputs} } ) {
        my $arg = $faa->{args}{$_};    # Point to the argument array.
        $arg->{mat_expr_out} = "plhs[" . $argno++ . "]";
    }

    my $outargs =
      join( ", ",
        map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{iostrs} } ),
        map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{outputs} } ) );

    # If there's more than one, put it in brackets.
    ( @{ $faa->{outputs} } + @{ $faa->{iostrs} } )> 1 and $outargs = "[$outargs]";

    $outargs ne '' and $outargs .= " = ";    # Add an equals sign too.

    my @inargs = map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{inputs} },
        @{ $faa->{inouts} } );
    my $inargs = join( ", ", @inargs );

    # Format the input arguments.
    my $plhs = ( @{ $faa->{iostrs} } + @{ $faa->{outputs} } ? 'plhs' : '' );
    my $prhs = (
        @{ $faa->{inputs} } + @{ $faa->{inouts} }
        ? 'prhs'
        : ''
    );

    my $prototype = ::get_prototype($faa);
    $prototype =~ s/^/ \* /mg;

    my $funcname = $::mergefiles ? ( $fname . "_MeX" ) : "mexFunction";

    my $notestr =
      ( $::mergefiles || @{ $faa->{inouts} } == 0 )
      ? ""
      : " * NOTE: This function should be called through the M-file gateway function.\n *\n";

    ( "/* Gateway function\n * $outargs$fname($inargs)\n *\n"
      . $notestr
      . ( ( $language eq "C" )
          ? " * The original $language interface is\n$prototype\n"
          : "" )
      . " */\n"
      . "EXTERN_C void $funcname(int nlhs, mxArray *plhs\[\],\n    int nrhs, const mxArray *prhs\[\]) {\n"
    );
}

#
# Print out checking of number of arguments.  Arguments:
# 1) The %function_def array.
#
sub function_argchk {
    my ($faa) = @_;    # Access the argument.

    my $fname = $faa->{script_name};

    "    /******** Check number of input and output arguments. ********/\n"
      . (
        ( @{ $faa->{outputs} } + @{ $faa->{iostrs} } ) == 1
        ? "    if (nlhs > 1 || "
        : "    if (nlhs > " . (@{ $faa->{outputs} } + @{ $faa->{iostrs} }) . " || "
      )
      . "nrhs != "
      . ( @{ $faa->{inputs} } + @{ $faa->{inouts} } ) . ")\n"
      . "        mexErrMsgTxt(\"Wrong number of arguments to function $fname\");\n\n";
}

#
# function_end(\%function_def)
#
# Return a string which finishes off the definition of a wrapper.
#
sub function_end {
    "}\n\n";    # Close off the opening brace.
}

#
# get_c_arg_scalar(\%function_def, $argname)
#
# Returns C statements to load the current value of the given argument
# into the C variable C<$function_def{args}{$argname}{c_var_name}>.  The
# variable is guaranteed to be either a scalar or an array with dimensions
# 1,1,1....
#
sub get_c_arg_scalar {
    my ( $faa, $argname ) = @_;    # Name the arguments.

    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.

    if ( exists( $typemap_get_scalar{$argtype} ) )
    {                                  # Do we understand this type?
        return &{ $typemap_get_scalar{$argtype} }( $arg, $argname, $argtype )
          ;                            # Do the conversion.
    } elsif ( $argtype eq "void *" ) {  # Is this a pointer we don't understand?
         #    "  /*Extracting data as void * and pass it to computational routine.*/\n" .
         #    "  /*It is user's responsibility to make sure compatibility of data types.*/\n" .
        return ("    $arg->{c_var_name} = mxGetData($arg->{mat_expr_in});");
    } else {    # Unrecognized type?
        die("$::progname: don't understand type '$argtype'.\n");
    }
}

#
# get_c_arg_ptr(\%function_def, $argname)
#
# Returns C statements to set up a pointer which points to the first
# value in the given argument.  The dimensions are guaranteed to be
# correct.  The type of the argument should be checked.  The pointer
# value should be stored in the variable
# $function_def{args}{$argname}{c_var_name}.
#
# The pointer should actually point to the array of all the values of
# the variable.  If we want a float type and the input vector is double
# or int, then a temporary array must be made which is a copy of the
# double/int arrays.
#
sub get_c_arg_ptr {
    my ( $faa, $argname ) = @_;    # Name the arguments.

    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.

    if ( exists( $typemap_get_ptr{$argtype} ) ) {  # Do we understand this type?
        return &{ $typemap_get_ptr{$argtype} }( $arg, $argname, $argtype )
          ;                                        # Do the conversion.
    } elsif ( $argtype eq "void *" ) {  # Is this a pointer we don't understand?
        return ("    $arg->{c_var_name} = mxGetData($arg->{mat_expr_in});");

#"  /*Extracting data as void * and pass it to computational routine.*/\n" .
#"  /*It is user's responsibility to make sure compatibility of data types.*/\n" .

    } else {                            # Unrecognized type?
        die("$::progname: don't understand type '$argtype' as scalar/matrix\n");
    }
}

#
# free_c_arg_ptr(\%function_def, $argname)
#
# Returns C statements to free a pointer allocated using mxCalloc.
#
sub free_c_arg_ptr {
    my ( $faa, $argname ) = @_;         # Name the arguments.

    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.

    if ( exists( $typemap_free_ptr{$argtype} ) ) { # Do we understand this type?
        return &{ $typemap_free_ptr{$argtype} }( $arg, $argname, $argtype )
          ;                                        # Do the conversion.
    }
}

#
# get_size(\%function_def, $argname, $n)
#
# Returns a C expression which is the size of the nth dimension of the given
# argument.  Dimension 0 is the least-significant dimension.
#
sub get_size {
    my ( $faa, $argname, $index ) = @_;            # Name the arguments.

    my $arg = $faa->{args}{$argname};

    "_dim($arg->{mat_expr_in}, $index)";
}

#
# Initialize the output file.  Arguments:
# 1) The name of the output file.
# 2) A reference to a list of input files explicitly listed.
# 3) A reference to the words passed to the C preprocessor.
# 4) A string that represents our guess as to the #includes which are
#    required.
#
sub initialize {
    my ( $arg_outfile, $infiles, $cpp_cmd, $include_str ) =
      @_;    # Name the arguments.

    open( OUTFILE, "> $arg_outfile" )
      || die("$::progname : can't open output file $arg_outfile--$!\n");

    print OUTFILE "/*
 * This file was automatically generated for MATLAB & Octave from
 * @{[@$infiles, @$cpp_cmd]} using Xiangmin Jiao's $::progname.
 * For bug reports of $::progname, email jiao\@ams.sunysb.edu.
 */

#include \"c2mex.h\"   /* This includes \"mex.h\". */

$include_str

#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
  #define EXTERN_C extern \"C\"
#else
  #define EXTERN_C
#endif

#ifdef EXTERN
#undef EXTERN
#endif

#ifdef __cplusplus
  #define EXTERN extern \"C\"
#else
  #define EXTERN extern
#endif

";
}

#
# Convert basic_type into Matlab typename.
#
sub matlab_typename {
    my ($typename) = @_;    # Access the argument.

    if ( $typename eq 'double' ) {
        'double';
    } elsif ( $typename eq 'float' ) {
        'single';
    } elsif ( $typename eq 'long long' || $typename eq 'int64_t' ) {
        'int64';
    } elsif ( $typename eq 'unsigned long long' || $typename eq 'uint64_t' ) {
        'uint64';
    } elsif ( $typename eq 'long' ) {
        'long';
    } elsif ( $typename eq 'unsigned long' ) {
        'ulong';
    } elsif ( $typename eq 'ptrdiff_t' ) {
        'ptrdiff_t';
    } elsif ( $typename eq 'size_t' ) {
        'size_t';
    } elsif ( $typename eq 'int' || $typename eq 'int32_t' ) {
        'int32';
    } elsif ( $typename eq 'unsigneed int' || $typename eq 'unsigneed' || $typename eq 'uint32_t' ) {
        'uint32';
    } elsif ( $typename eq 'short' || $typename eq 'int16_t' ) {
        'int16';
    } elsif ( $typename eq 'unsigned short' || $typename eq 'uint16_t' ) {
        'uint16';
    } elsif ( $typename eq 'int8_t' ) {
        'int8';
    } elsif ( $typename eq 'uint8_t' ) {
        'uint8';
    } elsif ( $typename eq 'char' ) {
        'char';
    } elsif ( $typename eq 'unsigned char' ) {
        'char';
    } elsif ( $typename eq 'char *' ) {
        'char';
    } elsif ( $typename eq 'void *' ) {
        'numeric';
    } elsif ( $typename =~ '.*\*' ) {
'ulong (uint32 on 32-bit and uint64 on 64-bit machines. Equivalent to a pointer.)';
    } else {
        'unknown';
    }
}

#
# Convert basic_type into longer descriptive names for Matlab types.
#
sub matlab_long_typename {
    my ($typename) = @_;    # Access the argument.

    if ( $typename eq 'double' ) {
        'double-precision (double)';
    } elsif ( $typename eq 'float' ) {
        'single-precision (single)';
    } elsif ( $typename eq 'long long' || $typename eq 'int64_t' ) {
        '64-bit integer (int64)';
    } elsif ( $typename eq 'unsigned long long' || $typename eq 'uint64_t' ) {
        '64-bit unsigned integer (uint64)';
    } elsif ( $typename eq 'ptrdiff_t' or $typename eq 'long' ) {
        '64-bit or 32-bit integer (platform dependent)';
    } elsif ( $typename eq 'size_t' or $typename eq 'unsigned long' ) {
        '64-bit or 32-bit unsigned integer (platform dependent)';
    } elsif ( $typename eq 'int' || $typename eq 'int32_t' ) {
        '32-bit integer (int32)';
    } elsif ( $typename eq 'unsigned int' || $typename eq 'unsigned' || $typename eq 'uint32_t' ) {
        '32-bit unsigned integer (uint32)';
    } elsif ( $typename eq 'short' || $typename eq 'int16_t' ) {
        '16-bit unsigned integer (int16)';
    } elsif ( $typename eq 'unsigned short' || $typename eq 'uint16_t' ) {
        '16-bit unsigned integer (uint16)';
    } elsif ( $typename eq 'int8_t' ) {
        '8-bit unsigned integer (int8)';
    } elsif ( $typename eq 'uint8_t' ) {
        '8-bit unsigned integer (uint8)';
    } elsif ( $typename eq 'char' ) {
        'character string (char)';
    } elsif ( $typename eq 'unsigned char' ) {
        'character string (char)';
    } elsif ( $typename eq 'char *' ) {
        'character string (char)';
    } elsif ( $typename eq 'void *' ) {
        'generic numeric';
    } elsif ( $typename =~ '.*\*' ) {
        'unsigned long (Equivalent to a pointer.)';
    } else {
        'unsupported type';
    }
}

#
# Create nice matlab variable description.
#
sub matlab_argtype_description {
    my ($arg) = @_;    # Access the argument.

    if ( defined $arg->{cast} ) {
        "dynamic type based on $arg->{rawcast}";
    } elsif ( $arg->{basic_type} eq 'char' && $arg->{source} eq 'inout' ) {
        "character string"
          . (
            ( $arg->{dimension}[0] ne "(:)" )
            ? (
                " with default length "
                  . (
                    defined( $arg->{rawdimension} )
                    ? $arg->{rawdimension}
                    : $arg->{dimension}[0]
                  )
              )
            : ( $::default_strlen > 0
                ? " with default length $::default_strlen"
                : "" )
          );
    } elsif ( $arg->{basic_type} eq 'char' ) {
        'character string';
    } elsif ( $arg->{basic_type} eq 'void *' ) {
        'numeric array'
          . (
            ( $arg->{type} =~ /.*const *.*/ )
            ? ""
            : " (passed by reference)"
          );
    } elsif ( @{ $arg->{dimension} } == 0 ) {
        matlab_long_typename( $arg->{basic_type} ) . ", scalar";
    } elsif ( $arg->{dimension}[0] eq "(:)" ) {
        matlab_long_typename( $arg->{basic_type} ) . ", array";
    } elsif ( @{ $arg->{dimension} } == 1 ) {
        matlab_long_typename( $arg->{basic_type} )
          . ", len="
          . (
            defined( $arg->{rawdimension} )
            ? $arg->{rawdimension}
            : $arg->{dimension}[0] );
    } else {
        matlab_long_typename( $arg->{basic_type} )
          . "size=("
          . join( ", ", @{ $arg->{dimension} } ) . ")";
    }
}

#
# make_output_scalar(\%function_def, $argname)
#
#   Return C code to create the given output variable, which is guaranteed
#   to be a scalar.
#
sub make_output_scalar {
    my ( $faa, $argname ) = @_;
    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.

    if ( exists( $typemap_output_scalar_make{$argtype} ) )
    {                                  # Do we understand this type?
        return &{ $typemap_output_scalar_make{$argtype} }( $arg,
            $arg->{mat_expr_out} );

        # Do the conversion.
    } elsif ( $argtype =~ /\*$/ ) {    # Is this a pointer we don't understand?
        return
            "    $arg->{mat_expr_out} = mxCreateNumericMatrix(1, 1, mx"
            . uc( matlab_typename( $arg->{basic_type} ) )
            . "_CLASS, mxREAL);\n";
    } else {                           # Unrecognized type?
        die("$::progname: don't understand scalar output type '$argtype'\n");
    }
}

#
#  make_output_ptr(\%function_def, $argname, $n_dimensions, @dimensions)
#
# Return C code to set up the given output variable.  $n_dimensions is a C
# expression, not a constant.  @dimensions is a list of C expressions that are
# the sizes of each dimension.  There may be more values in @dimensions than
# are wanted.
#
sub make_output_ptr {
    my ( $faa, $argname, $n_dims, @dims ) = @_;

    my $arg  = $faa->{args}{$argname};    # Access the argument info.
    my $type = $arg->{basic_type};        # Access the type.

    my $retstr = '';

    #
    # Now make an argument of the appropriate type:
    #
    if ( $type eq "char" ) {
        $retstr .=
          "    $arg->{mat_expr_out} = mxCreateString($arg->{c_var_name});\n";
    } elsif ( $type =~ /\*$/ ) {          # Some random pointer type?
        $retstr .=
          (     "    $arg->{mat_expr_out} = mxCreateNumericMatrix(1,1,"
              . "(sizeof(void*)==8)?mxUINT64_CLASS:mxUINT32_CLASS, mxREAL);\n"
          );
    } elsif ( $arg->{dimension} > 1 ) {
        my $len = (
            defined( $arg->{rawdimension} )
            ? $arg->{rawdimension}
            : $arg->{dimension}[0] );
        $retstr .=
          (     "    $arg->{mat_expr_out} = mxCreateNumericMatrix($len,1,"
              . "mx" . uc( matlab_typename( $arg->{basic_type} ) ) . "_CLASS, mxREAL);\n"
              . "    $arg->{c_var_name} = mxGetData($arg->{mat_expr_out});\n"
          );
    } else {
        die("$::progname: can't handle scalar/matrix output of type '$type'\n");
    }

    $retstr;
}

#
# n_dimensions(\%function_def, $argname)
#
# Returns a C expression which is the number of dimensions of the argument
# whose name is $argname.
#
sub n_dimensions {
    my ( $faa, $argname ) = @_;    # Name the arguments.

    my $arg = $faa->{args}{$argname};
    if ( $arg->{basic_type} eq 'char *' ) {
        '0';                       # Strings are treated as atomic objects,
                                   # and we don't support arrays of strings.
    } else {
        "_n_dims($arg->{mat_expr_in})";
    }
}

#
# Parse the argument vector for language-specific options.  Arguments:
# 1) A reference to the argument vector.
# Any arguments we use should be removed from the argument vector.
#
sub parse_argv {
    my ($ARGV) = @_;               # Access the arguments.
    my $argidx;
    my $modname;
    my $overwrite;

    for ( $argidx = 0 ; $argidx < @$ARGV ; ++$argidx )
    {                              # Look at the arguments:
        if ( $ARGV->[$argidx] eq '-outdir' ) {    # Output directory specified?
            $outdir = $ARGV->[ $argidx + 1 ];     # Use the specification.
            splice( @$ARGV, $argidx, 2 )
              ;           # Remove these two elements from the array.
            $argidx--;    # Back up to account for the arg we removed.
        } elsif ( $ARGV->[$argidx] eq '-h' || $ARGV->[$argidx] eq '-help' ) {
            print STDOUT "
    $::progname [-h|-help] [-debug] [-outdir dir] srcfile1 [srcfile2 ...]\n"
              . ( ( $::progname eq "f2mex" )
                ? "    $::progname [-m|-module module] [-outdir dir]\n"
                : "" )
              . "
    -debug                 Print out debug information about functions and types
    -h or -help            Print this help message
    -outdir dir            Specify directory for output C and M-files
" . (
                ( $::progname eq "f2mex" )
                ? "    -m|-module module      generate template interface-declaration file with the given module name
    -overwrite             allow overwriting the interface-declaration file.
"
                : ""
            );
            exit;
        } elsif ( $ARGV->[$argidx] eq '-module' || $ARGV->[$argidx] eq '-m' ) {
            $modname = $ARGV->[ $argidx + 1 ];    # Use the specification.
            splice( @$ARGV, $argidx, 2 )
              ;           # Remove these two elements from the array.
            $argidx--;    # Back up to account for the arg we removed.
        } elsif ( $ARGV->[$argidx] eq '-overwrite' ) {
            $overwrite = 1;
        }
    }

    if ( defined($modname) && $::progname eq "f2mex" ) {
        ::print_template( $modname, $outdir, $overwrite );
        ::print_buildscript( $modname, $outdir, $overwrite );
        exit;
    }
    $outdir;
}

#
# put_val_scalar(\%function_def, $argname)
#
# Returns C code to take the value from the C variable whose name is given
# by $function_def{args}{$argname}{c_var_name} and store it back in the
# scripting language scalar variable.
#
sub put_val_scalar {
    my ( $faa, $argname ) = @_;
    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.

    if ( exists( $typemap_put_scalar{$argtype} ) )
    {                                  # Do we understand this type?
        return &{ $typemap_put_scalar{$argtype} }( $arg, $arg->{mat_expr_out} );
    }
    else {                           # Unrecognized type?
        die("$::progname: don't understand scalar output type '$argtype'\n");
    }
}

#
# put_val_ptr(\%function_def, $argname)
#
# Returns C code to take the value from the C array whose name is given by
# $function_def{args}{$argname}{c_var_name} and store it back in the scripting
# language array at the specified index.  The pointer
# $function_def{args}{$argname}{c_var_name} was set up by either get_c_arg or
# make_output, depending on whether this is an input/inout or an output
# variable.
#
sub put_val_ptr {
    my ( $faa, $argname ) = @_;

    my $arg = $faa->{args}{$argname};  # Access the definition of this argument.

    my $argtype = $arg->{basic_type};  # Get the basic type, without any frills.
    my $argdim  = $arg->{dimension};   # Point to the dimensions.

    if ( exists( $typemap_put_ptr{$argtype} ) ) {  # Do we understand this type?
        return &{ $typemap_put_ptr{$argtype} }($arg);    # Do the conversion.
    }
     else {                                             # Unrecognized type?
        die(
"$::progname: don't understand scalar/vector output type '$argtype'\n"
        );
    }
}

###############################################################################
#
# Wrap a function definition.  Arguments:
# 1) The %function_def array for this function.
#
sub wrap_function {
    my $faa = bless $_[0], cmex;   # Access the argument.
                                   # Bless it into the module so we
                                   # can access functions whose first argument
                                   # is this array using member function syntax.

    my $retstr;                    # Where we accumulate the C code.  We don't
                                   # output the C code immediately because
                                   # if the language module die()'s during
                                   # execution of this function, we want to
                                   # skip it and move to the next.
    my $args = $faa->{args};       # Argument definitions.
    my $arg;


    if ($faa->{external} && $::mergefiles) {
        my $funcname = $faa->{script_name} || $faa->{name};

        return "/* External gateway function */\n"
          . "EXTERN void ${funcname}_MeX(int nlhs, mxArray *plhs\[\],\n    int nrhs, const mxArray *prhs\[\]);\n\n";
    }

    eval {                         # Protect from die:
        $retstr = $faa->function_start();    # Begin the function declaration.

        foreach $argname (
            @{ $faa->{argnames} },           # Look at the arguments.
            ( $faa->{returns} eq 'void' ? () : ("__r_e_t__") )
          )
        {

            # Also include the return value here.
            # Declare space to hold argument values
            # and the return from the function, if there
            # is one.
            $arg = $faa->{args}{$argname};
            if ( @{ $arg->{dimension} } ) {    # Is it an array?
                my $type;
                if ( $arg->{type} ne "char **" ) {

                    if ( $arg->{basic_type} eq "char" && $arg->{source} eq "output" && $arg->{rawdimension} > 1) {
                        # For out character strings, use buffer
                        $retstr .= "    $arg->{basic_type} $arg->{c_var_name}\[$arg->{rawdimension}\];\n";
                    } else {
                        # For return type, we must preserve const modifier
                        $type = $arg->{type};
                        if ( $argname ne "__r_e_t__" ) {
                            $type =~ s/\bconst\b\s*//g;
                        }
                        $retstr .= "    $type $arg->{c_var_name};\n";
                    }
                } else {
                    $type = "$arg->{basic_type} *";
                    $retstr .= "    $type $arg->{c_var_name};\n";
                }

                # If len_var_name is defined, variable must be Fortran string
                if ( defined( $arg->{fstrlen} ) ) {
                    $retstr .= "    size_t $arg->{fstrlen};\n";
                }
            } else {
                if (   $arg->{source} eq "inout"
                    && $arg->{basic_type} ne "void *" )
                {
                    die(
"Error: $arg->{c_var_name} cannot be an INOUT argument.\n"
                    );
                }

                if ( $arg->{pass_by_pointer_reference} ) {
                    my $str = $arg->{type};
                    $str =~ s/^(.*?)\s*\*$/$1/g;
                    $retstr .= "    $str $arg->{c_var_name};\n";    # Scalar.
                } else {
                    $retstr .=
                      "    $arg->{type} $arg->{c_var_name};\n";     # Scalar.
                }
            }
        }

        $retstr .= "\n";
        $retstr .= $faa->function_argchk();    # Begin the function declaration.

        if ( @{ $faa->{inputs} } + @{ $faa->{inouts} } > 0 ) {
            $retstr .= "    /******** Obtain input and inout arguments ********/\n";
        }

        #
        # Calculate all of the dimensional arguments:
        #
        my ( %dims_calculated, %dimvar );
        foreach $arg ( grep( exists( $_->{calculate} ), values %$args ) ) {
            my $calc_str =
              "($arg->{calculate})";           # Put the string in parentheses.
            $calc_str =~ s{dim\((\w+), (\d+)\)}{
        $dims_calculated{$1, $2} = 1; # Remember that we got this dim.
        $dimvar{$1} = 1; # We handled this dimension.
        $faa->get_size($1, $2); # Replace dim(varname, n) with the appropriate
        }eg;    # C expression to get the dimension.

            $retstr .= "  $arg->{c_var_name} = $calc_str;\n";

            # Set the value of this dimensional variable.
        }

       #
       # Now calculate any other arguments which are used as dimensional indices
       # but we could not calculate from the given dimensions.
       #
        foreach $argname (
            grep( $args->{$_}{source} eq 'dimension' && !defined( $dimvar{$_} ),
                @{ $faa->{inputs} } )
          )
        {
            $retstr .=
              $faa->get_c_arg_scalar($argname);    # Get this argument value.
            $dimvar{$argname} = 1;    # Remember that we got this one.
        }

        #
        # Now verify that the dimension of all arguments are compatible,
        #  and get the pointer to the first argument value.
        #
        my $argcount = @{ $faa->{outputs} };
        foreach $argname ( @{ $faa->{inputs} }, @{ $faa->{inouts} } ) {

            # Look at the input arguments:
            $arg = $args->{$argname};    # Access the description of argument.
            my $dim = @{ $arg->{dimension} };

            # Get the minimum dimension of the argument.
            my @conds;

            if ( $dim == 1 ) {
                if ( $arg->{dimension}[0] ne "(:)" ) {
                    push( @conds,
                            "mxGetNumberOfElements("
                          . $arg->{mat_expr_in}
                          . ") < (int) ("
                          . $arg->{dimension}[0]
                          . ")" );
                }
            } else {
                foreach ( 0 .. $dim - 1 ) {    # Look at the dimension specs.
                    next
                      if $dims_calculated{ $argname, $_ }
                          || $arg->{dimension}[$_] eq "(:)";

                    # Skip if we used this to calculate a
                    # dimension variable.
                    push( @conds,
                            "  ("
                          . $faa->get_size( $argname, $_ )
                          . ") != (int) ("
                          . $arg->{dimension}[$_]
                          . ")" );

                    # Make sure this dimension matches.
                }
            }

            # We don't check dimension for one-dimensional arrays that are given implicitly
            if (
                $faa->n_dimensions($argname) ne "0"
                && (   $dim == 0
                    || $dim == 1 && $arg->{dimension}[0] ne "(:)" )
                && $arg->{basic_type} ne "void *"
              )
            {
                push( @conds, $faa->n_dimensions($argname) . " > $dim" );

                # Make sure it has exactly the right number of
                # dimensions.  Unfortunately, octave and matlab
                # can't distinguish between a vector and a
                # n by 1 matrix, so we have to check for less
                # than or equal to the number of dimensions.
            }

            if (@conds) {    # Any dimension conditions?
                $retstr .=
                  (     "    if ("
                      . join( " || ", @conds ) . ")\n"
                      . "        "
                      . $faa->error_dimension($argname)
                      . "\n" );

                # Blow up if there's a problem.
            }

            if ( @{ $arg->{dimension} } ) {
                $retstr .=
                    $faa->get_c_arg_ptr($argname);    # Get a pointer to this arg.
            } else {
                $retstr .= $faa->get_c_arg_scalar($argname) # Get this argument.
                  unless $dimvar{ $argname
                      };    # Unless we had to get it above because it
                            # was a dimensional variable.
            }

            $retstr .= "\n";    # Put an extra blank line in to make it
                                # more readable.
        }

        my $fstrlens;

        if ( @{ $faa->{outarrs} } > 0 ) {
            $retstr .= "    /******** Obtain fixed-size output arrays ********/\n";
        }

        #
        # Now verify that the dimension of all arguments are compatible,
        #  and get the pointer to the first argument value.
        #
        my $argcount = @{ $faa->{outarrs} };
        foreach $argname ( @{ $faa->{outarrs} } ) {

            $arg = $args->{$argname};    # Access the description of argument.
            my $dim = @{ $arg->{dimension} };

            # Get the minimum dimension of the argument.
            my @conds;

            $retstr .=
                $faa->make_output_ptr($argname);    # Get a pointer to this arg.

            $retstr .= "\n";    # Put an extra blank line in to make it
                                # more readable.
        }

        #
        # Now actually call the function.  Get each of the arguments in
        # a variable and then pass it off to the function:
        #
        #
        # Get an expression for each argument:
        #
        my @fargs = map {
            $arg = $faa->{args}{$_};    # Access this argument.
            my $cexp =
              $arg->{c_var_name};       # Assume we just use the variable name.

            if ( defined( $arg->{fstrlen} ) ) {
                $fstrlens .= ", $arg->{fstrlen}";
            }
            if (   $arg->{pass_by_pointer_reference}
                || $arg->{type} =~ /.*\*\*/ )
            {                           # Pass by reference?
                "&$cexp";
            } else {
                $cexp;
            }
        } @{ $faa->{argnames} };

        $retstr .= "\n    /******** Invoke computational function ********/\n";

        if ( $faa->{returns} ne 'void' ) {    # Is there a return code?
            $retstr .= "    $args->{__r_e_t__}{c_var_name} = ";
        } else {
            $retstr .= "    ";
        }

        my $fcallstr;
        $fcallstr =
          "$faa->{name}(" . join( ", ", @fargs ) . $fstrlens . ");\n\n";
        $retstr .= $fcallstr;                 # Call the function.

        #
        # Now we've called the function.  Free up memory first.
        #
        my $countfree = 0;
        foreach $argname ( @{ $faa->{inputs} } ) {
            $arg = $args->{$argname};         # Access this argument.
            if ( $arg->{basic_type} eq "char" ) {
                if ( $countfree == 0 ) {
                    $retstr .=
                      "\n    /******** Free up input buffers. ********/\n";
                    $countfree = 1;
                }
                $retstr .= $faa->free_c_arg_ptr($argname);
            }
        }

        #
        # Now we've called the function.  Put back all the output variables.
        # First, processing inout strings.
        #
        $countfree = 0;
        foreach $argname ( @{ $faa->{iostrs} } ) {
            $arg = $args->{$argname};    # Point to description of argument.

            if ( $countfree == 0 ) {
                $retstr .=
                    "\n    /******** Copy back inout strings ********/\n";
                $countfree = 1;
            }

            if ( @{ $arg->{dimension} } ) {    # Is this a vector?
                $retstr .= $faa->put_val_ptr($argname);
            } else {
                $retstr .= $faa->make_output_scalar($argname);
                $retstr .= $faa->put_val_scalar($argname) . "\n";
            }
        }

        if ( @{ $faa->{outvals} } > 0 ) {
            $retstr .= "\n    /******** Process output scalars and strings ********/\n";
        }

        my $count = 0;
        foreach $argname ( @{ $faa->{outvals} } ) {

            # We return at least one output argument.
            $arg = $args->{$argname};    # Point to description of argument.

            $retstr .= $count ? "    if (nlhs > $count) {\n" : "";
            my $indent = $count ? "    " : "";
            my $closed = $count ? 0      : 1;

            $count++;
            if ( @{ $arg->{dimension} } ) {    # Is this a vector?
                $retstr .= $indent
                  . $faa->make_output_ptr(
                    $argname,
                    scalar( @{ $arg->{dimension} } ),
                    @{ $arg->{dimension} }
                  );

                if ( $arg->{basic_type} ne 'char' ) {    # Is this a vector?
                    $retstr .= $indent
                      . $faa->put_val_ptr($argname);     # Put back as vector.
                } elsif ( $arg->{type} eq "char **" ) {
                    if ( $faa->{free_func} ne "" ) {
                        if ( $closed == 0 ) {
                            $retstr .= "    }\n";
                            $closed = 1;
                        }
                        $retstr .=
                          "    $faa->{free_func}($arg->{c_var_name});\n\n";
                    } else {
                        print STDERR
"Warning: Character string $arg->{c_var_name} is not freed. Potential memory leak.";
                    }
                }
            } else {    # It's a scalar:
                $retstr .= $indent . $faa->make_output_scalar($argname);
                $retstr .= $indent . $faa->put_val_scalar($argname);
            }

            if ( $closed == 0 ) { $retstr .= "    }\n"; }
        }

        $retstr .= "}\n\n";    # Close off the opening brace.
    };    # End of eval.

    if ($@) {    # Was there a problem?
        print STDERR "While wrapping function ",
          ( $faa->{script_name} || $faa->{name} ), ":\n$@";

        # Print the message.
    } elsif ($::mergefiles) {
        return $retstr;
    } else {
        print OUTFILE $retstr;    # Output the result.
    }
}

#
# print_matlab_code(\%function_def)
#
# Print out MATLAB code.
#
sub print_matlab_code {
    my ( $faa, $func_id ) = @_;    # Access the argument.

    # Get matlab's name for the function.
    my $fname = $faa->{script_name} || $faa->{name};

    #
    # We also generate an auxiliary .m file which contains the help text.
    #
    if ($faa->{external} && $::mergefiles) {
        $fname = "MEX_" . uc($fname);

        local (*MFILE);    # Make a local file handle.
        open( MFILE, "> $outdir/$fname.m" ) ||    # Create the file.
            die("can't open file $outdir/$fname.m--$!\n");

        print MFILE ("function func_id = $fname\n" .
            "% Function ID for $fname\n" .
            "func_id = int32($func_id);\n");

        close(MFILE);                             # Done with that file.

        return;
    }

    # Make list of output/inout arguments.
    my $outargs = join(
        ", ",
        map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{inouts} }),
        map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{outputs} })
    );
    # If there are multiple outputs, put them in brackets.
    @{ $faa->{outputs} } + @{ $faa->{inouts} } > 1 and $outargs = "[$outargs]";

    $outargs ne '' and $outargs .= " = ";    # Add an equals sign too.

    my @inargs = map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{inputs} },
        @{ $faa->{inouts} } );
    my $inargs = join( ", ", @inargs );

    foreach (@inargs) {
        s/^_+//;
    }    # Strip off leading underscores.  For some
         # strange reason matlab doesn't like these.

    my $mstr;

    # Format the input arguments.
    if ( $func_id == 0 && @{ $faa->{inouts} } == 0 && !$faa->{withcast} ) {
        $mstr = "% ";
    }
    $mstr .= "function $outargs$fname($inargs)\n" .
        "% Gateway function for $language function " . $faa->{name} . ".\n%\n";

    # Print out a plain version of the functions
    my $outargs_plain = $outargs;
    $outargs_plain =~ s/\bout_/$1/g;
    $outargs_plain =~ s/\bio_/$1/g;
    my $inargs_plain = $inargs;
    $inargs_plain =~ s/\bio_//g;
    $inargs_plain =~ s/\bin_//g;
    $mstr .= "% $outargs_plain$fname($inargs_plain)\n";

    # Print out the scripting language prototype.
    if ( @{ $faa->{inputs} } > 1 ) {
        $mstr .= "%\n% Input arguments (required; type is auto-casted):\n";
    } else {
        $mstr .= "%\n% Input argument (required; type is auto-casted):\n";
    }
    foreach ( @{ $faa->{inputs} } ) {
        $mstr .= sprintf( "%%    %12s: %s\n",
            $_, matlab_argtype_description( $faa->{args}{$_} ) );
    }

    my $required_in = 0;
    if ( @{ $faa->{inouts} } > 0 ) {
        if ( @{ $faa->{inouts} } > 1 ) {
            $mstr .= "%\n% In&Out arguments";
        } else {
            $mstr .= "%\n% In&Out argument";
        }

        my $count = 0;
        my $mstr_tmp;
        foreach ( @{ $faa->{inouts} } ) {
            $count++;
            my $arg = $faa->{args}{$_};
            my $required;
            if (   $arg->{basic_type} eq "void *"
                || defined( $arg->{cast} )
                || @{ $arg->{dimension} } == 1
                && $arg->{dimension}[0] eq "(:)"
                && ( $arg->{basic_type} ne "char"
                    || ( $::default_strlen == 0 ) ) )
            {
                $required    = " (must be preallocated at input)";
                $required_in = $count;
            } else {
                $required    = " (optional as input)";
            }

            $mstr_tmp .= sprintf( "%%    %12s: %s ${required}\n",
                $_, matlab_argtype_description($arg) );
        }
        $mstr .=
          " (required as output; type is auto-casted):\n$mstr_tmp";
    }

    if ( @{ $faa->{outputs} } > 1 ) {
        $mstr .= "%\n% Output arguments (optional):\n";
    } else {
        $mstr .= "%\n% Output argument (optional):\n";
    }

    my $free_var = 0;
    foreach ( @{ $faa->{outputs} } ) {
        $mstr .= sprintf(
            "%%    %12s: %s\n",
            ( $_ eq "__r_e_t__" ) ? $faa->{args}{$_}{c_var_name} : $_,
            matlab_argtype_description( $faa->{args}{$_} )
        );
        if (   $faa->{args}{$_}->{type} eq "char **"
            && $faa->{free_func} ne "" )
        {
            $free_var = 1;
        }
    }

    my $prototype = ::get_prototype($faa);
    $prototype =~ s/^/\% /mg;

    $mstr .= "%\n% The original $language function is:\n$prototype\n";

    if ( $faa->{url} ne "" ) {
        $mstr .=
"%\n% For detail, see <a href=\"$faa->{url}\">online documentation</a>.\n%\n";
    } elsif ( $::default_url ne "" ) {
        my $url = $::default_url;    # Make a copy of default_url and
        $url =~ s/(\w+:)%%/$1\/\//g;
        $url =~ s/\$_/$fname/g;        # substitute string for function name.
        $mstr .= "%\n% For detail, see $url.\n";
    } else {
        $mstr .=
          "%\n% For detail, see the documentation of the original function.\n";
    }

    if ( $faa->{seealso} ne "" ) {
        $mstr .= "%\n% See also $faa->{seealso}.\n";
    }

    if ($free_var) {
        $mstr .= "
% NOTE: Some buffer space for out char(s) was allocated by $language function
% $fname, and the MEX function has deallocated the buffer by
% calling $faa->{free_func}.
";
    }

    if ( $func_id || @{ $faa->{inouts} } || $faa->{withcast} ) {
        if ( $func_id == 0 ) {
            $mstr .= "
% NOTE: Because of INOUT argument(s), the user should not directly call the
% MEX-function directly. This M-function should be used as the gateway instead.
%
% An INOUT argument is mandatory as an output argument. However, it is an
% optional input argument for a basic type (i.e., integers or reals).
% If missing in the input arguments, this variable is initialized to zero of
% the proper type. If given in the input with proper type, the argument
% is passed by reference.

";
        }

        if ( @{ $faa->{inouts} } || ( @{ $faa->{inputs} } + $required_in ) ) {
            $mstr .= "if ("
              . ( @{ $faa->{inouts} }
                ? ( " nargout < " . ( @{ $faa->{inouts} } ))
                : "" )
              . ( @{ $faa->{inouts} } && ( @{ $faa->{inputs} } + $required_in ) ? " || " : "")
              . ( ( @{ $faa->{inputs} } + $required_in )
                ? ( "nargin < " . ( @{ $faa->{inputs} } + $required_in ) )
                : "" )
              . ")\n"
              . "    error('Incorrect number of input or output arguments.');\n"
              . "end\n";
        }

        # First, perform type casting
        my $argno = 0;
        foreach ( @{ $faa->{inputs} } ) {
            my $arg      = $faa->{args}{$_};
            my $var_name = $arg->{c_var_name};
            $argno++;

            if ( defined( $arg->{cast} ) ) {
                # Check whether it is an argument
                $mstr .= ::obtain_typecast( $arg->{cast}, $var_name );
            } else {
                my $basetype = matlab_typename( $arg->{basic_type} );
                if ( $basetype eq "ptrdiff_t" || $basetype eq "long" ) {
                    $mstr .= "if strfind(computer,'64') %#ok<STRIFCND>\n"
                          .  "    $var_name = int64($var_name);\n"
                          .  "else\n"
                          .  "    $var_name = int32($var_name);\n"
                          .  "end\n";
                } elsif ( $basetype eq "size_t" || $basetype eq "ulong" ) {
                    $mstr .= "if strfind(computer,'64') %#ok<STRIFCND>\n"
                          .  "    $var_name = uint64($var_name);\n"
                          .  "else\n"
                          .  "    $var_name = uint32($var_name);\n"
                          .  "end\n";
                } else {
                    $mstr .= "$var_name = ${basetype}($var_name);\n";
                }
            }
        }
        foreach ( @{ $faa->{inouts} } ) {
            my $arg      = $faa->{args}{$_};
            my $var_name = $arg->{c_var_name};
            $argno++;

            if ( defined( $arg->{cast} ) ) {
                # Check whether it is an argument
                $mstr .= ::obtain_typecast( $arg->{cast}, $var_name )
                  . "if ~isempty($var_name)\n"
                  . "    % Write to it to unshare memory with other variables\n"
                  . "    t=$var_name(1); $var_name(1)=t;\nend\n\n";
            }
        }

        $argno = @{ $faa->{inputs} };
        foreach ( @{ $faa->{inouts} } ) {
            my $arg      = $faa->{args}{$_};
            my $var_name = $arg->{c_var_name};
            $argno++;

            next if defined( $arg->{cast} );

            if ( $arg->{basic_type} eq "char" ) {
                if ( @{ $faa->{args}{$var_name}->{dimension} } == 0
                    || $faa->{args}{$var_name}->{dimension}[0] eq "(:)" )
                {
                    if ( $::default_strlen > 1 ) {
                        $mstr .=
                            "if nargin<$argno\n"
                          . "    $var_name=char(zeros(1,$::default_strlen));\n"
                          . "elseif length($var_name)<$::default_strlen\n"
                          . "    %% Enlarge the array if necessary;\n"
                          . "    $var_name=char([$var_name zeros(1,$::default_strlen-length($var_name))]);\nelse";
                    } else {
                        $mstr .=
                          "if nargin<$argno\n    $var_name=char(0);\nelse";
                    }
                } elsif ( @{ $arg->{dimension} } == 1 ) {
                    $mstr .= sprintf(
                        "if nargin<$argno\n"
                          . "    $var_name=char(zeros(1,%s));\n"
                          . "elseif length($var_name)<%s\n"
                          . "    %% Enlarge the array if necessary;\n"
                          . "    $var_name=char([$var_name zeros(1,%s-length($var_name))]);\nelse",
                        $arg->{dimension}[0],
                        $arg->{dimension}[0],
                        $arg->{dimension}[0]
                    );
                } else {
                    $mstr .= sprintf(
                        "if nargin<$argno\n"
                          . "    $var_name=char(zeros(%s));\n",
                        join( ", ", @{ $arg->{dimension} } )
                    );
                    $mstr .= "else";
                }
                $mstr .=
                    "if ~isa($var_name,'char')\n"
                  . "    $var_name=char($var_name);\n"
                  . "else\n"
                  . "    % Write to it to unshare memory with other variables\n"
                  . "    t=$var_name(1); $var_name(1)=t;\nend\n\n";
            } elsif ( $arg->{basic_type} eq "void *" ) {
                $mstr .=
                    "if ~isempty($var_name)\n"
                  . "    % Write to it to unshare memory with other variables\n"
                  . "    t=$var_name(1); $var_name(1)=t;\nend\n\n";
            } else {
                my $basetype = matlab_typename( $arg->{basic_type} );
                if ( $basetype eq "ptrdiff_t" || $basetype eq "long" ) {
                    $mstr .= "if strfind(computer,'64')  %#ok<STRIFCND>\n"
                          .  "    basetype = 'int64';\n"
                          .  "else\n"
                          .  "    basetype = 'int32';\n"
                          .  "end\n";
                } elsif ( $basetype eq "size_t" || $basetype eq "ulong" ) {
                    $mstr .= "if strfind(computer,'64')  %#ok<STRIFCND>\n"
                          .  "    basetype = 'uint64';\n"
                          .  "else\n"
                          .  "    basetype = 'uint32';\n"
                          .  "end\n";
                } else {
                    $mstr .= "basetype = '${basetype}';\n";
                }
                if ( @{ $arg->{dimension} } == 0 ) {
                    $mstr .= "if nargin<$argno\n    $var_name=${basic_type}(0);\nelse";
                } elsif ( @{ $arg->{dimension} } == 1 && $arg->{dimension}[0] ne "(:)" ) {
                    $mstr .= sprintf(
                        "if nargin<$argno\n"
                          . "    $var_name = zeros(1,%s,basetype);\n"
                          . "elseif length($var_name)<%s\n"
                          . "    %% Enlarge the array if necessary;\n"
                          . "    if size($var_name,2)==1\n"
                          . "        $var_name=[$var_name; zeros(%s-length($var_name),1,basetype)];\n"
                          . "    else\n"
                          . "        $var_name=[$var_name, zeros(1,%s-length($var_name),basetype)];\n"
                          . "    end\nelse",
                        $arg->{dimension}[0], $arg->{dimension}[0],
                        $arg->{dimension}[0], $arg->{dimension}[0]
                    );
                } elsif ( @{ $arg->{dimension} } > 1 ) {
                    $mstr .= sprintf(
                        "if nargin<$argno\n    $var_name=zeros(%s,basetype);\n",
                        join( ", ", @{ $arg->{dimension} } ) );
                    $mstr .= "else";
                }
                $mstr .=
                    "if ~isa($var_name,basetype)\n"
                  . "    $var_name = cast($var_name, basetype);\n"
                  . "elseif ~isempty($var_name)\n"
                  . "    % Write to it to unshare memory with other variables\n"
                  . "    t=$var_name(1); $var_name(1)=t;\nend\n\n";
            }
        }

        # Add inout arguments to output
        $mstr .= "\n% Invoke the actual MEX-function.\n";
        my $outargs = join( ", ",
            map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{iostrs} } ),
            map( { $faa->{args}{$_}{c_var_name} } @{ $faa->{outputs} } ));
        @{ $faa->{outputs} } + @{ $faa->{iostrs} } > 1 and $outargs = "[$outargs]";
        $outargs ne '' and $outargs .= " =";    # Add an equals sign too.

        # If func_id is non-zero, then mergefile is enabled.
        if ( $func_id == 0 ) {
            $mstr .= "$outargs ${fname}_mex($inargs);\n";
        } else {
            $mstr .=
              "$outargs ${::outfilebase}_mex(int32($func_id)"
              . (length($inargs) ? ", $inargs" : "") . ");\n";
        }

        # Finally, cast character strings
        my $argno = 0;
        foreach ( @{ $faa->{iostrs} } ) {
            my $arg      = $faa->{args}{$_};
            my $var_name = $arg->{c_var_name};
            $argno++;

            if ( defined( $arg->{cast} ) ) {
                # Check whether it is an argument
                $mstr .= ::obtain_typecast_string( $arg->{cast}, $var_name );
            }
        }
    } else {
        $mstr .=
          "\nassert(0,['This M-file should not be reached. It should be shadowed ' ...\n"
          . "'by the MEX function if the library is properly configured.']);";
    }

    local (*MFILE);    # Make a local file handle.
    open( MFILE, "> $outdir/$fname.m" ) ||    # Create the file.
      die("can't open file $outdir/$fname.m--$!\n");

    print MFILE "$mstr";

    close(MFILE);                             # Done with that file.
}
