#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;

//a customer object stores all the infomation of a sender or a recipient

class Customer {
public:
	Customer();
	Customer(string, string, string, string, string);
	void setName(string);
	void setAddress(string);
	void setCity(string);
	void setState(string);
	void setZipcode(string);

	string getName() const;
	string getAddress() const;
	string getCity() const;
	string getState() const;
	string getZipcode() const;

	void print() const;

private:
	string name;
	string address;
	string city;
	string state;
	string zipcode;
};

#endif // !CUSTOMER_H
