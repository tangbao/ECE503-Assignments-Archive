#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include"Account.h"

class BankAccount : public Account {
public:
	BankAccount();

	void printDetails() const;
	void printHistory() const;

	void addHistory(int mode, double amount); //add history to the file

	void depositMoney(double mon); //deposit money
	void withdrawMoney(double mon); //withdraw money

protected:
	virtual void checkPrivateFiles(); //check its own files

};

#endif // !BANKACCOUNT_H