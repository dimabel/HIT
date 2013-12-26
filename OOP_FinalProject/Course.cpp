//
//  Course.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//
//

#include "pch.h"
#include "Course.h"

static int counterCourseId = 0;

int Course::getCoursePoints() const {
	//return the number of points for the course
    return coursePoints;
}

Course::Course() {
    courseId = counterCourseId;
    counterCourseId++;// allows the ID to be serial
}

void Course::addParticipant() {
	//change the number of participants - add one
    participants++;
}

int Course::getParticipants() const {
	//returns the number of participants
    return participants;
}

std::vector<Course *> Course::getRequiredCourses() const {
    return requiredCourses;
}

int Course::getCourseId() const {
	//return the Course ID
    return courseId;
}

void Course::setRequiredCourses(std::vector<Course *> req) {
    requiredCourses = req;
}

void Course::setCourseName(string name) {
	//course name setter
    courseName = name;
}

string Course::getCourseName() const {
	//returns the name of the course
    return courseName;
}

void Course::setCoursePoints(int pts) {
	//set the number of point of a the course
    coursePoints = pts;
}

void Course::setCourseSemester(int sem) {
	//set the semester of the course
    courseSemester = sem;
}

void Course::setCourseLecturerId(int lecturerId) {
	//set a lecturer to a course
    courseLecturerId = lecturerId;
}

int Course::getCourseLecturerId() const {
	//returns the ID of the lecturer of the couse
    return courseLecturerId;
}

 int Course::getCourseSemester() const {
	 //return the semester of the course
        return courseSemester;
}

void Course::printInfo() const {
	//print out full info of the course
    cout << "Course #" << getCourseId() << "'s name is " << getCourseName() << " and it is a " << ((getCourseLevel() == BASIC) ? "basic BSc" : (INTERMEDIATE ? "intermediate BSc" : "MSc")) << " Course.\n";
    cout << "It's required courses are: \n";
    for (auto it = begin (getRequiredCourses()); it != end (getRequiredCourses()); ++it) {
        Course *course = *it;
        cout << "#" << course->getCourseId() << ": " << course->getCourseName();
    }
}

