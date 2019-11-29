//
//  provided.cpp
//  vacationplanninghw
//
//  Created by Zakaria Ridouh on 10/2/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "provided.h"

using std::ifstream;

/***************************************************************************
 *
 * This provided code uses C-style strings.
 * Later this semester the students will be learning and using C++ Strings
 * instead.
 * It is important to know about C-style strings because they are used
 * in a lot of code. Unless you have a specific, compelling reason to use C-style
 * strings, once you learn C++ Strings, use std::string (defined in the <string> header) instead.
 * std::string is easier, safer, and more flexible.
 *
 ***************************************************************************
 */


/*  Function readGameTitles
 *  fileName: c-style String, i.e., array of chars ended by â€˜\0
 *  ngames: number of games cousins are bringing to the house
 *  gameTitles: 2d-array where row i stores the title for game i
 *  Return value: -1 if error opening the file, otherwise 0.
 */

int readGameTitles (char fileName[], int ngames, char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE]) {
    ifstream fin;
    fin.open(fileName);
    if (!fin) { // error in opening the file
        return -1;
    }
    
    for (int i = 0; i < ngames; i++) {
        strcpy(gameTitles[i], "Unknown Title");
    }
    
    int gameid;
    char title[MAX_TITLE_SIZE];
    while (!fin.eof()) { // while not at the end of the file
        fin >> gameid;
        if (fin.good()) { // no error reading integer game
            // read title as the rest of the line
            if (gameid >= 0 && gameid < MAX_NB_GAMES) {
                // valid game
                // consume space; input is guaranteed to have only space before title
                char space;
                fin >> std::noskipws >> space;
                fin.getline(gameTitles[gameid], MAX_TITLE_SIZE);
            } else {
                // ignoring invalid gameid, just consume title
                fin.getline(title, MAX_TITLE_SIZE);
            }
        } else {
            // read the rest of the line and ignore it
            fin.clear();
            fin.getline(title, MAX_TITLE_SIZE);
        }
    }
    
    return 0;
}


/*  Function printGamesPlayedInVacation
 *  start:  first day of the vacation (1 <= start < 365)
 *  duration: number of vacation days
 *  plan: array with 366 positions with the sequence of games
 *        to be played over the year. In other words,
 *        plan[k] indicates the game planned for day k (1 <= k <= 365)
 *  gameTitles: array with game titles
 *  ngames: number of games
 *  Return value: none.
 */

void printGamesPlayedInVacation(int start, int duration, int plan[],
                                char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE],
                                int ngames) {
    bool title_included[MAX_NB_GAMES];
    for (int i = 0; i < ngames; i++) {
        title_included[i] = false;
    }
    int gameid;
    for (int i = start; i < start + duration && i <= 365; i++) {
        gameid = plan[i];
        if (!title_included[gameid]) {
            std::cout << gameTitles[gameid] << std::endl;
            title_included[gameid] = true;
        }
    }
}


