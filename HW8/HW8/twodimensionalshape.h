#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
#include"shape.h"
//two dimensional shapde has area.
class TwoDimensionalShape : public Shape {
public:
	//override these functions.
	virtual double getArea() const=0;
	virtual void print() const = 0;
};

#endif
