/*

Homework 7 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/21

Description: the implements of polynomial class

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include<iostream>
#include"Polynomial_Zhongze_Tang.h"
using namespace std;

Polynomial::Polynomial() { //initialize the polynomial, set all the items as 0
	this->numOfTerms = 0;
	for (int i = 0; i < MAX_DEGREE * 2 + 1; i++) {
		this->terms[i] = 0;
	}
}

Polynomial::~Polynomial() {
	//I think there is nothing to do
}

void Polynomial::setPolynomial() {
	//coefficient and exponent 系数和指数
	while (numOfTerms <= 0 || numOfTerms > MAX_DEGREE + 1) { //while the numOfTerms is invalid, 0< numOfTerms <=7
		cout << "Enter the number of polynomial terms(from 1 to " << MAX_DEGREE + 1 <<"): ";
		cin >> numOfTerms; //input numOfTerms
		cin.clear();
		cin.ignore(1024, '\n');
	}
	for (int i = 0; i < numOfTerms; i++) { //get the coefficient and exponent of each term
		int coefficient = -1, exponent = -1;
		while (exponent < 0 || exponent >= MAX_DEGREE + 1) { //while the exponent is invalid
			cout << "Enter coefficient and exponent: ";
			cin >> coefficient >> exponent; //input coefficient and exponent
			//cin.clear();
			//cin.ignore(1024, '\n');
			if (exponent >= 0 && exponent < MAX_DEGREE + 1) { //while the exponent is valid
				if (terms[exponent] != 0) { //if the coefficient of this exponent has been set, it's invalid
					exponent = -1;
					cout << "You cannot enter two terms having the same exponent!" << endl;
				}
				else {
					if (coefficient == 0) { //the coefficient of a term that user is inputing cannot be 0, or the numOfTerms is wrong
						exponent = -1;
						cout << "An term you are inputing cannot have a 0 coefficient!" << endl;
					}
					else {
						terms[exponent] = coefficient; //set the term
					}
				}
			}
		}
	}
}

double * Polynomial::getPolynomial()
{
	return terms;
}

void Polynomial::operator=(const Polynomial &a)
{
	//copy the data of the Polynomial a
	numOfTerms = a.numOfTerms;
	for (int i = 0; i < MAX_DEGREE * 2 + 1; i++)
		terms[i] = a.terms[i];
}

Polynomial Polynomial::operator+(const Polynomial &P)
{	
	Polynomial result;
	for (int i = 0; i < MAX_DEGREE + 1; i++) {
		result.terms[i] = terms[i] + P.terms[i]; //add the coefficient of each exponent
		if (result.terms[i] != 0)
			result.numOfTerms++; //renew the numOfTerms
	}
	return result;
}

Polynomial Polynomial::operator+=(const Polynomial &P)
{
	*this = *this + P;	//use + to plus two polynomials
	return *this;	//the operator += has to change the data of *this polynomial
}

Polynomial Polynomial::operator-(const Polynomial &P)
{
	Polynomial result;
	for (int i = 0; i < MAX_DEGREE + 1; i++) {
		result.terms[i] = terms[i] - P.terms[i];  //subtract the coefficient of each exponent
		if (result.terms[i] != 0)
			result.numOfTerms++; //renew the numOfTerms
	}
	return result;
}

Polynomial Polynomial::operator-=(const Polynomial &P)
{
	*this = *this - P; //use - to plus two polynomials
	return *this; //the operator -= has to change the data of *this polynomial
}

Polynomial Polynomial::operator*(const Polynomial &P)
{
	Polynomial result, result_fail;
	for (int i = 0; i < MAX_DEGREE + 1; i++)
		for (int j = 0; j < MAX_DEGREE + 1; j++) {
			if (terms[i] * P.terms[j] !=0) { //when the coefficient of the result != 0
				if (i + j > MAX_DEGREE * 2) { //check if the exponent is too large
					result_fail.numOfTerms = -1; //mark the fail result
					return result_fail;
				}
				else{
					result.terms[i + j] = result.terms[i + j] + terms[i] * P.terms[j]; //caculate the coefficient of result.terms[i+j]
				}
			}
		}

	for (int i = 0; i < MAX_DEGREE * 2 + 1; i++)
		if (result.terms[i] != 0)
			result.numOfTerms++; //renew the numOfTerms
	return result;
}

Polynomial Polynomial::operator*=(const Polynomial &P)
{
	(*this) = (*this * P);
	return (*this); //the operator *= has to change the data of *this polynomial
}

ostream & operator<<(ostream &output, const Polynomial&P)
{
	int cnt = 0; //it is the %cnt% term to be printed
	if (P.numOfTerms == -1){ //when it comes from a failed caculation
		output << "Error: DRGREE TOO GREAT.";
		return output;
	}
	else if (P.numOfTerms == 0) { //when the polynomial is 0
		output << "0";
		return output;
	}
	for (int i = 0; i < MAX_DEGREE * 2 + 1; i++) {//coefficient and exponent 系数和指数
		if (P.terms[i] != 0) { //when the coeffient of the term != 0, it can be printed
			++cnt;
			if (i == 0) { //when the exponent == 0, the "x" donot need to be printed
				if (cnt != 1 && P.terms[i] > 0) //the first item do not need a + before it
					output << "+";
				output << P.terms[i]; //print the coefficient of it directly
			}
			else {
				if (cnt != 1 && P.terms[i] > 0) //if the coefficient > 0, it should has a + before it
					output << "+"; 
				if (P.terms[i] == 1) //if the coefficient == 1 or -1, the 1 or -1 does not need to be printed
					output << "x";
				else if (P.terms[i] == -1)
					output << "-x";
				else output << P.terms[i] << "x";
			}

			if (i != 1 && i != 0) //if the exponent is 0 or 1, there is not a "^i" behind the term 
				output << "^" << i;
		}
	}
	return output;
}
