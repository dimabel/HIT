//
//  Lecturer.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "Lecturer.h"
#include "StudentsDb.h"
#include "CoursesDb.h"
#include "UnauthorizedException.h"

bool Lecturer::isMyStudent(const int studentId) const {
	//return 1 is the student is this Lecturer student
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    for (auto it = begin ((*st).getCourses()); it != end ((*st).getCourses()); ++it) {
        Course *course = it->getCourse();
        if (course->getCourseLecturerId() == getId()) {
            return true;
        }
    }
    return false;
}

void Lecturer::printCourseInfo(int courseId) const {
	//print out course info only if he is teaching it
    CoursesDb *db = CoursesDb::getInstance();
    Course *course = db->getCourse(courseId);
    if (course->getCourseLecturerId() == getId()) {
        return course->printInfo();
    }
    throw new UnauthorizedException("This course is not taught by you!");
}

void Lecturer::printStudentInfo(int studentId) const {
	//print out studets info if the student is his
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    if (isMyStudent(studentId)) {
        st->printInfo();
    }
    throw new UnauthorizedException("This is not your student!");
}

Lecturer::~Lecturer() { //default distractor
    
}

Lecturer::Lecturer() {
    
}
