//
//  rover.cpp
//  MarsRoverKata
//
//  Created by Rashmi Devarahalli on 3/25/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include "rover.h"


void Rover::PlaceRoverInSphere(Sphere roverSphere)
{
    this->sphere = roverSphere;
}


bool Rover::SetCurrentPosition(int x, int y)
{
	if(sphere.IsWithinSphere(x, y))
	{
		currentPosition.x = x;
		currentPosition.y = y;
        return true;
	}
	return false;
}

Point Rover::GetCurrentPosition()const
{
	return currentPosition;
}

bool Rover::SetDirectionFacing(DIRECTION direction)
{
	if(direction < DIRECTION_MAX)
	{
		directionFacing = direction;
		return true;
	}
	return false;
}

DIRECTION Rover::GetDirectionFacing()const
{
	return directionFacing;
}


void Rover::MoveRover(int startX, int startY, DIRECTION currentDirection, string moveCommand)
{
	currentPosition.x = startX;
	currentPosition.y = startY;
	directionFacing = currentDirection;
	
	
	for(char command = 0; command < moveCommand.length(); command++)
	{
		switch(moveCommand[command])
		{
			case 'f': moveFront();
                break;
                
			case 'b': moveBack();
                break;
                
			case 'l':turnLeft();
                break;
                
			case 'r':turnRight();
                break;
                
			default:
                break;
                
		}
	}
    
}

void Rover::moveFront()
{
    bool isMoverComplete = true;
    Point obstaclePoint;
	switch (directionFacing)
	{
		case DIRECTION_EAST:
			isMoverComplete = sphere.changeX(currentPosition, INCREMENT, obstaclePoint);
			break;
            
		case DIRECTION_WEST:
			isMoverComplete = sphere.changeX(currentPosition, DECREMENT, obstaclePoint);
			break;
            
		case DIRECTION_NORTH:
			isMoverComplete = sphere.changeY(currentPosition, INCREMENT, obstaclePoint);
			break;
            
		case DIRECTION_SOUTH:
			isMoverComplete = sphere.changeY(currentPosition, DECREMENT, obstaclePoint);
			break;
            
        default:
            break;
            
	}
    
    if(isMoverComplete == false)
    {
        printObstacleMessage(obstaclePoint);
    }
}

void Rover::moveBack()
{
    bool isMoverComplete = true;
    Point obstaclePoint;
    
	switch(directionFacing)
	{
		case DIRECTION_EAST:
			isMoverComplete = sphere.changeX(currentPosition, DECREMENT,obstaclePoint);
			break;
            
		case DIRECTION_WEST:
			isMoverComplete = sphere.changeX(currentPosition, INCREMENT, obstaclePoint);
			break;
            
		case DIRECTION_NORTH:
			isMoverComplete = sphere.changeY(currentPosition, DECREMENT, obstaclePoint);
			break;
            
		case DIRECTION_SOUTH:
			isMoverComplete = sphere.changeX(currentPosition, INCREMENT, obstaclePoint);
			break;
            
        default:
            break;
            
	}
    
    if(isMoverComplete == false)
    {
        printObstacleMessage(obstaclePoint);
    }
}

void Rover::turnLeft()
{
	switch(directionFacing)
	{
		case DIRECTION_EAST:
			directionFacing = DIRECTION_NORTH;
			break;
			
		case DIRECTION_NORTH:
			directionFacing = DIRECTION_WEST;
			break;
            
		case DIRECTION_WEST:
			directionFacing = DIRECTION_SOUTH;
			break;
            
		case DIRECTION_SOUTH:
			directionFacing = DIRECTION_EAST;
			break;
            
        default:
            break;
	}
}


void Rover::turnRight()
{
	switch(directionFacing)
	{
		case DIRECTION_EAST:
			directionFacing = DIRECTION_SOUTH;
			break;
			
		case DIRECTION_SOUTH:
			directionFacing = DIRECTION_WEST;
			break;
			
		case DIRECTION_WEST:
			directionFacing = DIRECTION_NORTH;
			break;
			
		case DIRECTION_NORTH:
			directionFacing = DIRECTION_EAST;
			break;
            
        default:
            break;
	}
}

void Rover::printObstacleMessage(Point obstaclePoint)
{
    cout << "Obstacle at location (" << obstaclePoint.x << " , " << obstaclePoint.y << ")" << endl;
    cout << "Staying at location (" << currentPosition.x << " , " << currentPosition.y << ")" <<endl;
}


