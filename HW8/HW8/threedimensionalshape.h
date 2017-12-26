#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H
#include<iostream>
using namespace std;
#include "shape.h"
// a three dimensional shape has Z-coordinate, area and volume
class ThreeDimensionalShape : public Shape {
public:
	void setZ(double);
	double getZ() const;
	//override these functions.
	virtual double getArea() const = 0;
	virtual double getVolume() const = 0;
	virtual void print() const = 0;

protected:
	double z;
};

#endif