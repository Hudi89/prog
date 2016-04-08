#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <cmath>

class Complex{
    float re;
    float im;

public:
    Complex();
    Complex(float re, float im=0);

    float abs();

    Complex operator+(const Complex &b);
    Complex& operator=(float v);
    Complex& operator+=(const Complex &v);

    void setRe(float re);
    void setIm(float im);

    friend std::ostream& operator<<(std::ostream& out, const Complex &o);
    friend std::istream& operator>>(std::istream& in, Complex &o);
};

std::ostream& operator<<(std::ostream& out, const Complex &o);
std::istream& operator>>(std::istream& in, Complex &o);

#endif // COMPLEX_H_INCLUDED
