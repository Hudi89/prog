#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Exception {
    URES_MATRIX,
    NEGATIVE_SIZE
};

struct Complex
{
    int Re;
    int Im;
};

istream& operator>>(istream &in, Complex &c);

template<typename T>
istream& operator>>(istream& in, vector<T> &a)
{
    int size;
    in >> size;
    if(size < 0) {
        throw NEGATIVE_SIZE;
    }
    for(int i = 0; i < size; ++i)
    {
        T temp;
        in >> temp;
        a.push_back(temp);
    }
    return in;
}

//Összegzés tétel Vectoron
int& osszeg(const vector<int> &v);
//Megszámlálás tétel Vectoron
int& szamol(const vector<int> &v);
//Maximum keresés tétel Vectoron
int& maxVector(const vector<int> &a);
//Maximumba ágyazott Összegzés Mátrixon
int& maximumOsszegMatrix(const vector<vector<int> > &a);
//Feltétel függvény
bool negativE(int a);
//Optimista keresés tétel Vectoron
bool& keresOptimistaVector(const vector<int> &a);
//Pesszimista keresés tétel Vectoron
bool& keresPesszimistaVector(const vector<int> &a);
//Feltételes Maximum kiválasztás tétel Vectoron
int& feltetelesMaximumKeresesVector(const vector<int> &a);

int osszegVector(const vector<int> &a);
int feltMaxKerOsszeg(const vector<vector<int> > &a );

void menu();

#endif // MYHEADER_H_INCLUDED
