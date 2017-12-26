#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
using namespace std;
#include"twodimensionalshape.h"
//a triangle has edge
class Triangle : public TwoDimensionalShape {
public:
	Triangle();
	void setEdge(double);
	double getEdge() const;
	//override these functions.
	virtual double getArea() const;

	virtual void print() const;

private:
	double edge;
};


#endif // !TRIANGLE_H

