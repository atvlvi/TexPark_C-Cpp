//
// Created by views on 31.10.2017.
//

#ifndef LAB_6_BOOK_H
#define LAB_6_BOOK_H

#include "Item.h"
#include <cstring>

static char *book_strcopy(const char *source) {
    size_t size = strlen(source) + 1;
    char *result = new char[size];
    return strncpy(result, source, size);
}

class Book : public Item {
public:
    Book() {
        this->author = nullptr;
        this->title = nullptr;
        this->publisher = nullptr;
    }

    Book(const Book &other) : year(other.year) {
        this->author = book_strcopy(other.author);
        this->title = book_strcopy(other.title);
        this->publisher = book_strcopy(other.publisher);
    }

    Book(int invNumber, const char *author, const char *title, const char *publisher, int year) : Item(invNumber), year(year) {
        this->author = book_strcopy(author);
        this->title = book_strcopy(title);
        this->publisher = book_strcopy(publisher);
        this->invNumber = invNumber;
    }

    ~Book() {
        delete this->author;
        delete this->title;
        delete this->publisher;
    }

    void Show();

    const char *Author();

    const char *Title();

    const char *Publisher();

    int YearOfPublishing();

private:
    char *author;
    char *title;
    char *publisher;
    int year = 0;
};


#endif //LAB_6_BOOK_H
