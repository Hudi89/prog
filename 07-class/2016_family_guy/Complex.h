#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

class Complex{
private:
    float re;
    float im;

public:
    Complex();
    Complex(float re, float im=0);

    float abs();

    Complex operator+(const Complex &rh);

    void setRe(float re);
    void setIm(float im);

    float getRe();
    float getIm();

    Complex& operator=(float v);
    Complex& operator+=(const Complex &rh);

    friend std::ostream& operator<<(std::ostream& out, const Complex &rh);
    friend std::istream& operator>>(std::istream& in, Complex &rh);
};

std::ostream& operator<<(std::ostream& out, const Complex &rh);
std::istream& operator>>(std::istream& in, Complex &rh);
#endif // COMPLEX_H_INCLUDED
