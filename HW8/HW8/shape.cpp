#include<iostream>
using namespace std;
#include"shape.h"

void Shape::setX(double xValue)
{
	x = xValue;
}

void Shape::setY(double yValue)
{
	y = yValue;
}

double Shape::getX() const
{
	return x;
}

double Shape::getY() const
{
	return y;
}
