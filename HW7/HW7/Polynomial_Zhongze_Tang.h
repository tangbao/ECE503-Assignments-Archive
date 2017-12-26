/*

Homework 7 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/21

Description: a polynomial class

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#define MAX_DEGREE 6 //the greatest degree of an input polynomial is 6(x^6)
using namespace std;

class Polynomial {
	friend ostream &operator<<(ostream &, const Polynomial &);
	
public:
	Polynomial(); //constructor function
	~Polynomial(); //desructor function
	void setPolynomial(); //set a polynomial
	double* getPolynomial(); //get a polynomial's all coefficients and exponents

	//overload operators =, +, +=, -, -=, *, *=, respectively
	void operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator-=(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	Polynomial operator*=(const Polynomial&);

private:
	double terms[MAX_DEGREE * 2 + 1]; //the array subscript means exponent, and the value of a array element means coefficient
	int numOfTerms; //the numbers of a term that the polynomial contains
};


#endif // !POLYNOMIAL_H

