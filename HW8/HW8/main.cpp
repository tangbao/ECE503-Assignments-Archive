/*

Homework 8 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/27

Description: INHERITANCE

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include<iostream>
using namespace std;

//include header files of four shapes
#include"circle.h"
#include"triangle.h"
#include"sphere.h"
#include"regulartetrahedron.h"

//functions for create shapes
void createCircle();
void createTriangle();
void createSphere();
void createRegularTetrahedron();

int main()
{
	int choice = -1; //user's choice
	bool flag = false; //when the user do not exit the program
	while (!flag)
	{
		cout << endl << "Please choose a shape or 0 to exit:" << endl;
		cout << "1. Circle" << endl;
		cout << "2. Triangle" << endl;
		cout << "3. Sphere" << endl;
		cout << "4. Regular Tetrahedron" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');
		//call corressponding function to create shapes
		switch (choice) {
		case 1:
			createCircle();
			break;
		case 2:
			createTriangle();
			break;
		case 3:
			createSphere();
			break;
		case 4:
			createRegularTetrahedron();
			break;
		case 0:
			flag = true; //quit
			break;
		default:
			cout << "Error: Wrong input." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

void createCircle()
{
	Circle c; //create a circle object
	double x, y, r; //x-coordinate, y-coordinate and the radius of the circle
	cout << "You have chosen the circle." << endl;
	cout << "Please enter the center of circle (x-coordinate and then y-coordinate):" << endl;
	cin >> x >> y;
	c.setX(x);// set the center of circle
	c.setY(y);
	cout << "Please enter the radius of the circle:" << endl;
	cin >> r;
	if (r <= 0) {
		cout << "Invalid radius." << endl;
	}
	else {
		c.setR(r); //set the radius
		c.print();//print the infomation of circle
	}
	
}

void createTriangle()
{
	Triangle t;//create a triangle object
	double x, y, edge;//x-coordinate, y-coordinate and the edge of the triangle
	cout << "You have chosen the triangle." << endl;
	cout << "Please enter the center of triangle (x-coordinate and then y-coordinate):" << endl;
	cin >> x >> y;
	t.setX(x); //set the center of the triangle
	t.setY(y);
	cout << "Please enter the edge length of the triangle:" << endl;
	cin >> edge;
	if (edge <= 0) {
		cout << "Invalid edge." << endl;
	}
	else {
		t.setEdge(edge); //set the edge length
		t.print(); //print the infomation of triangle
	}
}

void createSphere()
{
	Sphere s; //create a sphere object
	double x, y, z, r;//x-coordinate, y-coordinate, z-coordinate and the radius of the sphere
	cout << "You have chosen the sphere." << endl;
	cout << "Please enter the center of sphere (x-coordinate, y-coordinate and then z-coordinate):" << endl;
	cin >> x >> y >> z;
	s.setX(x); //set the center of sphere
	s.setY(y);
	s.setZ(z);
	cout << "Please enter the radius of the sphere:" << endl;
	cin >> r;
	if (r <= 0) {
		cout << "Invalid radius." << endl;
	}
	else {
		s.setR(r);
		s.print();//print the info of sphere
	}
}

void createRegularTetrahedron()
{
	RegularTetrahedron rt;//create a RegualarTetrahedron object
	double x, y, z, edge;//x-coordinate, y-coordinate, z-coordinate and the edge of the regular tetrahedron
	cout << "You have chosen the regular tetrahedron." << endl;
	cout << "Please enter the center of regular tetrahedron (x-coordinate, y-coordinate and then z-coordinate):" << endl;
	cin >> x >> y >> z;
	rt.setX(x);//set the center of regular tetrahedron
	rt.setY(y);
	rt.setZ(z);
	cout << "Please enter the edge length of the regular tetrahedron:" << endl;
	cin >> edge;
	if (edge <= 0) {
		cout << "Invalid edge." << endl;
	}
	else {
		rt.setEdge(edge); //set edge
		rt.print();// print the info of regular tetrahedron
	}
}