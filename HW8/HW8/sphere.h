#ifndef SPHERE_H
#define SPHERE_H
#include<iostream>
using namespace std;
#include"threedimensionalshape.h"
#define PI 3.1415926535898
//a sphere has a radius
class Sphere : public ThreeDimensionalShape {
public:
	Sphere();
	void setR(double);
	double getR() const;
	//override these functions.
	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void print() const;
private:
	double r;
};

#endif // !SPHERE_H

