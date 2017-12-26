#include<deque>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<iterator>
using namespace std;

bool greater6(int);
void printhalf(int);

int main() {
	deque<int> d;

	//use STL algorithms to:
	//1. insert nums 3,4,6,2,9,1,5,0,7,8 in the end
	d.push_back(3);
	d.push_back(4);
	d.push_back(6);
	d.push_back(2);
	d.push_back(9);
	d.push_back(1);
	d.push_back(5);
	d.push_back(0);
	d.push_back(7);
	d.push_back(8);

	//2. remove 7
	d.erase(remove(d.begin(), d.end(), 7), d.end());

	//3.replace num>6 =>10
	replace_if(d.begin(), d.end(), greater6, 10);

	//4.return the sum of all the elems, print out the sum, add the sum to the beginning.
	int sum = accumulate(d.begin(), d.end(), 0);
	cout << "The sum of the numbers 0 to 9 after removing 7 and replacing values greater than 6 with 10 is: "
		<< sum << endl << endl;
	d.push_front(sum);

	//5.count the numbers that are >6
	int cntGrt6 = count_if(d.begin(), d.end(), greater6);
	cout << "Now the number of elements greater than 6 is: " << cntGrt6 << endl << endl;

	//6.put out the half(integer division) of every elem(do not modify the elem)
	deque<int>::iterator half;
	cout << "The half of every elment in the deque is: ";
	for_each(d.begin(), d.end(), printhalf);
	cout << endl << endl;


	//7.sort the deque
	sort(d.begin(), d.end());

	//8.find the location of 6, print out the location
	deque<int>::iterator find6;
	find6 = find(d.begin(), d.end(), 6);
	if (find6 == d.end()) {
		cout << "Error: 6 not found." << endl << endl;
	}
	else {
		int pos = find6 - d.begin();
		cout << "After sorting, the location of 6 is at index: " << pos << endl << endl;
	}
	

	//9.use ostream_iterator and copy algorithm to print out the deque elems with a comma between the nums.
	//(the last elem can have a comma). (do not use loops or subscript operator like values[1])
	cout << "The items in the deque are: ";
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, ", "));
	cout << endl << endl;

	system("pause");
	return 0;
}

bool greater6(int x)
{
	return x > 6;
}

void printhalf(int x)
{
	cout << x / 2 << " ";
}