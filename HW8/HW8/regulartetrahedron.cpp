#include<iostream>
using namespace std;

#include "regulartetrahedron.h"

RegularTetrahedron::RegularTetrahedron()
{
	setX(0);
	setY(0);
	setZ(0);
	setEdge(0);
}

void RegularTetrahedron::setEdge(double eValue)
{
	edge = eValue;
}

double RegularTetrahedron::getEdge() const
{
	return edge;
}

double RegularTetrahedron::getArea() const//calculate area
{
	return 1.0 * sqrt(3) * getEdge() * getEdge();//to get a double result by 1.0
}

double RegularTetrahedron::getVolume() const//calculate volumn
{
	return 1.0 / 12.0 * sqrt(2) * getEdge() * getEdge() * getEdge();
}

void RegularTetrahedron::print() const //print basic infomation of regular terahedron like edge length, center, area and volume
{
	cout << "The regular terahedron with edge length " << getEdge() << " that is located at (" << getX() << ", " << getY() << ", " << getZ() << ") has:" << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
}
