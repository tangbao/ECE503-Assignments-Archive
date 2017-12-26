#include<iostream>
using namespace std;
#include "overnightpackage.h"

OvernightPackage::OvernightPackage(Customer senderV, Customer recipientV, double weightV, double costperounceV, double addtionalfeeV)
	:Package(senderV, recipientV, weightV, costperounceV) //use father's constructor
{
	setAddtionalFee(addtionalfeeV);
}

double OvernightPackage::calculateCost() const
{
	//the cost = weight * (costPerOunce + addtionalFeeOfOvernight)
	//the weight should round up
	return 1.0 * ceil(getWeight())*(getCostperounce() + getAddtionalFee());
}

void OvernightPackage::setAddtionalFee(double  addtionalfeeV)
{
	//the addtional fee must be positive
	if (addtionalfeeV > 0) {
		addtionalfee = addtionalfeeV;
	}
	else {
		addtionalfee = 0;
		cout << endl << "Error: The addtional fee should be positive." << endl;
	}
}

//get the addtional fee of overnightPackage
double OvernightPackage::getAddtionalFee() const
{
	return addtionalfee;
}

//get the delivery service name
string OvernightPackage::getServiceName() const
{
	return "Overnight Package";
}
