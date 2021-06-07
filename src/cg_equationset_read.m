function [out_EquationDimension, out_GoverningEquationsFlag, out_GasModelFlag, out_ViscosityModelFlag, out_ThermalConductivityModelFlag, out_TurbulenceClosureFlag, out_TurbulenceModelFlag, ierr] = cg_equationset_read()
% Gateway function for C function cg_equationset_read.
%
% [EquationDimension, GoverningEquationsFlag, GasModelFlag, ViscosityModelFlag, ThermalConductivityModelFlag, TurbulenceClosureFlag, TurbulenceModelFlag, ierr] = cg_equationset_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%    EquationDimension: 32-bit integer (int32), scalar
%    GoverningEquationsFlag: 32-bit integer (int32), scalar
%    GasModelFlag: 32-bit integer (int32), scalar
%    ViscosityModelFlag: 32-bit integer (int32), scalar
%    ThermalConductivityModelFlag: 32-bit integer (int32), scalar
%    TurbulenceClosureFlag: 32-bit integer (int32), scalar
%    TurbulenceModelFlag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_equationset_read(int * EquationDimension, int * GoverningEquationsFlag, int * GasModelFlag, int * ViscosityModelFlag, int * ThermalConductivityModelFlag, int * TurbulenceClosureFlag, int * TurbulenceModelFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_EquationDimension, out_GoverningEquationsFlag, out_GasModelFlag, out_ViscosityModelFlag, out_ThermalConductivityModelFlag, out_TurbulenceClosureFlag, out_TurbulenceModelFlag, ierr] = cgnslib_mex(int32(225));
