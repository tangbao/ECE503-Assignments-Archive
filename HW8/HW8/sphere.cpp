#include<iostream>
using namespace std;

#include "sphere.h"

Sphere::Sphere()
{
	setX(0);
	setY(0);
	setZ(0);
	setR(0);
}

void Sphere::setR(double rValue)
{
	r = rValue;
}

double Sphere::getR() const
{
	return r;
}

double Sphere::getArea() const //calculate area
{
	return 4.0 * PI * getR() * getR();
}
 
double Sphere::getVolume() const//calculate volume
{
	return 4.0 / 3.0 * PI * getR() * getR() * getR();
}

void Sphere::print() const //print basic infomation of sphere like radius, center, area and volume
{
	cout << "The sphere with raduis " << getR() << " that is located at (" << getX() << ", " << getY() << ", " << getZ() << ") has:" << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
}
