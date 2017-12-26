#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//define the macros for the files, to aviod wrong typo of the name

#define CASH_BALANCE "data\\cash_balance.txt"

#define BANK_HISTORY "data\\bank_transaction_history.txt"

#define PORTFOLIO_FILE "data\\stock_portfolio.txt"
#define STOCK_FILE "data\\stock_details.txt"
#define STOCK_HISTORY "data\\stock_transaction_history.txt"

#define RESULT_1 "data\\Result_1.txt"
#define RESULT_2 "data\\Result_2.txt"

class HelperFunc {
public:
	HelperFunc();
	string convertToString(double d) const; //Convert a double to string, with two decimal points
	string convert2String(double d) const; //Convert a double to string directly
	string convertTimeToString(long d) const; //Convert a long to string directly

	string getDate() const; //Get the date as mm/dd/yyyy now
	string getTime() const; //Get the time as hh:mm:ss now
	time_t getTimeSec() const; //Get the time as seconds now

	bool checkFile(char* file_name) const; //Check the file exists or not
	void cleanFile(char* file_name); //Clear the file
	string searchFile(char* file_name, string key) const; //Search the file to find the line that has the certain string

	int getLineNum(char* file_name) const; //Get the line numbers of a file
	void printAllLines(char* file_name) const; //Print all the content of the file

	void writeBalanceToFile(char* file_name, string s); //Write balance to file (It¡¯s a function to rewrite the file)
	void addToLastLine(char* file_name, string str); //Add a string to the last of a file
	string getLastLine(char* file_name) const; //Get the last line of a file

	string getSplit(string str, int num) const; //Get the n-th word in file, separated by ¡°\t¡±

};

#endif // !HELPERFUNC_H
