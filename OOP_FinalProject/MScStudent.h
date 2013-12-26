//
//  MScStudent.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__MScStudent__
#define __OOP_FinalProject__MScStudent__

#include <iostream>
#include "Student.h"

class MScStudent : Student {
	//M.Sc student class
public:
    MScStudent();		//default constractor
	~MScStudent();		//default distractor
    StudentStatus getStudentStatus() const {return MSCUSER; }	//return the type of the student - Master student in this case
    bool hasStudentGraduated();		//return 1 if the student have enought points
};


#endif /* defined(__OOP_FinalProject__MScStudent__) */
