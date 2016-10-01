/*
 * Shovel.h
 *
 *  Created on: Aug 16, 2016
 *      Author: Erik
 */

#ifndef INCLUDE_DUMPER_H_
#define INCLUDE_DUMPER_H_

struct Dumper {
	PantherMotor topLeft;
	PantherMotor frontLeft;
	PantherMotor backLeft;
	PantherMotor topRight;
	PantherMotor frontRight;
	PantherMotor backRight;
}typedef Dumper;

Dumper * initDumper(PantherMotor topLeft, PantherMotor frontLeft, PantherMotor backLeft,
		PantherMotor topRight, PantherMotor frontRight, PantherMotor backRight);
void runDumper(Dumper * dumper, int speed);

#endif /* INCLUDE_DUMPER_H_ */
