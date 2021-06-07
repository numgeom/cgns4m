function [out_ThermalRelaxationFlag, out_ChemicalKineticsFlag, ierr] = cg_equationset_chemistry_read()
% Gateway function for C function cg_equationset_chemistry_read.
%
% [ThermalRelaxationFlag, ChemicalKineticsFlag, ierr] = cg_equationset_chemistry_read()
%
% Input argument (required; type is auto-casted):
%
% Output arguments (optional):
%    ThermalRelaxationFlag: 32-bit integer (int32), scalar
%    ChemicalKineticsFlag: 32-bit integer (int32), scalar
%            ierr: 32-bit integer (int32), scalar
%
% The original C function is:
% int cg_equationset_chemistry_read(int * ThermalRelaxationFlag, int * ChemicalKineticsFlag);
%
% For detail, see <a href="https://cgns.github.io/CGNS_docs_current/midlevel/equation.html">online documentation</a>.
%

% Invoke the actual MEX-function.
[out_ThermalRelaxationFlag, out_ChemicalKineticsFlag, ierr] = cgnslib_mex(int32(226));
