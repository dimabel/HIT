//
//  MScCourse.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__MScCourse__
#define __OOP_FinalProject__MScCourse__

#include <iostream>
#include "Course.h"

class MScCourse : Course {
public:
    MScCourse();		//default constractor
	~MScCourse();		//default distractor
    CourseLevel getCourseLevel() const {	//returns the level of the Course - INTERMEDIATE in this case
        return MSC;
    }
};

#endif /* defined(__OOP_FinalProject__MScCourse__) */
