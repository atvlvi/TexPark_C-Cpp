#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Magazin.h"
#include "Book.h"

const int size_array = 16;

int main() {
    Item **array = new Item *[size_array];
    for (int i = 0; i < size_array; i++) {
        if (i % 2 == 0) {
            array[i] = new Book(rand(), "author name", "book title", "publisher name", 2000 + i);
        } else {
            array[i] = new Magazin(rand(), "magazine title", 64, i, 2017);
        }
    }
    for (int i = 0; i < size_array; i++) {
        array[i]->Show();

        delete (Book *)array[i];
//        std::cout << *array[i];
        std::cout<<std::endl;
    }
    return 0;
}