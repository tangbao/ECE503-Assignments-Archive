#include<iostream>
using namespace std;
#include "triangle.h"

Triangle::Triangle()
{
	setX(0);
	setY(0);
	setEdge(0);
}

void Triangle::setEdge(double edgeValue)
{
	edge = edgeValue;
}

double Triangle::getEdge() const
{
	return edge;
}

double Triangle::getArea() const //calculate the area
{
	return sqrt(3) / 4.0 * getEdge() * getEdge();
}

void Triangle::print() const //print basic infos of a triangle like edge length, center and area
{
	cout << "The triangle with edge length " << getEdge() << " that is located at (" << getX() << ", " << getY() << ") has:" << endl;
	cout << "An area of " << getArea() << endl;
}
