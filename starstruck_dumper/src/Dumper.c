/*
 * Shovel.c
 *
 *  Created on: Aug 16, 2016
 *      Author: Erik
 */

#include "main.h"

Dumper * initDumper(PantherMotor topLeft, PantherMotor frontLeft, PantherMotor backLeft,
		PantherMotor topRight, PantherMotor frontRight, PantherMotor backRight)
{
	Dumper * newDumper = malloc(sizeof(Dumper));
	newDumper->topLeft = topLeft;
	newDumper->frontLeft = frontLeft;
	newDumper->backLeft = backLeft;
	newDumper->topRight = topRight;
	newDumper->frontRight = frontRight;
	newDumper->backRight = backRight;

	return newDumper;
}

void runDumper(Dumper * shovel, int speed)
{
	setPantherMotor(shovel->topLeft, speed);
	setPantherMotor(shovel->frontLeft, speed);
	setPantherMotor(shovel->backLeft, speed);
	setPantherMotor(shovel->topRight, speed);
	setPantherMotor(shovel->frontRight, speed);
	setPantherMotor(shovel->backRight, speed);
}
