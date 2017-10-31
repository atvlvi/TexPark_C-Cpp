//
// Created by views on 31.10.2017.
//

#ifndef LAB_6_ITEM_H
#define LAB_6_ITEM_H


class Item {
public:

    explicit Item(int invNumber = 0, bool taken = false) : invNumber(invNumber), taken(taken) {}

    virtual void Show() = 0;
    bool isAvailable();
    int GetinvNumber();
    void Take();
    void Return();

private:

protected:
    int invNumber;
    bool taken;
};


#endif //LAB_6_ITEM_H
