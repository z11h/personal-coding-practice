//
//  provided.h
//  vacationplanninghw
//
//  Created by Zakaria Ridouh on 10/2/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#ifndef provided_h
#define provided_h

const int MAX_NB_GAMES = 200;
const int MAX_TITLE_SIZE = 128;

int readGameTitles(char fileName[], int ngames, char  gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE]);

void printGamesPlayedInVacation(int start, int duration, int plan[], char gameTitles[MAX_NB_GAMES][MAX_TITLE_SIZE], int ngames);

#endif /* provided_h */
