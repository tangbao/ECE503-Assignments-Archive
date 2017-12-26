#include<iostream>
using namespace std;
#include "customer.h"

Customer::Customer()
{
	setName("");
	setAddress("");
	setCity("");
	setState("");
	setZipcode("");
}

Customer::Customer(string nameV, string addressV, string cityV, string stateV, string zipcodeV)
{
	setName(nameV);
	setAddress(addressV);
	setCity(cityV);
	setState(stateV);
	setZipcode(zipcodeV);
}

//set and get of name, adderss, city, state and zipcode of the customer

void Customer::setName(string nameV)
{
	name = nameV;
}

void Customer::setAddress(string addressV)
{
	address = addressV;
}

void Customer::setCity(string cityV)
{
	city = cityV;
}

void Customer::setState(string stateV)
{
	state = stateV;
}

void Customer::setZipcode(string zipcodeV)
{
	zipcode = zipcodeV;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}

string Customer::getCity() const
{
	return city;
}

string Customer::getState() const
{
	return state;
}

string Customer::getZipcode() const
{
	return zipcode;
}

//print the information of the customer
void Customer::print() const
{
	cout << getName() << endl;
	cout << getAddress() << endl;
	cout << getCity() << ", " << getState() << " " << getZipcode() << endl;
}
