#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

struct complexNum {
    double real;
    double img;
};

complexNum operator + (const complexNum& a, const complexNum& b);
void operator += (complexNum& a, const complexNum& b);

complexNum operator - (const complexNum& a, const complexNum& b);
void operator -= (complexNum& a, const complexNum& b);

complexNum operator * (const complexNum& a, const complexNum& b);
void operator *= (complexNum& a, const complexNum& b);

complexNum operator / (const complexNum& a, const complexNum& b);
void operator /= (complexNum& a, const complexNum& b);

std::ostream& operator << (std::ostream& result, const complexNum& a);

#endif //COMPLEX_COMPLEX_H
