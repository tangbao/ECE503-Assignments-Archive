/*

InClass3 - 16:332:503:02 F17

Author: Zhongze Tang

Email: zhongze.tang@rutgers.edu

Time: 2017/9/23

Description: find the next apprentice

IDE: Visual Studio 2017 Community

Version: 0.0.3

*/

#include <iostream>
#define STU_NUM 5 //the number of students
#define CAN_NUM 5  //the number of candidates

using namespace std;

int main()
{
	int stu[STU_NUM] = { 0 };			//store each student votes for which candidate
	int can[CAN_NUM + 1] = { 0 };		//store each candidate has how many votes
	int result[STU_NUM + 1] = { 0 };	//store the result of votes by using a simple counting sort
	int winner = -1;					//winner's number				

	//for each student
	for (int i = 0; i < STU_NUM; i++)
	{
		bool if_confirmed = false;		//mark if the user confirms the input
		char user_confirm = 'n';		//user's input of his confirmation
		//when the user doesn't confirm his input
		while (!if_confirmed)			
		{
			bool if_valid = false;		//mark if the input is valid
			//when the input is invalid
			while (!if_valid)
			{
				cout << "Student " << i + 1 << " plase vote." << " Use number 1~5 to represent candidates 1~5: ";
				cin >> stu[i];
				//clear the failbit & all the things in cin
				//prevent that the user input more than expected resulting in wrong value of user_confirm
				cin.clear();
				cin.ignore(1024, '\n');
				//if any of input is invalid, set if_valid as false
				if_valid = (stu[i] >= 1 && stu[i] <= 5) ? true : false ;
			}

			cout << "Do you CONFIRM? Enter y to continue, any other to redo: ";
			cin >> user_confirm;
			//clear the failbit & all the things in cin
			cin.clear();
			cin.ignore(1024, '\n');
			//if user input y, then the program will continue to next student.
			//otherwise, it will ask the user to input again.
			if_confirmed = user_confirm == 'y' ? true : false;
		}
		
	}

	//traverse the stu[] to count votes
	for (int i = 0; i < STU_NUM; i++)
	{
		can[stu[i]]++;
	}

	//traverse the can[] to get results
	for (int i = 1; i < CAN_NUM + 1; i++)
	{
		//if result[can[i]] != 0, it means another candidate has the same votes of him
		//then set result[can[i]] as -1, which means the winner will not be the one who has %can[i]% votes
		result[can[i]] = result[can[i]] == 0 ? i : -1;
	}

	//REVERSE traverse the can[] to get winner
	//the number of winner is in the first found result[i] which not equals to 0
	//if this result[i] == -1, it means more than one get the most votes and NO WINNER.
	//if result[i] != -1, the winner will be the value of result[i]
	int i = STU_NUM;
	while(result[i] == 0 && i >= 0)
	{
		i--;
	}
	winner = result[i];

	//if winner is -1, it means no winner. if not, the winner's number is the value of winner
	if (winner == -1)
	{
		cout << "There is no winner." << endl;
	}
	else
	{
		cout << "The winner is " << winner << "." << endl;
	}

	//print all candidates' votes
	for (int i = 1; i < CAN_NUM + 1; i++)
	{
		cout << "Candidate " << i << " recieved " << can[i] << " vote(s)." << endl;
	}

	system("pause");

	return 0;
}