#include<iostream>
#include <ctime>
#include "ATM.h"
using namespace std;

int main()
{
	srand(time(0));
	ATM First;
	bool admin = 0;
	unsigned int answer = 0;
	cout << "PRESS Admin - 1 User - 0" << endl;
	cin >> admin;
	cout << endl;
	if (admin)
	{
		do
		{
			cout << "Add money - 0 Change ID - 1 Set min - 2 Set max - 3 Set bill - 4 Show money - 5 Show ID - 6 Show Min - 7 Show Max - 8 Show bill - 9 Exit - 10" << endl;
			cin >> answer;
			if (answer == 0)
			{
				cout << "Type sum to add:";
				cin >> answer;
				cout << endl;
				First.GiveMoney(answer);
				answer = 0;
			}
			else if (answer == 1)
			{
				cout << "Type ID to change:";
				cin >> answer;
				cout << endl;
				First.SetId(answer);
				answer = 1;
			}
			else if (answer == 2)
			{
				cout << "Type value to change min:";
				cin >> answer;
				cout << endl;
				First.SetMin(answer);
				answer = 2;
			}
			else if (answer == 3)
			{
				cout << "Type value to change max:";
				cin >> answer;
				cout << endl;
				First.SetMax(answer);
				answer = 3;
			}
			else if (answer == 3)
			{
				cout << "Type value to change max:";
				cin >> answer;
				cout << endl;
				First.SetMax(answer);
				answer = 3;
			}
			else if (answer == 4)
			{
				unsigned int answer2;
				cout << "Type index to change bill:";
				cin >> answer;
				cout << endl;
				cout << "Type value to change bill:";
				cin >> answer2;
				cout << endl;
				First.SetBill(answer, answer2);
				answer = 4;
			}
			else if (answer == 5)
			{
				First.Getmoney();
			}
			else if (answer == 6)
			{
				First.GetId();
			}
			else if (answer == 7)
			{
				First.GetMin();
			}
			else if (answer == 8)
			{
				First.GetMax();
			}
			else if (answer == 9)
			{
				cout << "Type index to watch bill:";
				cin >> answer;
				cout << endl;
				First.GetBill(answer);
				answer = 9;
			}
		} while (answer != 10);
	}
	else
	{
		do
		{
			cout << "How mach money you want to recive(0 - to exit):";
			cin >> answer;
			cout << endl;
			First.TakeMoney(answer);
			cout << "You have recive your money!" << endl;
		} while (answer != 0);
	}
}