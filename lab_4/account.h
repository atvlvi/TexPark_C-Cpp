//
// Created by views on 13.10.2017.
//

#ifndef LAB_4_ACCOUNT_H
#define LAB_4_ACCOUNT_H

#include <ctime>
#include <cstring>
#include "account.h"


class Account {
public:

    Account(int number = 0, const char *lastName = "None", int balance = 0, int transactionsAmount = 0,
            time_t openDate = time(NULL))
            : number(number),
              openDate(openDate),
              balance(balance),
              transactionsAmount(transactionsAmount) {
        size_t length = strlen(lastName) + 1;
        this->lastName = new char[length];
        strncpy(this->lastName, lastName, length);
    }

    Account(const Account &other)
            : number(other.number),
              openDate(other.openDate),
              balance(other.balance),
              transactionsAmount(other.transactionsAmount) {
        size_t length = strlen(other.lastName) + 1;
        lastName = new char[length];
        strncpy(lastName, other.lastName, length);
    }

    ~Account() {
        delete[] lastName;
    }

    void show() const;

    void set(int number, const char *lastName, int balance);

    int getNumber() const;

    const char *getLastName() const;

    time_t getOpenDate() const;

    double getBalance() const;

    int getTransactionsAmount() const;

private:
    int number;
    char *lastName;
    time_t openDate;
    double balance;
    int transactionsAmount;
};

void showAccountsOpenLaterThan(const Account *in, int length, time_t openDate);
void showAccountsOfOwner(const Account *in, int length, const char *lastName);
Account *getNAccountsWithLargestBalance(const Account *in, int length, int n);
void sort(Account const **in, int length);

#endif //LAB_4_ACCOUNT_H
