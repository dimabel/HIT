//
//  CampusWorker.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include "pch.h"
#include "CampusWorker.h"
#include "StudentsDb.h"
#include "CoursesDb.h"
#include <string>
#include "CourseGradeMap.h"

#define MAX_COURSE_PARTICIPANTS 150 // the maximum amount of PARTICIPANTS in a course

void CampusWorker::printStudentInfo(const int studentId) const {
	//print out a students info
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    st->printInfo();
}

void CampusWorker::printCourseInfo(const int courseId) const {
	//print out a Courses info
    CoursesDb *db = CoursesDb::getInstance();
    Course *course = db->getCourse(courseId);
    course->printInfo();
}

void CampusWorker::updateStudent(Student student) {
	////allows the worker to update students info
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(student.getId());
    st->setBirthDate(student.getBirthDate());
    st->setName(student.getName());
}

void CampusWorker::enroll(int studentId, int courseId) {
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    
    CoursesDb *courseDb = CoursesDb::getInstance();
    Course *course = courseDb->getCourse(courseId);

    bool isAllowedToStudy = true;
    
    if (st->getStudentStatus() != UNDERGRAD) {
        for (auto it = begin (course->getRequiredCourses()); it != end (course->getRequiredCourses()); ++it) {
            bool didStudy = false;
            for (auto it2 = begin (st->getCourses()); it2 != end (st->getCourses()); ++it2) {
                Course *course = *it;
                if (it2->getCourse()->getCourseId() == course->getCourseId()) {
                    didStudy = true;
                }
            }
            if (!didStudy) {
                isAllowedToStudy = false;
            }
        }
    }
    
    if (course->getParticipants() > MAX_COURSE_PARTICIPANTS) {
        isAllowedToStudy = false;
    }

    if (isAllowedToStudy) {
        course->addParticipant();
        std::vector<CourseGradeMap>::iterator it;
        it = st->getCourses().begin();
        it = st->getCourses().insert(it, *new CourseGradeMap(course));
    }
    else {
        //TODO:throw
    }
}

void CampusWorker::printReport(int studentId) const {
	//prints students report
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    cout << "Student #" << studentId << "'s name is " << st->getName() << " and he is " << st->getStudentAge() << " years old\n";
    for (auto it = begin (st->getCourses()); it != end (st->getCourses()); ++it) {
        cout << "Student studies/has studied course #" << it->getCourse()->getCourseName() << " of level " << ((it->getCourse()->getCourseLevel() == BASIC) ? "basic" : (INTERMEDIATE ? "intermediate" : "MSC")) << " with grade " << it->getCourseGrade();
    }
}

void CampusWorker::openNewCourse(Course course) {
	//Createing a new Course
    CoursesDb *db = CoursesDb::getInstance();
    std::vector<Course *> courses = db->getCourses();
	std::vector<Course *>::iterator it;
    it = courses.begin();
    it = courses.insert(it, &course);
}

void CampusWorker::updateCourse(Course aCourse) {
	//updateing an existing Course
    CoursesDb *db = CoursesDb::getInstance();
    Course *course = db->getCourse(aCourse.getCourseId());

    course->setCourseName(aCourse.getCourseName());
    course->setCoursePoints(aCourse.getCoursePoints());
    course->setCourseSemester(aCourse.getCourseSemester());
    course->setCourseLecturerId(aCourse.getCourseLecturerId());
    course->setRequiredCourses(aCourse.getRequiredCourses());
}

void CampusWorker::updateStudentFinalGrade(int studentId, int courseId, int finalGrade) {
	//allows the worker to change students grade
    StudentsDb *studentDb = StudentsDb::getInstance();
    Student *st = studentDb->getStudent(studentId);
    
    CourseGradeMap *courseGradeMap = st->getCourse(courseId);
    courseGradeMap->setCourseGrade(finalGrade);
}

void CampusWorker::updateStudentCourseStatus(int studentId, int courseId, CourseStatus courseStatus) {
	//changes a students course status
    StudentsDb *db = StudentsDb::getInstance();
    Student *st = db->getStudent(studentId);
    CourseGradeMap *courseGradeMap = st->getCourse(courseId);
    courseGradeMap->setCourseStatus(courseStatus);
}

CampusWorker::CampusWorker():SystemUser() {		//default constractor
}
CampusWorker::~CampusWorker() {	//default distractor
}