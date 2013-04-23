//
//  rover.h
//  MarsRover
//
//  Created by Rashmi Devarahalli on 3/25/13.
//
//

#ifndef __MarsRover__rover__
#define __MarsRover__rover__

#include <iostream>

#include <vector>
#include <string>

using namespace std;

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Grid
{
	int length;
	int breadth;
}Grid;

typedef enum
{
	DIRECTION_EAST,
	DIRECTION_WEST,
	DIRECTION_NORTH,
	DIRECTION_SOUTH,
	DIRECTION_MAX,
}DIRECTION;


class Rover
{
	Point currentPosition;
	DIRECTION directionFacing;
	Grid grid;
	vector<Point> obstaclePointsInGrid;
	
public:
	Rover(){}
	Rover(Point pos, DIRECTION direction, Grid gridDimensions)//overloaded constructor
	{
		currentPosition = pos;
		directionFacing = direction;
		grid = gridDimensions;
	}
	
	bool SetCurrentPosition(int x, int y);
	Point GetCurrentPosition()const;
	bool SetDirectionFacing(DIRECTION direction);
	DIRECTION GetDirectionFacing()const;
	bool SetGridDimensions(int length, int breadth);
    //	void GetGridDimensions(int* length, int* breadth)const;
	void MoveRover(int startX, int startY, DIRECTION currentDirection, string moveCommand);
	void RoverSetObstaclesAtPoints(vector<Point> obstaclePoints);
	
private:
    void moveFront();
    void moveBack();
    void turnLeft();
    void turnRight();
    void wrapBreadth(int& x);
    void wrapLength(int& y);
	
    
};

#endif /* defined(__MarsRover__rover__) */
