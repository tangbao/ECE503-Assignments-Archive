#include<iostream>
using namespace std; 
#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(Customer senderV, Customer recipientV, double weightV, double costperounceV, double addtionalfeeV)
	:Package(senderV, recipientV, weightV, costperounceV)
{
	setAddtionalFee(addtionalfeeV);
}

double TwoDayPackage::calculateCost() const
{
	//the cost = weight * (costPerOunce + addtionalFeeOfOvernight)
	//the weight should round up
	return 1.0 * ceil(getWeight())*(getCostperounce() + getAddtionalFee());
}


void TwoDayPackage::setAddtionalFee(double addtionalfeeV)
{
	//the addtional fee must > 0
	if (addtionalfeeV > 0) {
		addtionalfee = addtionalfeeV;
	}
	else {
		addtionalfee = 0;
		cout << endl << "Error: The addtional fee should be positive." << endl;
	}
}

//get the addtionnal fee of the two day package
double TwoDayPackage::getAddtionalFee() const
{
	return addtionalfee;
}

//return the service name
string TwoDayPackage::getServiceName() const
{
	return "Two Day Package";
}
