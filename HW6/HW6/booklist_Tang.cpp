/*

Class Name: Booklist

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/14

Description: a class use in booklist program

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/


#include <iostream>
#include "booklist_Tang.h"
using namespace std;

Booklist::Booklist()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		booklist[i] = 0;
	}

	num = 0;
	if_sorted = false;
}

int Booklist::callMenu()
{
	//show the main menu
	int choice = 10;
	cout << endl << "Welcome to the Book List Program!" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1: Add an book to the end of the list" << endl;
	cout << "2: Add an book at a position" << endl;
	cout << "3: Find a book by ISBN number (linear search)" << endl;
	cout << "4: Find a book by ISBN number (binary search)" << endl;
	cout << "5: Delete a book at a position" << endl;
	cout << "6: Delete a book by ISBN number" << endl;
	cout << "7: Sort the list (using selection sort)" << endl;
	cout << "8: Sort the list (using bubble sort)" << endl;
	cout << "9: Print the list" << endl;
	cout << "0: Exit" << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	cin.clear(); //reset cin, in order to prevent the user enter an alphabet, etc.
	cin.ignore(1024, '\n'); //if the user input more than one choice, ignore it.
	return choice;
}

//1 insert the book to the end of the list
void Booklist::insert(int book)
{
	//the end of the list is (*num) + 1, so just call insertByPosition()
	insertByPosition(num + 1, book);
}

//2 insert the book to a certain position of the list
void Booklist::insertByPosition(int position, int book)
{
	if (num < MAX_NUM) //when the list is not full
		if (position >= 1 && position <= num + 1) // when position is in the range of list
		{
			for (int i = num; i >= position; i--)
				*(booklist + i) = *(booklist + i - 1); //move the books behind the position to next one
			*(booklist + position - 1) = book; //add the book to the list
			num++; //the number of books in the list + 1
			print();
			if_sorted = false;//when insert successfully, set if_sorted as false.
		}
		else
		{
			cout << "Error: Invalid postion." << endl;
		}
	else
	{
		cout << "Error: The book list is full." << endl;
	}
}

//3 find a book by linear search
int Booklist::findByLinear(int book) const
{
	int position = -1; //default result, when book no found return -1
	for (int i = 0; i < num; i++)
		if (*(booklist + i) == book) //compare the ISBN with all the books in the list
		{
			position = i + 1;
			break;
		}
	if (position == -1)
	{
		cout << "Error: Book not found." << endl;
	}
	else
	{
		cout << "The book is in position " << position << "." << endl;
	}
	return position;
}

//4 find a book by binary search
int Booklist::findByBinary(int book) const
{
	int position = -1;
	if (if_sorted) //before using findByBinary, user have to sort the list first
	{
		int low = 0, high = num - 1, mid = (low + high) / 2;
		while (low <= high)
		{
			if (book == *(booklist + mid)) //find the book
			{
				position = mid + 1;
				break;
			}
			else  // change the low or the high to reset the range
			{
				if (book > *(booklist + mid))
				{
					low = mid + 1;
					mid = (low + high) / 2;
				}
				else
				{
					high = mid - 1;
					mid = (low + high) / 2;
				}

			}
		}
	}
	else
	{
		cout << "Error: You have to sort the list first." << endl;
		return position;
	}

	if (position == -1)
	{
		cout << "Error: Book not found." << endl;
	}
	else
	{
		cout << "The book is in position " << position << "." << endl;
	}
	return position;
}

//5 delete a book at a certain position
void Booklist::deleteByPosition(int position)
{
	if (position >= 1 && position <= num)
	{
		for (int i = position; i < num; i++)
			*(booklist + i - 1) = *(booklist + i); //move books to the front
		num--; // number of books in the list - 1
		print();
	}
	else
	{
		cout << "Error: Invalid postion." << endl;
	}

}

//6 delete a book by ISBN
void Booklist::deleteByISBN(int book)
{
	if (num == 0) // no book to delete
	{
		cout << "Error: The list is empty." << endl;
	}
	else
	{
		int position = findByLinear(book); //find the position of the book
		if (position != -1)// book found
		{
			deleteByPosition(position); //call deleteByPosition()
		}
	}
}

//7 use selection sort to find the book
void Booklist::sortBySelection()
{
	for (int i = 0; i < num - 1; i++)
	{
		int min_pos = i;
		for (int j = i; j < num; j++)
		{
			if (*(booklist + j) < *(booklist + min_pos))
			{
				min_pos = j;
			}
		}
		int temp = *(booklist + min_pos);
		*(booklist + min_pos) = *(booklist + i);
		*(booklist + i) = temp;
	}

	if_sorted = true; //the list has been sorted
	cout << "The selection sort is done." << endl;
	print();
}

//8 use bubble sort to find the book
void Booklist::sortByBubble()
{
	for (int i = 0; i < num - 1; i++)
		for (int j = 0; j < num - i - 1; j++)
		{
			if (*(booklist + j) > *(booklist + j + 1))
			{
				int temp = *(booklist + j);
				*(booklist + j) = *(booklist + j + 1);
				*(booklist + j + 1) = temp;
			}
		}
	if_sorted = true; //the list has been sorted
	cout << "The bubble sort is done." << endl;
	print();
}

//9 print the book list
void Booklist::print() const
{
	cout << "Your book list now is:" << endl;
	if (num == 0)
		cout << "Empty." << endl;
	for (int i = 0; i < num; i++)
		cout << i + 1 << ". " << booklist[i] << endl;
	cout << endl;
}