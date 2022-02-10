/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the DC_motor driver
 *
 * Author: Hesham Medhat
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* DC MOTOR HW Ports and Pins Ids */
#define DC_A_PORT_ID                 PORTB_ID
#define DC_A_PIN_ID                  PIN0_ID

#define DC_B_PORT_ID                 PORTB_ID
#define DC_B_PIN_ID                  PIN1_ID

#define DC_ENABLE_PORT_ID            PORTB_ID
#define DC_ENABLE_PIN_ID             PIN3_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC MOTOR:
 * 1. Setup the DC MOTOR pins directions by use the GPIO driver.
 * 2. Stop the DC MOTOR at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor CW/ or A-CW or
	  stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the
      required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
