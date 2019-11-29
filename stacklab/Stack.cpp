//
//  Stack.cpp
//  stacklab
//
//  Created by Zakaria Ridouh on 11/4/19.
//  Copyright © 2019 zakaria ridouh. All rights reserved.
//
#include <cstdlib>
#include "Stack.h"

template <class T>
Stack<T>::Stack() {
    stack_ptr = new T[1];
    this->capacity = 1;
    this->length = 0; // empty at declaration
}

template <class T>
Stack<T>::~Stack(){
    delete [] stack_ptr;
}

template <class T>
void Stack<T>::push(T element) {
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

template <class T>
bool Stack<T>::isEmpty() {
    return (this->length == 0) ? true : false;
}

template <class T>
T Stack<T>::pop() {
        T last_val = stack_ptr[length-1];
        length--;
        stack_ptr[length] = 0; // delete value
        return last_val;
}

template <class T>
T Stack<T>::peek() {
    if (isEmpty()) {
        exit(0);
    }
    return stack_ptr[length-1];
}

