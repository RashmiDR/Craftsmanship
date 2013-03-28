//
//  sphere.cpp
//  MapExample
//
//  Created by Rashmi Devarahalli on 3/28/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#include "sphere.h"

const int ONE_STEP = 1;


bool Sphere::SetSphereDimensions(int length, int breadth)
{
	if(length > 0 && breadth > 0)
	{
		this->length = length;
		this->breadth = breadth;
		return true;
	}
	return false;
}

bool Sphere::IsWithinSphere(int x, int y)
{
    if(x <= length && y <= breadth)
	{
		return true;
	}
	return false;
    
}

void Sphere::SetObstaclesAtPoints(vector<Point> obstaclePoints)
{
    vector<Point>::iterator iter;
    for(iter = obstaclePoints.begin(); iter != obstaclePoints.end(); iter++)
    {
        obstaclePointsInGrid.insert(pair<Point, bool>(*iter, true) );
    }
}


bool Sphere::changeX(Point& currentPosition, INCREMENT_OR_DECREMENT change, Point& obstaclePoint)
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
        obstaclePoint = currentPosition;
        currentPosition.x = prevX;
        return false;
    }
    
    return true;
    
}

bool Sphere::changeY(Point& currentPosition, INCREMENT_OR_DECREMENT change, Point& obstaclePoint)
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
        obstaclePoint = currentPosition;
        currentPosition.y = prevY;
        return false;
    }    
    return true;    
}

void Sphere::wrapLength(int& x)
{
	if(x >= length)
		x-= length;
	if(x == -1)
        x = length - 1;
}

void Sphere::wrapBreadth(int& y)
{
	if(y >= breadth)
		y -= breadth;
    if (y == -1)
        y = breadth - 1;
}

bool Sphere::hasObstacle(Point p)
{
    if (obstaclePointsInGrid.count(p) > 0)
        return true;
    return false;
    
    
}