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

/***********************************************************************
 * Revisions:
 *
 ***********************************************************************/

#if defined(_WIN32) && !defined(__NUTC__)
#include <math.h>
#include <ctype.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#if defined(_WIN32) && !defined(__NUTC__)
#include <io.h>     /* suggested by MTI */
#else
#include <unistd.h>
#endif
#include "cgnslib.h"
#include "cgns_header.h"
#include "ADF.h"
#if defined(_WIN32) && !defined(__NUTC__)
#include <ctype.h>
#ifndef F_OK
#define R_OK    004 /* Test for Read permission */
#define W_OK    002 /* Test for Write permission */
#define X_OK    001 /* Test for eXecute permission */
#define F_OK    000 /* Test for existence of File */
#endif
#endif