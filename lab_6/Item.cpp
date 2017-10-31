//
// Created by views on 31.10.2017.
//
#include <iostream>
#include "Item.h"

bool Item::isAvailable() {
    return !this->taken;
}

int Item::GetinvNumber() {
    return this->invNumber;
}

void Item::Take() {
    this->taken = true;
}

void Item::Return() {
    this->taken = false;
}