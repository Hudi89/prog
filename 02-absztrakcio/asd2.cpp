#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct Complex{
    float re;
    float im;
};

istream& operator>>(istream& in, Complex& c){
    in >> c.re >> c.im;
    return in;
}
ostream& operator<<(ostream& out, const Complex& c){
    out << c.re << " " << c.im;
    return out;
}


template<class T>
istream& operator>>(istream& in, vector<T> &v2){
    int n;
    in >> n;
    for(int a=0;a<n;a++){
        T temp;
        in >> temp;
        v2.push_back(temp);
    }
    return in;
}

template<class T>
void kiir(const vector<T> &v2){
    for(int a=0;a<v2.size();a++){
        cout << v2[a] << endl;
    }
}

float cabs(const Complex &c){
    return sqrt(c.im * c.im + c.re * c.re);
}

float osszegzes(vector<Complex>& v){
    float ret = 0;
    for(int a=0;a<v.size();a++){
        ret += cabs(v[a]);
    }
    return ret;
}

int main()
{
    ifstream f("asd.txt");
    vector<Complex> v;
    vector<Complex> v2;
    f >>  v >> v2;

    kiir(v);
    kiir(v2);
    cout << "Ered" << osszegzes(v) << endl;
    return 0;
}
