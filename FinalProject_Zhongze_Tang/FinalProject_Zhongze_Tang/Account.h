#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"HelperFunc.h"
using namespace std;
class Account {
public:
	Account();

	void setBalance(string bal); //set the balance
	double getBalance() const; //get the balance

	virtual void printHistory() const = 0; //print transaciton history

	HelperFunc hf; //an object of HelperFunc

	/*
		Design Pattern: Template.  Check all the files' status
		the mothods below contains two other methods: checkSharedFiles() and checkPrivateFiles()
		checkSharedFiles() is implemented in base class to check the cash_balance.txt, which will be used both by StockAccount and BankAccount
		checkPrivateFiles() is a virtual function, it will be implemented seperately in StockAccount and BankAccount to check these two accounts' own files
	*/
	void checkFileStatus_Template(); 

protected:
	void checkSharedFiles(); //for design pattern: Template, check the shared file
	virtual void checkPrivateFiles(); //for design pattern: Template, check the private file

};


#endif // !ACCOUNT_H
