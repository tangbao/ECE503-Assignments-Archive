/*

Final Project - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/11/22

Description: Account Management System

IDE: Visual Studio 2017 Community

Version: 0.0.5

*/

#include <iostream>
#include <string>
using namespace std;

#include "HelperFunc.h"
#include "BankAccount.h"
#include "StockAccount.h"
#include "DoublyLinkedList.h"

void ManageStockAccount(); //the function to do stock account operations
void ManageBankAccout(); //the funciton to do bank account operations
void Setting(); //change the sort algorithm
void Exit(); //store the portfolio value now to file
template <class T> 
T getPositive(); //a function to let the user input positive value only

BankAccount ba; //create an object of BankAccount
StockAccount sa; //create an object of StockAccount

int main() {
	int choice = 0;
	while (choice != 4) { //when user not chooses to quit
		cout << endl << "Welcome to the Account Management System." << endl;
		cout << "Please select an account to access:" << endl;
		cout << "1. Stock Portfolio Account" << endl;
		cout << "2. Bank Account" << endl;
		cout << "3. Settings (Design Pattern: Strategy)" << endl;
		cout << "4. Exit" << endl;
		cout << endl << "Option: ";
		cin >> choice; //get the choice
		cin.clear();
		cin.ignore(1024, '\n');

		switch (choice) //call different functions
		{
		case 1:
			ManageStockAccount();
			break;
		case 2:
			ManageBankAccout();
			break;
		case 3:
			Setting();
			break;
		case 4:
			Exit();
			break;
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

void ManageStockAccount()
{
	int choice = 0;
	while (choice != 7) { //when user not chooses to quit
		cout << endl << "Stock Portfolio Account" << endl;
		cout << "Please select an option :" << endl;
		cout << "1. Display the price for a stock symbol" << endl;
		cout << "2. Display the current portfolio" << endl;
		cout << "3. Buy shares" << endl;
		cout << "4. Sell shares" << endl;
		cout << "5. View a graph for the portfolio value" << endl;
		cout << "6. View transaction history" << endl;
		cout << "7. Return to previous menu" << endl;
		cout << endl << "Option: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');

		string name; //the name of the stock
		int num; //the number of the stock
		double price; //the price of the stock

		switch (choice)
		{
		case 1:
			cout << "Please enter the stock symbol: " << endl;
			getline(cin, name); //read in a line
			sa.showStockDetails(name); //call this method to show the details of a stock
			break;
		case 2:
			sa.pCon->DoSort(sa); //sort the doubly linked list in stock account first
			sa.printDetails(); //print the details of the current portfolio
			break;
		case 3:
			cout << "Please enter the stock symbol you wish to purchase: " << endl;
			getline(cin, name); //get the name
			cout << "Please enter the number of shares: " << endl;
			num = getPositive<int>(); //get the positive number
			cout << "Please enter the maximum amount you are willing to pay per share: " << endl << "$";
			price = getPositive<double>(); //get the positive amount
			sa.buyShares(name, num, price, ba); //call the method to buy shares
			break;
		case 4:
			cout << "Please enter the stock symbol you wish to sell: " << endl;
			getline(cin, name); //get the name
			cout << "Please enter the number of shares: " << endl;
			num = getPositive<int>(); //get the positive number
			cout << "Please enter the minimum amount you are willing to sell per share: " << endl << "$";
			price = getPositive<double>(); //get the positive amount
			sa.sellShares(name, num, price, ba); //call the method to sell shares
			break;
		case 5:
			sa.printGraph(); //print the graph by matlab
			break;
		case 6:
			sa.printHistory(); //print the transaction history
			break;
		case 7:
			break; //return to the previous menu
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}
	}
}

void ManageBankAccout()
{
	int choice = 0;
	double money;
	while (choice != 5) { //when user not to quit
		cout << endl << "Stock Portfolio Account" << endl;
		cout << "Please select an option :" << endl;
		cout << "1. View account balance" << endl;
		cout << "2. Deposit money" << endl;
		cout << "3. Withdraw money" << endl;
		cout << "4. Print out history" << endl;
		cout << "5. Return to previous menu" << endl;
		cout << endl << "Option: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');

		switch (choice)
		{
		case 1:
			ba.printDetails(); //print the details of bank account
			break;
		case 2:
			cout << "Please enter the amount you wish to deposit:" << endl << "$";
			money = getPositive<double>(); //get positive value of money
			ba.depositMoney(money); //call the mothod to deposit money
			sa.setPortfolio(sa.getPortfolio() + money); //add the money to portfolio value
			break;
		case 3:
			cout << "Please enter the amount you wish to withdraw:" << endl << "$";
			money = getPositive<double>(); //get positive value of money
			ba.withdrawMoney(money); //call the mothod to withdraw money
			sa.setPortfolio(sa.getPortfolio() - money); //substract the money from portfolio value
			break;
		case 4:
			ba.printHistory(); //print the history of bank account
			break;
		case 5:
			break;
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}
	}
}

void Setting()
{
	int choice = 0;
	while (choice != 3) {
		cout << endl << "Settings (Design Pattern: Strategy)" << endl;
		cout << "Please select an option :" << endl;
		cout << "1. Bubble Sort (default)" << endl;
		cout << "2. Selection Sort" << endl;
		cout << "3. Return to previous menu" << endl;
		cout << endl << "Option: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');

		switch (choice)
		{
		case 1:
			sa.pSS = new BubbleSort(); //choose bubble sort
			cout << "You have change the sort method to bubble sort." << endl;
			break;
		case 2:
			sa.pSS = new SelectionSort(); //choose selection sort
			cout << "You have change the sort method to selection sort." << endl;
			break;
		case 3:
			break; //quit
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}

		sa.pCon = new Context(sa.pSS); //update the strategy

	}
}

void Exit()
{
	sa.updatePortfolio(); //store the portfolio value now to file
}

template <class T> T getPositive() //use template to adapt to different data type
{
	T m;
	cin >> m;
	cin.clear();
	cin.ignore(1024, '\n');
	while (m <= 0) { //m must > 0
		cout << "Error: Please enter a positive number!" << endl;
		cin >> m;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	return m;
}
