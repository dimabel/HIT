//
//  MScStudent.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "MScStudent.h"

bool MScStudent::hasStudentGraduated() {
    int intermediateCoursesPoints = 0;
    int sumPoints = 0;
    for (auto it = begin (getCourses()); it != end (getCourses()); ++it) {
        sumPoints += it->getCourse()->getCoursePoints();
        intermediateCoursesPoints += (it->getCourse()->getCourseLevel() == MSC ? it->getCourse()->getCoursePoints() : 0);
    }
    return (intermediateCoursesPoints <= 4 && sumPoints >= 10);
}

void Student::setBirthDate(time_t birthDate) {
    this->birthDate = birthDate;
}