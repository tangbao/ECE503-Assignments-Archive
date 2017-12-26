/*

InClass2-1 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/9/16

Description: Use nested for to print a * diamond

IDE: Visual Studio 2017 Community

Version: 0.0.2

*/

#include <iostream>
using namespace std;

int main()
{
	//Ask the user to enter the max number of stars in each line
	int num = 0;
	cout << "Please enter the max number of stars in each line, and the number MUST be ODD and POSITIVE:" << endl;
	cin >> num;

	//If the num is not odd, ask the user to enter again
	//An odd number % 2 == 1, and the number must >=0
	while ((num % 2 == 0) || (num < 0))
	{
		cout << "Invalid input. Please enter a POSITIVE ODD number: ";
		cin >> num;
	}
	
	//Print the top half of the diamond
	//use i to control the line
	for (int i = 1; i <= num; i+=2)
	{
		//use j to control the space
		//In each line, the number of the spaces is (num - i)/2
		for (int j = 1; j <= (num - i) / 2; j++)
		{
			cout << " ";
		}
		//use k to control the "*"
		for (int k = 1; k <= i; k++)
		{
			cout << "*";
		}
		//Change to the next line
		cout << endl;
	}

	//Print the second half of the diamond
	for (int i = num-2; i >= 1; i -= 2)
	{
		for (int j = 1; j <= (num - i) / 2; j++)
		{
			cout << " ";
		}
		for (int k = i; k >=1; k--)
		{
			cout << "*";
		}
		cout << endl;
	}

	//Pause to check results
	system("pause");

	return 0;
}