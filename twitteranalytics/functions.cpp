#include <iostream>
#include <string>
using namespace std;

#include "functions.h"

// a rewritten version of bubblesort for hashlist usecase
// TODO: use type template and pass in array of objects, and size of array, not just object.

void htBubbleSort(OrderedHashtagList& orderedhtlist) {
    bool swapped;
    for (int i = 0; i < orderedhtlist.size -1; i++)
    {
        swapped = false;
        for (int j = 0; j < orderedhtlist.size-i-1; j++){
            if (orderedhtlist.list[j].counter < orderedhtlist.list[j+1].counter) {
                // swap the two hashtags
                Hashtag temp_val = orderedhtlist.list[j];
                orderedhtlist.list[j] = orderedhtlist.list[j+1];
                orderedhtlist.list[j+1] = temp_val;

                swapped = true;
            }
        }

        if (!swapped) break; // if nothing gets swapped in the inside loop, we dont need to keep checking
    }
}

int countHashTags(const string& my_str)
{
    int count = 0;
    for (int i = 0; i < my_str.length(); i++) {
        if (my_str[i] == '#') {
            count++;
        }
    }
    return count;
}

bool is_retweet(const string& str) {
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == 'R' && str[i+1] == 'T') return true;
    }
    return false;
}

/* readTweet
 * Parameters:
 *      line: string containing the tweet information received by the function
 *      isRetweet: reference to bool; function will update it with true if retweet
 *      nb_htags: reference to int; function will update with number of hashtags
 *                in the tweet.
 *      array_of_htags: reference to an array of strings; function will allocate
 *                      the array and store the hashtag in it
 * Return value:
 *      none
 * Functionality:
 *     Processes the string in order to find out hashtags and identify if it is Retweet
 */


void readTweet(string line, bool& isRetweet,
               int& nb_htags, string*& array_of_htags) {

    isRetweet = is_retweet(line);
    nb_htags = countHashTags(line);

    if (nb_htags > 0) {
        array_of_htags = new string[nb_htags];
        int curr_pos = 0;
        // parse then fill up arr with string of hashtags
        for (int i = 0; i < line.size()-1; i++) {
            if (line[i] == '#') { // found a hashtag, get each alphanumeric character and push it into string, then push into array of hashtags
                int j = i+1;
                string temp_str;
                while(isalnum(line[j])) {
                    string s(1, line[j]);
                    temp_str.append(s);
                    j++;
                }

                array_of_htags[curr_pos] = temp_str;
                curr_pos++;
            }
        }
    }

}

/* insertHashtag
 * Parameters:
 *      ht: string
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      true if insertion succeeds, false if memory allocation
 *      fails.
 * Functionality:
 *      See prompt for specification and examples.
 */

bool insertHashtag(string ht, OrderedHashtagList& hashlist) {

    string my_ht_name = ht;

    // convert to lower
    for (int i = 0; i < ht.length(); i++) {
        my_ht_name[i] = tolower(ht[i]);
    }

    // check if hashtag obj already exists in the list, if so just increment count and sort
    for (int i = 0; i < hashlist.size; i++) {
        if (hashlist.list[i].name == my_ht_name) { // if we already have the hashtag in the list, just increment count and return true
            hashlist.list[i].counter++;
            return true; // successful insertion
        }
    }

    // hashtag does not already exist in the orderedhashtaglist, add it in at the end disregarding count, as we are sorting after this function

    // if our OrderedHashtagList is fully loaded, double capacity
    if (hashlist.capacity == hashlist.size) {
        hashlist.capacity *= 2; // double capacity
        Hashtag* new_list = new Hashtag[hashlist.capacity];

        for (int i = 0; i < hashlist.size; i++) { // copy elements over from old hashlist list to new one
            new_list[i] = hashlist.list[i];
        }

        delete [] hashlist.list;
        hashlist.list = new_list;
    }

    // make and insert insert our new Hashtag
    Hashtag temp_h;
    temp_h.name = my_ht_name;
    temp_h.counter = 1;

    hashlist.list[hashlist.size] = temp_h;

    // increment size of hashlist
    hashlist.size++;

    return true;
}

/* showMostPopularHashtags
 * Parameters:
 *      hashlist: reference to OrderedHashtagList struct
 * Return value:
 *      none
 * Functionality:
 *      Prints the k most popular hashtags.
 *      See prompt for formatting details.
 */
void showMostPopularHashtags(OrderedHashtagList hashlist, int k) {
    if (hashlist.size > 0) { // only do something if there actually are hashtag elements
            int max = (k >= hashlist.size) ? hashlist.size : k;

//            if (hashlist.size <= k) {
//                max = hashlist.size;
//            } else {
//                max = k;
//            }

            for (int i = 0; i < max; i++) {
                cout << "Tag #" << hashlist.list[i].name << " - " << hashlist.list[i].counter << " occurrence(s)" << endl;
            }
    } else {
        cout << "No hashtags." << endl;
    }
}


