//
//  CampusWorker.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__CampusWorker__
#define __OOP_FinalProject__CampusWorker__

#include <iostream>
#include "SystemUser.h"
#include "Student.h"
#include "Course.h"

class CampusWorker : public SystemUser {
	//campus worker class
public:

	CampusWorker();		//default constractor
    ~CampusWorker();	//default distractor
    void printStudentInfo(const int studentId) const;	//print students info
    void printCourseInfo(const int courseId) const;	//print Course info

    void updateStudent(Student student);		//allows the worker to update students info
    void enroll(int studentId, int courseId);	//signs a user to a course, if it is possible
    void printReport(int studentId) const;		//prints students report
    void openNewCourse(Course course);			//Createing a new Course
    void updateCourse(Course course);			//updateing an existing Course
    void updateStudentFinalGrade(int studentId, int courseId, int finalGrade);	//allows the worker to change students grade
    void updateStudentCourseStatus(int studentId, int courseId, CourseStatus courseStatus);	//changes a students course status
	
};
#endif /* defined(__OOP_FinalProject__CampusWorker__) */
