#include "Complex.h"

#include <cmath>

Complex::Complex(){}
Complex::Complex(float re, float im/*=0*/){
    this->re = re;
    this->im = im;
}

float Complex::abs(){
    return sqrt(pow(re,2)+pow(im,2));
}

Complex Complex::operator+(const Complex &rh){
    Complex ret;
    ret.re = re + rh.re;
    ret.im= im + rh.im;
    return ret;
}

void Complex::setRe(float re){
    //(*this).re = re;
    this->re = re;
}
void Complex::setIm(float im){
    this->im = im;
}

float Complex::getRe(){
    return re;
}
float Complex::getIm(){
    return im;
}

Complex& Complex::operator=(float v){
    this->re = v;
    this->im = 0;

    return *this;
}
Complex& Complex::operator+=(const Complex &rh){
    this->re += rh.re;
    this->im += rh.im;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex &rh){
    out << rh.re << " " << rh.im;
    return out;
}
std::istream& operator>>(std::istream& in, Complex &rh){
    in >> rh.re >> rh.im;
    return in;
}
