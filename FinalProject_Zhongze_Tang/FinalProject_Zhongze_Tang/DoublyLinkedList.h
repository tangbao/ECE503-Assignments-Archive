#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;
#include"Node.h"
#include"StockAccount.h"
class StockAccount;
class DoublyLinkedList
{
	friend class BubbleSort;
	friend class SelectionSort;
public:
	DoublyLinkedList(); // I will call it dll
	~DoublyLinkedList();

	Node* getHead() const; //get the empty head of dll
	Node* getTail() const; //get the empty tail of dll
		
	int getSize() const; //get the size of dll (do not include the head and tail)

	void insertNode(Node *node); //insert a node before the tail
	void deleteNode(string stockName); //delete a node with a certain name 
	Node* findNode(string stockName); //find a node with a certain name 

	Node* findNodeByPosition(int position) const; //find the node at position(begin with 1, do not include the head and tail)
	void swapNode(int pos1, int pos2) const; // swap the node at pos1 and pos2

	void printList(); //print the content of the list for debugging

private:
	Node* head; // the empty head of dll
	Node* tail; // the empty tail of dll
	int nodeNum; // the number of nodes in dll  (do not include the head and tail)
};
#endif // !DOUBLYLINKEDLIST_H