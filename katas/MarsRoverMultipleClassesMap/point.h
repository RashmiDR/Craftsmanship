//
//  point.h
//  MapExample
//
//  Created by Rashmi Devarahalli on 3/28/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#ifndef __MapExample__point__
#define __MapExample__point__

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
    
    Point(){}
    Point(int x, int y): x(x), y(y) {}
    
    //Overload the  < operator in point class or provide a compare function while declaring the map
    bool operator<(const Point &other) const
    {
        if(x == other.x)
            return y < other.y;
        else
            return x < other.x;        
        
    }
};
        


#endif /* defined(__MapExample__point__) */
