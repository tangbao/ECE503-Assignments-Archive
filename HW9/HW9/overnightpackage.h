#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
using namespace std;
#include"package.h"

//contains all the infomation of a overnightPackage

class OvernightPackage : public Package {
public:
	OvernightPackage(Customer, Customer, double, double, double);
	virtual double calculateCost() const;//override it's father's

	void setAddtionalFee(double);
	double getAddtionalFee() const;

	virtual string getServiceName() const;//override it's father's

private:
	double addtionalfee;
};

#endif // !OVERNIGHTPACKAGE_H
