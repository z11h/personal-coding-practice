#ifndef PAIR_H
#define PAIR_H
/* File PairTemplated.h - templated version of Pairs.h
 * This can be used for pairs of integers, double, etc.
 */
template <class baseType>
class Pair {
private:
    baseType elem1;
    baseType elem2;
public:
    Pair(baseType elem1, baseType elem2) : elem1{elem1}, elem2{elem2} {} // constructor
    ~Pair() {} // destructor
    baseType getFirst() {return elem1;}
    void invert() {
        baseType tmp = elem1;
        elem1 = elem2;
        elem2 = tmp;
    }
};
#endif
