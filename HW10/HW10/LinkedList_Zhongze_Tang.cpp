#include "LinkedList.h"
#include<iomanip>
#include<string>
using namespace std;

LinkedList::LinkedList()
{
	myHead = NULL;
	myTail = NULL;
	mySize = 0;
}

LinkedList::~LinkedList()
{
	if (size() != 0) { //the list is not empty
		Node *currentPtr = myHead;
		Node *tempPtr;
		while (currentPtr != NULL) {
			tempPtr = currentPtr; //save the current pointer
			currentPtr = currentPtr->next; //move to next
			delete tempPtr; //delete the node
		}
	}
}

int LinkedList::size() const
{
	return mySize;
}

void LinkedList::addToStart(Node * newPtr)
{
	if (size() == 0) { //list is empty
		myHead = myTail = newPtr;
	}
	else {
		newPtr->next = myHead; //add to start
		myHead = newPtr;
	}

	mySize++; //add the size
}

void LinkedList::addToEnd(Node * newPtr)
{
	if (size() == 0) { //list is empty
		myHead = myTail = newPtr;
	}
	else {
		myTail->next = newPtr; //add to end
		myTail = newPtr;
	}

	mySize++; //add the size
}

void LinkedList::printList()
{
	if (size() == 0) { //empty
		cout << "Empty shopping list." << endl << endl;
	}
	else {
		Node *currentPtr = myHead;
		cout << setw(12) << "Item No." << setw(12) << "Item Name" << endl;
		while (currentPtr != NULL) { //when not move to end
			cout << setw(12) << currentPtr->itemNo << setw(12) << currentPtr->itemName << endl;
			currentPtr = currentPtr->next;// move to next
		}
		cout << endl;
	}
}

void LinkedList::removeFromStart()
{
	if (size() == 0) { //list is empty
		cout << "Error: Nothing to delete." << endl;
	}
	else {
		Node *tempPtr = myHead; //save the first node
		myHead = myHead->next; //delete the first item
		delete tempPtr; //release resources
		mySize--; //substract size
	}

}

void LinkedList::removeFromEnd()
{
	if (size() == 0) {
		cout << "Error: Nothing to delete." << endl;
	}
	else if (size() == 1) { //myHead = myTail
		myHead = myTail = NULL;
		mySize--;
	}else {
		Node *currentPtr = myHead;
		Node *tempPtr;
		while (currentPtr->next != myTail) { //find the 2nd last
			currentPtr = currentPtr->next;
		}
		myTail = currentPtr; //delete the last item
		tempPtr = myTail->next;
		myTail->next = NULL;
		delete tempPtr;
		mySize--; //substract size
	}
}

void LinkedList::removeNodeFromList(int number)
{
	if (size() == 0) { //empty
		cout << "Error: Nothing to delete." << endl;
	}
	else if (number == myHead->itemNo) { //if want to delete the 1st one
		removeFromStart();
	}
	else if (number == myTail->itemNo) { //want to delete the last one
		removeFromEnd();
	}
	else {
		Node *currentPtr = myHead;
		while (currentPtr->next != NULL && currentPtr->next->itemNo != number) { //try to find the item
			currentPtr = currentPtr->next;
		}
		if (currentPtr->next == NULL) { //item not found
			cout << "Error: Item not found." << endl;
		}
		else {
			Node *tempPtr = currentPtr->next;
			currentPtr->next = currentPtr->next->next; //delete the item 
			delete tempPtr; //release memory
			mySize--;
		}
	}
}

void LinkedList::removeNodeFromList(string name)
{
	if (size() == 0) {//empty
		cout << "Error: Nothing to delete." << endl;
	}
	else if (name == myHead->itemName) {//if want to delete the 1st one
		removeFromStart();
	}
	else if (name == myTail->itemName) {//want to delete the last one
		removeFromEnd();
	}
	else {
		Node *currentPtr = myHead;
		while (currentPtr->next != NULL && currentPtr->next->itemName != name) {//try to find the item
			currentPtr = currentPtr->next;
		}
		if (currentPtr->next == NULL) {//item not found
			cout << "Error: Item not found." << endl;
		}
		else {
			Node *tempPtr = currentPtr->next;
			currentPtr->next = currentPtr->next->next;//delete the item 
			delete tempPtr;//release memory
			mySize--;
		}
	}
}
