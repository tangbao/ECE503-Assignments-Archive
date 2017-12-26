/*

Homework 7 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/21

Description: polynimial and operator overloaded

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include<iostream>
#include"Polynomial_Zhongze_Tang.h"
using namespace std;

int main() {
	Polynomial Pa, Pb, Pc, Pd;
	Pa.setPolynomial(); //get Pa and Pb
	Pb.setPolynomial();
	cout << "The first Polynomial is: " << Pa << endl;
	cout << "The second Polynomial is: " << Pb << endl;

	Pc = Pa; Pd = Pa;// += & -= will change the value of Pa, so use Pc and Pd to replace Pa when using -= & *=

	cout << "Adding polynomial yields: " << (Pa + Pb) << endl;
	cout << "+= the polynomial yields: " << (Pa += Pb) << endl;

	cout << "Subtracting the polynomial yield: " << (Pc - Pb) << endl;
	cout << "-= the polynomials yields: " << (Pc -= Pb) << endl;

	cout << "Multiplying the polynomials yields: " << (Pd * Pb) << endl;
	cout << "*= the polynomial yields: " << (Pd *= Pb) << endl;

	system("pause");
	return 0;
}