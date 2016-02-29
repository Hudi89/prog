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
ostream& operator<<(ostream& out, const vector<T> &v2){
    out <<v2.size() << endl;
    for(int a=0;a<v2.size();a++){
        out << v2[a] << endl;
    }
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

void matrixBeolvas(istream &in, vector<vector<Complex> > &v ){
    int w,h;
    in >> w>> h;
    v.resize(h);
    for(int a =0;a<h;a++){
        v[a].resize(w);
        for(int b = 0;b<w;b++){
            in >> v[a][b];
        }
    }
}

bool parosE(int a) {
    return a % 2 == 0;
}



int osszeg(const vector<Complex> &v){
    int s=0;
    for(int a=0;a<v.size();a++){
        s += v[a].re;
    }
    return s;
}

bool kereses(const vector<vector<Complex> > &v, int &ind){
    bool l = false;
    int i = 0;
    while(!l && i<v.size()){
        l = (osszeg(v[i]) > 0);
        ind = i;
        i = i + 1;
    }
    return l;
}


int main()
{
    ifstream f("asd2.txt");
    vector<vector<Complex> > v;
    matrixBeolvas(f,v);

    int ind;
    if(kereses(v,ind)){
        cout << "Megtalalt" << ind <<endl;
    }else{
        cout << "Nincs pozitiv sor" << endl;
    }

    cout << v;
    return 0;
}
