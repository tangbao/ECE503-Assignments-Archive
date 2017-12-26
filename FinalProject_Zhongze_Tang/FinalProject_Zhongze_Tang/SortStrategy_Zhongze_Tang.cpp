#include "SortStrategy.h"

void SelectionSort::sortDoublyLinkedList(StockAccount & sa)
{
	cout << "Using selection sort." << endl << endl;
	Node* tempPtr = sa.dll.head->next;
	//get the price of every stock
	while (tempPtr != sa.dll.tail) {
		tempPtr->price = sa.findPriceByName(tempPtr->getStockName()); 
		tempPtr = tempPtr->next;
	}

	//selection sort
	for (int i = 1; i <= sa.dll.nodeNum - 1; i++) {
		int min = i;
		for (int j = i+1 ; j <= sa.dll.nodeNum; j++) {
			Node* stk1 = sa.dll.findNodeByPosition(min);
			Node* stk2 = sa.dll.findNodeByPosition(j);
			double stock1 = stk1->getStockNum() * stk1->price;
			double stock2 = stk2->getStockNum() * stk2->price;
			if (stock1 < stock2) {
				min = j;
			}
		}
		sa.dll.swapNode(i, min);
	}
}

void BubbleSort::sortDoublyLinkedList(StockAccount & sa)
{
	cout << "Using bubble sort." << endl << endl;
	Node* tempPtr = sa.dll.head->next;
	//get the price of every stock
	while (tempPtr != sa.dll.tail) {
		tempPtr->price = sa.findPriceByName(tempPtr->getStockName());
		tempPtr = tempPtr->next;
	}
	
	//bubble sort
	for (int i = 1; i <= sa.dll.nodeNum; i++) {
		for (int j = i; j <= sa.dll.nodeNum; j++) {
			Node* stk1 = sa.dll.findNodeByPosition(i);
			Node* stk2 = sa.dll.findNodeByPosition(j);
			double stock1 = stk1->getStockNum() * stk1->price;
			double stock2 = stk2->getStockNum() * stk2->price;
			if (stock1 < stock2) {
				sa.dll.swapNode(i, j);
			}
		}
	}
}

Context::Context(SortStrategy* sortstrategy)
{
	this->_sortstrategy = sortstrategy;
}

Context::~Context()
{
	delete this->_sortstrategy;
}

void Context::DoSort(StockAccount& sa)
{
	this->_sortstrategy->sortDoublyLinkedList(sa);
}
