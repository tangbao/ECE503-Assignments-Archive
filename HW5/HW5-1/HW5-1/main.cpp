/*

Homework 5 - 1 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/8

Description: recursive - print squares

IDE: Visual Studio 2017 Community

Version: 0.0.2

*/

#include <iostream>
#include <string>

using namespace std;

string getSqr(int);

int main()
{
	int num = 0;
	string result;

	while (num <= 0) //the num must > 0
	{
		cout << "Please input a positive number:" << endl;
		cin >> num; //the number cannot larger than 1779 on my computer due to the limit of stack
		cin.clear();
		cin.ignore(1024, '\n'); //reset cin if the user input sth rather than a number
	}
	
	result = getSqr(num); //call function to get result

	cout << "The result is: " << result << endl;
	system("pause");
	return 0;
}

string getSqr(int num)
{
	string result, strnum;
	char buf[8];

	_itoa_s(num*num, buf, 10); //convert num*num to string and save in buf[]
	//sprintf_s(buf, "%d", num*num); //if go wrong, try this statement
	strnum = buf; //get string from char buf[]

	if (num == 1)
		result = strnum; //the last one in the recursive
	else
		if (num % 2 == 0) // when it's a even, add it to the end of the result
			result = getSqr(num - 1) + ", " + strnum; 
		else
			result = strnum +  ", " +  getSqr(num - 1); // when it's a odd, add it to the start of the result
	 
	return result;
}
