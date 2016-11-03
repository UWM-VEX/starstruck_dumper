/*
 * AutoDumper.c
 *
 *  Created on: Nov 3, 2016
 *      Author: Erik
 */
#include "main.h"

AutoDumper * initAutoDumper(Dumper * dumper, int height)
{
	AutoDumper * newStep = malloc(sizeof(AutoDumper));

	newStep->isFinished = 0;
	newStep->height = height;
	newStep->dumper = dumper;

	return newStep;
}
