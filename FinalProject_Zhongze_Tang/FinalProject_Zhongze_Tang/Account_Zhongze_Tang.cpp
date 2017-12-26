#include "Account.h"


void Account::setBalance(string bal)
{
	hf.writeBalanceToFile(CASH_BALANCE, bal); //write balance to file
}

Account::Account()
{
	checkFileStatus_Template(); //check file status first
}

double Account::getBalance() const
{
	string newest = hf.getLastLine(CASH_BALANCE); //get the last line from the file
	double balance_from_file = atof(newest.c_str()) * 1.0; //convert it to double
	return balance_from_file;
}

void Account::checkFileStatus_Template()
{
	checkSharedFiles(); //check shared file
	checkPrivateFiles(); //check private file
}

void Account::checkSharedFiles()
{
	if (!hf.checkFile(CASH_BALANCE)) { //if CASH_BALANCE not exist, initialize it to "10000"
		string m = "10000.00";
		hf.addToLastLine(CASH_BALANCE, m);
	}
}

void Account::checkPrivateFiles()
{
	//nothing to do 
}
