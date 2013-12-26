//
//  UnauthorizedException.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/15/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__UnauthorizedException__
#define __OOP_FinalProject__UnauthorizedException__

#include <iostream>
#include "Exception.h"

class UnauthorizedException : Exception {
public:
    UnauthorizedException(string name);
};

#endif /* defined(__OOP_FinalProject__UnauthorizedException__) */
