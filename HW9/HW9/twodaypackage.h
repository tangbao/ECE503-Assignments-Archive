#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
using namespace std;
#include"package.h"

//contains all the information of a twoday Package

class TwoDayPackage : public Package {
public:
	TwoDayPackage(Customer, Customer, double, double, double);
	virtual double calculateCost() const;//override it's father's

	void setAddtionalFee(double);
	double getAddtionalFee() const;

	virtual string getServiceName() const;//override it's father's

private:
	double addtionalfee;
};

#endif // !TWODAYPACKAGE_H
