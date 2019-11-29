#ifndef PAIR_H
#define PAIR_H

// File Pair.h - pair of integers
class Pair {
private:
    int elem1;
    int elem2;
public:
    Pair(int elem1, int elem2) : elem1{elem1}, elem2{elem2} {}
    ~Pair();
    int getFirst() { return elem1; }
    void invert() {
        int tmp = elem1;
        elem1 = elem2;
        elem2 = tmp;
    }
};

#endif
