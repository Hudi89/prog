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
    v2.resize(n);
    for(int a=0;a<n;a++){
        in >> v2[a];
    }
    return in;
}

template<class T>
istream& beolvas(istream& in, vector<vector<T> > &v2){
    int h,w;
    in >> h >> w;
    v2.resize(h);
    for(int a=0;a<h;a++){
        v2[a].resize(w);
        for(int b=0;b<w;b++){
            in >> v2[a][b];
        }
    }
    return in;
}

template<class T>
ostream& operator<<(ostream& out, const vector<T> &v2){
    out << v2.size() << endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << endl;
    }
    return out;
}

Complex operator+(const Complex &lh,
                  const Complex &rh){
    Complex ret;
    ret.re = lh.re + rh.re;
    ret.im = lh.im + rh.im;
    return ret;
}

Complex osszegzes(const vector<Complex> &v){
    Complex s;
    s.im = 0;
    s.re = 0;
    for(int i=0;is<v.size();i++){
        s.re = s.re + v[i].re;
        s.im = s.im + v[i].im;
    }
    return s;
}

bool kereses(const vector<vector<Complex> > &M,
             int &ind){
    bool l = false;
    int i = 0;
    while(!l && i < M.size()){
        Complex c = osszegzes(M[i]);
        l = (c.im == 0);
        ind = i;
        i = i + 1;
    }
    return l;
}

int main()
{
    ifstream f("asd.txt");
    vector<vector<Complex> > v;
    beolvas(f,v);
    int ind;
    if(kereses(v,ind)){
        cout << "Megvan itte:" << ind << endl;
    }else{
        cout << "Nincs benne!" << endl;
    }
    return 0;
}
