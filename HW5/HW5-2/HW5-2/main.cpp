
/*

Homework 5 - 2 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/5

Description: a puzzle jump

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include<iostream>
#include<string.h>
#define MAX 256 //define the max size of the puzzle

using namespace std;

bool puzzleJump(int* , int);

int main()
{
	int arr[MAX], startIndex; // arr stores the puzzle
	bool if_valid = false; //mark the input is invalid or valid
	for (int i = 0; i < MAX; i++) //initialize the puzzleall set as -1(invalid)
		arr[i] = -1;

	while (!if_valid) //when the input is invalid
	{
		cout << "Please input the puzzle, 0 as the end." << endl;
		for (int i = 0; i < MAX; i++)
		{
			cin >> arr[i];

			if (arr[i] < 0) //the elements must > 0, and the last one must == 0
			{
				cout << "Error: you must input positive numbers." << endl;
				break;
			}
			else if(arr[i] == 0)
			{
				if_valid = true;
				break; //stop the input
			}
		}
		cin.clear();
		cin.ignore(1024, '\n'); //reset cin, clear extra input
	}

	cout << "Please input the start index£¬ the first is 0: " << endl;
	cin >> startIndex;

	if (puzzleJump(arr, startIndex))
		cout << "There is a solution to the puzzle." << endl;
	else
		cout << "The puzzle has no solution" << endl;

	system("pause");
	return 0;
}

bool puzzleJump(int * arr, int index)
{
	bool result = false; //mark the solution is found or not
	int left_index = index - *(arr + index); //get the left index
	int right_index = index + *(arr + index); //get the right index
	bool left_invalid = (left_index < 0 || *(arr + index - *(arr + index)) == -1); //when left index out of range or the left element ==-1, the left one is invalid
	bool right_invalid = (right_index >= MAX || *(arr + index + *(arr + index)) == -1); //when right index out of range or the left element ==-1, the left one is invalid

	if (*(arr + index) == 0) //pass
	{
		return true;
	}

	if (*(arr + index) == -1) //self invalid
	{
		return false;
	}
		
	*(arr + index) = -1; //the element has been visited so set it as -1
	if (!left_invalid && result == false) //try left when left is valid and has not find solution
	{
		result = puzzleJump(arr, left_index);
	}

	if (!right_invalid && result == false)//try right when left is valid and has not find solution
	{
		result = puzzleJump(arr, right_index);
	}

	return result;
}
