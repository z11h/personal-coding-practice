#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<char> s;
    // read input
    string expression;
    cin >> expression;
    // we ignore anything that is not {}[]()
    int idx = expression.find_first_of("{}[]()");
    while (idx != string::npos) {
	char c = expression[idx];
	switch (c) {
	case '{':
	case '[':
	case '(': {
	    s.push(expression[idx]);
	    break;
	}
	default:
	    // closing elemment
	    if (s.isEmpty()) {
		cout << "It is not balanced." << endl;
		return 0;
	    }
	    char sc = s.pop();
	    if ((c == '}' && sc != '{') ||
		(c == ']' && sc != '[') ||
		(c == ')' && sc != '(')) {
		cout << "It is not balanced." << endl;
		return 0;
	    }
	}
	// all good so far
	idx = expression.find_first_of("{}[]()", idx+1);
    }
    cout << "It is balanced." << endl;
    return 0;
}
