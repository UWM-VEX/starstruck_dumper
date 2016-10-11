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
	PantherMotor bottomLeft;
	PantherMotor topRight;
	PantherMotor frontRight;
	PantherMotor backRight;
	PantherMotor bottomRight;
}typedef Dumper;

Dumper * initDumper(PantherMotor topLeft, PantherMotor frontLeft, PantherMotor backLeft,
		PantherMotor bottomLeft, PantherMotor topRight, PantherMotor frontRight,
		PantherMotor backRight, PantherMotor bottomRight);
void runDumper(Dumper * dumper, int speed);

#endif /* INCLUDE_DUMPER_H_ */
