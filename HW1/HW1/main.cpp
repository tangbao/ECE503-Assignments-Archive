
/*
	Homework 1 - 16:332:503:02 F17

	Author: Zhongze Tang

	Email: zhongze.tang@rutgers.edu

	Time: 2017/9/10

	Description: Find the maximum and minimum of 5 numbers

	IDE: Visual Studio 2017 Community

	Version: 0.0.2

*/

#include <iostream>
using namespace std;

int main()
{
	//Define 5 numbers(num1~5) and initialize them , and the results(min & max).
	//min stands for the minimum number, and the max stands for the maximum one.
	double num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, min, max;

	//Ask the user to input 5 numbers.
	cout << "Please input 5 numbers:" << endl;
	//Read in 5 numbers and save them to num1~5
	//If user input a char or a string, it cannot change the value of the variable
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	//Initialize min & max
	min = num1;
	max = num1;

	//Compare num1 & num2, and update the results
	if (num1 > num2)
	{
		min = num2;
	}
	else
	{
		max = num2;
	}

	//Compare num3 with min & max, and update the results
	if (num3 < min)
	{
		min = num3;
	}
	else if (num3 > max)
	{
		max = num3;
	}
	
	//Compare num4 with min & max, and update the results
	if (num4 < min)
	{
		min = num4;
	}
	else if (num4 > max)
	{
		max = num4;
	}

	//Compare num5 with min & max, and update the results
	if (num5 < min)
	{
		min = num5;
	}
	else if (num5 > max)
	{
		max = num5;
	}

	//Output the results
	cout << "The minimum of these numbers is: " << min << endl << "The maximum of these numbers is: " << max << endl;

	//Pause to check results
	system("pause");

	return 0;
}