//
//  CourseGradeMap.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "CourseGradeMap.h"
#include "Course.h"

int CourseGradeMap::getCourseGrade() const {
	//returns course grade
    return courseGrade;
}

void CourseGradeMap::setCourseGrade(int newGrade) {
	//set course grade
    courseGrade = newGrade;
}

Course* CourseGradeMap::getCourse() const {
	//
    return course;
}

CourseStatus CourseGradeMap::getCourseStatus() const {
	//returns couse status
    return courseStatus;
}

void CourseGradeMap::setCourseStatus(CourseStatus courseStatus) {
	//course status setter
    this->courseStatus = courseStatus;
}

CourseGradeMap::CourseGradeMap(Course *aCourse) {
	//copy constractor
    this->course = aCourse;
    this->courseGrade = 0;
    this->courseStatus = ENROLLED;
}

void CourseGradeMap::printInfo() const {
    cout << "Course: ";
    getCourse()->printInfo();
    cout << "Status: ";
    cout << (this->getCourseStatus() == ENROLLED ? "Enrolled" : (this->getCourseStatus() == FAILED ? "Failed" : "Passed"));
    cout << "Grade: ";
    cout << this->getCourseGrade();
}

CourseGradeMap::CourseGradeMap() {
	//default constractor

}

CourseGradeMap::~CourseGradeMap() {
    
}