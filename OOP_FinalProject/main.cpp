//
//  main.cpp
//  OOP_FinalProject
//
//  Created by Daniel Gorlovetsky on 12/8/13.
//  Copyright (c) 2013 Daniel Gorlovetsky. All rights reserved.
//

#include <iostream>
#include "BScStudent.h"
#include "MScStudent.h"
#include "Lecturer.h"
#include "CampusWorker.h"
#include "StudentsDb.h"
#include "CoursesDb.h"
#include "UnauthorizedException.h"
#include "BScCourse.h"
#include "MScCourse.h"
#include "BScAdvancedCourse.h"
#include "UndergradStudent.h"
#include <ctime>

static BScStudent bscStudent;
static MScStudent mscStudent;
static Lecturer lecturer;
static CampusWorker campusWorker;

SystemUser* getLoggedInUser() {
	int index;
	cout << "Who you want to login as?\n 1. BSc Student\n 2. MSc Student 3. Lecturer\n 4. Worker\n";
	cin >> index;
	if (index == 1) {
		return &bscStudent;
	}
	else if (index == 2) {
		return &mscStudent;
	}
	else if (index == 2) {
		return &lecturer;
	}
	return &campusWorker;
}

void chooseBScUserAction() {

}

void chooseMScUserAction() {

}

void chooseLecturerUserAction() {

}

void chooseWorkerUserAction() {
	cout << "Choose an action: \n";

	cout << "1. Get information about a specific course\n";
	cout << "2. Get information about a specific student\n";
	cout << "3. Update student's details\n";
	cout << "4. Enroll new student\n";
	cout << "5. Enroll an existing student to a course\n";
	cout << "6. Open a new course\n";
	cout << "7. Update course\n";
	cout << "8. Update student's final grade\n";
	cout << "9. Update student's course status\n";
	cout << "0. Logout\n";

	int index;
	cin >> index;

	try {
		switch (index) {
		case 1: //get specific course
		{
				  int courseId;
				  cout << "Enter the course ID you'd like to get the information for\n";
				  cin >> courseId;
				  campusWorker.printCourseInfo(courseId);
				  break;
		}
		case 2: //get specific user
		{
				  int studentId;
				  cout << "Enter the student ID you'd like to get the information for\n";
				  cin >> studentId;
				  campusWorker.printStudentInfo(studentId);
				  break;
		}
		case 3://update student details
		{
				  int studentId;
				  string studentName;
				  int studentAge;
				  int studentStatus;
				  
				  cout << "Enter the student ID you'd like to get the information for\n";
				  cin >> studentId;

				  cout << "Enter a new name for the student\n";
				  cin >> studentName;

				  StudentsDb *db = StudentsDb::getInstance();
				  Student *st = db->getStudent(studentId);
				  st->setName(studentName);

				  campusWorker.updateStudent(st);
				  break;
		}
		case 4://new student
		{
            string studentName;
            time_t studentBirthDate;
            int studentStatus;

            cout << "Enter the new status: 0:FAILED, 1:ENROLLED, 2:PASSED\n";
            cin >> studentStatus;

            //TODO: ADD BIRTHDATE
            cout << "Enter a new name for the student\n";
            cin >> studentName;
            
            Student *student;
            
            if (studentStatus == 0) {
                BScStudent bscStudent;
                student = &bscStudent;
			}
            else if (studentStatus == 1) {
                MScStudent mscStudent;
                student = &mscStudent;
            }
            else {
                UndergradStudent enrolledStudent;
                student = &enrolledStudent;
            }
            
            campusWorker.enrollNewStudent(student);
			break;
		}
            case 5: {//existing user
			int courseId;
			int studentId;

			cout << "Enter the student Id\n";
			cin >> studentId;

			cout << "Enter the course Id\n";
			cin >> courseId;

			campusWorker.enroll(studentId, courseId);
			break;
		case 6: //new course
			//TODO: IMPLEMENT THIS
			string courseName;
			int coursePoints;
			int courseLevel;

			cout << "Enter the course level: 0:Basic 1:Intermediate 2:MSc\n";
			cin >> courseLevel;

			cout << "Enter the course name\n";
			cin >> courseName;

			cout << "Enter the course points\n";
			cin >> coursePoints;
                Course *course;
			if (courseLevel == 0) {
                BScCourse bscCourse;
                course = &bscCourse;
			}
            else if (courseLevel == 1) {
                BScAdvancedCourse bscAdvancedCourse;
                course = &bscAdvancedCourse;
            }
            else {
                MScCourse mscCourse;
                course = &mscCourse;
            }
                
            course->setCourseName(courseName);
            course->setCoursePoints(coursePoints);
			campusWorker.openNewCourse(course);
			break;
        }
		case 7: //update course
		{
                int courseId;
                string courseName;
                int coursePoints;

                cout << "Enter the course Id\n";
                cin >> courseId;

                cout << "Enter the course name\n";
                cin >> courseName;

                cout << "Enter the course points\n";
                cin >> coursePoints;

                CoursesDb *db = CoursesDb::getInstance();
                Course *course = db->getCourse(courseId);
                course->setCourseName(courseName);
                course->setCoursePoints(coursePoints);

              break;
		}
		case 8: //student final grade
		{
					int studentId;
					int courseId;
					float finalGrade;

					cout << "Enter the student Id\n";
					cin >> studentId;

					cout << "Enter the course Id\n";
					cin >> courseId;

					cout << "Enter the final grade\n";
					cin >> finalGrade;

					campusWorker.updateStudentFinalGrade(studentId, courseId, finalGrade);

				  break;
		}
		case 9: //student final status
		{
					int studentId;
					int courseId;
					int status;

					cout << "Enter the student Id\n";
					cin >> studentId;

					cout << "Enter the course Id\n";
					cin >> courseId;

					cout << "Enter the new status: 0:FAILED, 1:ENROLLED, 2:PASSED\n";
					cin >> status;

					campusWorker.updateStudentCourseStatus(studentId, courseId, (CourseStatus)status);
					break;
		}
		case 0: //logout
			getLoggedInUser();
			break;
		}
	}
	catch (UnauthorizedException &ex) {
	}
}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
