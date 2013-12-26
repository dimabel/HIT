//
//  BScAdvancedCourse.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/23/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__BScAdvancedCourse__
#define __OOP_FinalProject__BScAdvancedCourse__

#include <iostream>
#include "Course.h"

class BScAdvancedCourse : Course {
public:
    BScAdvancedCourse();	//default constractor
	~BScAdvancedCourse();	//default distractor
    CourseLevel getCourseLevel() const {return INTERMEDIATE;} //returns the level of the Course - INTERMEDIATE in this case
};

#endif /* defined(__OOP_FinalProject__BScAdvancedCourse__) */
