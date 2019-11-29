//
//  StackDouble.h
//  stacklab
//
//  Created by Zakaria Ridouh on 11/6/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#ifndef StackDouble_h
#define StackDouble_h

#include <stdio.h>

// define the Stack type
// a new stack is initially empty and has capacity 1
class StackDouble {
    double* A; // array for storage
    int capacity;       // capacity of A
    int length;      // number of elements in A

public:
    StackDouble(); // constructor
    ~StackDouble(); // destructor
    // add element to the top of Stack s
    // if Stack s is full, resize the underlying array
    void push(double element);
    // remove and return the element on top of Stack s
    // if Stack s is empty, return NAN
    double pop();
    // OPTIONAL
    // return but do not remove the element on top of Stack s
    double peek();
};

#endif /* StackDouble_hpp */
