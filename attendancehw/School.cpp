#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addCourses(std::string filename) {
	ifstream ifs(filename);

	if (!ifs.is_open()) {
		cout << "Unable to open file: " << filename << endl;
		return;
	}

	while (!ifs.eof()) {
		string line;
		getline(ifs, line);

		istringstream ss(line);

		string courseID;
		getline(ss, courseID, ',');

		string stime_hr, stime_min;
		getline(ss, stime_hr, ':');
		getline(ss, stime_min, ',');

		string etime_hr, etime_min;
		getline(ss, etime_hr, ':');
		getline(ss, etime_min, ',');

		string title;
		getline(ss, title);

		if (!ss.fail()) {

//            for (Course c : this->courses) {// check if course already exists
//                if (c.getID() == courseID) {
//                    continue;
//                }
//            }

            this->courses.push_back(Course(courseID, title, Date(stoi(stime_hr), stoi(stime_min)), Date(stoi(etime_hr), stoi(etime_min))));
		}
	}
}

void School::addStudents(string filename) {
	ifstream ifs(filename);

	if (!ifs.is_open()) {
		cout << "Unable to open file: " << filename << endl;
		return;
	}

	while (!ifs.eof()) {
		string line;
		getline(ifs, line);

		istringstream ss(line);
		string uin;
		getline(ss, uin, ',');

		string name;
		getline(ss, name);

		if (!ss.fail()) {
			this->students.push_back(Student(uin, name));
		}
	}
}

void School::addAttendanceData(std::string filename) {
	ifstream ifs(filename);

	if (!ifs.is_open()) {
		cout << "Unable to open file: " << filename << endl;
		return;
	}

	while (!ifs.eof()) {
		string line;
		getline(ifs, line);

		istringstream ss(line);

		string dyear, dmonth, dday, dhour, dmin, dsec;

		getline(ss, dyear, '-');
		getline(ss, dmonth, '-');
		getline(ss, dday, ' ');

		getline(ss, dhour, ':');
		getline(ss, dmin, ':');
		getline(ss, dsec, ',');

		string course_id;
		getline(ss, course_id, ',');

		string student_id;
		getline(ss, student_id);

		if (!ss.fail()) {
			for (Course c : this -> courses) {
				if (c.getID() == course_id) {
                    AttendanceRecord a(course_id, student_id, Date(stoi(dyear), stoi(dmonth), stoi(dday), stoi(dhour), stoi(dmin), stoi(dsec)));
            c.addAttendanceRecord(a);
				}
			}
			
		}
	}

//    string line;
//    getline(ifs, line);
//
//    istringstream ss(line);
//
//    string date;
//    getline(ss, date, ',');
//
//    stringstream strs(date);
//    string day;
//    strs >> day;
//
//    string time;
//    strs >> time;
//
//    istringstream dayss(day);
//    string year;
//    getline(dayss, year, '-');
//    string month;
//    getline(dayss, month, '-');
//    string _day;
//    getline(dayss, _day, ' ');
//
//    istringstream timess(time);
//    string hour;
//    getline(timess, hour, ':');
//    string minute;
//    getline(timess, minute, ':');
//    string second;
//    getline(timess, second);
//
//
//    string course_id;
//    getline(ss, course_id, ',');
//
//    string studentid;
//    getline(ss, studentid);
    //        if (!ss.fail()) {
    //
    //            Date my_date(stoi(year), stoi(month), stoi(_day), stoi(hour), stoi(minute), stoi(second));
    //            AttendanceRecord ar(course_id, studentid, my_date);
    //
    //            for(size_t i = 0; i < courses.size(); ++i)
    //            {
    //                if(ar.getCourseID() == courses.at(i).getID())
    //                {
    //                    courses.at(i).addAttendanceRecord(ar);
    //
    //                }
    //            }
    //        }
}

void School::listCourses()
{
	// check if we have courses 
	if (this->courses.empty()) { // no courses
		cout << "No Courses" << endl;
		return;
	}

	for (Course c : this->courses) {

        string __time_start_hr = (c.getStartTime().getHour() < 10) ? ("0" + to_string(c.getStartTime().getHour())) : to_string(c.getStartTime().getHour());

        string __time_start_min = (c.getStartTime().getMin() < 10) ? ("0" + to_string(c.getStartTime().getMin())) : to_string(c.getStartTime().getMin());

        string __time_end_hr = (c.getEndTime().getHour() < 10) ? ("0" + to_string(c.getEndTime().getHour())) : to_string(c.getEndTime().getHour());

        string __time_end_min = (c.getEndTime().getMin() < 10) ? ("0" +to_string(c.getEndTime().getMin())) : to_string(c.getEndTime().getMin());

        cout << c.getID() << "," << __time_start_hr << ":" << __time_start_min << "," << __time_end_hr << ":" << __time_end_min << "," << c.getTitle() << endl;

    }
}

void School::listStudents() {
	// check if we have students
	if (this->students.empty()) { // no students
		cout << "No Students" << endl;
		return;
	}

	 // we have students.size() students, print out names using getter functions
	for (Student s : this->students) {
		cout << s.get_id() << "," << s.get_name() << endl;
	}
}

void School::outputCourseAttendance(std::string course_id) {
//    for (Course c : this->courses) {
//        if (c.getID() == course_id) {
//            continue;
//        }
//        cout << "No Records" << endl;
//        return;
//    }

    for (Course c : this->courses) {
        if (c.getID() == course_id) {
            c.outputAttendance();
            return;
        }
    }
    cout << "No Records" << endl;
}

void School::outputStudentAttendance(std::string student_id, std::string course_id)
{
//    for (Course c : this->courses) {
//        if (c.getID() == course_id) {
//            continue;
//        }
//        cout << "No Records" << endl;
//        return;
//    }
//
//    for (Student s : this->students) {
//        if (s.get_id() == student_id) {
//            continue;
//        }
//        cout << "No Records" << endl;
//        return;
//    }

    for (Course c : this->courses) {
        if (c.getID() == course_id) { // the course we want to output
            c.outputAttendance(student_id);
            return;
        }
    }
    cout << "No Records" << endl;
//	if (this->students.empty() || this->courses.empty()) { // no students
//		cout << "No Records" << endl;
//		return;
//    } else {
//        for (Course c : this->courses) {
//            if (c.getID() == course_id) {
//                for (Student s : this->students) {
//                    if (s.get_id() == student_id) {
//                    c.outputAttendance(student_id);
//                    }
//                }
//            }
//        }
//    }
}

