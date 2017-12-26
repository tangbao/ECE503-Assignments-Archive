#ifndef BOOKLIST_H

#define BOOKLIST_H
#define MAX_NUM 20 // the max number of the booklist

class Booklist {

public:
	Booklist();

	int callMenu();
	void insert(int book); //1, add book
	void insertByPosition(int position, int book);//2, add book at a certain position
	int findByLinear(int book) const;//3, return -1 when book not found, or return the position
	int findByBinary(int book) const;//4, return -1 when book not found, or return the position
	void deleteByPosition(int position);//5
	void deleteByISBN(int book);//6
	void sortBySelection();//7
	void sortByBubble();//8
	void print() const;//9

private:
	int booklist[MAX_NUM];
	int num;
	bool if_sorted;
};

#endif // !BOOKLIST_H


