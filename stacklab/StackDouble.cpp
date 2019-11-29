//
//  StackDouble.cpp
//  stacklab
//
//  Created by Zakaria Ridouh on 11/6/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//


#include <iostream>
#include <cmath>
#include <string>
#include "StackDouble.h"

StackDouble::StackDouble() {
    A = new double[1];
    this->capacity = 1;
    this->length = 0; // empty at declaration
}

StackDouble::~StackDouble() {
    delete [] A;
}

// add element to the top of Stack s
// if Stack s is full, resize the underlying array
void StackDouble::push(double element) {
    if (length == capacity) { // stack is full
        int new_len = 2 * capacity;
        double* newArr = new double[new_len];

        for (int i  = 0; i < capacity; i++) {
            newArr[i] = A[i];
        }

        capacity = new_len;
        delete [] A;
        A = newArr;

        // increment length and push element to top of array
        length++;
        A[length-1] = element;
    } else { // stack still has space
        length++;
        A[length-1] = element;
    }
}

// remove and return the element on top of Stack s
// if Stack s is empty, return NAN
double StackDouble::pop() {
    if (length == 0) {
        return std::nan("");
    } else {
        double last_val = A[length-1];
        length--;
        A[length] = 0; // delete value
        return last_val;
    }
}

// OPTIONAL
// return but do not remove the element on top of Stack s
double StackDouble::peek() {
    return A[length-1];
}
