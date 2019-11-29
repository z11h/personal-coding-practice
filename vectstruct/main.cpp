#include <iostream>
#include "Vect.h"

using namespace std;

int main()
{
    Vect test_vect = vect_construct(10, 18);
    for (int i = 0; i < test_vect.size; i++) {
        cout << test_vect.arr[i] << endl;
    }

    vect_resize(test_vect, 7);


    cout << "-------" << endl;
    for (int i = 0; i < test_vect.size; i++) {
        cout << test_vect.arr[i] << endl;
    }

    cout << vect_size(test_vect) << endl;
	return 0;
}
