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



#include <string>
#include "sphere.h"
#include "point.h"

using namespace std;






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
	Sphere sphere;

	
public:
	Rover():currentPosition(0,0){}

    //overloaded constructor
	Rover(Point pos, DIRECTION direction, Sphere sphereDimensions): currentPosition(pos.x, pos.y)
	{
		directionFacing = direction;
		sphere = sphereDimensions;
	}
    
	void PlaceRoverInSphere(Sphere roverSphere);
	bool SetCurrentPosition(int x, int y);
	Point GetCurrentPosition()const;
	bool SetDirectionFacing(DIRECTION direction);
	DIRECTION GetDirectionFacing()const;
	void MoveRover(int startX, int startY, DIRECTION currentDirection, string moveCommand);
    

	
private:
    void moveFront();
    void moveBack();
    void turnLeft();
    void turnRight();
    void printObstacleMessage(Point obstaclePoint);

	
    
};

#endif /* defined(__MarsRoverKata__rover__) */
