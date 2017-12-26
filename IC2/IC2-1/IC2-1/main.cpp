/*

InClass2-1 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/9/16

Description: Use nested for to print a * triangle

IDE: Visual Studio 2017 Community

Version: 0.0.2

*/

#include <iostream>
using namespace std;

int main()
{
	//Ask the user how many lines he/she wants in the shape
	int num = 0;
	//Make sure num > 0
	while (num <= 0) 
	{
		cout << "Please enter a POSITIVE number you want in the shape:";
		cin >> num;
	}

	//Use i to control the number of lines
	for (int i = 1; i <= num; i++)
	{
		//Use j to control the number of "*"s each line
		//The max value of j is the value of i in this iteration of loop
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		//Move to the next line
		cout << endl;
	}

	//Pause to check results
	system("pause");

	return 0;
}