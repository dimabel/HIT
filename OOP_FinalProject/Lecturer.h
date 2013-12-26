//
//  Lecturer.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__Lecturer__
#define __OOP_FinalProject__Lecturer__

#include <iostream>
#include "SystemUser.h"
#include "Student.h"

class Lecturer : public SystemUser {
	//Lecturer Class with a Lecturer options
public:
	void printCourseInfo(const int courseId) const;	//print out studets info
    void printStudentInfo(int studentId) const;		//print out course info
    Lecturer();								//default distractor
    ~Lecturer();								//default distractor
private:
    bool isMyStudent(const int studentId) const; //return 1 is the student is this Lecturer student
};

#endif /* defined(__OOP_FinalProject__Lecturer__) */
