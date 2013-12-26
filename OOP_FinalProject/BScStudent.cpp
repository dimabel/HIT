//
//  BScStudent.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "BScStudent.h"

bool BScStudent::hasStudentGraduated()
// return 1 if the student Graduated by his points
//
{
    int intermediateCoursesPoints = 0; 
    int sumPoints = 0;
    for (auto it = begin (getCourses()); it != end (getCourses()); ++it) {
        sumPoints += it->getCourse()->getCoursePoints(); // add all the regular points
        intermediateCoursesPoints += (it->getCourse()->getCourseLevel() == INTERMEDIATE ? it->getCourse()->getCoursePoints() : 0);
    }
    return (intermediateCoursesPoints >= 5 && sumPoints >= 20);	//check if enought points
}
