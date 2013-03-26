//
//  rover.h
//  MarsRoverKata
//
//  Created by Rashmi Devarahalli on 3/25/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#ifndef __MarsRoverKata__rover__
#define __MarsRoverKata__rover__

#include <iostream>

#include <vector>
#include <map>

#include <string>

using namespace std;

int const GRID_LENGTH = 100;
int const GRID_BREADTH = 100;


class Point
{
public:
	int x;
	int y;
    
    Point(){}
    Point(int x, int y)
    {
        x = x;
        y = y;
    }   
   
};



typedef enum
{
	DIRECTION_EAST,
	DIRECTION_WEST,
	DIRECTION_NORTH,
	DIRECTION_SOUTH,
	DIRECTION_MAX,
}DIRECTION;

typedef enum
{
    INCREMENT,
    DECREMENT
}INCREMENT_OR_DECREMENT;


class Rover
{
	Point currentPosition;
	DIRECTION directionFacing;
	bool obstaclesGrid[GRID_LENGTH][GRID_BREADTH];

	
public:
	Rover():currentPosition(0,0)
    {
        initializeObstacleGrid();
    }

    //overloaded constructor
	Rover(Point pos, DIRECTION direction): currentPosition(pos.x, pos.y) 
	{
		//currentPosition = pos;
		directionFacing = direction;
	}
	
	bool SetCurrentPosition(int x, int y);
	Point GetCurrentPosition()const;
	bool SetDirectionFacing(DIRECTION direction);
	DIRECTION GetDirectionFacing()const;
	void MoveRover(int startX, int startY, DIRECTION currentDirection, string moveCommand);
	void SetObstaclesAtPoint(int x, int y);
	
private:
    void moveFront();
    void moveBack();
    void turnLeft();
    void turnRight();
    void wrapBreadth(int& x);
    void wrapLength(int& y);
    void changeX(INCREMENT_OR_DECREMENT change);
    void changeY(INCREMENT_OR_DECREMENT change);
    bool hasObstacle(Point p);
    void initializeObstacleGrid();
	
    
};

#endif /* defined(__MarsRoverKata__rover__) */
