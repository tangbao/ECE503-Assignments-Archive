#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
using namespace std;
#include"twodimensionalshape.h"

#define PI 3.1415926535898
// a circle has a radius
class Circle : public TwoDimensionalShape {
public:
	Circle();//constuctor
	void setR(double);
	double getR() const;
	//override these functions.
	virtual double getArea() const;

	virtual void print() const;

private:
	double r;
};

#endif
