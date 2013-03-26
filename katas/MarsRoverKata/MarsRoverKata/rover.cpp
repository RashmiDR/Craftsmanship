//
//  rover.cpp
//  MarsRoverKata
//
//  Created by Rashmi Devarahalli on 3/25/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include "rover.h"


const int ONE_STEP = 1;

void Rover::initializeObstacleGrid()
{
    for(int i = 0; i < GRID_LENGTH; i++)
    {
        for(int j = 0; j < GRID_BREADTH; j++)
        {
            obstaclesGrid[i][j] = false;
        }
    }
}

bool Rover::SetCurrentPosition(int x, int y)
{
	if(x <= GRID_LENGTH && y <= GRID_BREADTH)
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

void Rover::SetObstaclesAtPoint(int x, int y)
{
    obstaclesGrid[x][y] = true;

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
	switch (directionFacing)
	{
		case DIRECTION_EAST:
			changeX(INCREMENT);
			break;
            
		case DIRECTION_WEST:
			changeX(DECREMENT);
			break;
            
		case DIRECTION_NORTH:
			changeY(INCREMENT);
			break;
            
		case DIRECTION_SOUTH:
			changeY(DECREMENT);
			break;
            
        default:
            break;
            
	}
}

void Rover::moveBack()
{
	switch(directionFacing)
	{
		case DIRECTION_EAST:
			changeX(DECREMENT);
			break;
            
		case DIRECTION_WEST:
			changeX(INCREMENT);
			break;
            
		case DIRECTION_NORTH:
			changeY(DECREMENT);
			break;
            
		case DIRECTION_SOUTH:
			changeY(INCREMENT);
			break;
            
        default:
            break;
            
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


void Rover::wrapLength(int& x)
{
	if(x >= GRID_LENGTH)
	{
		x-=GRID_LENGTH;
	}
	else if(x == -1)
    {
        x = GRID_LENGTH - 1; //sphere
    }
}
void Rover::wrapBreadth(int& y)
{
	if(y >= GRID_BREADTH)
	{
		y -= GRID_BREADTH;
	}
    else if(y == -1)
    {
        y = GRID_BREADTH - 1;
    }
}

void Rover::changeX(INCREMENT_OR_DECREMENT change)
{
    int prevX = currentPosition.x;
    if(change == INCREMENT)
    {
        currentPosition.x += ONE_STEP;
    }
    else
    {
        currentPosition.x -= ONE_STEP;
    }
    wrapLength(currentPosition.x);
    if(hasObstacle(currentPosition))
    {
        cout << "Obstacle at location (" << currentPosition.x << " , " << currentPosition.y << ")" << endl;
        currentPosition.x = prevX;
        cout << "Staying at location (" << currentPosition.x << " , " << currentPosition.y << ")" <<endl;
    }

}

void Rover::changeY(INCREMENT_OR_DECREMENT change)
{
    int prevY = currentPosition.y;
    if(change == INCREMENT)
    {
        currentPosition.y += ONE_STEP;
    }
    else
    {
        currentPosition.y -= ONE_STEP;
    }
    wrapLength(currentPosition.y);
    if(hasObstacle(currentPosition))
    {
        cout << "Obstacle at location (" << currentPosition.x << " , " << currentPosition.y << ")" << endl;
        currentPosition.y = prevY;
        cout << "Staying at location (" << currentPosition.x << " , " << currentPosition.y << ")" <<endl;
    }
    
}

bool Rover::hasObstacle(Point p)
{   
    return obstaclesGrid[p.x][p.y];
}
