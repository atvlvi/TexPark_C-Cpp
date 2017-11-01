#include <iostream>
#include "fraction.h"

using namespace std;

const int sizeArray = 32;
void edit(Fraction **array, int length);

int main() {
    Fraction **array = new Fraction* [sizeArray];
    for(unsigned int i = 0; i < sizeArray; i++){
        array[i] = new Fraction(i + 1, i + 2);
    }
    edit(array, sizeArray);
    for (int i = 0; i < sizeArray; i++) {
        cout<<*array[i]<<endl;
    }
    delete[] array;
    return 0;
}

void edit(Fraction **array, int length) {
    for (int i = 0; i < length-1; i++) {
        if(i % 2 == 0) {
            *array[i] += *array[i + 1];
        }
    }
}