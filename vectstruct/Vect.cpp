#include "Vect.h"
#include <cstdlib>

Vect vect_construct(unsigned int n, int val) {
    Vect my_vect;

    my_vect.size = n;
    my_vect.capacity = n*2;

    my_vect.arr = new int[my_vect.capacity];

    for (int i = 0; i < my_vect.size; i++) {
        my_vect.arr[i] = val;
    }

    return my_vect;
}

unsigned int vect_size(const Vect &v) {
    return v.size;
}

unsigned int vect_capacity(const Vect &v) {
    return v.capacity;
}

bool vect_empty(const Vect &v) {
    return (vect_size(v) == 0) ? true : false ;
}

void vect_resize(Vect &v, unsigned int n) {
    v.capacity = n;

    int* temp_arr = new int[v.capacity];

    if (n < v.size) {
        // copy n elements from original array into new one
        for (int i = 0; i < n; i++) {
            temp_arr[i] = v.arr[i];
        }
        // update size to reflect the new size of the vector
        v.size = n;
    } else {     // our new array size is larger than original array size, can just copy old array and grow capacity without touching size
        for (int i = 0; i < n; i++) {
            temp_arr[i] = v.arr[i];
        }
    }

    // delete old array
    delete [] v.arr;

    // assign v.arr pointer to temp_arr pointer
    v.arr = temp_arr;

    // delete the temp_arr ptr, no longer needed
    temp_arr = nullptr;
}

int& vect_at(Vect &v, unsigned int idx) {
    if (idx <= v.size-1) {
//        int& elem_reference = v.arr[idx];
        return v.arr[idx];
    } else {
        exit(1);
    }
}

void vect_erase(Vect &v, unsigned int idx) {
    if (idx <= v.size-1) {
        for (int i = idx; i < v.size-1; i++) { // valid index to remove, shift everything down
            v.arr[i] = v.arr[i+1];
        }

        v.size--;
    } else {
        exit(1);
    }
}

void vect_push_back(Vect &v, int val) {

    // if vector is fully loaded, double capacity
    if (v.capacity == v.size) {
        v.capacity *= 2; // double capacity
        int* new_Arr = new int[v.capacity];

        for (int i = 0; i < v.size; i++) { // copy n elements over from old array to new one
                new_Arr[i] = v.arr[i];
        }

        delete [] v.arr;
        v.arr = new_Arr;
    }

    v.arr[v.size] = val;

    // increment size of vector
    v.size++;
}

void vect_insert(Vect &v, unsigned int idx, int val) {
    if (idx <= v.size-1) { // valid index to remove, shift everything up

        // if vector is fully loaded when we insert the new element, double capacity
        if (v.capacity == v.size) {
            v.capacity *= 2; // double capacity
            int* new_Arr = new int[v.capacity];

            for (int i = 0; i < v.size; i++) { // copy n elements over from old array to new one
                    new_Arr[i] = v.arr[i];
            }

            delete [] v.arr;
            v.arr = new_Arr;
        }

        // increment size of array
        v.size++;

        // shift all elements up one, traversing from the right to left
        for (int i = v.size-1; i > idx; i--) {
            v.arr[i] = v.arr[i-1];
        }

        // insert value into array at index
        v.arr[idx] = val;

    } else {
        exit(1);
    }
}

void vect_clear(Vect &v) {
    if (v.size >= 20) {
        delete [] v.arr;

        v.capacity = 20;
        v.size = 0;
        v.arr = new int[v.capacity];
    } else {
        v.size = 0;
    }
}

void vect_destruct(Vect &v) {
    v.size = 0;
    v.capacity = 0;
    delete[] v.arr;
}

