//
//  StudentsDb.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__StudentsDb__
#define __OOP_FinalProject__StudentsDb__

#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class StudentsDb {
private:
    static bool instanceFlag;
    static StudentsDb *sharedInstance;
    StudentsDb()
    {
        //private constructor
    }
    std::vector<Student *> students;
public:
    static StudentsDb* getInstance();
    ~StudentsDb()
    {
        instanceFlag = false;
    }
    Student* getStudent(int studentId);
};

#endif /* defined(__OOP_FinalProject__StudentsDb__) */
