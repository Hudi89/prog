#include "Complex.h"

Complex::Complex(){/*Szarazegész*/}
Complex::Complex(float re, float im/*=0*/){
    this->re = re;
    this->im = im;
}

float Complex::abs(){
    return sqrt(pow(re,2) + pow(im,2));
}

Complex Complex::operator+(const Complex &b){
    Complex ret;
    ret.re = re + b.re;
    ret.im = im + b.im;
    return ret;
}

Complex& Complex::operator=(float v){
    re = v;
    im = 0;
    return *this;
}
Complex& Complex::operator+=(const Complex &v){
    re += v.re;
    im += v.im;
    return *this;
}


void Complex::setRe(float re){
    this->re = re;
}
void Complex::setIm(float im){
    this->im = im;
}

std::ostream& operator<<(std::ostream& out, const Complex &o){
    out << o.re << ' ' << o.im;
    return out;
}

std::istream& operator>>(std::istream& in, Complex &o){
    in >> o.re >> o.im;
    return in;
}
