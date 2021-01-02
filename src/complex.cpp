#include <iostream>
#include "complex.h"

complexNum operator + (const complexNum& a, const complexNum& b) {
    complexNum result{};

    result.real = a.real + b.real;
    result.img = a.img + b.img;

    return result;
}

void operator += (complexNum& a, const complexNum& b) {
    a = a + b;
}


complexNum operator - (const complexNum& a, const complexNum& b) {
    complexNum result{};

    result.real = a.real - b.real;
    result.img = a.img - b.img;

    return result;
}

void operator -= (complexNum& a, const complexNum& b) {
    a = a - b;
}


complexNum operator * (const complexNum& a, const complexNum& b) {
    complexNum result{};

    result.real = a.real * b.real - a.img * b.img;
    result.img = a.real * b.img + a.img * b.real;

    return result;
}

void operator *= (complexNum& a, const complexNum& b) {
    a = a * b;
}


complexNum operator / (const complexNum& a, const complexNum& b) {
    complexNum result{};

    if (b.real == 0 && b.img == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    else {
        double d = b.real * b.real + b.img * b.img;
        result.real = (a.real * b.real + a.img * b.img) / d;
        result.img = (a.img * b.real - a.real * b.img) / d;

        return result;
    }
}

void operator /= (complexNum& a, const complexNum& b) {
    a = a / b;
}


std::ostream& operator << (std::ostream& result, const complexNum& a) {
    if (a.real == 0 && a.img == 0) { result << 0; }
    else {
        if (a.real != 0) {
            result << a.real;
            if (a.img > 0) { result << '+'; }
        }
        if (a.img != 0) {
            if (a.img == 1) { result << 'i'; }
            else if (a.img == -1) { result << "-i"; }
            else { result << a.img << 'i'; }
        }
    }

    return result;
}
