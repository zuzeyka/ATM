#pragma once
#include<iostream>
#include <ctime>
using namespace std;
class ATM
{
	int Id;
	int MoneyInATM;
	int MinSumToGet;
	int MaxSumToGet;
	int bills[5][2]; // 50, 100, 200, 500, 1000
public:
	void SetUpBills(bool first);
	bool GoodValue(int SumToGet);
	void TakeMoney(int SumToGet);
	void GiveMoney(int SumToGive);
	void SetMin(int value); // set
	void SetMax(int value);
	void SetBill(int index, int value);
	void SetId(int value);
	void Getmoney(); // get
	void GetMin();
	void GetMax();
	void GetBill(int index);
	void GetId();

	ATM()
	{
		Id = rand();
		MoneyInATM = rand() % 100000;
		MoneyInATM -= MoneyInATM % 50;
		MinSumToGet = 50;
		MaxSumToGet = 10000;
		SetUpBills(1);
	}
};

