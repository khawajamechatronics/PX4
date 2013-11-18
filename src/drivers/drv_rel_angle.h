/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file MAX127 driver interface.
 * The MAX127 IC is a analog to digital converter with a I2C interface
 * Relativ angle between vehicle and paraglider
 */

#ifndef _DRV_REL_ANGLE_H
#define _DRV_REL_ANGLE_H

#include <stdint.h>
#include <sys/ioctl.h>

#include "drv_sensor.h"
#include "drv_orb_dev.h"


#define REL_ANGLE_DEVICE_PATH	"/dev/rel_angle"

/**
 * relativ angle report structure.  Reads from the device must be in multiples of this
 * structure.
 */
struct rel_angle_report {
	uint64_t timestamp;
	float raw_left; 			/** Raw value from max127 adc of the left potentiometer [V] */
	float angle_left; 			/** Relativ angle left between vehicle and paraglider [rad] */
	float raw_right; 			/** Raw value from max127 adc of the right potentiometer [V] */
	float angle_right; 			/** Relativ angle right between vehicle and paraglider [rad] */
};


/*
 * ObjDev tag for max127 data.
 */
ORB_DECLARE(rel_angle);

/*
 * ioctl() definitions
 */
#define _REL_ANGLEIOCBASE			(0x2600)            //TODO: arbitrary choice...
#define _REL_ANGLEIOC(_n)		(_IOC(_REL_ANGLEIOCBASE, _n))

#endif /* _DRV_REL_ANGLE_H */
