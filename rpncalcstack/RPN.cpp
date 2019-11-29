#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stod;
using std::isdigit;

int main() {
    Stack rpn_stack;
    string inp = "";
    bool is_valid = true;

    cin >> inp;
    while (inp != "="){
        // handle case where we have operand
        if (isdigit(inp.at(0)) || inp.at(0) == '.') {
            push(rpn_stack, stod(inp));
        } else {
            // handle case where we have operator
            double right = pop(rpn_stack); // second number
            double left = pop(rpn_stack); // first number

            // operate from 1st on second
            if (inp == "+") {
                push(rpn_stack, left + right);
            } else if (inp == "-") {
                push(rpn_stack, left - right);
            } else if (inp == "/") {
                push(rpn_stack, left / right);
            } else if (inp == "*") {
                push(rpn_stack, left * right);
            } else {
                cout << "[ERROR] invalid operator: " << inp << endl;
                is_valid = false;
            }
        }

        // reset inp and read in next operator/operand
        inp = "";
        cin >> inp;
    }

    // we only have one item left on the stack, which is our answer, since we have reached "="
    if (is_valid) {
        cout << pop(rpn_stack) << endl;
    }
    delete[] rpn_stack.A;
    return 0;
}
