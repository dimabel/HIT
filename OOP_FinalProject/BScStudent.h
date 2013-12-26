//
//  BScStudent.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__BScStudent__
#define __OOP_FinalProject__BScStudent__

#include "Student.h"
#include <iostream>

class BScStudent : Student {
	//B.Sc student class
public:
    BScStudent();		//default constractor
	~BScStudent();		//default distractor
    StudentStatus getStudentStatus() const {return BSCUSER;} //return the type of the student - Bachelour in this case
    bool hasStudentGraduated();// return 1 if the student Graduated by his points
};

#endif /* defined(__OOP_FinalProject__BScStudent__) */
