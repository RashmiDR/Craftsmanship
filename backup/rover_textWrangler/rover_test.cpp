#include <iostream>
#include "rover.h"

using namespace std;

void printRoverTestResult(string testDescription, bool testStatus, Point position);

int main()
{
	Rover rover;
	Point finalPosition;
	int numOfPassingTests = 0;
	int numOfFailingTests = 0;

	
	rover.SetGridDimensions(100,100);
	
	
	//general test
	rover.MoveRover(0, 0, DIRECTION_NORTH, "ffrff");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 2 && finalPosition.y == 2)
	{
		numOfPassingTests++;
		printRoverTestResult("General test", true, finalPosition);
		
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("General test", false, finalPosition);
	}
		
	//wrapping test
	rover.MoveRover(100, 100, DIRECTION_NORTH, "ffrff");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 2 && finalPosition.y == 2)
	{
		numOfPassingTests++;
		printRoverTestResult("Wrapping test", true, finalPosition);
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("Wrapping test", false, finalPosition);
	}			
	
	cout << "Number of passing tests: " << numOfPassingTests << endl;
	cout << "Number of failing tests: " << numOfFailingTests << endl; 
}

void printRoverTestResult(string testDescription, bool testStatus, Point position)
{
	string testResult;
	if(testStatus)
		testResult = " Passed\t";
	else
		testResult = " Failed\t";
		
	cout << testDescription << testResult;
	cout << "Final rover position: (" << position.x << " , " <<position.y << ")" << endl;
}