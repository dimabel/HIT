//
//  UndergradStudent.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__UndergradStudent__
#define __OOP_FinalProject__UndergradStudent__

#include <iostream>
#include "Student.h"

class UndergradStudent : public Student {
public:
    UndergradStudent();		//default constractor
	~UndergradStudent();	//default distractor
    StudentStatus getStudentStatus() const {return UNDERGRAD; } //returns the type of the student - undergraduate in this case
};

#endif /* defined(__OOP_FinalProject__UndergradStudent__) */
