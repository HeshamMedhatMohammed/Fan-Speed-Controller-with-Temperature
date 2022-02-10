/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the DC_motor driver
 *
 * Author: Hesham Medhat
 *
 *******************************************************************************/

#include "gpio.h"
#include "dc_motor.h"
#include "pwm.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC MOTOR:
 * 1. Setup the DC MOTOR pins directions by use the GPIO driver.
 * 2. Stop the DC MOTOR at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_A_PORT_ID, DC_A_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_B_PORT_ID, DC_B_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(DC_A_PORT_ID, DC_A_PIN_ID, 0);
	GPIO_writePin(DC_B_PORT_ID, DC_B_PIN_ID, 0);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty ;
	if (state == 0)
	{
		GPIO_writePin(DC_A_PORT_ID, DC_A_PIN_ID, 0);
		GPIO_writePin(DC_B_PORT_ID, DC_B_PIN_ID, 0);
	}
	else if (state == 1)
	{
		GPIO_writePin(DC_A_PORT_ID, DC_A_PIN_ID, 0);
		GPIO_writePin(DC_B_PORT_ID, DC_B_PIN_ID, 1);
	}
	else if (state == 2)
	{
		GPIO_writePin(DC_A_PORT_ID, DC_A_PIN_ID, 1);
		GPIO_writePin(DC_B_PORT_ID, DC_B_PIN_ID, 0);
	}
	duty = (uint8)(((float32)speed/100)*255);
	PWM_Timer0_Start (duty);
}
