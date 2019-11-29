#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(string student_id, string name) : id(student_id), name(name) {}

string Student::get_id() {
	return this->id;
}

string Student::get_name() {
	return this->name;
}

void Student::addCourse(string course_id) {
	course_ids.push_back(course_id);
}

void Student::listCourses() {
	if (this->course_ids.empty()) {
		cout << "No Courses" << endl;
        return;
	}
    cout << "Courses for " << this->get_id() << endl;
    for (string cid : this->course_ids) {
        cout << cid << endl;
    }
}
