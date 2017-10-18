//
// Created by views on 13.10.2017.
//
#include <ctime>
#include <cstring>
#include <iostream>
#include "account.h"

using namespace std;

void Account::set(int number = 0, const char *lastName = "None", int balance = 0)
{
    this->number = number;
    this->openDate = time(NULL);
    this->balance = balance;
    size_t length = strlen(lastName)+1;
    delete[] this->lastName;
    this->lastName = new char[length];
    strncpy(this->lastName, lastName, length);
}
void Account::show() const {
    cout<<"Account number:\t\t"<<this->number<<endl;
    cout<<"Owner's last name:\t"<<this->lastName<<endl;
    cout<<"Open date:\t\t"<<this->openDate<<endl;
    cout<<"Account balance:\t"<<this->balance<<endl;
    cout<<"Transactions amount:\t"<<this->transactionsAmount<<endl<<endl;
}
int Account::getNumber() const {
    return number;
}
const char *Account::getLastName() const {
    return lastName;
}
time_t Account::getOpenDate() const {
    return openDate;
};
double Account::getBalance() const {
    return  balance;
}
int Account::getTransactionsAmount() const {
    return  transactionsAmount;
}
void showAccountsOpenLaterThan(const Account *in, int length, time_t openDate) {
    for (int i = 0; i < length; i++) {
        if (in[i].getOpenDate() > openDate) {
            in[i].show();
        }
    }
}
void showAccountsOfOwner(const Account *in, int length, const char *lastName) {
    for (int i = 0; i < length; i++) {
        if (strcmp(in[i].getLastName(), lastName) == 0) {
            in[i].show();
        }
    }
}
Account *getNAccountsWithLargestBalance(const Account *in, int length, int n) {
    Account const **sorted = new const Account* [length];
    for (int i = 0; i < length; i++) {
        sorted[i] = &in[i];
    }
    sort(sorted, length);
    Account* out = new Account[n];

    for (int i = 0; i < n; i++) {
        out[i] = *sorted[i];
    }
    return out;
}
void sort(Account const **in, int length) {
    Account const *buf;
    bool flag = true;
    while(flag) {
        flag = false;
        for (int i = 0; i < length-1; i++) {
            if (in[i]->getBalance() < in[i + 1]->getBalance()) {
                buf = in[i];
                in[i] = in[i + 1];
                in[i + 1] = buf;
                flag = true;
            }
        }
    }
}