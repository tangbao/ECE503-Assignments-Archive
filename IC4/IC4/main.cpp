
/*

InClass 4 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/10/6

Description: count c in s

IDE: Visual Studio 2017 Community

Version: 0.0.1

*/

#include <iostream>
#include <string>
using namespace std;

int countNum(const char*, char);

int main()
{
	string s;
	char c;

	cout << "Please input the string: " << endl;
	getline(cin, s);
	cout << "Please input the character you need to count:" << endl;
	while ((c = cin.get()) == '\n') {}
	int num = countNum(s.c_str(), c);
	cout << "The character occurs " << num << " times in the string." << endl;
	system("pause");
	return 0;
}

int countNum(const char* s, char c)
{
	int result = 0;
	if (*s == '\0')
		return 0;
	else
	{
		if (*s == c)
			result = countNum(s + 1, c) + 1;
		else
			result = countNum(s + 1, c);
		return result;
	}

}
