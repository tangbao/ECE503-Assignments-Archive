#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node {
	friend class DoublyLinkedList;
	friend class BubbleSort;
	friend class SelectionSort;
public:
	Node(string name, int num);

	void setStockNum(int num); //set the number of stock
	int getStockNum(); //get the number of stock
	string getStockName();//get the name of the stock

	double getPrice(); //get the price of the stock

	Node* getNext(); //get the next of the node
private:
	Node *prev;
	Node *next;

	string stockName;
	int stockNum;
	double price;
};

#endif // !NODE_H
