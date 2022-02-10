/*
 ================================================================================================
 Name        : fan_control.c
 Author      : Hesham Medhat
 Description : Control the speed of fan according to the temperature using LM35 Temperature Sensor
 Date        : 12/10/2021
 ================================================================================================
 */
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "lcd.h"
#include "adc_updated.h"

int main (void)
{
	uint8 temp;
	ADC_ConfigType ADC_Config = {INTERNAL_VREF,DIVIDE_8};
	ADC_init(&ADC_Config);
	DcMotor_Init();
	LCD_init();
	LCD_displayStringRowColumn(0,2,"Fan is ");
	LCD_displayStringRowColumn(1,2,"Temp =    C");
	while (1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(1,9);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		if (temp < 30)
		{
			LCD_displayStringRowColumn(0,9,"OFF");
			DcMotor_Rotate(STOP,0);
		}
		else if ((temp >= 30) && (temp < 60))
		{
			LCD_displayStringRowColumn(0,9,"ON ");
			DcMotor_Rotate(CW,25);
		}
		else if ((temp >= 60) && (temp < 90))
		{
			LCD_displayStringRowColumn(0,9,"ON ");
			DcMotor_Rotate(CW,50);
		}
		else if ((temp >= 90) && (temp < 120))
		{
			LCD_displayStringRowColumn(0,9,"ON ");
			DcMotor_Rotate(CW,75);
		}
		else if (temp >= 120)
		{
			LCD_displayStringRowColumn(0,9,"ON ");
			DcMotor_Rotate(CW,100);
		}
	}
}
