#include<iostream>
using namespace std;
#include"circle.h"

Circle::Circle()
{
	setX(0);
	setY(0);
	setR(0);
}

void Circle::setR(double rValue)
{
	r = rValue;
}

double Circle::getR() const
{
	return r;
}

double Circle::getArea() const //calculate the value of area
{
	return PI * getR() * getR();
}

void Circle::print() const //print the basic info of circle, like center , radius, and area
{
	cout << "The circle with raduis " << getR() << " that is located at (" << getX() << ", " <<  getY() << ") has:" << endl;
	cout << "An area of " << getArea() << endl;
}
