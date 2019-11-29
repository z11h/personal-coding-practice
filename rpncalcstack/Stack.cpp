#include <iostream>
#include <cmath>
#include <string>
#include "Stack.h"

using std::nan;
// add element to the top of Stack s
// if Stack s is full, resize the underlying array
void push(Stack& s, double element) {
    if (s.length == s.capacity) { // stack is full
        int new_len = 2 * s.capacity;
        double* newArr = new double[new_len];

        for (int i  = 0; i < s.capacity; i++) {
            newArr[i] = s.A[i];
        }

        s.capacity = new_len;
        delete [] s.A;
        s.A = newArr;
        // increment length and push element to top of array
        s.length++;
        s.A[s.length-1] = element;
    } else { // stack still has space
        s.length++;
        s.A[s.length-1] = element;
    }

}

// remove and return the element on top of Stack s
// if Stack s is empty, return NAN
double pop(Stack& s) {
    if (s.length == 0) {
        return NAN;
    } else {
        double last_val = s.A[s.length-1];
        s.length--;
        s.A[s.length] = 0; // delete value
        return last_val;
    }
}
// OPTIONAL
// return but do not remove the element on top of Stack s
double peek(const Stack s) {
    return s.A[s.length-1];
}


