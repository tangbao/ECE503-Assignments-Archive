#ifndef REGULARTETRAHEDRON_H
#define REGULARTETRAHEDRON_H
#include<iostream>
using namespace std;
#include"threedimensionalshape.h"
//a regular tetrahedron has edges.
class RegularTetrahedron : public ThreeDimensionalShape{
public:
	RegularTetrahedron();
	void setEdge(double);
	double getEdge() const;
	//override these functions.
	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void print() const;
private:
	double edge;

};


#endif