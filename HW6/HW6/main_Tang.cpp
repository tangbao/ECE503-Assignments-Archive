/*

Homework 6 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/14

Description: use class to implement booklist program

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/


#include<iostream>
#include "booklist_Tang.h"
using namespace std;

int main()
{
	bool flag = false;
	Booklist listmanager;

	//while user doesnt choice to quit the programme
	while (!flag)
	{
		int choice = listmanager.callMenu();
		int book = 0, position = 0;
		if ((choice >= 1 && choice <= 4) || (choice == 6)) //when user need to add ,find or delete a book using ISBN
		{
			cout << "Please enter the ISBN of the book:" << endl;
			cin >> book;
			cin.clear();
			cin.ignore(1024, '\n');//if the user input more than one number, ignore it.
		}

		if ((choice == 2) || (choice == 5)) //when user need to add or delete a book by position
		{
			cout << "At what position?" << endl;
			cin >> position;
			cin.clear();
			cin.ignore(1024, '\n');
		}

		switch (choice)
		{
		case 1: //add
			listmanager.insert(book);
			break;

		case 2: //add by position
			listmanager.insertByPosition(position, book);
			break;

		case 3: //find linear
			listmanager.findByLinear(book);
			break;

		case 4: //find binary
			listmanager.findByBinary(book);
			break;

		case 5: //delete by position
			listmanager.deleteByPosition(position);
			break;

		case 6://delete by isbn
			listmanager.deleteByISBN(book);
			break;

		case 7:  //sort by selection
			listmanager.sortBySelection();
			break;

		case 8: //sort by bubble
			listmanager.sortByBubble();
			break;

		case 9:
			listmanager.print();
			break;
		case 0:
			flag = true; //quit
			break;
		default:
			cout << "Please enter the right choice!" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}