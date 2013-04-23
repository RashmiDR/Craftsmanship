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

class Point
{
public:
	int x;
	int y;
    
    Point(){}
    Point(int x, int y)
    : x(x), y(y)
    {
        //x = x;Rashmi
        //y = y;
    }
    
    //Overload the  < operator in point class or provide a compare function while declaring the map 
    bool operator<(const Point &other) const
    {
        cout << x << " " << y << " " << other.x << " " << other.y << endl;
        if(x == other.x)
            return y < other.y;
        else
            return x < other.x;
    }

};

/*
class Pointcompare
{
public:
    bool operator()(const Point& p1,const Point& p2) const
    {
        cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
        //return p1 < p2;
        
        if(p1.x != p2.x)
            return p1.x < p2.x;
        else
            return p1.y < p2.y;
         
    }
};*/


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

typedef enum
{
    INCREMENT,
    DECREMENT
}INCREMENT_OR_DECREMENT;


class Rover
{
	Point currentPosition;
	DIRECTION directionFacing;
	Grid grid;
    map<Point,bool> obstaclePointsInGrid;
	
public:
	Rover():currentPosition(0,0){}

    //overloaded constructor
	Rover(Point pos, DIRECTION direction, Grid gridDimensions): currentPosition(pos.x, pos.y)
	{
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
	void SetObstaclesAtPoints(vector<Point> obstaclePoints);
	
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
	
    
};

#endif /* defined(__MarsRoverKata__rover__) */
