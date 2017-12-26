#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
using namespace std;
//the base class of all the shapes.
//a shape has an X and a Y at least, so there are set and get functions for x and y.
class Shape {
public:
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;
	//override these functions.
	virtual void print() const = 0; //print the infomation of shape

protected:
	double x, y;
};
#endif