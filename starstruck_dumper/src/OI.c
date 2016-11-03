/*
 * OI.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveLeft()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveRight()
{
	return joystickGetAnalog(1, 2);
}

int OIGetDriveY()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveX()
{
	return joystickGetAnalog(1, 4);
}

int OIGetDumper()
{
	return joystickGetAnalog(1, 2);
}

int OIGetDumperLow()
{
	return joystickGetDigital(2, 8, JOY_DOWN);
}

int OIGetDumperTravel()
{
	return joystickGetDigital(2, 8, JOY_RIGHT);
}

int OIGetDumperHigh()
{
	return joystickGetDigital(2, 8, JOY_UP);
}

int OIGetDumperDump()
{
	return joystickGetDigital(2, 5, JOY_UP) && joystickGetDigital(2, 6, JOY_UP);
}
