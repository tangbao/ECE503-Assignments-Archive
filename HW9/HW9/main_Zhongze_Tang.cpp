#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

#include"customer.h"
#include"package.h"
#include"twodaypackage.h"
#include"overnightpackage.h"

void calculateAll(vector<Package *>);//to print infomation of each package and add up all the fees

int main() 
{
	//create customers
	Customer c1("Zhongze Tang", "1 College Ave.", "New Brunswick", "NJ", "08901");
	Customer c2("Zichen Zhu", "2 College Ave.", "New Brunswick", "NJ", "08901");
	Customer c3("Xin Yang", "3 College Ave.", "New Brunswick", "NJ", "08901");
	Customer c4("Zhuohang Li", "4 College Ave.", "New Brunswick", "NJ", "08901");
	Customer c5("Zhaoyi Xu", "5 College Ave.", "New Brunswick", "NJ", "08901");
	Customer c6("Pikachu", "6 College Ave.", "New Brunswick", "NJ", "08901");
	
	//set cost per ounce, addtional fee of twodayPackage and overnightPackage, the weight of three packages
	double costperounce = 0.5, addtion_twoday = 2.0, addtion_overnight = 5.0;
	double p1_weight = 10.0, p2_weight = 5.0, p3_weight = 2.0;

	//create packages and store them into the vertor
	vector<Package *> packages;
	Package *p1 = new Package(c1, c2, p1_weight, costperounce);
	Package *p2 = new TwoDayPackage(c3, c4, p2_weight, costperounce, addtion_twoday);
	Package *p3 = new OvernightPackage(c5, c6, p3_weight, costperounce, addtion_overnight);
	packages.push_back(p1);
	packages.push_back(p2);
	packages.push_back(p3);

	cout << "Package delivery services program " << endl << endl;
	cout << fixed << setprecision(2);//make sure there will be 2 numbers after the decimal point
	cout << "Cost per ounce for a package: $"  << costperounce << "/ounce" << endl;
	cout << "Additional cost for two day delivery: $" << addtion_twoday << "/ounce" << endl;
	cout << "Additional cost for overnight delivery: $" << addtion_overnight << "/ounce" << endl << endl;
	calculateAll(packages);

	system("pause");
	return 0;
}

void calculateAll(vector<Package *> p)
{
	double cost = 0.0;
	int j = 0;
	//use iterator to traverse the vector
	for (vector<Package *>::iterator i = p.begin(); i != p.end(); i++) {
		cout << "Package " << (++j) << ":" << endl << endl;
		(*i)->printInfo(); //print the infomation of each pack
		if ((*i)->calculateCost() == 0) { 
			//when the weight or the cost per ounce or the addtional fee <= 0, the cost of the package will be 0
			cout << endl << "Error: The package is invalid." << endl;
		}
		else {
			cost += (*i)->calculateCost();// add the cost
		}
	}
	cout << endl << "Total cost of all the packages: $" << cost << endl;
}