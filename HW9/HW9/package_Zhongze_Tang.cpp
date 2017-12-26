#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
#include "package.h"

Package::Package(Customer senderV, Customer recipientV, double weightV, double costperounceV)
{
	setSender(senderV);
	setRecipient(recipientV);
	setWeight(weightV);
	setCostperounce(costperounceV);
}

double Package::calculateCost() const
{
	//the weight should round up
	return 1.0 * ceil(getWeight()) * getCostperounce();
}

void Package::setSender(Customer senderV)
{
	sender = senderV;
}

void Package::setRecipient(Customer recipientV)
{
	recipient = recipientV;
}

void Package::setWeight(double weightV)
{
	//the weight of a package must > 0
	if (weightV > 0) {
		weight = weightV;
	}
	else {
		weight = 0;
		cout << endl << "Error: The weight should be positive." << endl;
	}
}

void Package::setCostperounce(double costperounceV)
{
	//the cost per ounce must > 0
	if (costperounceV > 0) {
		costperounce = costperounceV;
	}
	else {
		costperounce = 0;
		cout << endl << "Error: The cost per ounce should be positive." << endl;
	}
}

//return the service name of the delivery
string Package::getServiceName() const
{
	return "Regular Delivery";
}

Customer Package::getSender() const
{
	return sender;
}

Customer Package::getRecipient() const
{
	return recipient;
}

double Package::getWeight() const
{
	return weight;
}

double Package::getCostperounce() const
{
	return costperounce;
}

//print all the infomation of the package
void Package::printInfo() const
{
	cout << "Sender:" << endl;
	sender.print();
	cout << endl << "Receipent:" << endl;
	recipient.print();
	cout << endl << "Weight of package: " << getWeight() << " ounces" << endl;
	cout << "Type of delivery: " << getServiceName() << endl;
	cout << "Cost of Package: $" << calculateCost() << endl << endl;
}
