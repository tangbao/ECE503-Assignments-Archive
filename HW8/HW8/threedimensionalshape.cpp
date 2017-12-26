#include <iostream>
using namespace std;
#include "threedimensionalshape.h"

void ThreeDimensionalShape::setZ(double zValue)
{
	z = zValue;
}

double ThreeDimensionalShape::getZ() const
{
	return z;
}