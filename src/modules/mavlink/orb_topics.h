/****************************************************************************
 *
 *   Copyright (C) 2008-2012 PX4 Development Team. All rights reserved.
 *   Author: @author Lorenz Meier <lm@inf.ethz.ch>
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
 * @file orb_topics.h
 * Common sets of topics subscribed to or published by the MAVLink driver,
 * and structures maintained by those subscriptions.
 */
#pragma once

#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/rc_channels.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_global_position.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/offboard_control_setpoint.h>
#include <uORB/topics/vehicle_command.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_vicon_position.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <uORB/topics/vehicle_rates_setpoint.h>
#include <uORB/topics/vehicle_control_mode.h>
#include <uORB/topics/optical_flow.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/actuator_controls_effective.h>
#include <uORB/topics/actuator_controls.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/manual_control_setpoint.h>
#include <uORB/topics/telemetry_status.h>
#include <uORB/topics/debug_key_value.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/battery_status.h>
#include <drivers/drv_rc_input.h>
#include <uORB/topics/navigation_capabilities.h>
#include <uORB/topics/vehicle_paraglider_angle.h>
#include <uORB/topics/xsens_sensor_combined.h>
#include <uORB/topics/xsens_vehicle_attitude.h>
#include <uORB/topics/xsens_vehicle_global_position.h>
//#include <uORB/topics/xsens_vehicle_gps_position.h>
#include <uORB/topics/paraglider_altitude_estimator.h>

struct mavlink_subscriptions {
	int sensor_sub;
	int att_sub;
	int global_pos_sub;
	int act_0_sub;
	int act_1_sub;
	int act_2_sub;
	int act_3_sub;
	int gps_sub;
	int man_control_sp_sub;
	int safety_sub;
	int actuators_sub;
	int armed_sub;
	int actuators_effective_sub;
	int local_pos_sub;
	int spa_sub;
	int spl_sub;
	int triplet_sub;
	//int debug_key_value;// todo Disabled von Carlo zum sparen von subscriptions (Werden f�r XSENS-Messages ben�tigt)
	int input_rc_sub;
	int optical_flow;
	int rates_setpoint_sub;
	int home_sub;
	int airspeed_sub;
	int navigation_capabilities_sub;
	int position_setpoint_triplet_sub;
	int vehicle_paraglider_angle_sub;
	int xsens_sensor_combined_sub;
	//int xsens_attitude_sub;
	int para_alt_estim_sub;
//	int xsens_global_position_sub;
		//int xsens_gps_position_sub;
};

extern struct mavlink_subscriptions mavlink_subs;


/** Global position */
extern struct vehicle_global_position_s global_pos;

/** Local position */
extern struct vehicle_local_position_s local_pos;

/** navigation capabilities */
extern struct navigation_capabilities_s nav_cap;

/** Vehicle status */
extern struct vehicle_status_s v_status;

/** Position setpoint triplet */
extern struct position_setpoint_triplet_s pos_sp_triplet;

/** RC channels */
//extern struct rc_channels_s rc;// todo Disabled von Carlo zum sparen von subscriptions (Werden f�r XSENS-Messages ben�tigt)

/** Actuator armed state */
extern struct actuator_armed_s armed;

// todo Carlo: Flags for selected Parameter-Transmission to QGroundControl
typedef struct sel_par_QGC{
	uint8_t TWIST_ANGLE_SEL : 1;
	uint8_t XSENS_ATTITUDE_SEL :1;
	uint8_t XSENS_GLOB_POS :1;
	uint8_t XSENS_GPS_POS_SEL :1;
	uint8_t XSENS_SENS_COMB_SEL :1;
	uint8_t XSENS_SENS_RAW_SEL :1;
	uint8_t PARA_ALT_ESTIM :1;
}sel_par_QGC_t;

// todo Carlo: Selected Parameters to send to QGC
extern sel_par_QGC_t qgc_selected_params;


/** Worker thread starter */
extern pthread_t uorb_receive_start(void);
