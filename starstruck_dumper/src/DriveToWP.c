/*
 * DriveToWP.c
 *
 *  Created on: Jul 27, 2015
 *      Author: Erik
 */

#include "main.h"

DriveToWPProperties * initDriveToWPProperties(Drive drive, double magnitudeDB,
		double magnitudeBreakingDistance, long magnitudeRampUpTime, int magnitudeMaxSpeed,
		int magnitudeMinSpeed, int rotationDB, int rotationBreakingDistance,
		int rotationMaxSpeed, int rotationMinSpeed, double wheelDiameter,
		int encoderLines, int gyroInverted, unsigned long holdTime)
{
	DriveToWPProperties * newDriveToWPProperties = malloc(sizeof(DriveToWPProperties));

	newDriveToWPProperties->drive = drive;
	newDriveToWPProperties->magnitudeDB = magnitudeDB;
	newDriveToWPProperties->magnitudeBreakingDistance = magnitudeBreakingDistance;
	newDriveToWPProperties->magnitudeRampUpTime = magnitudeRampUpTime;
	newDriveToWPProperties->magnitudeMaxSpeed = magnitudeMaxSpeed;
	newDriveToWPProperties->magnitudeMinSpeed = magnitudeMinSpeed;
	newDriveToWPProperties->rotationDB = rotationDB;
	newDriveToWPProperties->rotationBreakingDistance = rotationBreakingDistance;
	newDriveToWPProperties->rotationMaxSpeed = rotationMaxSpeed;
	newDriveToWPProperties->rotationMinSpeed = rotationMinSpeed;
	newDriveToWPProperties->wheelDiameter = wheelDiameter;
	newDriveToWPProperties->encoderLines = encoderLines;
	newDriveToWPProperties->gyroInverted = gyroInverted;
	newDriveToWPProperties->holdTime = holdTime;

	return newDriveToWPProperties;
}

DriveToWP * initDriveToWP(DriveToWPProperties * properties, double distance, int rotation)
{
	DriveToWP * newDriveToWP = malloc(sizeof(DriveToWP));
	newDriveToWP->distance = distance;
	newDriveToWP->rotation = rotation;
	newDriveToWP->properties = properties;
	newDriveToWP->reachedDistance = 0;
	newDriveToWP->reachedRotation = 0;
	newDriveToWP->timeAchievedGoodLocation = 0;
	return newDriveToWP;
}

void driveToWP(DriveToWP * step)
{
	double averageEncoder = ((double)(encoderGet(step->properties->drive.leftEncoder)
			- encoderGet(step->properties->drive.rightEncoder)) / 2);
	double distancePV = averageEncoder * encoderToInches(step->properties->encoderLines,
			step->properties->wheelDiameter);
	int rotationPV = gyroGet(step->properties->drive.gyro);

	if(step->properties->gyroInverted)
	{
		rotationPV *= -1;
	}

	double distanceError = step->distance - distancePV;
	int rotationError = step->rotation - rotationPV;

	int inDistanceDB = (absDouble(distanceError) < step->properties->magnitudeDB);

	if(inDistanceDB)
	{
		step->reachedDistance = 1;
	}

	int inRotationDB = abs(rotationError) < step->properties->rotationDB;

	if(inRotationDB)
	{
		step->reachedRotation = 1;
	}

	int magnitude = 0;
	int rotation = 0;

	// If it has not reached both its distance and rotation targets
	if( ! (step->reachedDistance && step->reachedRotation))
	{
		if(inDistanceDB)
		{
			magnitude = 0;
		}
		else if(absDouble(distanceError) < step->properties->magnitudeBreakingDistance)
		{
			// slow down
			// magnitude = (Vmax - Vmin)(SP - PV)/Breaking Distance + Vmin
			magnitude = (int) ((step->properties->magnitudeMaxSpeed -
					step->properties->magnitudeMinSpeed) * (distanceError)) /
							step->properties->magnitudeBreakingDistance +
							step->properties->magnitudeMinSpeed;
		}
		else if(autonomousInfo.elapsedTime < step->properties->magnitudeRampUpTime)
		{
			// speed up
			// magnitude = (Vmax - Vmin)*t/ramp up time + Vmin
			magnitude = (int) ((step->properties->magnitudeMaxSpeed -
					step->properties->magnitudeMinSpeed) * autonomousInfo.elapsedTime
							/ step->properties->magnitudeRampUpTime +
							step->properties->magnitudeMinSpeed);
		}
		else
		{
			// coast
			magnitude = step->properties->magnitudeMaxSpeed;
		}

		if(inRotationDB)
		{
			// no rotation
			rotation = 0;
		}
		else if(abs(rotationError) < step->properties->rotationBreakingDistance)
		{
			// turn slowly
			rotation = step->properties->rotationMinSpeed;
		}
		else
		{
			// turn quickly
			rotation = step->properties->rotationMaxSpeed;
		}

		step->isFinished = 0;
	}
	else
	{
		// If at some point we've reached a good distance and a good rotation
		int goodDistance = 0;

		// Check that we're at a good distance, if we're not, slowly move to a good distance
		if(absDouble(distanceError) < step->properties->magnitudeDB)
		{
			goodDistance = 1;
		}
		else
		{
			magnitude = step->properties->magnitudeMinSpeed;
		}

		int goodRotation = 0;

		// Check that we're at a good rotation, if we're not, slowly move to a good rotation
		if(abs(rotationError) < step->properties->rotationDB)
		{
			goodRotation = 1;
		}
		else
		{
			rotation = step->properties->rotationMinSpeed;
		}

		if(goodDistance && goodRotation)
		{
			if(step->timeAchievedGoodLocation != 0)
			{
				step->timeAchievedGoodLocation = millis();
			}

			if(millis() - step->timeAchievedGoodLocation > step->properties->holdTime)
			{
				step->isFinished = 1;
			}
		}
		else
		{
			step->timeAchievedGoodLocation = 0;
		}
	}

	if(magnitude != 0)
	{
		magnitude = limit(magnitude, step->properties->magnitudeMaxSpeed,
				step->properties->magnitudeMinSpeed);
	}

	if(rotation != 0)
	{
		rotation = limit(rotation, step->properties->rotationMaxSpeed,
				step->properties->rotationMinSpeed);
	}

	if(distanceError < 0)
	{
		magnitude *= -1;
	}

	if(rotationError < 0)
	{
		rotation *= -1;
	}

	arcadeDrive(step->properties->drive, magnitude, rotation);
}
