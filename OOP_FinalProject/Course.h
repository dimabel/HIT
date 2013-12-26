//
//  Course.h
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#ifndef __OOP_FinalProject__Course__
#define __OOP_FinalProject__Course__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum {
    BASIC, INTERMEDIATE, MSC
} CourseLevel;

class Course {
public:
    Course();				//default constractor
    ~Course();				//default distractor
    virtual CourseLevel getCourseLevel() const=0;	//returns the level of the course - for status checking
    int getCoursePoints() const;			//return the number of points for the course
    int getParticipants() const;			//returns the number of participants
    void addParticipant();					//change the number of participants - add one
    int getCourseId() const;				//return the course ID
    string getCourseName() const;			//returns the name of the course
    int getCourseLecturerId() const;		//returns the ID of the Lecturer for this Course
    int getCourseSemester() const;			//returns Course Semester
    std::vector<Course *> getRequiredCourses() const;
    void setRequiredCourses(std::vector<Course> req);
    void setCourseName(string name);		//course name setter
    void setCoursePoints(int pts);			//course points setter
    void setCourseSemester(int sem);		//semester of the course setter
    void setCourseLecturerId(int lecturerId);//course lecturer setter
    void setRequiredCourses(std::vector<Course *> requiredCourses);
    void printInfo() const;						//print out course info
private:
    std::vector<Course *> requiredCourses;
    int courseId;					//Course ID
    string courseName;				//Course Name
    int coursePoints;				//Points for the Course 
    int courseSemester;				//from whitch Semester the Course is
    int courseLecturerId;			//ID of the lecturar of this Course
    int participants;				//Number of participants
};

#endif /* defined(__OOP_FinalProject__Course__) */
