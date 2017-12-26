#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
#include<iomanip>
using namespace std;
#include "HelperFunc.h"

string HelperFunc::convertToString(double d) const
{
	stringstream ss; //read in the d to stringstream, and convert it to string, then return
	ss << fixed << setprecision(2) << d; //set two decimal points
	return ss.str();
}

string HelperFunc::convert2String(double d) const
{
	stringstream ss;
	ss << d;
	return ss.str();
}

string HelperFunc::convertTimeToString(long d) const
{
	stringstream ss;
	ss << d;
	return ss.str();
}

HelperFunc::HelperFunc()
{
}

string HelperFunc::getDate() const
{
	time_t now = time(0);
	tm *ltm = localtime(&now); 
	//format the date
	string time = convert2String(1 + ltm->tm_mon) + "/" +
		convert2String(ltm->tm_mday) + "/" + convert2String(1900 + ltm->tm_year);
	return time;
}

string HelperFunc::getTime() const
{
	time_t now = time(0);
	tm *ltm = localtime(&now); 
	//format the time
	string time = convert2String(ltm->tm_hour) + ":" +
		convert2String(ltm->tm_min) + ":" + convert2String(ltm->tm_sec);
	return time;
}

time_t HelperFunc::getTimeSec() const
{
	time_t seconds = time(0);
	return seconds;
}

bool HelperFunc::checkFile(char * file_name) const
{
	fstream fs;
	bool result;
	fs.open(file_name, ios::in||ios::out); //it will build the file automatically if file does not exist
	int ch;
	ch = fs.get(); //try to read a char in file
	if (ch == EOF) { //if read a EOF, it means nothing in file
		result = false;
	}
	else {
		result = true;
	}
	fs.close();
	return result;
}

void HelperFunc::cleanFile(char * file_name)
{
	ofstream ofs;
	ofs.open(file_name);
	if (ofs.fail()) { //faile to open file
		cout << "Error: " << file_name << " cannot open" << endl;
		return;
	}
	else {
		ofs << ""; //rewrite "" to the file
		ofs.close();
	}
}

string HelperFunc::searchFile(char* file_name, string key) const
{
	string result = "";
	ifstream ifs;
	ifs.open(file_name);
	if (ifs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
	}
	else {
		string line;
		while (getline(ifs, line)) {
			if (getSplit(line, 1) == key) {//get the first word in the line, compare it with the key
				result = line;
				break;
			}
		}
	}
	return result;
}

int HelperFunc::getLineNum(char * file_name) const
{
	int num = 0;
	ifstream ifs;
	ifs.open(file_name);
	if (ifs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
		return 0;
	}
	else {
		string line;
		while (getline(ifs, line)) {
			num++;//just go over the file and add the num
		}
		ifs.close();
	}
	return num;
}

void HelperFunc::printAllLines(char * file_name) const
{
	ifstream ifs;
	ifs.open(file_name);
	if (ifs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
		return;
	}
	else {
		string line;
		while (getline(ifs, line)) {
			cout << line << endl; //print every line
		}
		ifs.close();
	}
}

void HelperFunc::writeBalanceToFile(char * file_name, string s)
{
	cleanFile(file_name);
	fstream fs;
	fs.open(file_name);
	if (fs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
		return;
	}
	else {
		fs << s; //rewrite the number d to the file
		fs.close();
	}
}

void HelperFunc::addToLastLine(char * file_name, string str)
{
	ofstream ofs;
	ofs.open(file_name, ios::app);// use "ios::app" to move the pointer to the end of file
	if (ofs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
		return;
	}
	else {
		ofs << str; //write str to the last line
		ofs.close();
	}
}

string HelperFunc::getLastLine(char* file_name) const
{
	string lastline;
	ifstream ifs;
	ifs.open(file_name);
	if (ifs.fail()) {
		cout << "Error: " << file_name << " cannot open" << endl;
		return "";
	}
	else {
		while (getline(ifs, lastline)) {} //when while finishes, the lastline will be the content of last line
		ifs.close();
	}
	return lastline;
}

string HelperFunc::getSplit(string str, int num) const
{
	stringstream strs(str);
	string tok;
	int cnt = 0;
	while (getline(strs, tok, '\t') && ((++cnt) != num)) {} //get the num-th word seperated by "\t" in the string
	return tok;
}
