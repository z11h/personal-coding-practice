#ifndef STACK_H
#define STACK_H

// define the Stack type
// a new stack is initially empty and has capacity 1
typedef struct Stack {
	double* A = new double[1];    // array for storage
	int capacity = 1;       // capacity of A
	int length = 0;         // number of elements in A
} Stack;

// add element to the top of Stack s
// if Stack s is full, resize the underlying array
void push(Stack& s, double element);

// remove and return the element on top of Stack s
// if Stack s is empty, return NAN
double pop(Stack& s);

#endif
