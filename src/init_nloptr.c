/*
 * Copyright (C) 2017 Jelmer Ypma. All Rights Reserved.
 * This code is published under the L-GPL.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *   
 * File:   init_nloptr.c
 * Author: Jelmer Ypma
 * Date:   3 October 2017
 *
 * This file registers C functions to be used from R.
 * 
 * 03/10/2017: Included registering of C functions to be used by external R packages.
 * 01/10/2017: Initial version.
 */


#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

#include "nloptr.h"
#include "nlopt.h"

static const R_CallMethodDef CallEntries[] = {
    {"NLoptR_Optimize", (DL_FUNC) &NLoptR_Optimize, 1},
    {NULL, NULL, 0}
};

void R_init_nloptr(DllInfo *info) {
    // Register C functions that can be used by external packages
    // linking to internal NLopt code from C.
    R_RegisterCCallable("nloptr", "nlopt_version", (DL_FUNC) &nlopt_version);

    // Register routines to improve lookup from R using .Call interface.
    R_registerRoutines(info, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);
}
