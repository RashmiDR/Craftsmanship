#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

class CoinChanger
{
	private:
		vector<int> denominations;
		//map<int, int> coinsDispensed;
		
	
	public:
	map<int, int> DispenseCoins(double change);
	void SetDenominations();
	
	bool tests(int amount);
};


int main()
{
	CoinChanger coinChanger;
	double changeAmount;
	map<int, int> dispensedCoins;
	map<int, int>::iterator iter;
	

	coinChanger.SetDenominations();	
		
	cout << "Enter the change amount in dollars" << endl;	
	cin >> changeAmount;
	

	dispensedCoins = coinChanger.DispenseCoins(changeAmount);
	
	for(iter = dispensedCoins.begin(); iter != dispensedCoins.end(); iter++)
	{
		cout<< "coins of denomination " << iter->first << " : " << iter->second << endl;
	}
	 
	return 0;
	
}

void CoinChanger::SetDenominations()
{
	int inputDenomination, numOfDenominations;
	denominations.clear();
	cout << "Enter the number of denominations of change coins" << endl;
	
	cin >> numOfDenominations;
	
	cout << "Enter the denominations of change coins" << endl;
	for(int count = 0; count < numOfDenominations; count++)
	{
		cin >> inputDenomination;
		denominations.push_back(inputDenomination);
	}
	sort(denominations.begin(),denominations.end());
}

map<int, int> CoinChanger::DispenseCoins(double changeAmountInDollars)
{	
	int changeAmountInCents = 0; 
	map<int, int>coinsDispensed;
	int numOfCoins;	

	changeAmountInCents += round(changeAmountInDollars * 100);
	
	for(int i = denominations.size()-1; i >=0; i--)
	{
		cout << "Denomination " << denominations[i] << endl;
		numOfCoins = changeAmountInCents/denominations[i];
		cout << "num of coins " << numOfCoins << endl;
		coinsDispensed[denominations[i]] = numOfCoins;
		changeAmountInCents = changeAmountInCents % denominations[i];
		cout << "Remainder " << changeAmountInCents << endl;

	}
	
	//tests(coinsDispensed);
	return coinsDispensed;
}




/*
bool CoinChanger::tests(int changeAmount)
{
	int numOfTestsFailed = 0;
	int change = 0;
	map<int, int> coinsDispensed;
	
	if(!DispenseCoins(0).empty())
	{
		cout << "Test - zero change amount failed" << endl;
		numOfTestsFailed++;
	}
	if(!DispenseCoins(-1).empty())
	{
		cout << "Test - negative change amount failed" << endl;
		numOfTestsFailed++;
	}
	coinsDispensed = DispenseCoins(changeAmount);
	
	int nSum = 0;
	map<int,int>::iterator iter;
	for(iter = coinsDispensed.begin(); iter != coinsDispensed.end(); ++iter)
	{
		nSum = nSum + (iter->first * iter->second);
	}

	/*
	if(!(coinsDispensed.size() == 1 && coinsDispensed[1] == 1))
	{
		cout << "Test - change amount of 1 failed" << endl;
		numOfTestsFailed++;	
	}*/
	
	
	
/*	if(numOfTestsFailed)
	{
		cout << numOfTestsFailed << " tests failed" << endl;
		return false;
	}
	return true;
	
}*/
