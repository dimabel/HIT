//
//  StudentsDb.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "StudentsDb.h"

bool StudentsDb::instanceFlag = false;
StudentsDb* StudentsDb::sharedInstance = NULL;
StudentsDb* StudentsDb::getInstance()
{
    if(! instanceFlag)
    {
        sharedInstance = new StudentsDb();
        instanceFlag = true;
        return sharedInstance;
    }
    else
    {
        return sharedInstance;
    }
}

Student* StudentsDb::getStudent(int studentId) {
    for (auto it = begin (students); it != end (students); ++it) {
        Student *st = *it;
        if (st->getId() == studentId) {
            return *it;
        }
    }
    return NULL;
}