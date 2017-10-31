//
// Created by views on 22.10.2017.
//

#include "fraction.h"

int Fraction::getDivisible() {
    return this->divisible;
};

int Fraction::getDivisor() {
    return this->divisor;
}

Fraction& operator+=(Fraction &f1, const Fraction &f2) {
    f1.divisible = f1.divisible * f2.divisor + f2.divisible * f1.divisor;
    f1.divisor *= f2.divisor;
    f1.shorten();
    return f1;
}

Fraction operator-(const Fraction &f) {
    return {f.divisible, f.divisor};
}

Fraction operator+(const Fraction &f1, const Fraction &f2) {
    Fraction result(f1.divisible * f2.divisor + f2.divisible * f1.divisor, f1.divisor * f2.divisor);
    result.shorten();
    return result;
}

Fraction operator-(const Fraction &f1, const Fraction &f2) {
    return f1 + (-f2);
}

Fraction operator*(const Fraction &f1, const Fraction &f2) {
    Fraction result = Fraction(f1.divisible * f2.divisible, f1.divisor * f2.divisor);
    result.shorten();
    return result;
}

Fraction operator/(const Fraction &f1, const Fraction &f2) {
    Fraction result = Fraction(f1.divisible * f2.divisor, f1.divisor * f2.divisible);
    result.shorten();
    return result;
}

bool operator == (const Fraction &f1, const Fraction &f2) {
    return (f1.divisible == f2.divisible and f1.divisor == f2.divisor);
}

bool operator != (const Fraction &f1, const Fraction &f2) {
    return !(f1 == f2);
}

bool operator < (const Fraction &f1, const Fraction &f2) {
    return (f1.divisible * f2.divisor < f2.divisible * f1.divisor);
}

bool operator >= (const Fraction &f1, const Fraction &f2) {
    return !(f1 < f2);
}

bool operator <= (const Fraction &f1, const Fraction &f2) {
    return (f1 == f2 or f1 < f2);
}

bool operator > (const Fraction &f1, const Fraction &f2) {
    return !(f1 <= f2);
}

std::ostream &operator<<(std::ostream &s, const Fraction &f) {
    s << f.divisible << '/' << f.divisor;
    return s;
}

Fraction::operator float() const {
    return float(divisible) / divisor;
}

int Fraction::nod(int a, int b) const {
    if (a == 0 and b == 0) {
        a = int(divisible);
        b = divisor;
    }
    if (a < 0) {
        a *= -1;
    }
    while (a != 0 and b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (a + b);
}

void Fraction::shorten() {
    int n = this->nod();
    divisible /= n;
    divisor /= n;
}
