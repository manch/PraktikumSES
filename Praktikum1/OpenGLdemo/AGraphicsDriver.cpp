#include "AGraphicsDriver.h"

void AGraphicsDriver::setDrawRoutine(void(*pt2drawFunction)())
{
	mDrawFunction = pt2drawFunction;
}

