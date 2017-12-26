#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	int size() const; //the size of the list
	void addToStart(Node *); //add an item to the start of the start
	void addToEnd(Node *); //add an item to the end of the start
	void printList();
	void removeFromStart(); //remove the first item in the list
	void removeFromEnd(); //remove the last item in the list
	void removeNodeFromList(int); //remove the item having the certain number
	void removeNodeFromList(string); //remove the item having the certain name

private:
	Node *myHead; //the first item in the list
	Node *myTail; //the last item in the list
	int mySize; //the amount of the items in the list
};


#endif // !LINKEDLIST_H

