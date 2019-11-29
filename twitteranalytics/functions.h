#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>

/* struct that keeps track of the statistics for a single
 * hashtag.
 */
struct Hashtag {
    std::string name;
    long counter = 0;     // total number of occurrences
};

/* struct that maintains a list of hashtags ordered in
 * decreasing order of popularity, i.e., in the
 * first position of the array we maintain the most popular hashtag.
 */
struct OrderedHashtagList {
    int capacity = 1;
    
    /* how many positions have been allocated
     * for the array 'list'. The 'list' array may be
     * resized during
     * execution, possibly growing or shrinking
     */

    Hashtag* list = new Hashtag[capacity];
    /* array of Hashtag elements
     * that must be kept sorted by number
     * of occurrences of the hashtag.
     */

    int size = 0;
    /* size of the array 'list', i.e., how many positions in
     * the array are currently occupied
     */
};

void htBubbleSort(OrderedHashtagList& orderedhtlist);

void readTweet(std::string line, bool& isRetweet,
               int& nb_htags, std::string*& array_of_htags);

bool insertHashtag(std::string ht, OrderedHashtagList& hashlist);

void showMostPopularHashtags(OrderedHashtagList hashlist, int k);

#endif //#ifndef _FUNCTIONS_H
