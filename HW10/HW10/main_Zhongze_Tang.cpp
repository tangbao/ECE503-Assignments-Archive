#include<iostream>
#include<string>
using namespace std;

#include"Node.h"
#include"LinkedList.h"

int main() 
{
	bool flag = false; //mark the user decide to quit or not
	int choice = 0; //the user's choice in the menu
	int number = 0; //the number of the item
	string name = ""; //the name of the item
	LinkedList list; //the linked list to store items
	Node *a = new Node(name, number); //an item to deal with

	cout << "Welcome to the shopping list program" << endl;
	while (!flag) //when the user is not going to quit
	{
		cout << "1.  Add a new node at the beginning" << endl;
		cout << "2.  Add a new node at the end" << endl;
		cout << "3.  Remove the beginning node" << endl;
		cout << "4.  Remove the end node" << endl;
		cout << "5.  Remove a node from the list by entering an item number" << endl;
		cout << "6.  Remove a node from the list by entering an item name" << endl;
		cout << "7.  Print out the list" << endl;
		cout << "8.  Quit the program" << endl;
		cout << "Please choose an option: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1024, '\n');

		if (choice == 1 || choice == 2) { //get the number and the name of the item to add when user chooses 1 or 2
			cout << "Please enter product number to insert" << endl;
			cin >> number;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Please enter the name for the product" << endl;
			cin >> name;
			cin.clear();
			cin.ignore(1024, '\n');
			a = new Node(name, number);
		}
		else if (choice == 5) { //get the number of the item to delete when user chooses 5
			cout << "Please enter product number to delete" << endl;
			cin >> number;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (choice == 6) { //get the name of the item to delete when user chooses 6
			cout << "Please enter the name of the product to delete" << endl;
			cin >> name;
			cin.clear();
			cin.ignore(1024, '\n');
		}

		switch (choice)
		{
		case 1:
			list.addToStart(a);
			list.printList();
			break;
		case 2:
			list.addToEnd(a);
			list.printList();
			break;
		case 3:
			list.removeFromStart();
			list.printList();
			break;
		case 4:
			list.removeFromEnd();
			list.printList();
			break;
		case 5:
			list.removeNodeFromList(number);
			list.printList();
			break;
		case 6:
			list.removeNodeFromList(name);
			list.printList();
			break;
		case 7:
			list.printList();
			break;
		case 8:
			flag = true; //quit
			break;
		default:
			cout << "Please enter the right number" << endl << endl; //when user input an invalid number
			break;
		}
	}

	system("pause");
	return 0;
}