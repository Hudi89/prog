#include "Complex.h"

using namespace std;

Complex::Complex(double R2,double I2){
    R = R2;
    I = I2;
}

Complex::Complex(const Complex &other){
    R = other.R;
    I = other.I;
}
Complex::Complex(int R2){
    R = R2;
    I = 0;
}
Complex::Complex(){}

Complex Complex::conj(){
    Complex ret(R,-I);
    return ret;
}
Complex& Complex::operator=(Complex c){
    R = c.R;
    I = c.I;
    return *this;
}
Complex& Complex::operator=(int rh){
    R = rh;
    I = 0;
    return *this;
}

Complex Complex::operator+(Complex rh){
    return rh += *this;
}
Complex& Complex::operator+=(Complex rh){
    R += rh.R;
    I += rh.I;
    return *this;
}

double Complex::getR(){
    return R;
}
double Complex::getI(){
    return I;
}
void Complex::setR(double v){
    R = v;
}
void Complex::setI(double v){
    I = v;
}


ostream& operator<<(ostream& out,
                     const Complex &c){
    out << c.R << " " << c.I;
    return out;
}

istream& operator>>(istream& in,
                     Complex &c){
    in >> c.R >> c.I;
    return in;
}
