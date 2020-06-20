/* ------------------------------------------------------------------------- *
 * CGNS - CFD General Notation System (http://www.cgns.org)                  *
 * CGNS/MLL - Mid-Level Library header file                                  *
 * Please see cgnsconfig.h file for this local installation configuration    *
 * ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- *

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

 * -------------------------------------------------------------------------
 *
 *  DEVELOPER'S NOTE:
 *    When adding a defined constant to this file, also add the same defined
 *    constant to cgns_f.F90
 *
 * ------------------------------------------------------------------------- */

/************
 * This file is based on cgnslib.h in the cgnslib_3.4.1 distribution.
 *
 * It is funcationally identical to the file in the official CGNS
 * distribution, except for the annotations added for C2mex.
 *
 * Xiangmin Jiao, jiao@ams.sunysb.edu, 06/10/2020.
 */

/*%default_strlen 32 */
/*%default_strfree cg_free */
/*%default_retlast 1 */
/*%default_retname ierr */
/* All macros start with CG_ will be treated as enum */
/*%enumdef CG_ */


#ifndef CGNSLIB_H
#define CGNSLIB_H

#define CGNS_VERSION 3401
#define CGNS_DOTVERS 3.40

#define CGNS_COMPATVERSION 2540
#define CGNS_COMPATDOTVERS 2.54

#include "cgnstypes.h"

#if defined(C2MEX) && defined(CG_BUILD_64BIT)
    typedef long long cgsize_t;
#endif
#if CG_BUILD_SCOPE
# ifndef CGNS_SCOPE_ENUMS
#  define CGNS_SCOPE_ENUMS
# endif
#else
# ifdef CGNS_SCOPE_ENUMS
#  undef CGNS_SCOPE_ENUMS
# endif
#endif

#ifndef CGNSDLL
# ifdef _WIN32
#  if defined(BUILD_DLL)
#    define CGNSDLL __declspec(dllexport)
#  elif defined(USE_DLL)
#    define CGNSDLL __declspec(dllimport)
#  else
#    define CGNSDLL
#  endif
# else
#  define CGNSDLL
# endif
#endif

#ifdef CGNS_SCOPE_ENUMS
/* set scope prefix for values only */
#define CGNS_ENUMV( e ) CG_ ## e
/* set scope prefix for types */
#define CGNS_ENUMT( e ) CG_ ## e
/* set scope prefix for defines */
#define CGNS_ENUMD( e ) CG_ ## e
/* set scope prefix for variables (lowercase same as functions) */
#define CGNS_ENUMF( e ) cg_ ## e
#else
#define CGNS_ENUMV( e ) e
#define CGNS_ENUMT( e ) e
#define CGNS_ENUMD( e ) e
#define CGNS_ENUMF( e ) e
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      modes for cgns file                                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define CG_MODE_READ	0
#define CG_MODE_WRITE	1
#define CG_MODE_MODIFY  2
#define CG_MODE_CLOSED  3

/* file types */

#define CG_FILE_NONE  0
#define CG_FILE_ADF   1
#define CG_FILE_HDF5  2
#define CG_FILE_ADF2  3

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

#define CG_CONFIG_ERROR      1
#define CG_CONFIG_COMPRESS   2
#define CG_CONFIG_SET_PATH   3
#define CG_CONFIG_ADD_PATH   4
#define CG_CONFIG_FILE_TYPE  5
#define CG_CONFIG_RIND_INDEX 6

#define CG_CONFIG_HDF5_COMPRESS   201
#define CG_CONFIG_HDF5_MPI_COMM   202

/* note: CG_CONFIG_RIND_ZERO is obsolete and considered a bug.  Users are given
 *       the option only for backwards compatibility */
#define CG_CONFIG_RIND_ZERO (void*)0
#define CG_CONFIG_RIND_CORE (void*)1

#ifdef __cplusplus
extern "C" {
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *  Enumerations:  if any of this enumerations need to be modified,      *
 *	           the corresponding namelist must also be updated.      *
 *                                                                       *
 *  Any addition to an enum should be done as an addition at end of list *
 *  with an explicit declaration of the corresponding integer.           *
 *  This is required for enums stored as integers in the CGNS file or    *
 *  used in applications.                                                *
 *                                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Dimensional Units                                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( MassUnitsNull )       =CG_Null,
  CGNS_ENUMV( MassUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Kilogram )            =2,
  CGNS_ENUMV( Gram )                =3,
  CGNS_ENUMV( Slug )                =4,
  CGNS_ENUMV( PoundMass )           =5
} CGNS_ENUMT( MassUnits_t );

typedef enum {
  CGNS_ENUMV( LengthUnitsNull )       =CG_Null,
  CGNS_ENUMV( LengthUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Meter )                 =2,
  CGNS_ENUMV( Centimeter )            =3,
  CGNS_ENUMV( Millimeter )            =4,
  CGNS_ENUMV( Foot )                  =5,
  CGNS_ENUMV( Inch )                  =6
} CGNS_ENUMT( LengthUnits_t );

typedef enum {
  CGNS_ENUMV( TimeUnitsNull )       =CG_Null,
  CGNS_ENUMV( TimeUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Second )              =2
} CGNS_ENUMT( TimeUnits_t );

typedef enum {
  CGNS_ENUMV( TemperatureUnitsNull )       =CG_Null,
  CGNS_ENUMV( TemperatureUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Kelvin )                     =2,
  CGNS_ENUMV( Celsius )                    =3,
  CGNS_ENUMV( Rankine )                    =4,
  CGNS_ENUMV( Fahrenheit )                 =5
} CGNS_ENUMT( TemperatureUnits_t );

typedef enum {
  CGNS_ENUMV( AngleUnitsNull )       =CG_Null,
  CGNS_ENUMV( AngleUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Degree )               =2,
  CGNS_ENUMV( Radian )               =3
} CGNS_ENUMT( AngleUnits_t );

typedef enum {
  CGNS_ENUMV( ElectricCurrentUnitsNull )       =CG_Null,
  CGNS_ENUMV( ElectricCurrentUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Ampere )                         =2,
  CGNS_ENUMV( Abampere )                       =3,
  CGNS_ENUMV( Statampere )                     =4,
  CGNS_ENUMV( Edison )                         =5,
  CGNS_ENUMV( auCurrent )                      =6
} CGNS_ENUMT( ElectricCurrentUnits_t );

typedef enum {
  CGNS_ENUMV( SubstanceAmountUnitsNull )       =CG_Null,
  CGNS_ENUMV( SubstanceAmountUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Mole )                           =2,
  CGNS_ENUMV( Entities )                       =3,
  CGNS_ENUMV( StandardCubicFoot )              =4,
  CGNS_ENUMV( StandardCubicMeter )             =5
} CGNS_ENUMT( SubstanceAmountUnits_t );

typedef enum {
  CGNS_ENUMV( LuminousIntensityUnitsNull )       =CG_Null,
  CGNS_ENUMV( LuminousIntensityUnitsUserDefined )=CG_UserDefined,
  CGNS_ENUMV( Candela )                          =2,
  CGNS_ENUMV( Candle )				 =3,
  CGNS_ENUMV( Carcel )				 =4,
  CGNS_ENUMV( Hefner )				 =5,
  CGNS_ENUMV( Violle )				 =6
} CGNS_ENUMT( LuminousIntensityUnits_t );

#define NofValidMassUnits              6
#define NofValidLengthUnits            7
#define NofValidTimeUnits              3
#define NofValidTemperatureUnits       6
#define NofValidAngleUnits             4
#define NofValidElectricCurrentUnits   7
#define NofValidSubstanceAmountUnits   6
#define NofValidLuminousIntensityUnits 7

extern CGNSDLL const char * MassUnitsName[NofValidMassUnits];
extern CGNSDLL const char * LengthUnitsName[NofValidLengthUnits];
extern CGNSDLL const char * TimeUnitsName[NofValidTimeUnits];
extern CGNSDLL const char * TemperatureUnitsName[NofValidTemperatureUnits];
extern CGNSDLL const char * AngleUnitsName[NofValidAngleUnits];
extern CGNSDLL const char * ElectricCurrentUnitsName[NofValidElectricCurrentUnits];
extern CGNSDLL const char * SubstanceAmountUnitsName[NofValidSubstanceAmountUnits];
extern CGNSDLL const char * LuminousIntensityUnitsName[NofValidLuminousIntensityUnits];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data Class                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( DataClassNull ) =CG_Null,
  CGNS_ENUMV( DataClassUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Dimensional ) =2,
  CGNS_ENUMV( NormalizedByDimensional ) =3,
  CGNS_ENUMV( NormalizedByUnknownDimensional ) =4,
  CGNS_ENUMV( NondimensionalParameter ) =5,
  CGNS_ENUMV( DimensionlessConstant ) =6
} CGNS_ENUMT( DataClass_t );

#define NofValidDataClass 7

extern CGNSDLL const char * DataClassName[NofValidDataClass];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Location
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( GridLocationNull ) =CG_Null,
  CGNS_ENUMV( GridLocationUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Vertex ) =2,
  CGNS_ENUMV( CellCenter ) =3,
  CGNS_ENUMV( FaceCenter ) =4,
  CGNS_ENUMV( IFaceCenter ) =5,
  CGNS_ENUMV( JFaceCenter ) =6,
  CGNS_ENUMV( KFaceCenter ) =7,
  CGNS_ENUMV( EdgeCenter ) =8
} CGNS_ENUMT( GridLocation_t );

#define NofValidGridLocation 9

extern CGNSDLL const char * GridLocationName[NofValidGridLocation];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      BCData Types: Can not add types and stay forward compatible      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( BCDataTypeNull ) =CG_Null,
  CGNS_ENUMV( BCDataTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Dirichlet ) =2,
  CGNS_ENUMV( Neumann ) =3
} CGNS_ENUMT( BCDataType_t );

#define NofValidBCDataTypes 4

extern CGNSDLL const char * BCDataTypeName[NofValidBCDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Grid Connectivity Types 					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( GridConnectivityTypeNull ) =CG_Null,
  CGNS_ENUMV( GridConnectivityTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Overset ) =2,
  CGNS_ENUMV( Abutting ) =3,
  CGNS_ENUMV( Abutting1to1 ) =4
} CGNS_ENUMT( GridConnectivityType_t );

#define NofValidGridConnectivityTypes 5

extern CGNSDLL const char * GridConnectivityTypeName[NofValidGridConnectivityTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	Point Set Types: Can't add types and stay forward compatible
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( PointSetTypeNull ) =CG_Null,
  CGNS_ENUMV( PointSetTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( PointList ) =2,
  CGNS_ENUMV( PointListDonor ) =3,
  CGNS_ENUMV( PointRange ) =4,
  CGNS_ENUMV( PointRangeDonor ) =5,
  CGNS_ENUMV( ElementRange ) =6,
  CGNS_ENUMV( ElementList ) =7,
  CGNS_ENUMV( CellListDonor ) =8
} CGNS_ENUMT( PointSetType_t );

#define NofValidPointSetTypes 9

extern CGNSDLL const char * PointSetTypeName[NofValidPointSetTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Governing Equations and Physical Models Types                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( GoverningEquationsNull ) =CG_Null,
  CGNS_ENUMV( GoverningEquationsUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( FullPotential ) =2,
  CGNS_ENUMV( Euler ) =3,
  CGNS_ENUMV( NSLaminar ) =4,
  CGNS_ENUMV( NSTurbulent ) =5,
  CGNS_ENUMV( NSLaminarIncompressible ) =6,
  CGNS_ENUMV( NSTurbulentIncompressible ) =7
} CGNS_ENUMT( GoverningEquationsType_t );

/* Any model type will accept both ModelTypeNull and ModelTypeUserDefined.
** The following models will accept these values as valid...
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
  CGNS_ENUMV( ModelTypeNull ) =CG_Null,
  CGNS_ENUMV( ModelTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Ideal ) =2,
  CGNS_ENUMV( VanderWaals ) =3,
  CGNS_ENUMV( Constant ) =4,
  CGNS_ENUMV( PowerLaw ) =5,
  CGNS_ENUMV( SutherlandLaw ) =6,
  CGNS_ENUMV( ConstantPrandtl ) =7,
  CGNS_ENUMV( EddyViscosity ) =8,
  CGNS_ENUMV( ReynoldsStress ) =9,
  CGNS_ENUMV( ReynoldsStressAlgebraic ) =10,
  CGNS_ENUMV( Algebraic_BaldwinLomax ) =11,
  CGNS_ENUMV( Algebraic_CebeciSmith ) =12,
  CGNS_ENUMV( HalfEquation_JohnsonKing ) =13,
  CGNS_ENUMV( OneEquation_BaldwinBarth ) =14,
  CGNS_ENUMV( OneEquation_SpalartAllmaras ) =15,
  CGNS_ENUMV( TwoEquation_JonesLaunder ) =16,
  CGNS_ENUMV( TwoEquation_MenterSST ) =17,
  CGNS_ENUMV( TwoEquation_Wilcox ) =18,
  CGNS_ENUMV( CaloricallyPerfect ) =19,
  CGNS_ENUMV( ThermallyPerfect ) =20,
  CGNS_ENUMV( ConstantDensity ) =21,
  CGNS_ENUMV( RedlichKwong ) =22,
  CGNS_ENUMV( Frozen ) =23,
  CGNS_ENUMV( ThermalEquilib ) =24,
  CGNS_ENUMV( ThermalNonequilib ) =25,
  CGNS_ENUMV( ChemicalEquilibCurveFit ) =26,
  CGNS_ENUMV( ChemicalEquilibMinimization ) =27,
  CGNS_ENUMV( ChemicalNonequilib ) =28,
  CGNS_ENUMV( EMElectricField ) =29,
  CGNS_ENUMV( EMMagneticField ) =30,
  CGNS_ENUMV( EMConductivity ) =31,
  CGNS_ENUMV( Voltage ) =32,
  CGNS_ENUMV( Interpolated ) =33,
  CGNS_ENUMV( Equilibrium_LinRessler ) =34,
  CGNS_ENUMV( Chemistry_LinRessler ) =35
} CGNS_ENUMT( ModelType_t );

#define NofValidGoverningEquationsTypes 8
#define NofValidModelTypes 36

extern CGNSDLL const char * GoverningEquationsTypeName[NofValidGoverningEquationsTypes];
extern CGNSDLL const char * ModelTypeName[NofValidModelTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 * 	Boundary Condition Types					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( BCTypeNull ) =CG_Null,
  CGNS_ENUMV( BCTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( BCAxisymmetricWedge ) =2,
  CGNS_ENUMV( BCDegenerateLine ) =3,
  CGNS_ENUMV( BCDegeneratePoint ) =4,
  CGNS_ENUMV( BCDirichlet ) =5,
  CGNS_ENUMV( BCExtrapolate ) =6,
  CGNS_ENUMV( BCFarfield ) =7,
  CGNS_ENUMV( BCGeneral ) =8,
  CGNS_ENUMV( BCInflow ) =9,
  CGNS_ENUMV( BCInflowSubsonic ) =10,
  CGNS_ENUMV( BCInflowSupersonic ) =11,
  CGNS_ENUMV( BCNeumann ) =12,
  CGNS_ENUMV( BCOutflow ) =13,
  CGNS_ENUMV( BCOutflowSubsonic ) =14,
  CGNS_ENUMV( BCOutflowSupersonic ) =15,
  CGNS_ENUMV( BCSymmetryPlane ) =16,
  CGNS_ENUMV( BCSymmetryPolar ) =17,
  CGNS_ENUMV( BCTunnelInflow ) =18,
  CGNS_ENUMV( BCTunnelOutflow ) =19,
  CGNS_ENUMV( BCWall ) =20,
  CGNS_ENUMV( BCWallInviscid ) =21,
  CGNS_ENUMV( BCWallViscous ) =22,
  CGNS_ENUMV( BCWallViscousHeatFlux ) =23,
  CGNS_ENUMV( BCWallViscousIsothermal ) =24,
  CGNS_ENUMV( FamilySpecified ) =25
} CGNS_ENUMT( BCType_t );

#define NofValidBCTypes 26

extern CGNSDLL const char * BCTypeName[NofValidBCTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Data types:  Can not add data types and stay forward compatible  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( DataTypeNull ) =CG_Null,
  CGNS_ENUMV( DataTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Integer ) =2,
  CGNS_ENUMV( RealSingle ) =3,
  CGNS_ENUMV( RealDouble ) =4,
  CGNS_ENUMV( Character ) =5,
  CGNS_ENUMV( LongInteger ) =6
} CGNS_ENUMT( DataType_t );
/*%typemap CG_Integer=>int32,CG_RealSingle=>single,CG_RealDouble=>double,CG_Character=>char,CG_LongInteger=>int64, */

#define NofValidDataTypes 7

extern CGNSDLL const char * DataTypeName[NofValidDataTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Element types                                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* PLEASE ALSO UPDATE the cgnslib.h/el_size static table */

typedef enum {
  CGNS_ENUMV( ElementTypeNull  ) =CG_Null,
  CGNS_ENUMV( ElementTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( NODE ) =2,
  CGNS_ENUMV( BAR_2 ) =3,
  CGNS_ENUMV( BAR_3 ) =4,
  CGNS_ENUMV( TRI_3 ) =5,
  CGNS_ENUMV( TRI_6 ) =6,
  CGNS_ENUMV( QUAD_4 ) =7,
  CGNS_ENUMV( QUAD_8 ) =8,
  CGNS_ENUMV( QUAD_9 ) =9,
  CGNS_ENUMV( TETRA_4 ) =10,
  CGNS_ENUMV( TETRA_10 ) =11,
  CGNS_ENUMV( PYRA_5 ) =12,
  CGNS_ENUMV( PYRA_14 ) =13,
  CGNS_ENUMV( PENTA_6 ) =14,
  CGNS_ENUMV( PENTA_15 ) =15,
  CGNS_ENUMV( PENTA_18 ) =16,
  CGNS_ENUMV( HEXA_8 ) =17,
  CGNS_ENUMV( HEXA_20 ) =18,
  CGNS_ENUMV( HEXA_27 ) =19,
  CGNS_ENUMV( MIXED ) =20,
  CGNS_ENUMV( PYRA_13 ) =21,
  CGNS_ENUMV( NGON_n ) =22,
  CGNS_ENUMV( NFACE_n ) =23,
  CGNS_ENUMV( BAR_4 ) =24,
  CGNS_ENUMV( TRI_9 ) =25,
  CGNS_ENUMV( TRI_10 ) =26,
  CGNS_ENUMV( QUAD_12 ) =27,
  CGNS_ENUMV( QUAD_16 ) =28,
  CGNS_ENUMV( TETRA_16 ) =29,
  CGNS_ENUMV( TETRA_20 ) =30,
  CGNS_ENUMV( PYRA_21 ) =31,
  CGNS_ENUMV( PYRA_29 ) =32,
  CGNS_ENUMV( PYRA_30 ) =33,
  CGNS_ENUMV( PENTA_24 ) =34,
  CGNS_ENUMV( PENTA_38 ) =35,
  CGNS_ENUMV( PENTA_40 ) =36,
  CGNS_ENUMV( HEXA_32 ) =37,
  CGNS_ENUMV( HEXA_56 ) =38,
  CGNS_ENUMV( HEXA_64 ) =39,
  CGNS_ENUMV( BAR_5 )=40,
  CGNS_ENUMV( TRI_12 )=41,
  CGNS_ENUMV( TRI_15 )=42,
  CGNS_ENUMV( QUAD_P4_16 )=43,
  CGNS_ENUMV( QUAD_25 )=44,
  CGNS_ENUMV( TETRA_22 )=45,
  CGNS_ENUMV( TETRA_34 )=46,
  CGNS_ENUMV( TETRA_35 )=47,
  CGNS_ENUMV( PYRA_P4_29 )=48,
  CGNS_ENUMV( PYRA_50 )=49,
  CGNS_ENUMV( PYRA_55 )=50,
  CGNS_ENUMV( PENTA_33 )=51,
  CGNS_ENUMV( PENTA_66 )=52,
  CGNS_ENUMV( PENTA_75 )=53,
  CGNS_ENUMV( HEXA_44 )=54,
  CGNS_ENUMV( HEXA_98 )=55,
  CGNS_ENUMV( HEXA_125 )=56
} CGNS_ENUMT( ElementType_t );

#define NofValidElementTypes 57

extern CGNSDLL const char * ElementTypeName[NofValidElementTypes];

#ifdef CGNS_SCOPE_ENUMS
#define  CG_NPE_NODE         1
#define  CG_NPE_BAR_2        2
#define  CG_NPE_BAR_3        3
#define  CG_NPE_TRI_3        3
#define  CG_NPE_TRI_6        6
#define  CG_NPE_QUAD_4       4
#define  CG_NPE_QUAD_8       8
#define  CG_NPE_QUAD_9       9
#define  CG_NPE_TETRA_4      4
#define  CG_NPE_TETRA_10    10
#define  CG_NPE_PYRA_5       5
#define  CG_NPE_PYRA_13     13
#define  CG_NPE_PYRA_14     14
#define  CG_NPE_PENTA_6      6
#define  CG_NPE_PENTA_15    15
#define  CG_NPE_PENTA_18    18
#define  CG_NPE_HEXA_8       8
#define  CG_NPE_HEXA_20     20
#define  CG_NPE_HEXA_27     27
#define  CG_NPE_MIXED        0
#define  CG_NPE_NGON_n       0
#define  CG_NPE_NFACE_n      0
#define  CG_NPE_BAR_4        4
#define  CG_NPE_TRI_9        9
#define  CG_NPE_TRI_10      10
#define  CG_NPE_QUAD_12     12
#define  CG_NPE_QUAD_16     16
#define  CG_NPE_TETRA_16    16
#define  CG_NPE_TETRA_20    20
#define  CG_NPE_PYRA_21     21
#define  CG_NPE_PYRA_29     29
#define  CG_NPE_PYRA_30     30
#define  CG_NPE_PENTA_24    24
#define  CG_NPE_PENTA_38    38
#define  CG_NPE_PENTA_40    40
#define  CG_NPE_HEXA_32     32
#define  CG_NPE_HEXA_56     56
#define  CG_NPE_HEXA_64     64
#define  CG_NPE_BAR_5        5
#define  CG_NPE_TRI_12      12
#define  CG_NPE_TRI_15      15
#define  CG_NPE_QUAD_P4_16  16
#define  CG_NPE_QUAD_25     25
#define  CG_NPE_TETRA_22    22
#define  CG_NPE_TETRA_34    34
#define  CG_NPE_TETRA_35    35
#define  CG_NPE_PYRA_P4_29  29
#define  CG_NPE_PYRA_50     50
#define  CG_NPE_PYRA_55     55
#define  CG_NPE_PENTA_33    33
#define  CG_NPE_PENTA_66    66
#define  CG_NPE_PENTA_75    75
#define  CG_NPE_HEXA_44     44
#define  CG_NPE_HEXA_98     98
#define  CG_NPE_HEXA_125   125
#else
#define  NPE_NODE         1
#define  NPE_BAR_2        2
#define  NPE_BAR_3        3
#define  NPE_TRI_3        3
#define  NPE_TRI_6        6
#define  NPE_QUAD_4       4
#define  NPE_QUAD_8       8
#define  NPE_QUAD_9       9
#define  NPE_TETRA_4      4
#define  NPE_TETRA_10    10
#define  NPE_PYRA_5       5
#define  NPE_PYRA_13     13
#define  NPE_PYRA_14     14
#define  NPE_PENTA_6      6
#define  NPE_PENTA_15    15
#define  NPE_PENTA_18    18
#define  NPE_HEXA_8       8
#define  NPE_HEXA_20     20
#define  NPE_HEXA_27     27
#define  NPE_MIXED        0
#define  NPE_NGON_n       0
#define  NPE_NFACE_n      0
#define  NPE_BAR_4        4
#define  NPE_TRI_9        9
#define  NPE_TRI_10      10
#define  NPE_QUAD_12     12
#define  NPE_QUAD_16     16
#define  NPE_TETRA_16    16
#define  NPE_TETRA_20    20
#define  NPE_PYRA_21     21
#define  NPE_PYRA_29     29
#define  NPE_PYRA_30     30
#define  NPE_PENTA_24    24
#define  NPE_PENTA_38    38
#define  NPE_PENTA_40    40
#define  NPE_HEXA_32     32
#define  NPE_HEXA_56     56
#define  NPE_HEXA_64     64
#define  NPE_BAR_5        5
#define  NPE_TRI_12      12
#define  NPE_TRI_15      15
#define  NPE_QUAD_P4_16  16
#define  NPE_QUAD_25     25
#define  NPE_TETRA_22    22
#define  NPE_TETRA_34    34
#define  NPE_TETRA_35    35
#define  NPE_PYRA_P4_29  29
#define  NPE_PYRA_50     50
#define  NPE_PYRA_55     55
#define  NPE_PENTA_33    33
#define  NPE_PENTA_66    66
#define  NPE_PENTA_75    75
#define  NPE_HEXA_44     44
#define  NPE_HEXA_98     98
#define  NPE_HEXA_125   125
#endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Zone types                                                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( ZoneTypeNull ) =CG_Null,
  CGNS_ENUMV( ZoneTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Structured ) =2,
  CGNS_ENUMV( Unstructured ) =3
} CGNS_ENUMT( ZoneType_t );

#define NofValidZoneTypes 4

extern CGNSDLL const char * ZoneTypeName[NofValidZoneTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Rigid Grid Motion types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( RigidGridMotionTypeNull ) =CG_Null,
  CGNS_ENUMV( RigidGridMotionTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( ConstantRate ) =2,
  CGNS_ENUMV( VariableRate ) =3
} CGNS_ENUMT( RigidGridMotionType_t );

#define NofValidRigidGridMotionTypes 4

extern CGNSDLL const char * RigidGridMotionTypeName[NofValidRigidGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Arbitrary Grid Motion types                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( ArbitraryGridMotionTypeNull ) =CG_Null,
  CGNS_ENUMV( ArbitraryGridMotionTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( NonDeformingGrid ) =2,
  CGNS_ENUMV( DeformingGrid ) =3
} CGNS_ENUMT( ArbitraryGridMotionType_t );

#define NofValidArbitraryGridMotionTypes 4

extern CGNSDLL const char * ArbitraryGridMotionTypeName[NofValidArbitraryGridMotionTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Simulation types					         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( SimulationTypeNull ) =CG_Null,
  CGNS_ENUMV( SimulationTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( TimeAccurate ) =2,
  CGNS_ENUMV( NonTimeAccurate ) =3
} CGNS_ENUMT( SimulationType_t );

#define NofValidSimulationTypes 4

extern CGNSDLL const char * SimulationTypeName[NofValidSimulationTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *	BC Property types						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( WallFunctionTypeNull ) =CG_Null,
  CGNS_ENUMV( WallFunctionTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( Generic ) =2
} CGNS_ENUMT( WallFunctionType_t );

typedef enum {
  CGNS_ENUMV( AreaTypeNull ) =CG_Null,
  CGNS_ENUMV( AreaTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( BleedArea ) =2,
  CGNS_ENUMV( CaptureArea ) =3
} CGNS_ENUMT( AreaType_t );

#define NofValidWallFunctionTypes 3
#define NofValidAreaTypes 4

extern CGNSDLL const char * WallFunctionTypeName[NofValidWallFunctionTypes];
extern CGNSDLL const char * AreaTypeName[NofValidAreaTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Grid Connectivity Property types				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef enum {
  CGNS_ENUMV( AverageInterfaceTypeNull ) =CG_Null,
  CGNS_ENUMV( AverageInterfaceTypeUserDefined ) =CG_UserDefined,
  CGNS_ENUMV( AverageAll ) =2,
  CGNS_ENUMV( AverageCircumferential ) =3,
  CGNS_ENUMV( AverageRadial ) =4,
  CGNS_ENUMV( AverageI ) =5,
  CGNS_ENUMV( AverageJ ) =6,
  CGNS_ENUMV( AverageK ) =7
} CGNS_ENUMT( AverageInterfaceType_t );

#define NofValidAverageInterfaceTypes 8

extern CGNSDLL const char * AverageInterfaceTypeName[NofValidAverageInterfaceTypes];

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      LIBRARY FUNCTIONS						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_is_cgns(const char *filename, int *file_type);
/*%output file_type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */

CGNSDLL int cg_open(const char * filename, int mode, int *fn);
/*%output fn */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_version(int fn, float *FileVersion);
/*%output FileVersion */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_precision(int fn, int *precision);
/*%output precision */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_close(int fn);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_save_as(int fn, const char *filename, int file_type,
	int follow_links);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_set_file_type(int file_type);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_get_file_type(int fn, int *file_type);
/*output file_type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_root_id(int fn, double *rootid);
/*%output rootid */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_get_cgio(int fn, int *cgio_num);
/*%output cgio_num */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */

CGNSDLL int cg_configure(int what, void *value);
/*%input value */
/*%typecast value:cgns_configure_type(what) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_error_handler(void (*)(int, char *));
/*%ignore */
CGNSDLL int cg_set_compress(int compress);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_get_compress(int *compress);
/*%output compress */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_set_path(const char *path);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */
CGNSDLL int cg_add_path(const char *path);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/fileops.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      typedef names                   				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#undef type

CGNSDLL const char *cg_get_name(int nnames, const char **names, int type);
/*%ignore */
CGNSDLL const char *cg_MassUnitsName(CGNS_ENUMT( MassUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_LengthUnitsName(CGNS_ENUMT( LengthUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_TimeUnitsName(CGNS_ENUMT( TimeUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_TemperatureUnitsName(CGNS_ENUMT( TemperatureUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_AngleUnitsName(CGNS_ENUMT( AngleUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_ElectricCurrentUnitsName(CGNS_ENUMT( ElectricCurrentUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_SubstanceAmountUnitsName(CGNS_ENUMT( SubstanceAmountUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_LuminousIntensityUnitsName(CGNS_ENUMT( LuminousIntensityUnits_t ) type);
/*%retname name */
CGNSDLL const char *cg_DataClassName(CGNS_ENUMT( DataClass_t ) type);
/*%retname name */
CGNSDLL const char *cg_GridLocationName(CGNS_ENUMT( GridLocation_t ) type);
/*%retname name */
CGNSDLL const char *cg_BCDataTypeName(CGNS_ENUMT( BCDataType_t ) type);
/*%retname name */
CGNSDLL const char *cg_GridConnectivityTypeName(CGNS_ENUMT( GridConnectivityType_t ) type);
/*%retname name */
CGNSDLL const char *cg_PointSetTypeName(CGNS_ENUMT( PointSetType_t ) type);
/*%retname name */
CGNSDLL const char *cg_GoverningEquationsTypeName(CGNS_ENUMT( GoverningEquationsType_t ) type);
/*%retname name */
CGNSDLL const char *cg_ModelTypeName(CGNS_ENUMT( ModelType_t ) type);
/*%retname name */
CGNSDLL const char *cg_BCTypeName(CGNS_ENUMT( BCType_t ) type);
/*%retname name */
CGNSDLL const char *cg_DataTypeName(CGNS_ENUMT( DataType_t ) type);
/*%retname name */
CGNSDLL const char *cg_ElementTypeName(CGNS_ENUMT( ElementType_t ) type);
/*%retname name */
CGNSDLL const char *cg_ZoneTypeName(CGNS_ENUMT( ZoneType_t ) type);
/*%retname name */
CGNSDLL const char *cg_RigidGridMotionTypeName(CGNS_ENUMT( RigidGridMotionType_t ) type);
/*%retname name */
CGNSDLL const char *cg_ArbitraryGridMotionTypeName(CGNS_ENUMT( ArbitraryGridMotionType_t ) type);
/*%retname name */
CGNSDLL const char *cg_SimulationTypeName(CGNS_ENUMT( SimulationType_t ) type);
/*%retname name */
CGNSDLL const char *cg_WallFunctionTypeName(CGNS_ENUMT( WallFunctionType_t ) type);
/*%retname name */
CGNSDLL const char *cg_AreaTypeName(CGNS_ENUMT( AreaType_t ) type);
/*%retname name */
CGNSDLL const char *cg_AverageInterfaceTypeName(CGNS_ENUMT( AverageInterfaceType_t ) type);
/*%retname name */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write CGNSBase_t Nodes					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nbases(int fn, int *nbases);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
CGNSDLL int cg_base_read(int file_number, int B, char *basename,
	int *cell_dim, int *phys_dim);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
/*%output cell_dim,phys_dim */
CGNSDLL int cg_base_id(int fn, int B, double *base_id);
/*%output base_id */
CGNSDLL int cg_base_write(int file_number, const char * basename,
	int cell_dim, int phys_dim, int *B);
/*%output B */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */

CGNSDLL int cg_cell_dim(int fn, int B, int *cell_dim);
/*%output cell_dim */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Zone_t Nodes    					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nzones(int fn, int B, int *nzones);
/*%output nzones */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
CGNSDLL int cg_zone_read(int fn, int B, int Z, char *zonename, cgsize_t *size);
/*%output size(9) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
CGNSDLL int cg_zone_type(int file_number, int B, int Z,
	CGNS_ENUMT(ZoneType_t) *type);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
CGNSDLL int cg_zone_id(int fn, int B, int Z, double *zone_id);
/*%output zone_id */
CGNSDLL int cg_zone_write(int fn, int B, const char * zonename,
	const cgsize_t * size, CGNS_ENUMT(ZoneType_t) type, int *Z);
/*%input size(9) */
/*%output Z */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */

CGNSDLL int cg_index_dim(int fn, int B, int Z, int *index_dim);
/*%output index_dim(3) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Family_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nfamilies(int file_number, int B, int *nfamilies);
/*%output nfamilies */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_family_read(int file_number, int B, int F,
	char *family_name, int *nboco, int *ngeos);
/*%output nboco, ngeos*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

CGNSDLL int cg_family_write(int file_number, int B,
	const char * family_name, int *F);
/*%output F*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

CGNSDLL int cg_nfamily_names(int file_number, int B, int F, int *nnames);
/*%output nnames*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_family_name_read(int file_number, int B, int F,
	int N, char *name, char *family);
/*%output name, family */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_family_name_write(int file_number, int B, int F,
	const char *name, const char *family);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyName_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_famname_read(char *family_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_famname_write(const char * family_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

CGNSDLL int cg_nmultifam(int *nfams);
/*%output nfams */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_multifam_read(int N, char *name, char *family);
/*%output name,family */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_multifam_write(const char *name, const char *family);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyBC_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_fambc_read(int file_number, int B, int F, int BC,
	char *fambc_name, CGNS_ENUMT(BCType_t) *bocotype);
/*%output bocotype*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_fambc_write(int file_number, int B, int F,
	const char * fambc_name, CGNS_ENUMT(BCType_t) bocotype, int *BC);
/*%output BC */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryReference_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_geo_read(int file_number, int B, int F, int G, char *geo_name,
	char **geo_file, char *CAD_name, int *npart);
/*%output npart */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_geo_write(int file_number, int B, int F, const char * geo_name,
	const char * filename, const char * CADname, int *G);
/*%output G */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GeometryEntity_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_part_read(int file_number, int B, int F, int G, int P,
	char *part_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */
CGNSDLL int cg_part_write(int file_number, int B, int F, int G,
	const char * part_name, int *P);
/*%output P */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/families.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ngrids(int file_number, int B, int Z, int *ngrids);
/*%output ngrids */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_grid_read(int file_number, int B, int Z, int G, char *gridname);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_grid_write(int file_number, int B, int Z,
	const char * zcoorname, int *G);
/*%output G */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridCoordinates_t/DataArray_t Nodes               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ncoords(int fn, int B, int Z, int *ncoords);
/*%output ncoords */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_coord_info(int fn, int B, int Z, int C,
	CGNS_ENUMT(DataType_t) *type, char *coordname);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_coord_read(int fn, int B, int Z, const char * coordname,
	CGNS_ENUMT(DataType_t) type, const cgsize_t * rmin,
	const cgsize_t * rmax, void *coord);
/*%typecast coord:type */
/*%input rmin(:), rmax(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_coord_general_read(int fn, int B, int Z,
        const char * coordname, const cgsize_t *s_rmin, const cgsize_t *s_rmax,
        CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dimvals,
        const cgsize_t *m_rmin, const cgsize_t *m_rmax, void *coord_ptr);
/*%typecast coord_ptr:m_type */
/*%input s_rmin(:), s_rmax(:), m_rmin(:), m_rmax(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_coord_id(int fn, int B, int Z, int C, double *coord_id);
/*%output coord_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_coord_write(int fn, int B, int Z,
	CGNS_ENUMT(DataType_t) type, const char * coordname,
 	const void * coord_ptr, int *C);
/*%typecast coord_ptr:type */
/*%output C */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_coord_partial_write(int fn, int B, int Z,
	CGNS_ENUMT(DataType_t) type, const char * coordname,
    const cgsize_t *rmin, const cgsize_t *rmax,
    const void * coord_ptr, int *C);
/*%typecast coord_ptr:type */
/*%input rmin(:), rmax(:) */
/*%output C */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_coord_general_write(int fn, int B, int Z,
	const char *coordname, CGNS_ENUMT(DataType_t) s_type,
	const cgsize_t *rmin, const cgsize_t *rmax,
	CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dims,
	const cgsize_t *m_rmin, const cgsize_t *m_rmax,
	const void *coord_ptr, int *C);
/*%typecast coord_ptr:m_type */
/*%input rmin(:), rmax(:), m_rmin(:), m_rmax(:) */
/*%output C */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Elements_t Nodes                                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nsections(int file_number, int B, int Z, int *nsections);
/*%output nsections */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_section_read(int file_number, int B, int Z, int S,
	char *SectionName,  CGNS_ENUMT(ElementType_t) *type,
	cgsize_t *start, cgsize_t *end, int *nbndry, int *parent_flag);
/*%output type,start,end,nbndry,parent_flag */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_elements_read(int file_number, int B, int Z, int S,
	cgsize_t *elements, cgsize_t *parent_data);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_section_write(int file_number, int B, int Z,
	const char * SectionName, CGNS_ENUMT(ElementType_t) type,
	cgsize_t start, cgsize_t end, int nbndry, const cgsize_t * elements,
	int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_parent_data_write(int file_number, int B, int Z, int S,
	const cgsize_t * parent_data);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_npe( CGNS_ENUMT(ElementType_t) type, int *npe);
/*%output npe */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_ElementDataSize(int file_number, int B, int Z, int S,
	cgsize_t *ElementDataSize);
/*%output ElementDataSize */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_section_partial_write(int file_number, int B, int Z,
	const char * SectionName, CGNS_ENUMT(ElementType_t) type,
	cgsize_t start, cgsize_t end, int nbndry, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_elements_partial_write(int fn, int B, int Z, int S,
	cgsize_t start, cgsize_t end, const cgsize_t *elements);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_parent_data_partial_write(int fn, int B, int Z, int S,
	cgsize_t start, cgsize_t end, const cgsize_t *ParentData);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_elements_partial_read(int file_number, int B, int Z, int S,
	cgsize_t start, cgsize_t end, cgsize_t *elements, cgsize_t *parent_data);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

CGNSDLL int cg_ElementPartialSize(int file_number, int B, int Z, int S,
	cgsize_t start, cgsize_t end, cgsize_t *ElementDataSize);
/*%output ElementDataSize */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowSolution_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nsols(int fn, int B, int Z, int *nsols);
/*%output nsols */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_sol_info(int fn, int B, int Z, int S, char *solname,
	CGNS_ENUMT(GridLocation_t) *location);
/*%output location */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_sol_id(int fn, int B, int Z,int S, double *sol_id);
/*%output sol_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_sol_write(int fn, int B, int Z, const char * solname,
	CGNS_ENUMT(GridLocation_t) location, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_sol_size(int fn, int B, int Z, int S,
	int *data_dim, cgsize_t *dim_vals);
/*%output data_dim */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_sol_ptset_info(int fn, int B, int Z, int S,
	CGNS_ENUMT(PointSetType_t) *ptset_type, cgsize_t *npnts);
/*%output ptset_type, npnts */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_sol_ptset_read(int fn, int B, int Z, int S, cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_sol_ptset_write(int fn, int B, int Z, const char *solname,
	CGNS_ENUMT(GridLocation_t) location,
	CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
	const cgsize_t *pnts, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write solution DataArray_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nfields(int fn, int B, int Z, int S, int *nfields);
/*%output nfields */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_field_info(int fn,int B,int Z,int S, int F,
	CGNS_ENUMT(DataType_t) *type, char *fieldname);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_field_read(int fn, int B, int Z, int S, const char *fieldname,
	CGNS_ENUMT(DataType_t) type, const cgsize_t *rmin,
        const cgsize_t *rmax, void *field_ptr);
/*%typecast field_ptr:type */
/*%input rmin(:), rmax(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_field_general_read(int fn, int B, int Z, int S,
        const char *fieldname, const cgsize_t *s_rmin, const cgsize_t *s_rmax,
        CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dimvals,
        const cgsize_t *m_rmin, const cgsize_t *m_rmax, void *field_ptr);
/*%typecast field_ptr:m_type */
/*%input s_rmin(:), s_rmax(:), m_rmin(:), m_rmax(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_field_id(int fn, int B, int Z,int S, int F, double *field_id);
/*%output field_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_field_write(int fn,int B,int Z,int S,
	CGNS_ENUMT(DataType_t) type, const char * fieldname,
	const void * field_ptr, int *F);
/*%typecast field_ptr:type */
/*%output F */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_field_partial_write(int fn, int B, int Z, int S,
	CGNS_ENUMT(DataType_t) type, const char * fieldname,
	const cgsize_t *rmin, const cgsize_t *rmax,
        const void * field_ptr, int *F);
/*%typecast field_ptr:type */
/*%input rmin(:), rmax(:) */
/*%output F */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_field_general_write(int fn, int B, int Z, int S,
        const char * fieldname, CGNS_ENUMT(DataType_t) s_type,
        const cgsize_t *rmin, const cgsize_t *rmax,
        CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dims,
        const cgsize_t *m_rmin, const cgsize_t *m_rmax,
        const void *field_ptr, int *F);
/*%typecast field_ptr:m_type */
/*%input rmin(:), rmax(:), m_rmin(:), m_rmax(:) */
/*%output F */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ZoneSubRegion_t Nodes                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nsubregs(int fn, int B, int Z, int *nsubreg);
/*%output nsubreg */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_info(int fn, int B, int Z, int S, char *regname,
	int *dimension, CGNS_ENUMT(GridLocation_t) *location,
	CGNS_ENUMT(PointSetType_t) *ptset_type, cgsize_t *npnts,
	int *bcname_len, int *gcname_len);
/*%output dimension, location, ptset_type, npnts, bcname_len, gcname_len */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_ptset_read(int fn, int B, int Z, int S, cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_bcname_read(int fn, int B, int Z, int S, char *bcname);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_gcname_read(int fn, int B, int Z, int S, char *gcname);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_ptset_write(int fn, int B, int Z, const char *regname,
	int dimension, CGNS_ENUMT(GridLocation_t) location,
	CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
	const cgsize_t *pnts, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_bcname_write(int fn, int B, int Z, const char *regname,
	int dimension, const char *bcname, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_subreg_gcname_write(int fn, int B, int Z, const char *regname,
	int dimension, const char *gcname, int *S);
/*%output S */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ZoneGridConnectivity_t Nodes  			 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nzconns(int fn, int B, int Z, int *nzconns);
/*%output nzconns */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_zconn_read(int fn, int B, int Z, int C, char *name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_zconn_write(int fn, int B, int Z, const char *name, int *C);
/*%output C */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_zconn_get(int fn, int B, int Z, int *C);
/*%output C */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_zconn_set(int fn, int B, int Z, int C);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write OversetHoles_t Nodes  				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nholes(int fn, int B, int Z, int *nholes);
/*%output nholes */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_hole_info(int fn, int B, int Z, int Ii, char *holename,
	CGNS_ENUMT(GridLocation_t) *location,  CGNS_ENUMT(PointSetType_t) *ptset_type,
	int *nptsets, cgsize_t *npnts);
/*%output location, ptset_type, nptsets, npnts */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_hole_read(int fn, int B, int Z, int Ii, cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_hole_id(int fn, int B, int Z, int Ii, double *hole_id);
/*%output hole_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_hole_write(int fn, int B, int Z, const char * holename,
	CGNS_ENUMT(GridLocation_t) location, CGNS_ENUMT(PointSetType_t) ptset_type,
	int nptsets, cgsize_t npnts, const cgsize_t * pnts, int *Ii);
/*%output Ii */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nconns(int fn, int B, int Z, int *nconns);
/*%output nconns */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_conn_info(int file_number, int B, int Z, int Ii,
	char *connectname, CGNS_ENUMT(GridLocation_t) *location,
	CGNS_ENUMT(GridConnectivityType_t) *type,
	CGNS_ENUMT(PointSetType_t) *ptset_type,
	cgsize_t *npnts, char *donorname,
	CGNS_ENUMT(ZoneType_t) *donor_zonetype,
	CGNS_ENUMT(PointSetType_t) *donor_ptset_type,
        CGNS_ENUMT(DataType_t) *donor_datatype,
        cgsize_t *ndata_donor);
/*%output location,type,ptset_type,npnts,donor_zonetype,donor_ptset_type,donor_datatype,ndata_donor*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_conn_read(int file_number, int B, int Z, int Ii, cgsize_t *pnts,
        CGNS_ENUMT(DataType_t) donor_datatype,
        cgsize_t *donor_data);
/*%typecast donor_data:donor_datatype */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_conn_id(int fn, int B, int Z, int Ii, double *conn_id);
/*%output conn_id */
CGNSDLL int cg_conn_write(int file_number, int B, int Z,
	const char * connectname, CGNS_ENUMT(GridLocation_t) location,
	CGNS_ENUMT(GridConnectivityType_t) type,
	CGNS_ENUMT(PointSetType_t) ptset_type,
	cgsize_t npnts, const cgsize_t * pnts, const char * donorname,
	CGNS_ENUMT(ZoneType_t) donor_zonetype,
	CGNS_ENUMT(PointSetType_t) donor_ptset_type,
        CGNS_ENUMT(DataType_t) donor_datatype,
        cgsize_t ndata_donor, const cgsize_t *donor_data, int *Ii);
/*%typecast donor_data:donor_datatype */
/*%output Ii */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_conn_write_short(int file_number, int B, int Z,
	const char * connectname, CGNS_ENUMT(GridLocation_t) location,
	CGNS_ENUMT(GridConnectivityType_t) type,
	CGNS_ENUMT(PointSetType_t) ptset_type,
	cgsize_t npnts, const cgsize_t * pnts, const char * donorname, int *Ii);
/*%output Ii */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_conn_read_short(int file_number, int B, int Z, int Ii,
	cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivity1to1_t Nodes in a zone            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n1to1(int fn, int B, int Z, int *n1to1);
/*%output n1to1 */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_read(int fn, int B, int Z, int Ii, char *connectname,
	char *donorname, cgsize_t *range, cgsize_t *donor_range, int *transform);
/*%output range(6), donor_range(6), transform(3) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

CGNSDLL int cg_1to1_id(int fn, int B, int Z, int Ii, double *one21_id);
/*%output one21_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_write(int fn, int B, int Z, const char * connectname,
	const char * donorname, const cgsize_t * range,
	const cgsize_t * donor_range, const int * transform, int *Ii);
/*%output Ii */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read all GridConnectivity1to1_t Nodes of a base                  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n1to1_global(int fn, int B, int *n1to1_global);
/*%output n1to1_global */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_read_global(int fn, int B, char **connectname,
	char **zonename, char **donorname, cgsize_t **range,
	cgsize_t **donor_range, int **transform);
/*%output connectname,zonename,donorname,range(:),donor_range(:),transform(:)*/
/*%external */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BC_t Nodes                                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nbocos(int fn, int B, int Z, int *nbocos);
/*%output nbocos */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_info(int fn, int B, int Z, int BC, char *boconame,
	CGNS_ENUMT(BCType_t) *bocotype, CGNS_ENUMT(PointSetType_t) *ptset_type,
 	cgsize_t *npnts, int *NormalIndex, cgsize_t *NormalListSize,
 	CGNS_ENUMT(DataType_t) *NormalDataType, int *ndataset);
/*%output bocotype,ptset_type,npnts,NormalListSize,NormalDataType,ndataset */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_read(int fn, int B, int Z, int BC, cgsize_t *pnts,
	void *NormalList);
/*%typecast NormalList:cgns_get_boco_type(fn,B,Z,BC) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_id(int fn, int B, int Z, int BC, double *boco_id);
/*%output boco_id */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_write(int file_number, int B, int Z, const char * boconame,
	CGNS_ENUMT(BCType_t) bocotype, CGNS_ENUMT(PointSetType_t) ptset_type,
	cgsize_t npnts, const cgsize_t * pnts, int *BC);
/*%output BC */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_normal_write(int file_number, int B, int Z, int BC,
	const int * NormalIndex, int NormalListFlag,
	CGNS_ENUMT(DataType_t) NormalDataType, const void * NormalList);
/*%typecast NormalList:NormalDataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

CGNSDLL int cg_boco_gridlocation_read(int file_number, int B, int Z,
	int BC, CGNS_ENUMT(GridLocation_t) *location);
/*%output location */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_boco_gridlocation_write(int file_number, int B, int Z,
	int BC, CGNS_ENUMT(GridLocation_t) location);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCDataSet_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_dataset_read(int fn, int B, int Z, int BC, int DS, char *name,
	CGNS_ENUMT(BCType_t) *BCType, int *DirichletFlag, int *NeumannFlag);
/*%output BCType,DirichletFlag,NeumannFlag */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_dataset_write(int file_number, int B, int Z, int BC,
	const char *name, CGNS_ENUMT(BCType_t) BCType, int *Dset);
/*%output Dset */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FamilyBCDataSet_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bcdataset_write(const char *name, CGNS_ENUMT(BCType_t) BCType,
	CGNS_ENUMT(BCDataType_t) BCDataType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_bcdataset_info(int *n_dataset);
/*%output n_dataset */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_bcdataset_read(int index, char *name,
	CGNS_ENUMT(BCType_t) *BCType, int *DirichletFlag, int *NeumannFlag);
/*%output BCType,DirichletFlag,NeumannFlag */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCData_t Nodes                                    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bcdata_write(int file_number, int B, int Z, int BC, int Dset,
	CGNS_ENUMT(BCDataType_t) BCDataType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DiscreteData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ndiscrete(int file_number, int B, int Z, int *ndiscrete);
/*%output ndiscrete */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_discrete_read(int file_number, int B, int Z, int D,
	char *discrete_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_discrete_write(int file_number, int B, int Z,
	const char * discrete_name, int *D);
/*%output D */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_discrete_size(int fn, int B, int Z, int D,
	int *data_dim, cgsize_t *dim_vals);
/*%output data_dim, dim_vals(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

CGNSDLL int cg_discrete_ptset_info(int fn, int B, int Z, int D,
	CGNS_ENUMT(PointSetType_t) *ptset_type, cgsize_t *npnts);
/*%output ptset_type, npnts */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_discrete_ptset_read(int fn, int B, int Z, int D,
	cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */
CGNSDLL int cg_discrete_ptset_write(int fn, int B, int Z,
	const char *discrete_name, CGNS_ENUMT(GridLocation_t) location,
	CGNS_ENUMT(PointSetType_t) ptset_type, cgsize_t npnts,
	const cgsize_t *pnts, int *D);
/*%output D */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/solution.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RigidGridMotion_t Nodes				 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n_rigid_motions(int file_number, int B, int Z,
	int *n_rigid_motions);
/*%output n_rigid_motions */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_rigid_motion_read(int file_number, int B, int Z, int R,
	char *name, CGNS_ENUMT(RigidGridMotionType_t) *type);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_rigid_motion_write(int file_number, int B, int Z,
	const char * name, CGNS_ENUMT(RigidGridMotionType_t) type, int *R);
/*%output R */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ArbitraryGridMotion_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_n_arbitrary_motions(int file_number, int B, int Z,
	int *n_arbitrary_motions);
/*%output n_arbitrary_motions */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_arbitrary_motion_read(int file_number, int B, int Z, int A,
	char *name, CGNS_ENUMT(ArbitraryGridMotionType_t) *type);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_arbitrary_motion_write(int file_number, int B, int Z,
	const char * amotionname, CGNS_ENUMT(ArbitraryGridMotionType_t) type,
        int *A);
/*%output A */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write SimulationType_t Node                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_simulation_type_read(int file_number, int B,
	CGNS_ENUMT(SimulationType_t) *type);
/*%output type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */
CGNSDLL int cg_simulation_type_write(int file_number, int B,
	CGNS_ENUMT(SimulationType_t) type);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/structural.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BaseIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_biter_read(int file_number, int B, char *bitername, int *nsteps);
/*%output nsteps */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_biter_write(int file_number, int B, const char * bitername, int nsteps);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ZoneIterativeData_t Node                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ziter_read(int file_number, int B, int Z, char *zitername);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */
CGNSDLL int cg_ziter_write(int file_number, int B, int Z, const char * zitername);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/timedep.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Gravity_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_gravity_read(int file_number, int B, float *gravity_vector);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_gravity_write(int file_number, int B, float const *gravity_vector);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Axisymmetry_t Nodes                               *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_axisym_read(int file_number, int B, float *ref_point,
	float *axis);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_axisym_write(int file_number, int B, float const *ref_point,
  	float const *axis);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write RotatingCoordinates_t Nodes                       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_rotating_read(float *rot_rate, float *rot_center);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */
CGNSDLL int cg_rotating_write(float const *rot_rate, float const *rot_center);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/grid.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/WallFunction_t Nodes   	         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bc_wallfunction_read(int file_number, int B, int Z, int BC,
	CGNS_ENUMT(WallFunctionType_t) *WallFunctionType);
/*%output WallFunctionType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_bc_wallfunction_write(int file_number, int B, int Z, int BC,
	CGNS_ENUMT(WallFunctionType_t) WallFunctionType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write BCProperty_t/Area_t Nodes                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_bc_area_read(int file_number, int B, int Z, int BC,
	CGNS_ENUMT(AreaType_t) *AreaType, float *SurfaceArea, char *RegionName);
/*%output AreaType,SurfaceArea */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */
CGNSDLL int cg_bc_area_write(int file_number, int B, int Z, int BC,
	CGNS_ENUMT(AreaType_t) AreaType, float SurfaceArea, const char *RegionName);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/bc.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridConnectivityProperty_t/Periodic_t Nodes       *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conn_periodic_read(int file_number, int B, int Z, int Ii,
	float *RotationCenter, float *RotationAngle, float *Translation);
/*%output RotationCenter(3), RotationAngle(3), Translation(3) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_conn_periodic_write(int file_number, int B, int Z, int Ii,
	float const *RotationCenter, float const *RotationAngle,
	float const *Translation);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_periodic_write(int file_number, int B, int Z, int Ii,
	float const *RotationCenter, float const *RotationAngle,
	float const *Translation);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_periodic_read(int file_number, int B, int Z, int Ii,
	float *RotationCenter, float *RotationAngle, float *Translation);
/*%output RotationCenter(3), RotationAngle(3), Translation(3) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *   Read and write GridConnectivityProperty_t/AverageInterface_t Nodes  *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conn_average_read(int file_number, int B, int Z, int Ii,
	CGNS_ENUMT(AverageInterfaceType_t) *AverageInterfaceType);
/*%output AverageInterfaceType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_conn_average_write(int file_number, int B, int Z, int Ii,
	CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_average_write(int file_number, int B, int Z, int Ii,
	CGNS_ENUMT(AverageInterfaceType_t) AverageInterfaceType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */
CGNSDLL int cg_1to1_average_read(int file_number, int B, int Z, int Ii,
	CGNS_ENUMT(AverageInterfaceType_t) *AverageInterfaceType);
/*%output AverageInterfaceType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/connectivity.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Variable Argument List Functions                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_goto(int file_number, int B, ...);
/*%external */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */
CGNSDLL int cg_goto_f08(int file_number, int B, ...);
/*%ignore */
CGNSDLL int cg_gorel(int file_number, ...);
/*%external */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */
CGNSDLL int cg_gorel_f08(int file_number, ...);
/*%ignore */
CGNSDLL int cg_gopath(int file_number, const char *path);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */
CGNSDLL int cg_golist(int file_number, int B, int depth, char **label,
	int *num);
/*%external */
/*%input label(depth,32),num(depth) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */
CGNSDLL int cg_where(int *file_number, int *B, int *depth, char **label,
	int *num);
/*%external */
/*%output label(CG_MAX_GOTO_DEPTH,32),num(CG_MAX_GOTO_DEPTH) */
/*%output file_number,B,depth */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ConvergenceHistory_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_convergence_read(int *iterations, char **NormDefinitions);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_convergence_write(int iterations, const char * NormDefinitions);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write ReferenceState_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_state_read(char **StateDescription);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_state_write(const char * StateDescription);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write FlowEquationSet_t Nodes                           *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_equationset_read(int *EquationDimension,
        int *GoverningEquationsFlag, int *GasModelFlag,
        int *ViscosityModelFlag,     int *ThermalConductivityModelFlag,
        int *TurbulenceClosureFlag,  int *TurbulenceModelFlag);
/*%output EquationDimension,GoverningEquationsFlag,GasModelFlag,ViscosityModelFlag,ThermalConductivityModelFlag,TurbulenceClosureFlag,TurbulenceModelFlag */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_equationset_chemistry_read(int *ThermalRelaxationFlag,
	int *ChemicalKineticsFlag);
/*%output ThermalRelaxationFlag,ChemicalKineticsFlag */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_equationset_elecmagn_read(int *ElecFldModelFlag,
	int *MagnFldModelFlag, int *ConductivityModelFlag);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_equationset_write(int EquationDimension);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GoverningEquations_t Nodes                        *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_governing_read(CGNS_ENUMT(GoverningEquationsType_t) *EquationsType);
/*%output EquationsType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_governing_write(CGNS_ENUMT(GoverningEquationsType_t) Equationstype);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Diffusion Model Nodes                             *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_diffusion_read(int *diffusion_model);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_diffusion_write(const int * diffusion_model);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GasModel_t, ViscosityModel_t,                     *
 *      ThermalConductivityModel_t, TurbulenceClosure_t,                 *
 *      TurbulenceModel_t, ThermalRelaxationModel_t,                     *
 *      ChemicalKineticsModel_t, EMElectricFieldModel_t,                 *
 *      EMMagneticFieldModel_t Nodes                                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_model_read(const char *ModelLabel, CGNS_ENUMT(ModelType_t) *ModelType);
/*%output ModelType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */
CGNSDLL int cg_model_write(const char * ModelLabel, CGNS_ENUMT(ModelType_t) ModelType);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/equation.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataArray_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_narrays(int *narrays);
/*%output narrays */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_array_info(int A, char *ArrayName,
	CGNS_ENUMT(DataType_t) *DataType,
	int *DataDimension, cgsize_t *DimensionVector);
/*%output DataType, DataDimension */
/*%inout DimensionVector(12) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_array_read(int A, void *data);
/*%typecast data:cgns_get_array_type(A) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_array_read_as(int A, CGNS_ENUMT(DataType_t) type, void *data);
/*%typecast data:type */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

CGNSDLL int cg_array_general_read(int A,
        const cgsize_t *s_rmin, const cgsize_t *s_rmax,
        CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dimvals,
        const cgsize_t *m_rmin, const cgsize_t *m_rmax, void *data);
/*%typecast data:m_type */
/*%input s_rmin(:), s_rmax(:), m_rmin(:), m_rmax(:) */
/*%output data */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_array_write(const char * ArrayName,
	CGNS_ENUMT(DataType_t) DataType, int DataDimension,
	const cgsize_t * DimensionVector, const void * Data);
/*%typecast Data:DataType */
/*%input  DimensionVector(DataDimension) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_array_general_write(const char *arrayname,
        CGNS_ENUMT(DataType_t) s_type, int s_numdim, const cgsize_t *s_dimvals,
        const cgsize_t *s_rmin, const cgsize_t *s_rmax,
        CGNS_ENUMT(DataType_t) m_type, int m_numdim, const cgsize_t *m_dimvals,
        const cgsize_t *m_rmin, const cgsize_t *m_rmax, const void *data);
/*%input s_rmin(:), s_rmax(:), m_rmin(:), m_rmax(:) */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write UserDefinedData_t Nodes - new in version 2.1      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nuser_data(int *nuser_data);
/*%output nuser_data */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

CGNSDLL int cg_user_data_read(int Index, char *user_data_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_user_data_write(const char * user_data_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IntegralData_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_nintegrals(int *nintegrals);
/*%output nintegrals */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_integral_read(int IntegralDataIndex, char *IntegralDataName);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */
CGNSDLL int cg_integral_write(const char * IntegralDataName);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Rind_t Nodes                                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_rind_read(int *RindData);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */
CGNSDLL int cg_rind_write(const int * RindData);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Descriptor_t Nodes                                *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ndescriptors(int *ndescriptors);
/*%output ndescriptors */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html */
CGNSDLL int cg_descriptor_read(int descr_no, char *descr_name, char **descr_text);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html */
CGNSDLL int cg_descriptor_write(const char * descr_name, const char * descr_text);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalUnits_t Nodes                          *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int
cg_nunits(int *nunits);
/*%output nunits */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int
cg_units_read     (CGNS_ENUMT(MassUnits_t) *mass,
		   CGNS_ENUMT(LengthUnits_t) *length,
		   CGNS_ENUMT(TimeUnits_t) *time,
		   CGNS_ENUMT(TemperatureUnits_t) *temperature,
		   CGNS_ENUMT(AngleUnits_t) *angle);
/*%output mass, length, time,temperature, angle */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int
cg_units_write    (CGNS_ENUMT(MassUnits_t) mass,
		   CGNS_ENUMT(LengthUnits_t) length,
		   CGNS_ENUMT(TimeUnits_t) time,
		   CGNS_ENUMT(TemperatureUnits_t) temperature,
		   CGNS_ENUMT(AngleUnits_t) angle);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int
cg_unitsfull_read (CGNS_ENUMT(MassUnits_t) *mass,
		   CGNS_ENUMT(LengthUnits_t) *length,
		   CGNS_ENUMT(TimeUnits_t) *time,
		   CGNS_ENUMT(TemperatureUnits_t) *temperature,
		   CGNS_ENUMT(AngleUnits_t) *angle,
		   CGNS_ENUMT(ElectricCurrentUnits_t) *current,
		   CGNS_ENUMT(SubstanceAmountUnits_t) *amount,
		   CGNS_ENUMT(LuminousIntensityUnits_t) *intensity);
/*%output mass, length, time,temperature, angle,current,amount,intensity */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int
cg_unitsfull_write(CGNS_ENUMT(MassUnits_t) mass,
		   CGNS_ENUMT(LengthUnits_t) length,
		   CGNS_ENUMT(TimeUnits_t) time,
		   CGNS_ENUMT(TemperatureUnits_t) temperature,
		   CGNS_ENUMT(AngleUnits_t) angle,
		   CGNS_ENUMT(ElectricCurrentUnits_t) current,
		   CGNS_ENUMT(SubstanceAmountUnits_t) amount,
		   CGNS_ENUMT(LuminousIntensityUnits_t) intensity);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DimensionalExponents_t Nodes                      *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_exponents_info(CGNS_ENUMT(DataType_t) *DataType);
/*%output DataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_nexponents(int *numexp);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_exponents_read(void *exponents);
/*%typecast exponents:cg_exponents_info() */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_exponents_write(CGNS_ENUMT(DataType_t) DataType, const void * exponents);
/*%typecast exponents:DataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_expfull_read(void *exponents);
/*%typecast exponents:cg_exponents_info() */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_expfull_write(CGNS_ENUMT(DataType_t) DataType, const void * exponents);
/*%typecast exponents:DataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataConversion_t Nodes                            *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_conversion_info(CGNS_ENUMT(DataType_t) *DataType);
/*%output DataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_conversion_read(void *ConversionFactors);
/*%typecast ConversionFactors:cg_conversion_info() */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_conversion_write(CGNS_ENUMT(DataType_t) DataType, const void * ConversionFactors);
/*%typecast ConversionFactors:DataType */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write DataClass_t Nodes                                 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_dataclass_read(CGNS_ENUMT(DataClass_t) *dataclass);
/*%output dataclass */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */
CGNSDLL int cg_dataclass_write(CGNS_ENUMT(DataClass_t) dataclass);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/physical.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write GridLocation_t Nodes                              *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_gridlocation_read(CGNS_ENUMT(GridLocation_t) *GridLocation);
/*%output GridLocation */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */
CGNSDLL int cg_gridlocation_write(CGNS_ENUMT(GridLocation_t) GridLocation);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write Ordinal_t Nodes                                   *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ordinal_read(int *Ordinal);
/*%output Ordinal */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html */
CGNSDLL int cg_ordinal_write(int Ordinal);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/descriptor.html */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Read and write IndexArray/Range_t Nodes  - new in version 2.4    *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_ptset_info(CGNS_ENUMT(PointSetType_t) *ptset_type,
	cgsize_t *npnts);
/*%output ptset_type, npnts*/
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */
CGNSDLL int cg_ptset_write(CGNS_ENUMT(PointSetType_t) ptset_type,
	cgsize_t npnts, const cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */
CGNSDLL int cg_ptset_read(cgsize_t *pnts);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/location.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Link Handling Functions - new in version 2.1                     *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_is_link(int *path_length);
/*%output path_length*/
/*url https://cgns.github.io/CGNS_docs_current/midlevel/links.html */
CGNSDLL int cg_link_read(char **filename, char **link_path);
/*url https://cgns.github.io/CGNS_docs_current/midlevel/links.html */
CGNSDLL int cg_link_write(const char * nodename, const char * filename,
	const char * name_in_file);
/*url https://cgns.github.io/CGNS_docs_current/midlevel/links.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      General Delete Function						 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_delete_node(const char *node_name);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/navigating.html */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Free library malloced memory					 *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL int cg_free(void *data);
/*%ignore */
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/auxiliary.html */

/* Data are deallocated automatially, so free is not needed. */

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\
 *      Error Handling Functions                                         *
\* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

CGNSDLL const char *cg_get_error(void);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/error.html */
/*%retname msg */
CGNSDLL void cg_error_exit(void);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/error.html */
CGNSDLL void cg_error_print(void);
/*%url https://cgns.github.io/CGNS_docs_current/midlevel/error.html */

#ifdef __cplusplus
}
#endif
#endif
