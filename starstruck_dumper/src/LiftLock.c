/*
 * AntiTippers.c
 *
 *  Created on: Nov 10, 2016
 *      Author: Erik
 */

#include "main.h"

#define LIFT_LOCK_IN HIGH
#define LIFT_LOCK_OUT LOW

LiftLock * initLiftLock(int port)
{
	LiftLock * newLiftLock = malloc(sizeof(AntiTippers));
	newLiftLock->port = port;

	pinMode(port, OUTPUT);

	digitalWrite(port, LIFT_LOCK_OUT);

	return newLiftLock;
}

void liftLockIn(LiftLock * liftLock)
{
	digitalWrite(liftLock->port, LIFT_LOCK_IN);
}

void liftLockOut(LiftLock * liftLock)
{
	digitalWrite(liftLock->port, LIFT_LOCK_OUT);
}
