/*Given N dices.Each dice has A faces.That means each dice has numbers from 1 to A.
Given Sum S,Find the number of ways to make the sum S if dices are rolled together.
*/

#include <iostream>

using namespace std;

int main()
{
	int sum = 0, N = 0;
	
	cout << "Enter the sum " << endl;

	cin >> sum;
	
	cout << "Enter the number of dices" << endl;
	cin >> N;
	
	if(sum < N || sum > 10N)
	{
		cout << "not possible to get the sum specified" << endl;
		return 0; 
	}
	int numWaysToGetSum = 0;
	for(int i = 1; i <= 10; i++)
	{
		numWaysToGetSum += numWays(N, sum);
	}
}

int numWays(int numDices, int sum)
{
	if(sum == 0 || numDices == 0)
		return 0;
	
	1+ numWays(numDices-1, sum-)	
}