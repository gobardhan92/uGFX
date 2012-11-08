/*
    ChibiOS/GFX - Copyright (C) 2012
                 Joel Bodenmann aka Tectu <joel@unormal.org>

    This file is part of ChibiOS/GFX.

    ChibiOS/GFX is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/GFX is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file	include/touchpad.h
 * @brief	TOUCHPAD Touchpad Driver subsystem header file.
 *
 * @addtogroup TOUCHPAD
 * @{
 */

#ifndef _TOUCHPAD_H
#define _TOUCHPAD_H

#if GFX_USE_TOUCHPAD || defined(__DOXYGEN__)

/**
 * @brief	specifies how many conversions are made for a readout.
 *
 * @note	higher is more accurate, but takes more time
 */
#define	CONVERSIONS 3

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Low Level Driver details and error checks.                                */
/*===========================================================================*/

/* Include the low level driver information */
#include "touchpad_lld.h"

/* For definitions of coord_t, we require gdisp.h */
#include "gdisp.h"

/*===========================================================================*/
/* Type definitions                                                          */
/*===========================================================================*/

/**
 * @brief	Struct used for calibration
 */
typedef struct cal_t {
    float ax;
    float bx;
    float cx;
    float ay;
    float by;
    float cy;
} cal_t;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

void tpInit(const TOUCHPADDriver *tp);
coord_t tpReadX(void);
coord_t tpReadY(void);
void tpCalibrate(void);

#if TOUCHPAD_HAS_IRQ
	bool_t tpIRQ(void);
#endif

#if TOUCHPAD_HAS_PRESSURE
	uint16_t tpReadZ(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* GFX_USE_TOUCHPAD */

#endif /* _TOUCHPAD_H */
/** @} */

