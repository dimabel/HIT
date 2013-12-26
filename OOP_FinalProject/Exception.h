//
//  Exception.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/15/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__Exception__
#define __OOP_FinalProject__Exception__

#include <iostream>

using namespace std;

class Exception {
    string name;
public:
    string getName() const;
    Exception(string name);
};

#endif /* defined(__OOP_FinalProject__Exception__) */
