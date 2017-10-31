//
// Created by views on 31.10.2017.
//

#ifndef LAB_6_MAGAZIN_H
#define LAB_6_MAGAZIN_H

#include <cstring>
#include "Item.h"

static char *strcopy(const char *source) {
    size_t size = strlen(source) + 1;
    char *result = new char[size];
    return strncpy(result, source, size);
}

class Magazin : public Item {
public:
    Magazin() {
        this->title = nullptr;
    }

    Magazin(const Magazin &other) : volume(other.volume), number(other.number), year(other.year) {
        this->title = strcopy(other.title);
    }

    Magazin(int invNumber, const char *title, int volume, int number, int year) : Item(invNumber), volume(volume),
                                                                                  number(number), year(year)
    {
        this->title = strcopy(title);
    }

    ~Magazin() {
        delete this->title;
    }

    int Volume();

    const char *Title();

    int Number();

    int Year();

    void Show();

private:
    int volume = 0;
    int number = 0;
    int year = 0;
    char *title;
};


#endif //LAB_6_MAGAZIN_H
