//
// Created by views on 31.10.2017.
//

#ifndef LAB_7_DEQUE_H
#define LAB_7_DEQUE_H

template<typename T>
class Deque {
public:
    void pushBack(T source);
    void pushFront(T source);
    T popBack();
    T popFront();

private:
    T *data;
};


#endif //LAB_7_DEQUE_H
