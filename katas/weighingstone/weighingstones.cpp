#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int totalWeight = 0, sum =0;
	int nextSuperNumber;
	cout  << "Enter the total weight" << endl;
	cin >> totalWeight; 
	
	vector<int> subWeights;
	
	subWeights.push_back(1);
	sum = subWeights[0];
	
	for(int num = 1; num <= totalWeight; num++)
	{
		if(num > sum)
		{
			nextSuperNumber = num + sum;
			if(nextSuperNumber > totalWeight)
			{
				cout <<  "Impossible to have the sub-weights that measure every number between 1 to " << totalWeight << endl;
				return 0;
			}
			subWeights.push_back(nextSuperNumber);
			sum+= nextSuperNumber;
			if(sum > totalWeight)
				break;
			
		}	
	}
	
	cout << "\nsub-weights that can be used to weigh every number between 1 to " << totalWeight << ": " << endl;
	for(int i = 0; i < subWeights.size(); i++)
	{
		cout << subWeights[i] << endl;
	}
	
	
}

/*
void test(int totalWeight, vector<int> subWeights)
{
	
	int plus = 1, minus = -1, dontcare = 0; 
	int currentNum = 0; prevNum = 0;
	vector<int> multiplier;
	
	for(int i = 0; i< subWeights.size; i++)
	{
		multiplier.push_back(dontcare);
	} 
	//MAke only the first number multiplier to be 1
	multiplier[0] = 1;
	
	int  i = 0;
	while(currentNum < totalWeight)	
	{
		if(currentNum % subWeights)
		
		
	for()
		currentNum = subWeights[0] * multiplier[0]+ 
						subWeights[1] * multiplier[1]+
						 subWeights[2] * multiplier[2]; 			
	}
	
}*/