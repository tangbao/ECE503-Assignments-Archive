
/*

Homework 3-1 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/1

Description: Use Matrices to perform Matrix operations

IDE: Visual Studio 2017 Community

Version: 0.0.2

*/

#include<iostream>
#include <iomanip>
using namespace std;

int callMenu(); //get the choice from user
void inputMatrix(double [], int *, int *); //function to input matrix
void printMatrix(double [], int, int, int); //function to output matrix

void Addition(double[], double[], int, int, int, int);
void Subtraction(double[], double[], int, int, int, int);
void Multiplication(double[], double[], int, int, int, int);
double Determinant(double[], int, int);
void Transpose(double[], int, int);
void Inverse(double[], int, int);

int main() 
{
	bool flag = false;

	//while user doesnt choice to quit the programme
	while (!flag)
	{
		int choice = callMenu();
		int rowA = 0, columnA = 0, rowB = 0, columnB = 0;
		double A[100] = { 0 };
		double B[100] = { 0 };
		if (choice >= 1 && choice <= 3) //when user need to add, subtract or multiple two matrixes
		{
			inputMatrix(A, &rowA, &columnA); //pass the addresses of rowA and columnA to the function, in order to change and get the value of them
			printMatrix(A, rowA, columnA, 0);
			inputMatrix(B, &rowB, &columnB);
			printMatrix(B, rowB, columnB, 0);
		}
		else if (choice >= 4 && choice <= 6) //when user need to get the determinant, transpose or inverse of a matrix
		{
			inputMatrix(A, &rowA, &columnA);
			printMatrix(A, rowA, columnA, 0);
		}

		switch (choice)
		{
		case 1:
			Addition(A, B, rowA, columnA, rowB, columnB);
			break;
		case 2:
			Subtraction(A, B, rowA, columnA, rowB, columnB);
			break;
		case 3:
			Multiplication(A, B, rowA, columnA, rowB, columnB);
			break;
		case 4:
			Determinant(A, rowA, columnA);
			break;
		case 5:
			Transpose(A, rowA, columnA);
			break;
		case 6:
			Inverse(A, rowA, columnA);
			break;
		case 7: //the description of this programme
			cout << endl << "Max dimension for both row and Column be 10. You will be free to enter 2X3, or  4X2 , or 9X9 Matrix" << endl;
			cout << "For Determinant and Inverse operation, the programme only support the matrix with size of 3X3" << endl;
			system("pause");
			break;
		case 8:
			flag = true;
			break;
		default:
			cout << "Please enter the right choice! The programme will show the menu again." << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}

int callMenu()
{
	int choice = 0;
	cout << endl << "Welcome to the Matrix Calculator (Matrices version) !" << endl;
	cout << "1: Addtion" << endl;
	cout << "2: Subtraction" << endl;
	cout << "3: Multiplication" << endl;
	cout << "4: Determinant" << endl;
	cout << "5: Transpose" << endl;
	cout << "6: Inverse" << endl;
	cout << "7: Manual" << endl;
	cout << "8: Quit" << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	cin.clear(); //reset cin, in order to prevent the user enter an alphabet, etc.
	cin.ignore(1024, '\n'); //if the user input more than one choice, ignore it.
	return choice;
}

void inputMatrix(double A[], int *row, int *column)
{
	//while row or column is illegal, ask the user to input it
	while (*row <= 0 || *row > 10)
	{
		cout << "Please enter the number of the row(1<=row<=10): ";
		cin >> *row;
		cin.clear();
		cin.ignore(1024, '\n');//if the user input more than one number, ignore it.
	}
	while (*column <= 0 || *column > 10)
	{
		cout << "Please enter the number of the column(1<=column<=10): ";
		cin >> *column;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	cout << "Please enter the value of elements" << endl;
	//read in the matrix
	for (int i = 0; i < (*row)*(*column); i++)
	{
		cin >> A[i];
	}
	cin.clear();
	cin.ignore(1024, '\n');
}

void printMatrix(double M[], int row, int column, int model)
{
	//model 0 means output is from input, model 1 means output is a result
	if (model == 0) {
		cout << "Your input is:" << endl;
	}
	else if (model == 1) {
		cout << "The result is:" << endl;
	}

	//output the matrix, set the width of each element is 8.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << setw(8) << M[i*column+j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Addition(double A[], double B[], int rowA, int columnA, int rowB, int columnB)
{
	if (rowA != rowB || columnA != columnB) //check if two matrixs can add together
	{
		cout << "Error: Cannot add two matrix that have different size." << endl;
	}
	else
	{
		double C[100] = { 0 };
		for (int i = 0; i < rowA * columnA; i++)
			C[i] = A[i] + B[i]; //add
		printMatrix(C, rowA, columnA, 1);
	}
}

void Subtraction(double A[], double B[], int rowA, int columnA, int rowB, int columnB)
{

	if (rowA != rowB || columnA != columnB) //when two matrixes have the same size, they can be substracted
	{
		cout << "Error: Cannot subtract two matrix that have different size." << endl;
	}
	else
	{
		double C[100] = { 0 };
		for (int i = 0; i < rowA * columnA; i++)
			C[i] = A[i] - B[i]; //subtract
		printMatrix(C, rowA, columnA, 1);
	}
}

void Multiplication(double A[], double B[], int rowA, int columnA, int rowB, int columnB)
{
	if (columnA != rowB) //only when columnA == rowB, two matrixes can be multipled
	{
		cout << "Error: Operation is not supported." << endl;
	}
	else
	{
		double C[100] = { 0 };
		for (int i = 0; i < rowA; i++)
			for (int j = 0; j < columnB; j++)
				for (int k = 0; k< columnA; k++)
					C[i*columnB + j] += A[i*columnA + k] * B[k*columnB + j]; //multiple
		printMatrix(C, rowA, columnB, 1);
	}
}

double Determinant(double A[], int rowA, int columnA)
{
	if (rowA != 3 || columnA != 3) //the programme can only calculate the determinant of a 3-dimension matrix
	{
		cout << "Error: Operation is not supported." << endl;
		return 0;
	}
	else
	{
		double determinant = 0; //the equation below comes from the formula of 3-dimension matrix determinant
		determinant = A[0] * (A[4] * A[8] - A[5] * A[7]) - A[1] * (A[3] * A[8] - A[5] * A[6]) + A[2] * (A[3] * A[7] - A[4] * A[6]);
		cout << "The determinant is: " << determinant << endl;
		return determinant;
	}
}

void Transpose(double A[], int rowA, int columnA)
{
	double C[100] = {0};
	for (int i = 0; i < rowA; i++)
		for (int j = 0; j < columnA; j++)
			C[j*rowA + i] = A[i*columnA + j]; //the definition of a transpose matrix
	printMatrix(C, columnA, rowA, 1);
}

void Inverse(double A[], int rowA, int columnA)
{
	if (rowA != 3 || columnA != 3)//the programme can only calculate the inverse of a 3-dimension matrix
	{
		cout << "Error: Operation is not supported." << endl;
	}
	else
	{
		double determinant = Determinant(A, rowA, columnA); //get determinant
		if (determinant == 0)
		{
			cout << "Error: The inverse of the matrix does not exist." << endl;
		}
		else
		{
			double dd = 1 / determinant;
			//use a formula to calculate the inverse matrix
			double C[9] =
			{(A[4] * A[8] - A[7] * A[5])*dd, (A[7] * A[2] - A[1] * A[8])*dd, (A[1] * A[5] - A[2] * A[4])*dd,
			(A[5] * A[6] - A[8] * A[3])*dd, (A[8] * A[0] - A[2] * A[6])*dd, (A[2] * A[3] - A[0] * A[5])*dd,
			(A[3] * A[7] - A[6] * A[4])*dd, (A[6] * A[1] - A[0] * A[7])*dd, (A[0] * A[4] - A[1] * A[3])*dd};
			printMatrix(C, 3, 3, 1);
		}
	}
}