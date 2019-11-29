//
//  Stack.hpp
//  stacklab
//
//  Created by Zakaria Ridouh on 11/4/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//

#ifndef STACK_H
#define STACK_H
#include <cstdlib>

template <class T>
class Stack {
    T* stack_ptr; // array for storage
    int capacity; // capacity of A
    int length; // number of elements in A
public:
    Stack() {
        stack_ptr = new T[1];
        this->capacity = 1;
        this->length = 0; // empty at declaration
    }

    ~Stack() {
        delete [] stack_ptr;
    }

    void push(T element) {
        if (length == capacity) { // stack is full
            int new_len = 2 * capacity;
            T* newArr = new T[new_len];

            for (int i  = 0; i < capacity; i++) {
                newArr[i] = stack_ptr[i];
            }

            capacity = new_len;
            delete [] stack_ptr;
            stack_ptr = newArr;

            // increment length and push element to top of array
            length++;
            stack_ptr[length-1] = element;
        } else { // stack still has space
            length++;
            stack_ptr[length-1] = element;
        }
    }

    bool isEmpty() {
        return (this->length == 0) ? true : false;
    }

    T pop() {
        T last_val = stack_ptr[length-1];
        --length;
        return last_val;
    }

    T peek() {
        if (isEmpty()) {
            exit(0);
        }
        return stack_ptr[length-1];
    }
};

#endif
