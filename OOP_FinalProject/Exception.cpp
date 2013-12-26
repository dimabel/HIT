//
//  Exception.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/15/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "Exception.h"

string Exception::getName() const {
    return name;
}

Exception::Exception(string name) {
    this->name = name;
}