//
//  main.cpp
//  vacationplanninghw
//
//  Created by Zakaria Ridouh on 10/2/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#include <iostream>
#include "functions.h"
#include "provided.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int ngames = 0;
    int duration = 0;
    char game_titles_fname[256];
    char game_preferences_fname[256];
    char year_plan_fname[256];
    
    cout << "Please enter ngames and duration: ";
    cin >> ngames >> duration;
    if (ngames > 200 || ngames <= 0){
        cout << "Invalid input." << endl;
        return 0;
    }
    if (duration > 365 || duration <= 0){
        cout << "Invalid input." << endl;
        return 0;
    }
    
    cout << "Please enter name of file with titles: ";
    cin >> game_titles_fname;
    cout << "Please enter name of file with preferences: ";
    cin >> game_preferences_fname;
    cout << "Please enter name of file with plan: ";
    cin >> year_plan_fname;

    static int *gameprefs = new int[MAX_NB_GAMES];
    readPrefs(game_preferences_fname, ngames, gameprefs);

    static int *plan = new int[366];
    readPlan(year_plan_fname, ngames, plan);

    static char game_titles[MAX_NB_GAMES][MAX_TITLE_SIZE];
    readGameTitles(game_titles_fname, ngames, game_titles);

    if (readPlan(year_plan_fname, ngames, plan) == -1) {
        cout << "Invalid file." << endl;
        return 0;
    } else if (readPrefs(game_preferences_fname, ngames, gameprefs) == -1) {
        cout << "Invalid file." << endl;
        return 0;
    } else if (readGameTitles(game_titles_fname, ngames, game_titles) == -1) {
        cout << "Invalid file." << endl;
        return 0;
    }

    int best_vacation = findBestVacation(duration, gameprefs, ngames, plan);
    cout << "Best start day is " << best_vacation << endl;

    cout << "Games to be played: ";
    printGamesPlayedInVacation(best_vacation, duration, plan, game_titles, ngames);
    
    return 0;
}
