#include <stdlib.h>
#include<sstream>
using namespace std; 
#include "StockAccount.h"
#include "HelperFunc.h"

StockAccount::StockAccount()
{
	checkFileStatus_Template();
	pSS = new BubbleSort();
	pCon = new Context(pSS);

	getAllStock(); //get all the stock from file
	srand((unsigned)time(0)); //set the seed of random
}

StockAccount::~StockAccount()
{
	delete pCon;
	pCon = NULL;
	updatePortfolio();
}

double StockAccount::getPortfolioFromFile() const
{
	string newest = hf.getLastLine(PORTFOLIO_FILE); //get the last portfolio value
	string tok = hf.getSplit(newest, 1);
	double p = atof(tok.c_str()) * 1.0;
	return p;
}

void StockAccount::setPortfolio(double p)
{
	portfolio = p;
	updatePortfolio(); //store portfolio to file
}

double StockAccount::getPortfolio()
{
	return portfolio;
}

void StockAccount::printDetails()
{
	cout << "Cash balance = $" << getBalance() << endl;
	cout << left;
	cout << setw(16) << "CompanySymbol" << setw(12) << "Number" << setw(16) << "PricePerShare" << setw(16) << "TotalValue" << endl;
	Node* currentPtr = dll.getHead()->getNext(); //get the first node of stock
	double myBalance = 0.0;
	while (currentPtr != dll.getTail()) { //when it is not the tail 
		myBalance += currentPtr->getPrice() * currentPtr->getStockNum(); //calculate the tital value of stocks
		//print the details of stocks
		cout << setw(16) << currentPtr->getStockName() << setw(12) << currentPtr->getStockNum() << setw(16) <<
			"$" + hf.convertToString(currentPtr->getPrice()) << setw(16) << 
			"$" + hf.convertToString(currentPtr->getPrice()*currentPtr->getStockNum()) << endl;
		currentPtr = currentPtr->getNext();
	}
	if (dll.getSize() == 0) { //determine if the user has stocks
		cout << "You do not have any stock yet." << endl;
	}
	cout << "Total portfolio value: $" << myBalance + getBalance() << endl;
	setPortfolio(myBalance + getBalance());
}

void StockAccount::printHistory() const
{
	hf.printAllLines(STOCK_HISTORY); //print all the content of STOCK_HISTORY
}

void StockAccount::getAllStock()
{
	ifstream ifs;
	ifs.open(STOCK_FILE);
	if (ifs.fail()) {
		cout << "Error: file cannot open" << endl;
	}
	else {
		string line;
		int num = 0;
		while (getline(ifs, line)) {
			if (num++ == 0)
				continue; //skip the first line
			string name = hf.getSplit(line, 1); //get the name, it's the first word in line
			int num = atoi(hf.getSplit(line, 3).c_str()); //get the num, it's the 2nd word in line, convert it to integer
			Node* node = new Node(name, num); //build a new node
			dll.insertNode(node);//insert it to the dll
		}
		ifs.close();
	}
}

double StockAccount::findPriceByName(string name) const
{
	double random = rand() / double(RAND_MAX); //make a random number between 0-1
	string result_s;
	double price;
	//if random >= 0.5, use RESULT_1, or use RESULT_2
	if (random >= 0.5) {
		result_s = hf.searchFile(RESULT_1, name);
	}
	else {
		result_s = hf.searchFile(RESULT_2, name);
	}
	if (result_s == "") {
		price = -1; //stock not found
	}
	else {
		price = atof(hf.getSplit(result_s, 2).c_str()); //get the price, it's the 2nd word in the string
	}
	return price*1.0;
}

void StockAccount::showStockDetails(string name)
{
	
	double price = findPriceByName(name); //find the price first
	if (price > 0) { //stock found, print the name and price
		cout << left;
		cout << setw(16) << "Company Symbol" << setw(16) << "Price per share" << endl;
		string price_s = "$" + hf.convertToString(price);
		cout << setw(16) << name << setw(16) << price_s << endl;
	}
	else {
		cout << "Error: Stock not found. Cannot display the price." << endl;
	}
}

void StockAccount::sellShares(string name, int num, double price, BankAccount &ba)
{
	Node* stock = dll.findNode(name); //find the stock in the list first
	if (stock == nullptr) { //do not own the stock
		cout << "Transaction failed: You do not own this stock." << endl;
	}
	else {//own the stock
		double priceNow = findPriceByName(name); //find price first
		if (priceNow > 0) {
			if (num > stock->getStockNum()) { //the number user wants to sell is greater than what he owns
				cout << "Transaction failed: Insufficient stock shares" << endl;
				return;
			}
			else {
				if (priceNow < price) { //price per stock lower than what user wants to sell for
					cout << "Transaction failed: Price per stock is lower than what you want to sell for" << endl;
					return;
				}
				else {
					if (stock->getStockNum() - num == 0) {
						dll.deleteNode(name); //if user has 0 share of the stock, delete it from dll
					}
					else {
						stock->setStockNum(stock->getStockNum() - num); // or subtract the number
					}
					stringstream ss;
					ss << fixed << setprecision(2) << getBalance() + num*priceNow*1.0;
					setBalance(ss.str()); //set cash balance
					ba.addHistory(3, num*priceNow); //add the history of bank account
					addHistory(1, name, num, priceNow); //add the history of stock account
					updateStockFile(); //store the newest dll to file
					cout << "You have selled " << num << " shares of " << name << " at $" << 
						fixed << setprecision(2) << priceNow << " for a total of $" << priceNow*num << "." << endl;
				}
			}
		}
		else {
			cout << "Error: Stock not found." << endl;
		}
	}
}

void StockAccount::buyShares(string name, int num, double price, BankAccount& ba)
{
	
	double priceNow = findPriceByName(name); //find the price
	if (priceNow > 0) {
		if (price < priceNow) { //the user wants to buy a stock with a lower price
			cout << "Transaction failed: Your price is too low." << endl;
			return;
		}
		else {
			double totalCost = num*priceNow*1.0; //calculate the total cost
			double bal = getBalance(); //get the cash balance
			if (totalCost > bal) { //insufficient cash balance
				cout << "Transaction failed: Insufficient cash balance." << endl;
			}
			else {
				Node* stock = dll.findNode(name); //find if the stock has owned
				if (stock == nullptr) {//stock hasn't owned, build a new node and insert it
					stock = new Node(name, num); 
					dll.insertNode(stock);
				}
				else {
					stock->setStockNum(stock->getStockNum() + num); //add the share of the stock
				}
				stringstream ss;
				ss << fixed << setprecision(2) << bal - totalCost;
				setBalance(ss.str()); //set cash balance
				ba.addHistory(4, totalCost); //add the history of bank account
				addHistory(2, name, num, priceNow); //add the history of stock account
				updateStockFile(); //store the newest dll to file
				cout << "You have pruchased " << num << " shares of " << name << " at $" << 
					fixed << setprecision(2) << priceNow << " for a total of $" << priceNow*num << "." << endl;
			}
		}
	}
	else {
		cout << "Error: Stock not found." << endl;
	}
}

void StockAccount::updateStockFile()
{
	//rewrite all the names and shares of stocks to the file
	hf.cleanFile(STOCK_FILE);
	string title = "CompanySymbol\tNumber\t";
	hf.addToLastLine(STOCK_FILE, title);
	Node* currentPtr = dll.getHead()->getNext();
	while (currentPtr != dll.getTail()) {
		string stock = "\n" + currentPtr->getStockName() + "\t\t" + hf.convert2String(currentPtr->getStockNum());
		hf.addToLastLine(STOCK_FILE, stock);
		currentPtr = currentPtr->getNext();
	}
}

void StockAccount::updatePortfolio()
{
	//add a new record of portfolio
	string balance_record = "\n" + hf.convertToString(getPortfolio()) + "\t" + hf.convertTimeToString(hf.getTimeSec());
	hf.addToLastLine(PORTFOLIO_FILE, balance_record);
}

void StockAccount::addHistory(int mode, string name, int num, double pricepershare)
{
	string record = "";
	string type = "";
	//mode == 1: SellStock 2: BuyStock
	switch (mode) {
	case 1:
		type = "Sell";
		break;
	case 2:
		type = "Buy";
		break;
	default:
		break;
	}

	stringstream ss; //store the type, name, number of share, price per share and time to a stringstream
	ss << left << "\n" << setw(16) << type << setw(16) << name << setw(12) << hf.convert2String(num) << 
		setw(16) << "$" + hf.convertToString(pricepershare) << setw(16) << "$" + hf.convertToString(num*pricepershare) <<
		setw(16) << hf.getTime();
	record = ss.str(); //convert it to string and add it to the last of STOCK_HISTORY
	hf.addToLastLine(STOCK_HISTORY, record);
}

void StockAccount::checkPrivateFiles()
{
	//if PORTFOLIO_FILE, STOCK_HISTORY or STOCK_FILE does not exist, build it and initialize it.
	if (!hf.checkFile(PORTFOLIO_FILE)) {
		string balance_record = "10000.00\t" + hf.convertTimeToString(hf.getTimeSec());
		hf.addToLastLine(PORTFOLIO_FILE, balance_record);
	}
	else {
			setPortfolio(getPortfolioFromFile());
	}

	if (!hf.checkFile(STOCK_HISTORY)) {
		stringstream ss;
		ss << left << setw(16) << "Event" << setw(16) << "CompSymbol" << setw(12) << "Number" << 
			setw(16) << "PricePerShare" << setw(16) << "TotalValue" << setw(16) << "Time";
		string title = ss.str();
		hf.addToLastLine(STOCK_HISTORY, title);
	}

	if (!hf.checkFile(STOCK_FILE)) {
		string title = "CompanySymbol\tNumber\t";
		hf.addToLastLine(STOCK_FILE, title);
	}
}
