
/*

Homework 3-2 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/2

Description: Use Vectors to perform Matrix operations

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int callMenu(); //get the choice from user
void inputMatrix(vector<vector<double> >& , int *, int *); //function to input matrix
void printMatrix(vector<vector<double> >& , int, int, int); //function to output matrix

void Addition(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);
void Subtraction(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);
void Multiplication(vector<vector<double> >&, vector<vector<double> >&, int, int, int, int);
double Determinant(vector<vector<double> >&, int, int);
void Transpose(vector<vector<double> >&, int, int);
void Inverse(vector<vector<double> >&, int, int);

int main()
{
	bool flag = false;

	//while user doesnt choice to quit the programme
	while (!flag)
	{
		int choice = callMenu();

		vector<vector<double> >vA(10, vector<double>(10));
		vector<vector<double> >vB(10, vector<double>(10));
		int rowA = 0, columnA = 0, rowB = 0, columnB = 0;
		if (choice >= 1 && choice <= 3) //when user need to add, subtract or multiple two matrixes
		{
			inputMatrix(vA, &rowA, &columnA); //pass the addresses of rowA and columnA to the function, in order to change and get the value of them
			printMatrix(vA, rowA, columnA, 0);
			inputMatrix(vB, &rowB, &columnB);
			printMatrix(vB, rowB, columnB, 0);
		}
		else if (choice >= 4 && choice <= 6) //when user need to get the determinant, transpose or inverse of a matrix
		{
			inputMatrix(vA, &rowA, &columnA);
			printMatrix(vA, rowA, columnA, 0);
		}

		switch (choice)
		{
		case 1:
			Addition(vA, vB, rowA, columnA, rowB, columnB);
			break;
		case 2:
			Subtraction(vA, vB, rowA, columnA, rowB, columnB);
			break;
		case 3:
			Multiplication(vA, vB, rowA, columnA, rowB, columnB);
			break;
		case 4:
			Determinant(vA, rowA, columnA);
			break;
		case 5:
			Transpose(vA, rowA, columnA);
			break;
		case 6:
			Inverse(vA, rowA, columnA);
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
	cout << endl << "Welcome to the Matrix Calculator (Vector version) !" << endl;
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

void inputMatrix(vector<vector<double> >& vM, int *row, int *column)
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
	for (int i = 0; i < (*row); i++)
		for(int j = 0; j < *column; j++)
			cin >> vM[i][j];

	cin.clear();
	cin.ignore(1024, '\n');
}

void printMatrix(vector<vector<double> >& vM, int row, int column, int model)
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
			cout << setw(8) << vM[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Addition(vector<vector<double> >& vA, vector<vector<double> >& vB, int rowA, int columnA, int rowB, int columnB)
{
	if (rowA != rowB || columnA != columnB) //check if two matrixs can add together
	{
		cout << "Error: Cannot add two matrix that have different size." << endl;
	}
	else
	{
		vector<vector<double> >vC(10, vector<double>(10));
		for (int i = 0; i < rowA ; i++)
			for (int j = 0; j < columnA ; j++)
				vC[i][j] = vA[i][j] + vB[i][j]; //add
		printMatrix(vC, rowA, columnA, 1);
	}
}

void Subtraction(vector<vector<double> >& vA, vector<vector<double> >& vB, int rowA, int columnA, int rowB, int columnB)
{

	if (rowA != rowB || columnA != columnB) //when two matrixes have the same size, they can be substracted
	{
		cout << "Error: Cannot subtract two matrix that have different size." << endl;
	}
	else
	{
		vector<vector<double> >vC(10, vector<double>(10));
		for (int i = 0; i < rowA; i++)
			for (int j = 0; j < columnA; j++)
				vC[i][j] = vA[i][j] - vB[i][j]; //subcract
		printMatrix(vC, rowA, columnA, 1);
	}
}

void Multiplication(vector<vector<double> >& vA, vector<vector<double> >& vB, int rowA, int columnA, int rowB, int columnB)
{
	if (columnA != rowB) //only when columnA == rowB, two matrixes can be multipled
	{
		cout << "Error: Operation is not supported." << endl;
	}
	else
	{
		vector<vector<double> >vC(10, vector<double>(10));
		for (int i = 0; i < rowA; i++)
			for (int j = 0; j < columnB; j++)
				for (int k = 0; k< columnA; k++)
					vC[i][j] += vA[i][k] * vB[k][j]; //multiple corresponding elements and add up
		printMatrix(vC, rowA, columnB, 1);
	}
}

double Determinant(vector<vector<double> >& vA, int rowA, int columnA)
{
	if (rowA != 3 || columnA != 3) //the programme can only calculate the determinant of a 3-dimension matrix
	{
		cout << "Error: Operation is not supported." << endl;
		return 0;
	}
	else
	{
		double determinant = 0; //the equation below comes from the formula of 3-dimension matrix determinant
		determinant = vA[0][0] * (vA[1][1] * vA[2][2] - vA[1][2] * vA[2][1]) - vA[0][1] * (vA[1][0] * vA[2][2] - vA[1][2] * vA[2][0]) + vA[0][2] * (vA[1][0] * vA[2][1] - vA[1][1] * vA[2][0]);
		cout << "The determinant is: " << determinant << endl;
		return determinant;
	}
}

void Transpose(vector<vector<double> >& vA, int rowA, int columnA)
{
	vector<vector<double> >vC(10, vector<double>(10));
	for (int i = 0; i < rowA; i++)
		for (int j = 0; j < columnA; j++)
			vC[j][i] = vA[i][j]; //the definition of a transpose matrix
	printMatrix(vC, columnA, rowA, 1);
}

void Inverse(vector<vector<double> >& vA, int rowA, int columnA)
{
	if (rowA != 3 || columnA != 3)//the programme can only calculate the inverse of a 3-dimension matrix
	{
		cout << "Error: Operation is not supported." << endl;
	}
	else
	{
		double determinant = Determinant(vA, rowA, columnA); //get determinant
		if (determinant == 0)
		{
			cout << "Error: The inverse of the matrix does not exist." << endl;
		}
		else
		{
			double dd = 1 / determinant;
			//use a formula to calculate the inverse matrix
			vector<vector<double> >vC(3, vector<double>(3));
			double C[3][3] =
			{ (vA[1][1] * vA[2][2] - vA[2][1] * vA[1][2])*dd, (vA[2][1] * vA[0][2] - vA[0][1] * vA[2][2])*dd, (vA[0][1] * vA[1][2] - vA[0][2] * vA[1][1])*dd,
				(vA[1][2] * vA[2][0] - vA[2][2] * vA[1][0])*dd, (vA[2][2] * vA[0][0] - vA[0][2] * vA[2][0])*dd, (vA[0][2] * vA[1][0] - vA[0][0] * vA[1][2])*dd,
				(vA[1][0] * vA[2][1] - vA[2][0] * vA[1][1])*dd, (vA[2][0] * vA[0][1] - vA[0][0] * vA[2][1])*dd, (vA[0][0] * vA[1][1] - vA[0][1] * vA[1][0])*dd };

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					vC[i][j] = C[i][j];

			printMatrix(vC, 3, 3, 1);
		}
	}
}