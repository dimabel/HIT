//
//  BScCourse.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__BScCourse__
#define __OOP_FinalProject__BScCourse__

#include <iostream>
#include "Course.h"

class BScCourse : Course {
public:
    BScCourse();		//default constractor
	~BScCourse();		//default distractor
    CourseLevel getCourseLevel() const {return BASIC;} //returns the level of the Course - INTERMEDIATE in this case
};

#endif /* defined(__OOP_FinalProject__BScCourse__) */
