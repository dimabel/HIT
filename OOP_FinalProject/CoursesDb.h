//
//  CoursesDb.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__CoursesDb__
#define __OOP_FinalProject__CoursesDb__

#include <iostream>
#include <vector>
#include "Course.h"

using namespace std;

class CoursesDb {
private:
    static bool instanceFlag;
    static CoursesDb *sharedInstance;
    CoursesDb()
    {
        //private constructor
    }
    std::vector<Course *> courses;
public:
    static CoursesDb* getInstance();
    ~CoursesDb()
    {
        instanceFlag = false;
    }
    std::vector<Course *> getCourses() const;
    Course* getCourse(int courseId);
};

#endif /* defined(__OOP_FinalProject__CourseList__) */
