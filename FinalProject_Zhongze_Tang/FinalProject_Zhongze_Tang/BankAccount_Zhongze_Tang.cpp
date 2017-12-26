#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include "BankAccount.h"
#include "HelperFunc.h"


BankAccount::BankAccount()
{
	checkFileStatus_Template();
}

void BankAccount::printDetails() const
{
	cout << "You have $" << fixed << setprecision(2) << getBalance() << " in your bank account." << endl;
}

void BankAccount::printHistory() const
{
	hf.printAllLines(BANK_HISTORY); //print all the content of BANK_HISTORY
}

void BankAccount::addHistory(int mode, double amount)
{
	string record = "";
	string type = "";
	//mode == 1: Deposit, 2: Withdrawal, 3: SellStock 4: BuyStock
	switch (mode) {
		case 1:
			type = "Deposit";
			break;
		case 2:
			type = "Wthdrw";
			break;
		case 3:
			type = "SellStk";
			break;
		case 4:
			type = "BuyStk";
			break;
		default:
			break;
	}
	stringstream ss; //store the type, amount, date and balance to a stringstream
	ss << left << "\n" << setw(16) << type << setw(16) << "$" + hf.convertToString(amount) << setw(16) <<
		hf.getDate() << setw(16) << "$" + hf.convertToString(getBalance());
	record = ss.str(); //convert the stringstream to a string
	hf.addToLastLine(BANK_HISTORY, record); //write to BANK_HISTORY
}

void BankAccount::depositMoney(double mon)
{
	if (mon <= 0) { //money must > 0
		cout << "Error: invalid money." << endl;
		return;
	}
	else {
		stringstream ss;
		ss << fixed << setprecision(2) << getBalance() + mon*1.0;
		setBalance(ss.str()); //set balance(and it will write it to file)
		addHistory(1, mon); //add the history to file
		cout << "You have successfully deposit $" << fixed << setprecision(2) << mon << "." << endl;
		printDetails(); //print the details of bank account now to check
	}
}

void BankAccount::withdrawMoney(double mon)
{
	double bal = getBalance();
	if (bal - mon < 0) { //the account must have suficient balance
		cout << "Error: insuficient fund." << endl;
	}
	else {
		stringstream ss;
		ss << fixed << setprecision(2) << bal - mon*1.0;
		setBalance(ss.str()); //set balance
		addHistory(2, mon); //add history to file
		cout << "You have successfully withdraw $" << fixed << setprecision(2) << mon << "." << endl;
		printDetails(); //print the details of bank account now to check
	}
}

void BankAccount::checkPrivateFiles()
{
	if (!hf.checkFile(BANK_HISTORY)) { //if BANK_HISTORY not exist
		stringstream ss; //write the title of the file to the file
		ss << left << setw(16) << "Event" << setw(16) << "Amount" << setw(16) << "Date" << setw(16) << "Balance";
		string title = ss.str();
		hf.addToLastLine(BANK_HISTORY, title);
	}
}
