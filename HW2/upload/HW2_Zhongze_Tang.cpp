
/*

Homework 2 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/9/20

Description: Use Monte Carlo Method to calculate pi

IDE: Visual Studio 2017 Community

Version: 0.0.2 Correct some mistakes in comments

*/

#include <iostream>
#include <fstream>
#include <time.h> 
using namespace std;

int main()
{
	
	// num is the number of iterations, count is the number of points that inside the arc
	int num = 0, count = 0;
	//(x, y) is the coordinate of a point, pi will be the result of this expriment
	double x, y, pi;
	//ask user to input the right number
	cout << "Please input the number of iterations you want," << endl << "Do NOT enter a large number, it may takes a loog time" << endl;
	cin >> num;
	while (num <= 0)
	{
		cout << "Invalid. Please input the number of iterations you want:";
		cin >> num;
	}
	
	//initialize random seed
	srand(time(0));

	ofstream file;
	//opens the file result.txt
	file.open("result.txt");
	//for loop to write the values to the file
	for (int i = 0; i<num; i++) {
		// x and y must time 1.0 to get a DOUBLE result, or the result will be integer
		// x and y divided by RAND_MAX are numbers between 0 and 1
		x = rand() * 1.0 / RAND_MAX;
		y = rand() * 1.0 / RAND_MAX;
		file << x << "," << y << "\n";
		// if x^2 + y^2 <= 1, the point must be inside the arc
		if (x*x + y*y <= 1)
		{
			count++;
		}
	}

	// pi times 4.0 to get a DOUBLE result.
	// And this formula comes from the Monte Carlo Methods 
	pi = 4.0 * count / num;
	cout << "The result of ¦Ð in this expriment is: " << pi << endl;

	system("pause");
	return 0;
}