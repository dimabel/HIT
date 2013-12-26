//
//  Student.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "Student.h"
#include "CourseGradeMap.h"

CourseGradeMap* Student::getCourse(int courseId) {
    for (auto it = begin (getCourses()); it != end (getCourses()); ++it) {
        if (it->getCourse()->getCourseId() == courseId) {
            CourseGradeMap map = *it;
			return &map;
        }
    }
    return NULL;
}

double Student::getStudentAge() const {
	//returns students age
		time_t now;
		localtime (&now);
		return difftime(birthDate, now);
	}

	time_t Student::getBirthDate() const {
		//returns students birth date
		return birthDate;
	}

	vector<CourseGradeMap> Student::getCourses() const {
		return courses;
	}

	float Student::getAverage() const {
		//returns students average
		float sumPoints = 0;
		float courseCounter = 0;
		for (auto it = begin (courses); it != end (courses); ++it) {
			courseCounter++;
			sumPoints += it->getCourseGrade();
		}
		return sumPoints / courseCounter;
	}

	void Student::printInfo() const {
		//print out student info
		cout << "Student #" << getId() << "'s name is " << getName() << " and he is " << getStudentAge() << " years old\n";
		for (auto it = begin (getCourses()); it != end (getCourses()); ++it) {
			cout << "Student studies/has studied course #" << it->getCourse()->getCourseId() << " - " << it->getCourse()->getCourseName() << " of level " << ((it->getCourse()->getCourseLevel() == BASIC) ? "basic" : (INTERMEDIATE ? "intermediate" : "MSC")) << " with grade " << it->getCourseGrade();
		}
	}

void Student::printCourseInfo(int courseId) const {
    for (auto it = begin (getCourses()); it != end (getCourses()); ++it) {
        if (it->getCourse()->getCourseId() == courseId) {
            it->printInfo();
        }
    }
}

void Student::printStudentInfo(int studentId) const {
    if (studentId == this->getId()) {
        this->printInfo();
    }
}
