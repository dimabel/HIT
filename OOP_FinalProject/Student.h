//
//  Student.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__Student__
#define __OOP_FinalProject__Student__

#include <iostream>
#include <vector>
#include "CourseGradeMap.h"
#include "SystemUser.h"
#include "Course.h"
#include <time.h>

using namespace std;

enum StudentStatus { UNDERGRAD, BSCUSER, MSCUSER };		//new type - used to confirm the type of the entity

class Student : public SystemUser {
	std::vector<CourseGradeMap> courses;	// a vector containg all the courses of the student
	time_t birthDate;						//birth date

public:
	Student();								//default constractor
	~Student();								//default distractor
	
    virtual StudentStatus getStudentStatus() const; //used to confirm the type of the entity
    virtual bool hasStudentGraduated();
    
	double getStudentAge() const;			//returns students age
	time_t getBirthDate() const;			//returns date of birth
	vector<CourseGradeMap> getCourses() const;
	float getAverage() const;				//returns students average

	CourseGradeMap* getCourse(int courseId); //Returns the course studied by user + status + grade
	void setBirthDate(time_t birthDate);	 //setter for students date of bitrh
	void printInfo()const;					 //prints students full info
    void printCourseInfo(int courseId) const;
    void printStudentInfo(int studentId) const;
};

#endif /* defined(__OOP_FinalProject__Student__) */
