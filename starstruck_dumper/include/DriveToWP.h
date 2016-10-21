/*
 * PropDriveToWayPoint.h
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#ifndef PROPDRIVETOWAYPOINT_H_
#define PROPDRIVETOWAYPOINT_H_

#include "main.h"

#define GYRO_INVERTED 1

struct DriveToWPProperties {

	Drive drive;
	double magnitudeDB;
	double magnitudeBreakingDistance;
	long magnitudeRampUpTime;
	int magnitudeMaxSpeed;
	int magnitudeMinSpeed;
	int rotationDB;
	int rotationBreakingDistance;
	int rotationMaxSpeed;
	int rotationMinSpeed;
	double wheelDiameter;
	int encoderLines;
	int gyroInverted;
	unsigned long holdTime;

}typedef DriveToWPProperties;

struct DriveToWP {

	DriveToWPProperties *properties;
	double distance;
	int rotation;
	int isFinished;
	int reachedDistance;
	int reachedRotation;
	unsigned long timeAchievedGoodLocation;

} typedef DriveToWP;

DriveToWPProperties * initDriveToWPProperties(Drive drive, double magnitudeDB,
		double magnitudeBreakingDistance, long magnitudeRampUpTime, int magnitudeMaxSpeed,
		int magnitudeMinSpeed, int rotationDB, int rotationBreakingDistance,
		int rotationMaxSpeed, int rotationMinSpeed, double wheelDiameter,
		int encoderLines, int gyroInverted, unsigned long holdTime);
DriveToWP * initDriveToWP(DriveToWPProperties * properties, double distance, int rotation);
void driveToWP(DriveToWP * step);

#endif /* PROPDRIVETOWAYPOINT_H_ */
