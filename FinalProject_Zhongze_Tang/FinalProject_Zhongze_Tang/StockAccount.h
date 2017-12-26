#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H
#include<iostream>
using namespace std;
#include"Account.h"
#include"BankAccount.h"
#include "SortStrategy.h"
#include"DoublyLinkedList.h"

class SortStrategy;
class Context;
class StockAccount : public Account {
	friend class BubbleSort;
	friend class SelectionSort;
public:
	StockAccount();
	~StockAccount();
	double getPortfolioFromFile() const; //get portfilio value from file
	void setPortfolio(double p); //set portfolio value and store it to file
	double getPortfolio(); //get portfolio value

	void printDetails();
	void printHistory() const;

	void getAllStock(); //get all stock from file and store it to doubly linked list

	double findPriceByName(string name) const; // find the price of a stock randomly from files by using its name
	void showStockDetails(string name); //show the detail of a stock
	void sellShares(string name, int num, double price, BankAccount &ba); //sell stocks
	void buyShares(string name, int num, double price, BankAccount &ba); //buy stocks
	void updateStockFile(); //write the new stock information to file
	void updatePortfolio(); //write the new portfolio value along with the time to file
	
	void printGraph(); //print the graph by MATLAB

	void addHistory(int mode, string name, int num, double pricepershare); //add history to file

	SortStrategy * pSS; //Strategy pattern, using bubble sort by default
	Context * pCon;//strategy pattern

protected:
	virtual void checkPrivateFiles(); //check its own files

private:
	DoublyLinkedList dll;
	double portfolio;
};

#endif // !STOCKACCOUNT_H
