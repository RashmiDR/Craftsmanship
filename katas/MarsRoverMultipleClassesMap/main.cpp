//
//  main.cpp
//  MarsRoverKata
//
//  Created by Rashmi Devarahalli on 3/25/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include <iostream>

#include "rover.h"

using namespace std;

void printRoverTestResult(string testDescription, bool testStatus, Point position);

int main(int argc, const char * argv[])
{

	Rover rover;
    Sphere sphere;
	Point finalPosition;
	int numOfPassingTests = 0;
	int numOfFailingTests = 0;
    
	sphere.SetSphereDimensions(100,100);    
    rover.PlaceRoverInSphere(sphere);
	
	
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
    
    //testing clockwise
    rover.MoveRover(0, 0, DIRECTION_NORTH, "ffrffrffrff");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 0 && finalPosition.y == 0)
	{
		numOfPassingTests++;
		printRoverTestResult("clockwise test", true, finalPosition);
		
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("clockwise test", false, finalPosition);
	}
    
    //testing anticlockwise
    rover.MoveRover(0, 0, DIRECTION_NORTH, "fflfflfflff");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 0 && finalPosition.y == 0)
	{
		numOfPassingTests++;
		printRoverTestResult("Anticlockwise test", true, finalPosition);
		
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("Anticlockwise test", false, finalPosition);
	}
    
    //testing back & wrapping
    rover.MoveRover(0, 0, DIRECTION_NORTH, "bblffrffrbb");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 96 && finalPosition.y == 0)
	{
		numOfPassingTests++;
		printRoverTestResult("backing test", true, finalPosition);
		
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("backing test", false, finalPosition);
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
    
    //obstacles
    vector<Point> obstacles;
    Point p1(2,2);
    obstacles.push_back(p1);
    sphere.SetObstaclesAtPoints(obstacles);    
    rover.PlaceRoverInSphere(sphere);
    
    rover.MoveRover(0, 0, DIRECTION_NORTH, "ffrff");
	finalPosition = rover.GetCurrentPosition();
	if(finalPosition.x == 1 && finalPosition.y == 2)
	{
		numOfPassingTests++;
		printRoverTestResult("Obstacle test", true, finalPosition);
		
	}
	else
	{
		numOfFailingTests++;
		printRoverTestResult("Obstacle test", false, finalPosition);
	}
    
	
	cout << "Number of passing tests: " << numOfPassingTests << endl;
	cout << "Number of failing tests: " << numOfFailingTests << endl;
    
    return 0;
}

void printRoverTestResult(string testDescription, bool testStatus, Point position)
{
	string testResult;
	if(testStatus)
		testResult = " Passed\t";
	else
		testResult = " Failed\t";
    
	cout << testDescription << testResult;
	cout << "Final rover position: ("<< position.x << " , " <<position.y << ")" << endl;
}


