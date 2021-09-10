#include "ATM.h"

void ATM::SetUpBills(bool first )
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			if (first)
				bills[i][1] = 50, bills[i][0] = MoneyInATM / 5 / bills[i][1];
			else
				bills[i][0] = MoneyInATM / 5 / bills[i][1];
		else if (i == 1)
			if (first)
				bills[i][1] = 100, bills[i][0] = MoneyInATM / 5 / bills[i][1];
			else
				bills[i][0] = MoneyInATM / 5 / bills[i][1];
		else if (i == 2)
			if (first)
				bills[i][1] = 200, bills[i][0] = MoneyInATM / 5 / bills[i][1];
			else
				bills[i][0] = MoneyInATM / 5 / bills[i][1];
		else if (i == 3)
			if (first)
				bills[i][1] = 500, bills[i][0] = MoneyInATM / 5 / bills[i][1];
			else
				bills[i][0] = MoneyInATM / 5 / bills[i][1];
		else if (i == 4)
			if (first)
				bills[i][1] = 1000, bills[i][0] = MoneyInATM / 5 / bills[i][1];
			else
				bills[i][0] = MoneyInATM / 5 / bills[i][1];
	}
}

bool ATM::GoodValue(int SumToGet)
{
	if (SumToGet % 50 == 0 && SumToGet >= MinSumToGet && SumToGet <= MaxSumToGet)
	{
		if (bills[0][0] >= SumToGet / bills[0][1] || bills[1][0] >= SumToGet / bills[1][1] || bills[2][0] >= SumToGet / bills[2][1] || bills[3][0] >= SumToGet / bills[3][1] || bills[4][0] >= SumToGet / bills[4][0])
		{
			return true;
		}
	} 
	return false;
}

void ATM::TakeMoney(int SumToGet)
{
	if (GoodValue(SumToGet))
	{
		MoneyInATM -= SumToGet;
		do
		{
			if (SumToGet >= bills[4][1] && bills[4][0] > SumToGet / bills[4][1])
			{
				bills[4][0] -= SumToGet / 1000;
				SumToGet = SumToGet % 1000;
			}
			else if (SumToGet >= bills[3][1] && bills[3][0] > SumToGet / bills[3][1])
			{
				bills[3][0] -= SumToGet / 500;
				SumToGet = SumToGet % 500;
			}
			else if (SumToGet >= bills[2][1] && bills[2][0] > SumToGet / bills[2][1])
			{
				bills[2][0] -= SumToGet / 200;
				SumToGet = SumToGet % 200;
			}
			else if (SumToGet >= bills[1][1] && bills[1][0] > SumToGet / bills[1][1])
			{
				bills[1][0] -= SumToGet / 100;
				SumToGet = SumToGet % 100;
			}
			else if (SumToGet >= bills[0][1] && bills[0][0] > SumToGet / bills[0][1])
			{
				bills[0][0] -= SumToGet / 50;
				SumToGet = SumToGet % 50;
			}
		} while (SumToGet != 0);
		cout << "\nSucces!" << endl;
	}
	else
	{
		cout << "Incorrect sum!" << endl;
	}
}

void ATM::GiveMoney(int SumToGive)
{
	if (GoodValue(SumToGive))
	{
		MoneyInATM += SumToGive;
		SetUpBills(0);
		cout << "\nSucces!" << endl;
	}
	else
	{
		cout << "Incorrect sum!" << endl;
	}
}

void ATM::Getmoney()
{
	cout << "Money in the ATM:" << MoneyInATM << endl;
}

void ATM::GetMin()
{
	cout << "Minimum sum:" << MinSumToGet << endl;
}

void ATM::GetMax()
{
	cout << "Maximum sum:" << MaxSumToGet << endl;
}

void ATM::GetBill(int index)
{
	cout << "Amount of this bill:" << bills[index][0] << endl;
}

void ATM::GetId()
{
	cout << "ID of ATM:" << Id << endl;
}

void ATM::SetMin(int value)
{
	MinSumToGet = value;
	cout << "\nSucces!" << endl;
}

void ATM::SetMax(int value)
{
	MaxSumToGet = value;
	cout << "\nSucces!" << endl;
}

void ATM::SetBill(int index, int value)
{
	bills[index][1] = value;
	SetUpBills(0);
	cout << "\nSucces!" << endl;
}

void ATM::SetId(int value)
{
	Id = value;
	cout << "\nSucces!" << endl;
}
