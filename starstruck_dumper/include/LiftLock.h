/*
 * AntiTippers.h
 *
 *  Created on: Nov 10, 2016
 *      Author: Erik
 */

#ifndef INCLUDE_LIFTLOCK_H_
#define INCLUDE_LIFTLOCK_H_

struct LiftLock{

	int port;

}typedef LiftLock;

LiftLock * initLiftLock(int port);

void liftLockIn(LiftLock * liftLock);

void liftLockOut(LiftLock * liftLock);

#endif /* INCLUDE_LIFTLOCK_H_ */
