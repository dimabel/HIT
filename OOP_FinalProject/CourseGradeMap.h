//
//  CourseGradeMap.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/13/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__CourseGradeMap__
#define __OOP_FinalProject__CourseGradeMap__

#include <iostream>
#include "Course.h"

typedef enum {	//new type that defines course status - one of 3 - FAILED, ENROLLED, PASSED
    FAILED, ENROLLED, PASSED
} CourseStatus;

class CourseGradeMap {
    int courseGrade;
    Course* course;
    CourseStatus courseStatus;
public:
    int getCourseGrade() const;				//returns Course grade
    CourseStatus getCourseStatus() const;	//returns Course status
    Course* getCourse() const;				

    void setCourseGrade(int newGrade);		//Course grade setter
    void setCourseStatus(CourseStatus courseStatus);//Course status setter

    void printInfo() const;

	CourseGradeMap();	//default constractor
	~CourseGradeMap();	//default distractor
    CourseGradeMap(Course *aCourse); //copy constractor
};
#endif /* defined(__OOP_FinalProject__CourseGradeMap__) */
