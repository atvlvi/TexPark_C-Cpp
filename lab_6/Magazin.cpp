//
// Created by views on 31.10.2017.
//

#include "Magazin.h"
#include <iostream>

void Magazin::Show() {
    std::cout<<"inventory number: "<<GetinvNumber()<<std::endl;
    if (isAvailable())
        std::cout<<"magazine is available"<<std::endl;
    else
        std::cout<<"magazine is not available"<<std::endl;
    std::cout<<"volume: "<<Volume()<<std::endl;
    std::cout<<"title: "<<Title()<<std::endl;
    std::cout<<"number: "<<Number()<<std::endl;
    std::cout<<"year of publishing: "<<Year()<<std::endl;
}
int Magazin::Volume() {
    return volume;
}
const char *Magazin::Title() {
    return title;
}
int Magazin::Number() {
    return number;
}
int Magazin::Year() {
    return year;
}