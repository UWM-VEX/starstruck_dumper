/*
 * Utilities.c
 *
 *  Created on: Feb 20, 2015
 *      Author: Erik
 */

#include "main.h"

/**
 * Returns a number limited between the min and max.
 */
int limit(int num, int max, int min)
{
	if(num > max) return max;
	else if(num < min) return min;
	else return num;
}

/**
 * Returns the absolute value of an input.
 */
int abs(int num)
{
	if(num < 0) return -num;
	else return num;
}

/**
 * Returns if realNum is in a range of plus or minus deadBand of desiredNum.
 */
int inDeadBand(int realNum, int desiredNum, int deadBand)
{
	return (abs(realNum - desiredNum) < deadBand);
}

double encoderToInches(int encoderLines, double wheelDiameter)
{
	return ((encoderLines / 360.0) * PI * wheelDiameter);
}

double absDouble(double num)
{
	if(num < 0) return -num;
	else return num;
}

int inDeadBandDouble(double realNum, double desiredNum, double deadBand)
{
	return (absDouble(realNum - desiredNum) < deadBand);
}

int enforceDeadband(int input, int desiredNumber, int deadband)
{
	if(abs(input - desiredNumber) <= deadband)
		return 0;
	else
		return input;
}
