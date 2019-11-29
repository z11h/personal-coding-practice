//
//  functions.h
//  vacationplanninghw
//
//  Created by Zakaria Ridouh on 10/2/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#ifndef functions_h
#define functions_h

/*  Function readPrefs
 *  fileName: c-style String, i.e., array of chars ended by ‘\0’
 *  ngames:   number of games
 *  prefs:    array of integers created with MAX_NB_GAMES=200
 *            positions
 *  Return value: described below
 */
int readPrefs(char fileName[], int ngames, int prefs[]);

/*  Function readPlan
 *  fileName: c-style String, i.e., array of chars ended by ‘\0’
 *  plan:    array of integers created with 365 positions
 *  Return value: as described below
 */
int readPlan(char fileName[], int ngames, int plan[]);

/*  Function computeFunLevel
 *  start:  first day of the vacation (1 <= start < 365)
 *  duration: number of vacation days (duration >= 1)
 *  gamePrefs: gamePrefs[k] indicates the rating specified for game k
 *  ngames: number of elements in the array gamePrefs
 *  plan: array with 366 positions with the sequence of games
 *        to be played over the year. In other words,
 *        plan[k] indicates the game planned for day k (1 <= k <= 365)
 *  Return value: Explained below.
 */
int computeFunLevel (int start, int duration, int gamePrefs[], int ngames, int plan[]);

/*  Function findBestVacation
 *  duration: number of vacation days
 *  gamePrefs: gamePrefs[k] indicates the rate specified for game k
 *  ngames: number of elements in the array gamePrefs
 *  plan: array with 366 positions with the sequence of games
 *        to be played over the year. In other words,
 *        plan[k] indicates the game planned for day k (1 <= k <= 365)
 *  Return value: Explained below.
 */
int findBestVacation (int duration,  int gamePrefs[], int ngames, int plan[]);

#endif /* functions_h */

