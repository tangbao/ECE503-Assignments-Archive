#ifndef PACKAGE_H
#define PACKAGE_H
#include<string.h>
using namespace std;
#include"customer.h"

//a package object contains all the information of a normal package

class Package {
public:
	Package(Customer, Customer, double, double);

	virtual double calculateCost() const;//should be overrided by it's subclass

	void setSender(Customer);
	void setRecipient(Customer);
	void setWeight(double);
	void setCostperounce(double);

	virtual string getServiceName() const;//should be overrided by it's subclass, return it's name
	Customer getSender() const;
	Customer getRecipient() const;
	double getWeight() const;
	double getCostperounce() const;

	virtual void printInfo() const;//should be overrided by it's subclass, print the sender's and recipient's information and the weight and fee of the package

private:
	Customer sender;
	Customer recipient;
	double weight;
	double costperounce;

};

#endif // !PACKAGE_H
