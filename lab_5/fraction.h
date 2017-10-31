//
// Created by views on 22.10.2017.
//

#ifndef LAB_5_FRACTION_H
#define LAB_5_FRACTION_H

#include <iostream>
#include <ostream>

class Fraction {
public:
    Fraction(int divisible = 0, unsigned int divisor = 1) : divisible(divisible), divisor(divisor) {
        if (divisor == 0) {
            std::cerr << "Zero division";
            exit(EXIT_FAILURE);
        }
    }

    Fraction();

    int getDivisible();

    int getDivisor();

    friend Fraction& operator+=(Fraction &f1, const Fraction &f2);

    friend Fraction operator-(const Fraction &f);

    friend Fraction operator+(const Fraction &f1, const Fraction &f2);

    friend Fraction operator-(const Fraction &f1, const Fraction &f2);

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);

    friend Fraction operator/(const Fraction &f1, const Fraction &f2);

    friend std::ostream &operator<<(std::ostream &s, const Fraction &f);

    friend bool operator == (const Fraction &f1, const Fraction &f2);

    friend bool operator < (const Fraction &f1, const Fraction &f2);

    friend bool operator <= (const Fraction &f1, const Fraction &f2);

    friend bool operator != (const Fraction &f1, const Fraction &f2);

    friend bool operator > (const Fraction &f1, const Fraction &f2);

    friend bool operator >= (const Fraction &f1, const Fraction &f2);

    operator float() const;

private:

    int divisible;
    unsigned int divisor;

    int nod(int a = 0, int b = 0) const;

    void shorten();
};

#endif //LAB_5_FRACTION_H
