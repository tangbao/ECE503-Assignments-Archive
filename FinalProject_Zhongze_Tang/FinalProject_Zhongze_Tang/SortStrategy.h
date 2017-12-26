#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include"StockAccount.h"

/*
	Use inheritance to implement an abstarct interface, this is called Strategy Pattern
	Abstract interface declaration in the base class, the specific implementation in the specific subclasses
*/
class StockAccount;
class SortStrategy {
public:
	virtual void sortDoublyLinkedList(StockAccount& sa) = 0;
};

//two derived class to implement different sort algorithm
class SelectionSort : public SortStrategy {
	virtual void sortDoublyLinkedList(StockAccount& sa);
};

class BubbleSort : public SortStrategy {
	virtual void sortDoublyLinkedList(StockAccount& sa);
};

//use Context to change the strategy
class Context {
public:
	Context(SortStrategy*);
	~Context();
	void DoSort(StockAccount& sa); //the method to call the sort function

private:
	SortStrategy* _sortstrategy;
};
#endif // !SORTSTRATEGY_H
