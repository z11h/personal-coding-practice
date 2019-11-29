//
//  tweets.cpp
//  twitteranalytics
//
//  Created by Zakaria Ridouh on 10/28/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "functions.h"

void printLine(string msg) {
    cout << msg << endl;
}

void printMenu() {
    cout << endl;
    printLine("Welcome to Aggieland Twitter Feeds Stats");
    printLine("The options are:");
    printLine("1. load tweet data file and update stats");
    printLine("2. show overall stats (number of tweets, retweets, and hashtags)");
    printLine("3. show most popular hashtags");
    printLine("9. quit");
    cout << "--------> Enter your option: ";
}

int getOption() {
    int option;

    cin >> option;

    if (cin.fail()) {

        cin.clear();
        cin.ignore(256, '\n');

        return -1;
    } else {
        cin.ignore(256, '\n');
    }
    return option;
}

int main() {
    OrderedHashtagList myhashlist;
    int curr_op;
    int total_tweets = 0;
    int total_retweets = 0;

    printMenu();
    curr_op = getOption();

    while (curr_op != 9) {
        if ((curr_op != 1) && (curr_op != 2) && (curr_op != 3) && (curr_op != 9)) { // validate input
            printLine("Invalid option");
        } else { // valid option
            switch (curr_op) {
                case 1:
                {
                    string file_name;
                    cout << "Enter filename: ";

                    cin >> file_name;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        break;
                    }
                    ifstream myfile (file_name);
                    if (myfile.is_open()) { // file has been opened sucessfully
                        string my_line;
                        while (getline(myfile, my_line)) {
                            // each line is a tweet, process one tweet at a time
                            if (my_line.size() > 0) {
                                total_tweets++; // not an empty line
                                bool isrt;
                                int temp_htags;
                                string* temp_htarr; // pointer to arr of hashtags that will be allocated on the heap inside readTweet

                                readTweet(my_line, isrt, temp_htags, temp_htarr);

                                // take arr of strings and construct Hashtag objects from each element, then pushing them into the OrderedHashTagList
                                for (int i = 0; i < temp_htags; i++) {
                                    insertHashtag(temp_htarr[i], myhashlist);
                                }

                                // incremenet total retweets of file with if the tweet is a retweet or not
                                if (isrt) total_retweets++;

                                if (temp_htags > 0) {
                                    // deallocate temp_htarr;
                                    delete [] temp_htarr;
                                    temp_htarr = nullptr;
                                } else {
                                    temp_htarr = nullptr;
                                }


                                if (myhashlist.size > 0) {
                                    // sort our orderedhashlist, now that we've inserted all possible hashtag objects
                                    htBubbleSort(myhashlist);
                                }
                            }
                        }
                        myfile.close();
                    } else {
                        printLine("File can't be open.");
                        break;
                    }
                }
                    break;
                case 2:
                    cout << "Tweets: " << total_tweets << ", Retweets: " << total_retweets << ", Hashtags: " << myhashlist.size << endl;
                    break;
                case 3:
                    showMostPopularHashtags(myhashlist, 10);
                    break;
                default:
                    break;
            }
        }
        // print menu and get selection
        printMenu();
        curr_op = getOption();
    }

    return 0;
}


