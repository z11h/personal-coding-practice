//
//  functions.cpp
//  vacationplanninghw
//
//  Created by Zakaria Ridouh on 10/2/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#include "functions.h"
#include <fstream>

using namespace std;

int readPrefs(char fileName[], int ngames, int prefs[]) {
    int valid_lines = 0;
        ifstream infs_obj;
        infs_obj.open(fileName);

        if (infs_obj.fail()) {
            return -1;
        }

        if (infs_obj.is_open()) {
            int index = 0;
            int rating = 0;

            for (int i = 0; i < ngames; i++) {
                infs_obj >> index >> rating;
                if (index < ngames && index >= 0) {
                    prefs[index] = rating;
                    valid_lines++;
                }
            }

            if (infs_obj.eof()) {
                infs_obj.close();
            }
        }


    return valid_lines;
}

int readPlan(char fileName[], int ngames, int plan[]) {

        ifstream infs_obj1;
        infs_obj1.open(fileName);

        if (infs_obj1.fail()) {
            return -1;
        }

        if (infs_obj1.is_open()) {
            int day = 1;
            int game_id = 0;

            for (int i = 0; i < 365; i++) {
                infs_obj1 >> day >> game_id;
                if (day < ngames && day >= 0) {
                    plan[day] = game_id;
                }
            }

//            if (infs_obj1.eof()) {
//                infs_obj1.close();
//            }
        }

    return 0;
}

int computeFunLevel (int start, int duration, int gamePrefs[], int ngames, int plan[]) {
//    if (duration > 365 - start) {
//        return -1;
//    }

    int sum = 0;
    for (int i = 0; i < duration; i++) {
        int plan_val = plan[start + i];
        sum += gamePrefs[plan_val];
    }

    return sum;
}

int findBestVacation(int duration,  int gamePrefs[], int ngames, int plan[]) {
    int max_fun = -1;
    int start_max_fun = 0;


    for (int i = 1; i <= 365 - duration; i++) {
        if (computeFunLevel(i, duration, gamePrefs, ngames, plan) > max_fun) {
            max_fun = computeFunLevel(i, duration, gamePrefs, ngames, plan);
            start_max_fun = i;
        }
    }

    return start_max_fun;
}
