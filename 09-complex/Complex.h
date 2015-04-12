#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

class Complex{
    double R;
    double I;

public:
    Complex(double R2,double I2);

    Complex(const Complex &other);
    Complex(int R2);
    Complex();

    Complex conj() const;
    Complex& operator=(Complex c);
    Complex& operator=(int rh);

    Complex operator+(Complex rh) const;
    Complex& operator+=(Complex rh);

    double getR() const;
    double getI() const;
    void setR(double v);
    void setI(double v);

    friend std::ostream& operator<<(std::ostream& out,
                     const Complex &c);
    friend std::istream& operator>>(std::istream& in,
                     Complex &c);
};

std::ostream& operator<<(std::ostream& out,
                     const Complex &c);
std::istream& operator>>(std::istream& in,
                     Complex &c);
#endif // COMPLEX_H_INCLUDED
