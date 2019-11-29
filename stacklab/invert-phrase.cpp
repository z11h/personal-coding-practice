#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<string> s;
    string word;
    // fill up our stack
    while(cin >> word) {
        // remove the period if we are at the last word
        if (word.back() == '.') {
            word.pop_back();
        }
        s.push(word);
    }

    // empty out the stack top down
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    s.~Stack(); // this calls the destructor

    return 0;
}
