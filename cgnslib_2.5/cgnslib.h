/*-------------------------------------------------------------------------
This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from
the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not
   be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------*/

/************
 * This file is based on cgnslib.h in the cgnslib_2.5 distribution.
 *
 * It is funcationally identical to the file in the official CGNS 
 * distribution, except for the annotations added for C2mex.
 *
 * Xiangmin Jiao, jiao@ams.sunysb.edu, 01/07/2009.
 */

/*%default_strlen 32 */
/*%default_strfree cg_free */
/*%default_retlast 1 */
/*%default_retname ierr */
/*%enumdef CG_MODE_READ, CG_MODE_WRITE, CG_MODE_CLOSED, CG_MODE_MODIFY */
/*%enumdef CG_OK,CG_ERROR, CG_NODE_NOT_FOUND, CG_INCORRECT_PATH, CG_NO_INDEX_DIM */
/*%enumdef CG_Null, CG_UserDefined */
/*%enumdef CG_MAX_GOTO_DEPTH */
/*%enumdef CG_CONFIG_ERROR, CG_CONFIG_COMPRESS, CG_CONFIG_SET_PATH, CG_CONFIG_ADD_PATH */

#ifndef CGNSLIB_H
#define CGNSLIB_H

#define CGNS_VERSION 2540
#define CGNS_DOTVERS 2.54

#ifndef CGNSDLL
# ifdef _WIN32
#  if defined(BUILD_DLL)
#    define CGNSDLL _declspec(dllexport)
#  elif defined(USE_DLL)
#    define CGNSDLL _declspec(dllimport)
#  else
#    define CGNSDLL
#  endif
# else
#  define CGNSDLL
# endif
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      modes for cgns file                                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define CG_MODE_READ	0
#define CG_MODE_WRITE	1
#define CG_MODE_CLOSED	2
#define CG_MODE_MODIFY	3

/* function return codes */

#define CG_OK		  0
#define CG_ERROR	  1
#define CG_NODE_NOT_FOUND 2
#define CG_INCORRECT_PATH 3
#define CG_NO_INDEX_DIM   4

/* Null and UserDefined enums */

#define CG_Null        0
#define CG_UserDefined 1

/* max goto depth */

#define CG_MAX_GOTO_DEPTH 20

/* configuration options */

#define CG_CONFIG_ERROR    1
#define CG_CONFIG_COMPRESS 2
#define CG_CONFIG_SET_PATH 3
#define CG_CONFIG_ADD_PATH 4

/* support for legacy code
   these will go away in 3.0 */

#if 0 && CGNS_VERSION < 3000

#define MODE_READ	CG_MODE_READ
#define MODE_WRITE	CG_MODE_WRITE
#define MODE_CLOSED	CG_MODE_CLOSED
#define MODE_MODIFY	CG_MODE_MODIFY
#define Null            CG_Null
#define UserDefined	CG_UserDefined
#define Celcius		Celsius

#endif

#ifdef __cplusplus
extern "C" {
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *  Enumerations:  if any of this enumerations need to be modified,      *
 *	           the corresponding namelist must also be updated.      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Dimensional Units                                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	MassUnitsNull, MassUnitsUserDefined,
	Kilogram, Gram, Slug, PoundMass
} MassUnits_t;

typedef enum {
	LengthUnitsNull, LengthUnitsUserDefined,
	Meter, Centimeter, Millimeter, Foot, Inch
} LengthUnits_t;

typedef enum {
	TimeUnitsNull, TimeUnitsUserDefined, Second
} TimeUnits_t;

typedef enum {
	TemperatureUnitsNull, TemperatureUnitsUserDefined,
	Kelvin, Celsius, Rankine, Fahrenheit
} TemperatureUnits_t;

typedef enum {
	AngleUnitsNull, AngleUnitsUserDefined, Degree, Radian
} AngleUnits_t;

typedef enum {
	ElectricCurrentUnitsNull, ElectricCurrentUnitsUserDefined,
	Ampere, Abampere, Statampere, Edison, auCurrent
} ElectricCurrentUnits_t;

typedef enum {
	SubstanceAmountUnitsNull, SubstanceAmountUnitsUserDefined,
	Mole, Entities, StandardCubicFoot, StandardCubicMeter
} SubstanceAmountUnits_t;

typedef enum {
	LuminousIntensityUnitsNull, LuminousIntensityUnitsUserDefined,
	Candela, Candle, Carcel, Hefner, Violle
} LuminousIntensityUnits_t;

#define NofValidMassUnits              6
#define NofValidLengthUnits            7
#define NofValidTimeUnits              3
#define NofValidTemperatureUnits       6
#define NofValidAngleUnits             4
#define NofValidElectricCurrentUnits   7
#define NofValidSubstanceAmountUnits   6
#define NofValidLuminousIntensityUnits 7

extern char const * MassUnitsName[NofValidMassUnits];
extern char const * LengthUnitsName[NofValidLengthUnits];
extern char const * TimeUnitsName[NofValidTimeUnits];
extern char const * TemperatureUnitsName[NofValidTemperatureUnits];
extern char const * AngleUnitsName[NofValidAngleUnits];
extern char const * ElectricCurrentUnitsName[NofValidElectricCurrentUnits];
extern char const * SubstanceAmountUnitsName[NofValidSubstanceAmountUnits];
extern char const * LuminousIntensityUnitsName[NofValidLuminousIntensityUnits];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data Class                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	DataClassNull, DataClassUserDefined,
	Dimensional, NormalizedByDimensional,
	NormalizedByUnknownDimensional,
	NondimensionalParameter, DimensionlessConstant
} DataClass_t;

#define NofValidDataClass 7

extern char const * DataClassName[NofValidDataClass];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Location
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GridLocationNull, GridLocationUserDefined,
        Vertex, CellCenter, FaceCenter,
        IFaceCenter, JFaceCenter, KFaceCenter, EdgeCenter
} GridLocation_t;

#define NofValidGridLocation 9

extern char const * GridLocationName[NofValidGridLocation];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      BCData Types: Can not add types and stay forward compatible      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	BCDataTypeNull, BCDataTypeUserDefined,
	Dirichlet, Neumann
} BCDataType_t;

#define NofValidBCDataTypes 4

extern char const * BCDataTypeName[NofValidBCDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Connectivity Types 					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GridConnectivityTypeNull, GridConnectivityTypeUserDefined,
	Overset, Abutting, Abutting1to1
} GridConnectivityType_t;

#define NofValidGridConnectivityTypes 5

extern char const * GridConnectivityTypeName[NofValidGridConnectivityTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Point Set Types: Can't add types and stay forward compatible
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	PointSetTypeNull, PointSetTypeUserDefined,
        PointList,  PointListDonor,
        PointRange, PointRangeDonor,
	ElementRange, ElementList, CellListDonor
} PointSetType_t;

#define NofValidPointSetTypes 9

extern char const * PointSetTypeName[NofValidPointSetTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Governing Equations and Physical Models Types                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	GoverningEquationsNull, GoverningEquationsUserDefined,
	FullPotential, Euler, NSLaminar, NSTurbulent,
	NSLaminarIncompressible, NSTurbulentIncompressible
} GoverningEquationsType_t;

/* Any model type will accept both ModelTypeNull and ModelTypeUserDefined.
** The following models will accept these values as vaild...
**
** GasModel_t: Ideal, VanderWaals, CaloricallyPerfect, ThermallyPerfect,
**    ConstantDensity, RedlichKwong
**
** ViscosityModel_t: Constant, PowerLaw, SutherlandLaw
**
** ThermalConductivityModel_t: PowerLaw, SutherlandLaw, ConstantPrandtl
**
** TurbulenceModel_t: Algebraic_BaldwinLomax, Algebraic_CebeciSmith,
**    HalfEquation_JohnsonKing, OneEquation_BaldwinBarth,
**    OneEquation_SpalartAllmaras, TwoEquation_JonesLaunder,
**    TwoEquation_MenterSST,TwoEquation_Wilcox
**
** TurbulenceClosure_t: EddyViscosity, ReynoldsStress, ReynoldsStressAlgebraic
**
** ThermalRelaxationModel_t: Frozen, ThermalEquilib, ThermalNonequilib
**
** ChemicalKineticsModel_t: Frozen, ChemicalEquilibCurveFit,
**    ChemicalEquilibMinimization, ChemicalNonequilib
**
** EMElectricFieldModel_t: Voltage, Interpolated, Constant, Frozen
**
** EMMagneticFieldModel_t: Interpolated, Constant, Frozen
**
** EMConductivityModel_t: Constant, Frozen, Equilibrium_LinRessler,
**				Chemistry_LinRessler
*/

typedef enum {
	ModelTypeNull, ModelTypeUserDefined,
	Ideal, VanderWaals,
	Constant,
	PowerLaw, SutherlandLaw,
	ConstantPrandtl,
	EddyViscosity, ReynoldsStress, ReynoldsStressAlgebraic,
	Algebraic_BaldwinLomax, Algebraic_CebeciSmith,
	HalfEquation_JohnsonKing, OneEquation_BaldwinBarth,
	OneEquation_SpalartAllmaras, TwoEquation_JonesLaunder,
	TwoEquation_MenterSST, TwoEquation_Wilcox,
	CaloricallyPerfect, ThermallyPerfect,
	ConstantDensity, RedlichKwong,
	Frozen, ThermalEquilib, ThermalNonequilib,
	ChemicalEquilibCurveFit, ChemicalEquilibMinimization,
	ChemicalNonequilib,
	EMElectricField, EMMagneticField, EMConductivity,
	Voltage, Interpolated, Equilibrium_LinRessler, Chemistry_LinRessler
} ModelType_t;

#define NofValidGoverningEquationsTypes 8
#define NofValidModelTypes 36

extern char const * GoverningEquationsTypeName[NofValidGoverningEquationsTypes];
extern char const * ModelTypeName[NofValidModelTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 * 	Boundary Condition Types					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	BCTypeNull, BCTypeUserDefined,
	BCAxisymmetricWedge, BCDegenerateLine, BCDegeneratePoint,
	BCDirichlet, BCExtrapolate, BCFarfield, BCGeneral, BCInflow,
	BCInflowSubsonic,  BCInflowSupersonic, BCNeumann, BCOutflow,
	BCOutflowSubsonic, BCOutflowSupersonic, BCSymmetryPlane,
	BCSymmetryPolar, BCTunnelInflow, BCTunnelOutflow, BCWall,
	BCWallInviscid, BCWallViscous, BCWallViscousHeatFlux,
	BCWallViscousIsothermal, FamilySpecified
} BCType_t;

#define NofValidBCTypes 26

extern char const * BCTypeName[NofValidBCTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data types:  Can not add data types and stay forward compatible  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	DataTypeNull, DataTypeUserDefined, Integer, RealSingle,
	RealDouble, Character
} DataType_t;
/*%typemap Integer=>int32,RealSingle=>single,RealDouble=>double,Character=>char */

#define NofValidDataTypes 6

extern char const * DataTypeName[NofValidDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Element types                                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	ElementTypeNull, ElementTypeUserDefined,	/* 0, 1,	*/
	NODE, BAR_2, BAR_3, 				/* 2, 3, 4, 	*/
	TRI_3, TRI_6,					/* 5, 6,	*/
	QUAD_4, QUAD_8, QUAD_9,				/* 7, 8, 9,	*/
	TETRA_4, TETRA_10, 				/* 10, 11,	*/
	PYRA_5, PYRA_14, 				/* 12, 13,	*/
	PENTA_6, PENTA_15, PENTA_18,			/* 14, 15, 16,	*/
	HEXA_8, HEXA_20, HEXA_27, 			/* 17, 18, 19,	*/
	MIXED, NGON_n					/* 20, 21+	*/
} ElementType_t;

#define NofValidElementTypes 22

extern char const * ElementTypeName[NofValidElementTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Zone types                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	ZoneTypeNull, ZoneTypeUserDefined,
	Structured, Unstructured
} ZoneType_t;

#define NofValidZoneTypes 4

extern char const * ZoneTypeName[NofValidZoneTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Rigid Grid Motion types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	RigidGridMotionTypeNull, RigidGridMotionTypeUserDefined,
	ConstantRate, VariableRate
} RigidGridMotionType_t;

#define NofValidRigidGridMotionTypes 4

extern char const * RigidGridMotionTypeName[NofValidRigidGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Arbitrary Grid Motion types                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
        ArbitraryGridMotionTypeNull, ArbitraryGridMotionTypeUserDefined,
        NonDeformingGrid, DeformingGrid
} ArbitraryGridMotionType_t;

#define NofValidArbitraryGridMotionTypes 4

extern char const * ArbitraryGridMotionTypeName[NofValidArbitraryGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Simulation types					         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	SimulationTypeNull, SimulationTypeUserDefined,
	TimeAccurate, NonTimeAccurate
} SimulationType_t;

#define NofValidSimulationTypes 4

extern char const * SimulationTypeName[NofValidSimulationTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	BC Property types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	WallFunctionTypeNull, WallFunctionTypeUserDefined,
	Generic
} WallFunctionType_t;

typedef enum {
	AreaTypeNull, AreaTypeUserDefined,
	BleedArea, CaptureArea
} AreaType_t;

#define NofValidWallFunctionTypes 3
#define NofValidAreaTypes 4

extern char const * WallFunctionTypeName[NofValidWallFunctionTypes];
extern char const * AreaTypeName[NofValidAreaTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Grid Connectivity Property types				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
	AverageInterfaceTypeNull, AverageInterfaceTypeUserDefined,
	AverageAll, AverageCircumferential, AverageRadial, AverageI,
	AverageJ, AverageK
} AverageInterfaceType_t;

#define NofValidAverageInterfaceTypes 8

extern char const * AverageInterfaceTypeName[NofValidAverageInterfaceTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      LIBRARY FUNCTIONS						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_open(char const * filename, int mode, int *fn);
/*%output fn */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */
CGNSDLL int cg_version(int fn, float *FileVersion);
/*%output FileVersion */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */
CGNSDLL int cg_close(int fn);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */
CGNSDLL int cg_root_id(int fn, double *rootid);
/*%output rootid */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */

CGNSDLL int cg_configure(int what, void *value);
/*%input value */
/*%typecast value:cgns_configure_type(what) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */
CGNSDLL int cg_is_cgns(const char *filename);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/fileops.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      utility functions               				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL const char *cg_get_name(int nnames, const char **names, int type);
/*%ignore */
CGNSDLL const char *cg_MassUnitsName(MassUnits_t type);
/*%retname name */
CGNSDLL const char *cg_LengthUnitsName(LengthUnits_t type);
/*%retname name */
CGNSDLL const char *cg_TimeUnitsName(TimeUnits_t type);
/*%retname name */
CGNSDLL const char *cg_TemperatureUnitsName(TemperatureUnits_t type);
/*%retname name */
CGNSDLL const char *cg_AngleUnitsName(AngleUnits_t type);
/*%retname name */
CGNSDLL const char *cg_ElectricCurrentUnitsName(ElectricCurrentUnits_t type);
/*%retname name */
CGNSDLL const char *cg_SubstanceAmountUnitsName(SubstanceAmountUnits_t type);
/*%retname name */
CGNSDLL const char *cg_LuminousIntensityUnitsName(LuminousIntensityUnits_t type);
/*%retname name */
CGNSDLL const char *cg_DataClassName(DataClass_t type);
/*%retname name */
CGNSDLL const char *cg_GridLocationName(GridLocation_t type);
/*%retname name */
CGNSDLL const char *cg_BCDataTypeName(BCDataType_t type);
/*%retname name */
CGNSDLL const char *cg_GridConnectivityTypeName(GridConnectivityType_t type);
/*%retname name */
CGNSDLL const char *cg_PointSetTypeName(PointSetType_t type);
/*%retname name */
CGNSDLL const char *cg_GoverningEquationsTypeName(GoverningEquationsType_t type);
/*%retname name */
CGNSDLL const char *cg_ModelTypeName(ModelType_t type);
/*%retname name */
CGNSDLL const char *cg_BCTypeName(BCType_t type);
/*%retname name */
CGNSDLL const char *cg_DataTypeName(DataType_t type);
/*%retname name */
CGNSDLL const char *cg_ElementTypeName(ElementType_t type);
/*%retname name */
CGNSDLL const char *cg_ZoneTypeName(ZoneType_t type);
/*%retname name */
CGNSDLL const char *cg_RigidGridMotionTypeName(RigidGridMotionType_t type);
/*%retname name */
CGNSDLL const char *cg_ArbitraryGridMotionTypeName(ArbitraryGridMotionType_t type);
/*%retname name */
CGNSDLL const char *cg_SimulationTypeName(SimulationType_t type);
/*%retname name */
CGNSDLL const char *cg_WallFunctionTypeName(WallFunctionType_t type);
/*%retname name */
CGNSDLL const char *cg_AreaTypeName(AreaType_t type);
/*%retname name */
CGNSDLL const char *cg_AverageInterfaceTypeName(AverageInterfaceType_t type);
/*%retname name */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write CGNSBase_t Nodes					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nbases(int fn, int *nbases);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
CGNSDLL int cg_base_read(int file_number, int B, char *basename,
	int *cell_dim, int *phys_dim);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
/*%output cell_dim,phys_dim */

CGNSDLL int cg_base_id(int fn, int B, double *base_id);
/*%output base_id */
CGNSDLL int cg_base_write(int file_number, char const * basename,
	int cell_dim, int phys_dim, int *B);
/*%output B */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Zone_t Nodes    					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nzones(int fn, int B, int *nzones);
/*%output nzones */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
CGNSDLL int cg_zone_read(int fn, int B, int Z, char *zonename, int *size);
/*%output size(9) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
CGNSDLL int cg_zone_type(int file_number, int B, int Z, ZoneType_t *type);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
CGNSDLL int cg_zone_id(int fn, int B, int Z, double *zone_id);
/*%output zone_id */
CGNSDLL int cg_zone_write(int fn, int B, char const * zonename,
	int const * size, ZoneType_t type, int *Z);
/*%input size(9) */
/*%output Z */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write SimulationType_t Node                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_simulation_type_read(int file_number, int B, SimulationType_t *type);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */
CGNSDLL int cg_simulation_type_write(int file_number, int B, SimulationType_t type);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Family_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nfamilies(int file_number, int B, int *nfamilies);
/*%output nfamilies */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

CGNSDLL int cg_family_read(int file_number, int B, int F, char *family_name,
	int *nboco, int *ngeos);
/*%output nboco, ngeos*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

CGNSDLL int cg_family_write(int file_number, int B, char const * family_name,
	int *F);
/*%output F*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyName_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_famname_read(char *family_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

CGNSDLL int cg_famname_write(char const * family_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyBC_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_fambc_read(int file_number, int B, int F, int BC,
	char *fambc_name, BCType_t *bocotype);
/*%output bocotype*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

CGNSDLL int cg_fambc_write(int file_number, int B, int F,
	char const * fambc_name, BCType_t bocotype, int *BC);
/*%output BC */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryReference_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_geo_read(int file_number, int B, int F, int G, char *geo_name,
        char **geo_file, char *CAD_name, int *npart);
/*%output npart */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

CGNSDLL int cg_geo_write(int file_number, int B, int F, char const * geo_name,
        char const * filename, char const * CADname, int *G);
/*%output G */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryEntity_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_part_read(int file_number, int B, int F, int G, int P,
	char *part_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */
CGNSDLL int cg_part_write(int file_number, int B, int F, int G,
	char const * part_name, int *P);
/*%output P */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ngrids(int file_number, int B, int Z, int *ngrids);
/*%output ngrids */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_grid_read(int file_number, int B, int Z, int G, char *gridname);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_grid_write(int file_number, int B, int Z,
	char const * zcoorname, int *G);
/*%output G */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t/DataArray_t Nodes               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ncoords(int fn, int B, int Z, int *ncoords);
/*%output ncoords */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_coord_info(int fn, int B, int Z, int C, DataType_t *type,
	char *coordname);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_coord_read(int fn, int B, int Z, char const * coordname,
	DataType_t type, int const * rmin, int const * rmax, void *coord);
/*%typecast coord:type */
/*%input rmin(:), rmax(:) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_coord_id(int fn, int B, int Z, int C, double *coord_id);
/*%output coord_id */
CGNSDLL int cg_coord_write(int fn, int B, int Z, DataType_t type,
	char const * coordname, void const * coord_ptr, int *C);
/*%typecast coord_ptr:type */
/*%output C */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */


CGNSDLL int cg_coord_partial_write(int fn, int B, int Z, DataType_t type,
	char const * coordname, int *rmin, int *rmax,
	void const * coord_ptr, int *C);
/*%typecast coord_ptr:type */
/*%input rmin(:), rmax(:) */
/*%output C */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Elements_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nsections(int file_number, int B, int Z, int *nsections);
/*%output nsections */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_section_read(int file_number, int B, int Z, int S,
	char *SectionName, ElementType_t *type, int *start, int *end,
        int *nbndry, int *parent_flag);
/*%output type,start,end,nbndry,parent_flag */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_elements_read(int file_number, int B, int Z, int S,
	int *elements, int *parent_data);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_section_write(int file_number, int B, int Z,
	char const * SectionName, ElementType_t type, int start, int end,
        int nbndry, int const * elements, int *S);
/*%output S */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_parent_data_write(int file_number, int B, int Z, int S,
	int const * parent_data);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_npe(ElementType_t type, int *npe);
/*%output npe */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_ElementDataSize(int file_number, int B, int Z, int S,
	int *ElementDataSize);
/*%output ElementDataSize */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_section_partial_write(int file_number, int B, int Z,
	char const * SectionName, ElementType_t type, int start, int end,
	int nbndry, int const * elements, int *S);
/*%output S */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_parent_data_partial_write(int fn, int B, int Z, int S,
	int rmin, int rmax, int const *ParentData);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_elements_partial_read(int file_number, int B, int Z, int S,
	int start, int end, int *elements, int *parent_data);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_ElementPartialSize(int file_number, int B, int Z, int S,
	int start, int end, int *ElementDataSize);
/*%output ElementDataSize */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowSolution_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


CGNSDLL int cg_nsols(int fn, int B, int Z, int *nsols);
/*%output nsols */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_sol_info(int fn, int B, int Z, int S, char *solname,
	GridLocation_t *location);
/*%output location */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_sol_id(int fn, int B, int Z,int S, double *sol_id);
/*%output sol_id */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_sol_write(int fn, int B, int Z, char const * solname,
	GridLocation_t location, int *S);
/*%output S */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write solution DataArray_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nfields(int fn, int B, int Z, int S, int *nfields);
/*%output nfields */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_field_info(int fn,int B,int Z,int S,int F, DataType_t *type,
	char *fieldname);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_field_read(int fn, int B, int Z, int S, char const *fieldname,
	DataType_t type, int *rmin, int *rmax, void *field_ptr);
/*%typecast field_ptr:type */
/*%input rmin(:), rmax(:) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_field_id(int fn, int B, int Z,int S,int F, double *field_id);
/*%output field_id */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_field_write(int fn,int B,int Z,int S, DataType_t type,
	char const * fieldname, void const * field_ptr, int *F);
/*%typecast field_ptr:type */
/*%output F */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_field_partial_write(int fn, int B, int Z, int S,
	DataType_t type, char const * fieldname, int *rmin, int *rmax,
	void const * field_ptr, int *F);
/*%typecast field_ptr:type */
/*%input rmin(:), rmax(:) */
/*%output F */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write OversetHoles_t Nodes  				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nholes(int fn, int B, int Z, int *nholes);
/*%output nholes */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_hole_info(int fn, int B, int Z, int I, char *holename,
	GridLocation_t *location, PointSetType_t *ptset_type, int *nptsets,
        int *npnts);
/*%output location, ptset_type, nptsets, npnts */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_hole_read(int fn, int B, int Z, int I, int *pnts);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_hole_id(int fn, int B, int Z, int I, double *hole_id);
/*%output hole_id */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_hole_write(int fn, int B, int Z, char const * holename,
	GridLocation_t location, PointSetType_t ptset_type, int nptsets,
        int npnts, int const * pnts, int *I);
/*%output I */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nconns(int fn, int B, int Z, int *nconns);
/*%output nconns */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_info(int file_number, int B, int Z, int I,
	char *connectname, GridLocation_t *location,
        GridConnectivityType_t *type, PointSetType_t *ptset_type, int *npnts,
        char *donorname, ZoneType_t *donor_zonetype,
        PointSetType_t *donor_ptset_type, DataType_t *donor_datatype,
        int *ndata_donor);
/*%output location,type,ptset_type,npnts,donor_zonetype,donor_ptset_type,donor_datatype,ndata_donor*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_read(int file_number, int B, int Z, int I, int *pnts,
        DataType_t donor_datatype, void *donor_data);
/*%typecast donor_data:donor_datatype */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_id(int fn, int B, int Z, int I, double *conn_id);
/*%output conn_id */
CGNSDLL int cg_conn_write(int file_number, int B, int Z,
	char const * connectname, GridLocation_t location,
        GridConnectivityType_t type, PointSetType_t ptset_type, int npnts,
        int const * pnts, char const * donorname, ZoneType_t donor_zonetype,
        PointSetType_t donor_ptset_type, DataType_t donor_datatype,
        int ndata_donor, void const *donor_data, int *I);
/*%typecast donor_data:donor_datatype */
/*%output I */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_write_short(int file_number, int B, int Z,
	char const * connectname, GridLocation_t location,
        GridConnectivityType_t type, PointSetType_t ptset_type,
        int npnts, int const * pnts, char const * donorname, int *I);
/*%output I */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_read_short(int file_number, int B, int Z, int I,
	int *pnts);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity1to1_t Nodes in a zone            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n1to1(int fn, int B, int Z, int *n1to1);
/*%output n1to1 */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_read(int fn, int B, int Z, int I, char *connectname,
	char *donorname, int *range, int *donor_range, int *transform);
/*%output range(6), donor_range(6), transform(3) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_id(int fn, int B, int Z, int I, double *one21_id);
/*%output one21_id */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_write(int fn, int B, int Z, char const * connectname,
	char const * donorname, int const * range, int const * donor_range,
        int const * transform, int *I);
/*%output I */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read all GridConnectivity1to1_t Nodes of a base                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n1to1_global(int fn, int B, int *n1to1_global);
/*%output n1to1_global */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_read_global(int fn, int B, char **connectname,
	char **zonename, char **donorname, int **range, int **donor_range,
        int **transform);
/*%output connectname,zonename,donorname,range(:),donor_range(:),transform(:)*/
/*%external */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BC_t Nodes                                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nbocos(int fn, int B, int Z, int *nbocos);
/*%output nbocos */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_boco_info(int fn, int B, int Z, int BC, char *boconame,
	BCType_t *bocotype, PointSetType_t *ptset_type, int *npnts,
	int *NormalIndex, int *NormalListFlag, DataType_t *NormalDataType,
	int *ndataset);
/*%output bocotype,ptset_type,npnts,NormalListFlag,NormalDataType,ndataset */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_boco_read(int fn, int B, int Z, int BC, int *pnts,
	void *NormalList);
/*%typecast NormalList:cgns_get_boco_type(fn,B,Z,BC) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_boco_id(int fn, int B, int Z, int BC, double *boco_id);
/*%output boco_id */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_boco_write(int file_number, int B, int Z,
	char const * boconame, BCType_t bocotype, PointSetType_t ptset_type,
        int npnts, int const * pnts, int *BC);
/*%output BC */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_boco_normal_write(int file_number, int B, int Z, int BC,
	int const * NormalIndex, int NormalListFlag,
        DataType_t NormalDataType, void const * NormalList);
/*%typecast NormalList:NormalDataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCDataSet_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_dataset_read(int fn, int B, int Z, int BC, int DS, char *name,
	BCType_t *BCType, int *DirichletFlag, int *NeumannFlag);
/*%output BCType,DirichletFlag,NeumannFlag */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_dataset_write(int file_number, int B, int Z, int BC,
	char const * name, BCType_t BCType, int *Dset);
/*%output Dset */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_bcdataset_write(char *name, BCType_t BCType,
	BCDataType_t BCDataType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_bcdataset_info(int *n_dataset);
/*%output n_dataset */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_bcdataset_read(int index, char *name, BCType_t *BCType,
	int *DirichletFlag, int *NeumannFlag);
/*%output BCType,DirichletFlag,NeumannFlag */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCData_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset,
        BCDataType_t BCDataType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DiscreteData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ndiscrete(int file_number, int B, int Z, int *ndiscrete);
/*%output ndiscrete */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_discrete_read(int file_number, int B, int Z, int D,
	char *discrete_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

CGNSDLL int cg_discrete_write(int file_number, int B, int Z,
	char const * discrete_name, int *D);
/*%output D */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RigidGridMotion_t Nodes				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n_rigid_motions(int file_number, int B, int Z,
	int *n_rigid_motions);
/*%output n_rigid_motions */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_rigid_motion_read(int file_number, int B, int Z, int R,
	char *name, RigidGridMotionType_t *type);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_rigid_motion_write(int file_number, int B, int Z,
	char const * name, RigidGridMotionType_t type, int *R);
/*%output R */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ArbitraryGridMotion_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n_arbitrary_motions(int file_number, int B, int Z,
	int *n_arbitrary_motions);
/*%output n_arbitrary_motions */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_arbitrary_motion_read(int file_number, int B, int Z, int A,
	char *name, ArbitraryGridMotionType_t *type);
/*%output type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_arbitrary_motion_write(int file_number, int B, int Z,
	char const * amotionname, ArbitraryGridMotionType_t type, int *A);
/*%output A */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BaseIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_biter_read(int file_number, int B, char *bitername, int *nsteps);
/*%output nsteps */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_biter_write(int file_number, int B, char const * bitername, int nsteps);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ZoneIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ziter_read(int file_number, int B, int Z, char *zitername);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */

CGNSDLL int cg_ziter_write(int file_number, int B, int Z, char const * zitername);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/timedep.html */


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Gravity_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_gravity_read(int file_number, int B, float *gravity_vector);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_gravity_write(int file_number, int B, float const *gravity_vector);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Axisymmetry_t Nodes                               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_axisym_read(int file_number, int B, float *ref_point,
	float *axis);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_axisym_write(int file_number, int B, float const *ref_point,
  	float const *axis);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RotatingCoordinates_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_rotating_read(float *rot_rate, float *rot_center);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

CGNSDLL int cg_rotating_write(float const *rot_rate, float const *rot_center);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/WallFunction_t Nodes   	         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bc_wallfunction_read(int file_number, int B, int Z, int BC,
	WallFunctionType_t *WallFunctionType);
/*%output WallFunctionType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_bc_wallfunction_write(int file_number, int B, int Z, int BC,
	WallFunctionType_t WallFunctionType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/Area_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bc_area_read(int file_number, int B, int Z, int BC,
	AreaType_t *AreaType, float *SurfaceArea, char *RegionName);
/*%output AreaType,SurfaceArea */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

CGNSDLL int cg_bc_area_write(int file_number, int B, int Z, int BC,
	AreaType_t AreaType, float SurfaceArea, char const *RegionName);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivityProperty_t/Periodic_t Nodes       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conn_periodic_read(int file_number, int B, int Z, int I,
	float *RotationCenter, float *RotationAngle, float *Translation);
/*%output RotationCenter(3), RotationAngle(3), Translation(3) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_periodic_write(int file_number, int B, int Z, int I,
	float const *RotationCenter, float const *RotationAngle,
	float const *Translation);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_periodic_write(int file_number, int B, int Z, int I,
	float const *RotationCenter, float const *RotationAngle,
	float const *Translation);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_periodic_read(int file_number, int B, int Z, int I,
	float *RotationCenter, float *RotationAngle, float *Translation);
/*%output RotationCenter(3), RotationAngle(3), Translation(3) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *   Read and write GridConnectivityProperty_t/AverageInterface_t Nodes  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conn_average_read(int file_number, int B, int Z, int I,
	AverageInterfaceType_t *AverageInterfaceType);
/*%output AverageInterfaceType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_conn_average_write(int file_number, int B, int Z, int I,
	AverageInterfaceType_t AverageInterfaceType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_average_write(int file_number, int B, int Z, int I,
	AverageInterfaceType_t AverageInterfaceType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

CGNSDLL int cg_1to1_average_read(int file_number, int B, int Z, int I,
	AverageInterfaceType_t *AverageInterfaceType);
/*%output AverageInterfaceType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Variable Argument List Functions                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_goto(int file_number, int B, ...);
/*%external */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */
CGNSDLL int cg_gorel(int file_number, ...);
/*%external */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */
CGNSDLL int cg_gopath(int file_number, const char *path);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */
CGNSDLL int cg_golist(int file_number, int B, int depth, char **label,
	int *num);
/*%external */
/*%input label(depth,32),num(depth) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */
CGNSDLL int cg_where(int *file_number, int *B, int *depth, char **label,
	int *num);
/*%external */
/*%output label(CG_MAX_GOTO_DEPTH,32),num(CG_MAX_GOTO_DEPTH) */
/*%output file_number,B,depth */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ConvergenceHistory_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_convergence_read(int *iterations, char **NormDefinitions);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_convergence_write(int iterations, char const * NormDefinitions);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ReferenceState_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_state_read(char **StateDescription);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */
CGNSDLL int cg_state_write(char const * StateDescription);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowEquationSet_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_equationset_read(int *EquationDimension,
        int *GoverningEquationsFlag, int *GasModelFlag,
        int *ViscosityModelFlag,     int *ThermalConductivityModelFlag,
        int *TurbulenceClosureFlag,  int *TurbulenceModelFlag);
/*%output EquationDimension,GoverningEquationsFlag,GasModelFlag,ViscosityModelFlag,ThermalConductivityModelFlag,TurbulenceClosureFlag,TurbulenceModelFlag */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_equationset_chemistry_read(int *ThermalRelaxationFlag,
	int *ChemicalKineticsFlag);
/*%output ThermalRelaxationFlag,ChemicalKineticsFlag */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_equationset_elecmagn_read(int *ElecFldModelFlag,
	int *MagnFldModelFlag, int *ConductivityModelFlag);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_equationset_write(int EquationDimension);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GoverningEquations_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_governing_read(GoverningEquationsType_t *EquationsType);
/*%output EquationsType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_governing_write(GoverningEquationsType_t Equationstype);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Diffusion Model Nodes                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_diffusion_read(int *diffusion_model);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_diffusion_write(int const * diffusion_model);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GasModel_t, ViscosityModel_t,                     *
 *      ThermalConductivityModel_t, TurbulenceClosure_t,                 *
 *      TurbulenceModel_t, ThermalRelaxationModel_t,                     *
 *      ChemicalKineticsModel_t, EMElectricFieldModel_t,                 *
 *      EMMagneticFieldModel_t Nodes                                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_model_read(char const *ModelLabel, ModelType_t *ModelType);
/*%output ModelType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

CGNSDLL int cg_model_write(char const * ModelLabel, ModelType_t ModelType);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataArray_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_narrays(int *narrays);
/*%output narrays */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_array_info(int A, char *ArrayName, DataType_t *DataType,
        int *DataDimension, int *DimensionVector);
/*%output DataType, DataDimension */
/*%inout DimensionVector(3) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_array_read(int A, void *Data);
/*%typecast Data:cgns_get_array_type(A) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_array_read_as(int A, DataType_t type, void *Data);
/*%typecast Data:type */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_array_write(char const * ArrayName, DataType_t DataType,
        int DataDimension, int const * DimensionVector, void const * Data);
/*%typecast Data:DataType */
/*%input  DimensionVector(DataDimension) */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write UserDefinedData_t Nodes - new in version 2.1      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nuser_data(int *nuser_data);
/*%output nuser_data */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_user_data_read(int Index, char *user_data_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_user_data_write(char const * user_data_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IntegralData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nintegrals(int *nintegrals);
/*%output nintegrals */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_integral_read(int IntegralDataIndex, char *IntegralDataName);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

CGNSDLL int cg_integral_write(char const * IntegralDataName);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Rind_t Nodes                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_rind_read(int *RindData);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

CGNSDLL int cg_rind_write(int const * RindData);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Descriptor_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ndescriptors(int *ndescriptors);
/*%output ndescriptors */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/descriptor.html */

CGNSDLL int cg_descriptor_read(int descr_no, char *descr_name, char **descr_text);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/descriptor.html */

CGNSDLL int cg_descriptor_write(char const * descr_name, char const * descr_text);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/descriptor.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalUnits_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nunits(int *nunits);
/*%output nunits */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_units_read(MassUnits_t *mass, LengthUnits_t *length, TimeUnits_t *time,
        TemperatureUnits_t *temperature, AngleUnits_t *angle);
/*%output mass, length, time,temperature, angle */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_units_write(MassUnits_t mass, LengthUnits_t length, TimeUnits_t time,
        TemperatureUnits_t temperature, AngleUnits_t angle);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_unitsfull_read(MassUnits_t *mass, LengthUnits_t *length,
	TimeUnits_t *time, TemperatureUnits_t *temperature, AngleUnits_t *angle,
	ElectricCurrentUnits_t *current, SubstanceAmountUnits_t *amount,
	LuminousIntensityUnits_t *intensity);
/*%output mass, length, time,temperature, angle,current,amount,intensity */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_unitsfull_write(MassUnits_t mass, LengthUnits_t length,
	TimeUnits_t time, TemperatureUnits_t temperature, AngleUnits_t angle,
	ElectricCurrentUnits_t current, SubstanceAmountUnits_t amount,
	LuminousIntensityUnits_t intensity);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalExponents_t Nodes                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_exponents_info(DataType_t *DataType);
/*%output DataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_nexponents(int *numexp);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_exponents_read(void *exponents);
/*%typecast exponents:cg_exponents_info() */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_exponents_write(DataType_t DataType, void const * exponents);
/*%typecast exponents:DataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_expfull_read(void *exponents);
/*%typecast exponents:cg_exponents_info() */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_expfull_write(DataType_t DataType, void const * exponents);
/*%typecast exponents:DataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataConversion_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conversion_info(DataType_t *DataType);
/*%output DataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_conversion_read(void *ConversionFactors);
/*%typecast ConversionFactors:cg_conversion_info() */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_conversion_write(DataType_t DataType, void const * ConversionFactors);
/*%typecast ConversionFactors:DataType */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataClass_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_dataclass_read(DataClass_t *dataclass);
/*%output dataclass */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

CGNSDLL int cg_dataclass_write(DataClass_t dataclass);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridLocation_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_gridlocation_read(GridLocation_t *GridLocation);
/*%output GridLocation */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

CGNSDLL int cg_gridlocation_write(GridLocation_t GridLocation);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Ordinal_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ordinal_read(int *Ordinal);
/*%output Ordinal */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/descriptor.html */
CGNSDLL int cg_ordinal_write(int Ordinal);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/descriptor.html */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IndexArray/Range_t Nodes  - new in version 2.4    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ptset_info(PointSetType_t *ptset_type, int *npnts);
/*%output ptset_type, npnts*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

CGNSDLL int cg_ptset_write(PointSetType_t ptset_type, int npnts, int const *pnts);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

CGNSDLL int cg_ptset_read(int *pnts);
/*%output pnts*/
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Link Handling Functions - new in version 2.1                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_is_link(int *path_length);
/*%output path_length*/
/*url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/links.html */

CGNSDLL int cg_link_read(char **filename, char **link_path);
/*url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/links.html */

CGNSDLL int cg_link_write(char const * nodename, char const * filename,
	char const * name_in_file);
/*url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/links.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      General Delete Function						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_delete_node(char *node_name);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/navigating.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Free library malloced memory					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_free(void *data);
/*%ignore */
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Error Handling Functions                                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL const char *cg_get_error(void);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/error.html */
/*%retname msg */
CGNSDLL void cg_error_exit(void);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/error.html */
CGNSDLL void cg_error_print(void);
/*%url http://www.grc.nasa.gov/WWW/cgns/CGNS_docs_rel25/midlevel/error.html */

#ifdef __cplusplus
}
#endif
#endif
