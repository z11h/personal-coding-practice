#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime): id(id), title(title), startTime(startTime), endTime(endTime) {}

std::string Course::getID()
{
	return this->id;
}

std::string Course::getTitle()
{
	return this->title;
}

Date Course::getStartTime()
{
	return this->startTime;
}

Date Course::getEndTime()
{
	return this->endTime;

}

void Course::addAttendanceRecord(AttendanceRecord ar) {
    if ((this->getStartTime() <= ar.getDate()) && (ar.getDate() <= this->getEndTime())) {
        this->attendanceRecords.push_back(ar);
    } else {
        cout << "did not save this record." << endl;
    }
}

void Course::outputAttendance() {
//	if (this->attendanceRecords.empty()) {
//		cout << "No Records" << endl;
//		return;
//	}

	for (AttendanceRecord a : this->attendanceRecords) {
		Date curr_date_obj = a.getDate();

        string __time_hr = ((curr_date_obj.getHour()) < 10) ? ("0" + to_string(curr_date_obj.getHour())) : to_string(curr_date_obj.getHour());

        string __time_min = ((curr_date_obj.getMin()) < 10) ? ("0" + to_string(curr_date_obj.getMin())) : to_string(curr_date_obj.getMin());

        string __time_sec = ((curr_date_obj.getSec()) < 10) ? ("0" + to_string(curr_date_obj.getSec())) : to_string(curr_date_obj.getSec());

		cout << curr_date_obj.getMonth() << "/" << curr_date_obj.getDay() << "/" << curr_date_obj.getYear() << " " << __time_hr << ":" << __time_min << ":" << __time_sec << "," << a.getCourseID() << "," << a.getStudentID() << endl;
	}
}

void Course::outputAttendance(std::string student_id) {
	if (this->attendanceRecords.empty()) {
		cout << "No Records" << endl;
		return;
	}

	for (AttendanceRecord att : this->attendanceRecords) {
		if (att.getStudentID() == student_id) {
			Date curr_date_obj = att.getDate();

            string __time_hr = ((curr_date_obj.getHour()) < 10) ? ("0" + to_string(curr_date_obj.getHour())) : to_string(curr_date_obj.getHour());

            string __time_min = ((curr_date_obj.getMin()) < 10) ? ("0" + to_string(curr_date_obj.getMin())) : to_string(curr_date_obj.getMin());

            string __time_sec = ((curr_date_obj.getSec()) < 10) ? ("0" + to_string(curr_date_obj.getSec())) : to_string(curr_date_obj.getSec());

			cout << curr_date_obj.getMonth() << "/" << curr_date_obj.getDay() << "/" << curr_date_obj.getYear() << " " << __time_hr << ":" << __time_min << ":" << __time_sec << "," << att.getCourseID() << "," << att.getStudentID() << endl;
		}
	}

}

