#ifndef VECT_H
#define VECT_H

struct Vect {
    int *arr = nullptr;
    unsigned int capacity = 0; // no elements can store
    unsigned int size = 0; // no elements currently held
};

Vect vect_construct(unsigned int n, int val);

unsigned int vect_size(const Vect &v);

unsigned int vect_capacity(const Vect &v);

bool vect_empty(const Vect &v);

void vect_resize(Vect &v, unsigned int n);

int& vect_at(Vect &v, unsigned int idx);

void vect_erase(Vect &v, unsigned int idx);

void vect_push_back(Vect &v, int val);

void vect_insert(Vect &v, unsigned int idx, int val);

void vect_clear(Vect &v);

void vect_destruct(Vect &v);

#endif
