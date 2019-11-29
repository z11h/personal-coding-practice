#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

template <typename T>
class Stack {
    LinkedList<T> list;
    
    public:
    bool empty();
    T& peek();
    void pop();
    void push(const T&);
    
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << stack.list;
        return os;
    }
};

template <typename T>
bool Stack<T>::empty() {
	
	return !(list.length() > 0);
}

template <typename T>
T& Stack<T>::peek() {
	
	return list.front();
	
}

template <typename T>
void Stack<T>::pop() {
	list.pop_front();
}

template <typename T>
void Stack<T>::push(const T& elem) {
	list.push_front(elem);
}

#endif