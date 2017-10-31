//
// Created by views on 31.10.2017.
//

#include "Book.h"
#include <iostream>

void Book::Show() {
    std::cout<<"inventory number: "<<GetinvNumber()<<std::endl;
    if (isAvailable())
        std::cout<<"book is available"<<std::endl;
    else
        std::cout<<"book is not available"<<std::endl;
    std::cout<<"author: "<<Author()<<std::endl;
    std::cout<<"title: "<<Title()<<std::endl;
    std::cout<<"publisher: "<<Publisher()<<std::endl;
    std::cout<<"year of publishing: "<<YearOfPublishing()<<std::endl;
}

const char *Book::Author() {
    return author;
}

const char *Book::Title() {
    return title;
}

const char *Book::Publisher() {
    return publisher;
}

int Book::YearOfPublishing() {
    return year;
}