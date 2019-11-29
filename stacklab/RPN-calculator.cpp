#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<double> s;
    while (true) {
        // read input
        string token;
        cin >> token;
        if (isdigit(token[0]) || token[0] == '.') {
            double d = stod(token);
            // push operand onto stack
            s.push(d);
        } else {
            char c = token[0];
            if (c == '=') {
                break;
            }
            double right = s.pop();
            double left = s.pop();
            switch (c) {
                case '+':
                    s.push(left + right);
                    break;
                case '-':
                    s.push(left - right);
                    break;
                case '*':
                    s.push(left * right);
                    break;
                case '/':
                    s.push(left / right);
                    break;
                default:
                    cout << "[ERROR] invalid operator: " << c << endl;
                    return 1;
            }
        }
    }
    // pop result from stack
    cout << s.pop() << endl;
    
    return 0;
}
