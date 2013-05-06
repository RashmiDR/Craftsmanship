/*
Write a program to find the element in an array that is 
repeated more than half number of times. Return -1 if no such element is found.
*/

#include <iostream>
#include <map>

using namespace std;


int getRepeatingElement(int array[], int size);
int getRepeatingElementVotingAlgo(int array[], int size);
int main()
{
	//int array[] = {1,2,3,4,4,4,4,4,4,2};
	int array[] = {2,2,2,3,4,5,1,1};
	
	int repeatingElement = getRepeatingElement(array, 7);
	
	if(repeatingElement!= INT_MIN)
		cout << "repeating element is " << repeatingElement << endl;
	else
		cout << "No element that repeats more than half the times in the array"<<endl;
		

	repeatingElement = getRepeatingElementVotingAlgo(array, 7);
	if(repeatingElement!= INT_MIN)
		cout << "repeating element is " << repeatingElement << endl;
	else
		cout << "No element that repeats more than half the times in the array"<<endl;
		
	return 0;
	
}


//TIME COMPLEXITY IS O(N), SPACE COMPLEXITY IS O(2N)
int getRepeatingElement(int array[], int size)
{
	map<int, int> occuranceHashMap;
	map<int, int>::iterator iter;
	for(int i = 0; i<size; i++)
	{
		iter = occuranceHashMap.find(array[i]);
		if(iter == occuranceHashMap.end())
		{
			occuranceHashMap.insert(make_pair(array[i], 1));			
		}
		else
		{
			iter->second++;
			if(iter->second > size/2)
				return iter->first;
		}
	}
	return INT_MIN;
}

//	Time complexity is O(n) and Space complexity is O(1)
//Boyer Moore Voting algorithm
int getRepeatingElementVotingAlgo(int array[], int size)
{
	int count = 0, i = 0;
	int currentCandidate = array[0];
	for(i = 0; i< size; i++)
	{
		if(currentCandidate == array[i])
		{
			count++;
		}
		else if(count == 0)
		{
			currentCandidate = array[i];
			count++;
		}
		else 
		{
			count--;
		}
	}
	
	//The second phase check if the candidate actually repeats more than half the times
	count = 0;
	for(i = 0; i< size; i++)
	{
		if(array[i] == currentCandidate)
		{
			count++;
			if(count > size/2)
				return currentCandidate;
		}		
	}

	return INT_MIN;
}


//Reference http://www.geeksforgeeks.org/majority-element/ 

