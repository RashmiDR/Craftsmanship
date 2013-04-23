//
//  singleton.h
//  trees
//
//  Created by Rashmi Devarahalli on 4/18/13.
//  Copyright (c) 2013 Rashmi Devarahalli. All rights reserved.
//

#ifndef __trees__singleton__
#define __trees__singleton__

#include <iostream>

class Singleton
{
private:
    Singleton();
    Singleton* instance = NULL;
    
public:
    Singleton* getInstance()
    {
        if(instance == NULL)
            instance = new Singleton();
        return instance;
        
    }
};

#endif /* defined(__trees__singleton__) */
