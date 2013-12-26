//
//  SystemUser.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__SystemUser__
#define __OOP_FinalProject__SystemUser__

#include <iostream>

using namespace std;

class SystemUser {
	string name;		//name of the user
	int entityId;		//ID of the user

public:
    SystemUser();					//default constractor
	virtual ~SystemUser();		//default distractor

	string getName() const {return name;}			//name getter - returns string
	void setName(string name){this->name = name;}	//name setter - change the name of the user
	int getId() const {return entityId;}			//ID getter - returns string

	virtual void printCourseInfo(const int courseId) const = 0;	//Course getter - return a Course by ID (Implemented by any subclass)
	virtual void printStudentInfo(const int) const = 0;			//Student getter - return a Student by ID (Implemented by any subclass)
};

#endif /* defined(__OOP_FinalProject__SystemUser__) */
