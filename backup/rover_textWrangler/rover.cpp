#include "rover.h"

const int ONE_STEP = 1;

bool Rover::SetGridDimensions(int length, int breadth)
{
	if(length > 0 && breadth > 0)
	{
		grid.length = length;
		grid.breadth = breadth;	
		return true;
	}
	return false;
}

/*
void Rover::GetGridDimensions(int* length, int* breadth)const;
{
	length = grid.length;
	breadth = grid.breadth; 
}
*/

bool Rover::SetCurrentPosition(int x, int y)
{
	if(x <= grid.length && y <= grid.breadth)
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

void Rover::RoverSetObstaclesAtPoints(vector<Point> obstaclePoints)
{
	obstaclePointsInGrid = obstaclePoints;
}

void Rover::MoveRover(int startX, int startY, DIRECTION currentDirection, string moveCommand)
{
	currentPosition.x = startX;
	currentPosition.y = startY;
	directionFacing = currentDirection;
	
	
	for(char command = 0; command < moveCommand.length(); command++)
	{
		switch(command)
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
			currentPosition.x+= ONE_STEP;
			wrapLength(currentPosition.x);
			break;
							
		case DIRECTION_WEST:
			currentPosition.x-= ONE_STEP;
			wrapLength(currentPosition.x);
			break;
	
		case DIRECTION_NORTH:
			currentPosition.y+= ONE_STEP;
			wrapBreadth(currentPosition.y);
			break;
							
		case DIRECTION_SOUTH:
			currentPosition.y-= ONE_STEP;
			wrapBreadth(currentPosition.y);
			break;
									
	}
}

void Rover::moveBack()
{
	switch(directionFacing)
	{
		case DIRECTION_EAST:
			currentPosition.x-= ONE_STEP;
			wrapLength(currentPosition.x);
			break;
							
		case DIRECTION_WEST:
			currentPosition.x+= ONE_STEP;
			wrapLength(currentPosition.x);
			break;
	
		case DIRECTION_NORTH:
			currentPosition.y-= ONE_STEP;
			wrapBreadth(currentPosition.y);
			break;
							
		case DIRECTION_SOUTH:
			currentPosition.y+= ONE_STEP;
			wrapBreadth(currentPosition.y);
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
	}
}


void Rover::wrapLength(int& x)
{
	if(x > grid.length)
	{
		x-=grid.length;
	}	
}
void Rover::wrapBreadth(int& y)
{
	if(y > grid.breadth)
	{
		y -= grid.breadth;
	}
}

