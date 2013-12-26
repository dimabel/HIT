//
//  CourseList.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "CoursesDb.h"

bool CoursesDb::instanceFlag = false;
CoursesDb* CoursesDb::sharedInstance = NULL;
CoursesDb* CoursesDb::getInstance()
{
    if(! instanceFlag)
    {
        sharedInstance = new CoursesDb();
        instanceFlag = true;
        return sharedInstance;
    }
    else
    {
        return sharedInstance;
    }
}

Course* CoursesDb::getCourse(int courseId) {
    for (auto it = begin (courses); it != end (courses); ++it) {
        Course *course = *it;
        if (course->getCourseId() == courseId) {
            return (*it);
        }
    }
    return NULL;
}

std::vector<Course *> CoursesDb::getCourses() const {
    return courses;
}