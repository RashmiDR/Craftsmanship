//
//  sphere.h
//  MapExample
//
//  Created by Rashmi Devarahalli on 3/28/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#ifndef __MapExample__sphere__
#define __MapExample__sphere__

#include <iostream>
#include <vector>
#include <map>

#include "point.h"

using namespace std;

typedef enum
{
    INCREMENT,
    DECREMENT
}INCREMENT_OR_DECREMENT;


class Sphere
{
private:
	int length;
	int breadth;    
    map<Point,bool> obstaclePointsInGrid;
    
    
public:
    bool IsWithinSphere(int length, int breadth);
    void SetObstaclesAtPoints(vector<Point> obstaclePoints);
    bool SetSphereDimensions(int length, int breadth);
    bool changeX(Point& currentPosition, INCREMENT_OR_DECREMENT change, Point& obstaclePoint);
    bool changeY(Point& currentPoistion, INCREMENT_OR_DECREMENT change, Point& obstaclePoint);
    //	void GetSphereDimensions(int* length, int* breadth)const;
    
private:
    void wrapBreadth(int& x);
    void wrapLength(int& y);
    bool hasObstacle(Point p);
    
};




#endif /* defined(__MapExample__sphere__) */
