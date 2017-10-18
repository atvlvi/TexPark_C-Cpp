#include <iostream>
#include <cstdlib>
#include "account.h"
#define ACCOUNT_COUNT 32

using namespace std;

int main(int argc, char** argv) {

    Account *array = new Account[ACCOUNT_COUNT];
    char buf[16];
    char num[8];

    for (int i = 0; i < ACCOUNT_COUNT; i++) {
        strncpy(buf, "Name", 16);
        _itoa_s(rand()%12, num, 8, 10);
        strncat(buf, num, 16);
        if (i % 8 == 0)
            array[i] = *(new Account(i, buf, rand(), rand()));
        else
            array[i] = *(new Account(i, buf, rand(), rand(), rand()));
    }

    cout<<"-- Show all users\n\n";
    for (int i = 0; i < ACCOUNT_COUNT; i++) {
        array[i].show();
    }

    cout<<"-- Show Accounts open later than\n\n";
    showAccountsOpenLaterThan(array, ACCOUNT_COUNT, time(NULL) - 4);

    cout<<"-- Show Accounts of owner \"Name5\"\n\n";
    showAccountsOfOwner(array, ACCOUNT_COUNT, "Name5");

    cout<<"-- Show n (= 6) Accounts with largest balance\n\n";
    Account *nLB = getNAccountsWithLargestBalance(array, ACCOUNT_COUNT, 6);
    for (int i = 0; i < 6; i++) {
        nLB[i].show();
    }

    delete[] array;
    system("pause");
    return 0;
}