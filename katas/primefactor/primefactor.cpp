#include <iostream>

#include "primefactor.h"


vector<int> NumberGenerator::generate(int N)
{
	vector<int> primeFactors;
	for(int divisor=2; N>1 && divisor <= N; divisor++)
	{
		if(N % divisor == 0)
		{
			primeFactors.push_back(divisor);
			while(N%divisor == 0)
			{
				N/= divisor;		
			}	
		}
	}
	return primeFactors;
}

int main()
{
	vector<int> primefactors;
	//for(int i = 1; i<100; i++)
	//{
	int i= 16;
		primefactors = NumberGenerator::generate(i);
		cout << "primefactors of " <<  i << endl;
		for(int j=0; j<primefactors.size(); j++)
		{
			cout << primefactors[j] << "\t";
		}
		cout << endl;
	//}	
	


	return 0;
}