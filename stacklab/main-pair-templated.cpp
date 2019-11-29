#include <iostream>
#include <string>
#include "PairTemplated.h"
using namespace std;

int main() {
    Pair<int> pair1(10, 20);
    cout << "pair1.getFirst returns " << pair1.getFirst() << endl;
    pair1.invert();
    cout << "After invert pair, pair1.getFirst returns " << pair1.getFirst() << endl;

    Pair<double> pair2(1.1, 2.2);
    cout << "pair2.getFirst returns " << pair2.getFirst() << endl;
    pair2.invert();
    cout << "After invert pair, pair2.getFirst returns " << pair2.getFirst() << endl;

    Pair<string> pair3("word1", "word2");
    cout << "pair3.getFirst returns " << pair3.getFirst() << endl;
    pair3.invert();
    cout << "After invert pair, pair3.getFirst returns " << pair3.getFirst() << endl;
    return 0;
}
