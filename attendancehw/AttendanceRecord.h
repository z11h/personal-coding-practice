#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <string>
#include "Date.h"

using namespace std;

class AttendanceRecord {
public:
	AttendanceRecord(std::string course_id, std::string student_id, Date time);
	string getCourseID();
	string getStudentID();
	Date getDate();

private:
	string course_id;
	string student_id;
	Date time;
};

#endif
