#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T> &v){
    int n;
    in >> n;
    v.resize(n);
    for(int a=0;a<n;a++){
        in >> v[a];
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> &v){
    int n;
    out << v.size();
    for(int a=0;a<v.size();a++){
        out << ' ' << v[a];
    }
    return out;
}








class Bolygo{
    string nev;

    double x;
    double y;

    vector<double> holdTomegek;
public:
    double norma() const {
        return sqrt(pow(x,2)+pow(y,2));
    }

    int getHoldakSzama() const {
        return holdTomegek.size();
    }

    friend istream& operator>>(istream& in, Bolygo &o);
    friend ostream& operator<<(ostream& out, Bolygo &o);
};


istream& operator>>(istream& in, Bolygo &o){
    string temp;
    getline(in,temp);
    stringstream majom(temp);
    majom >> o.nev >> o.x >> o.y;
    double temp2;
    while(majom >> temp2){
        o.holdTomegek.push_back(temp2);
    }
    return in;
}
ostream& operator<<(ostream& out, Bolygo &o){
    out << o.nev << ' ' << o.x << ' ' << o.y <<
        ' ' << o.holdTomegek;
    return out;
}

ostream& operator<<(ostream& out, vector<Bolygo> &v){
    int n;
    out << v.size();
    for(int a=0;a<v.size();a++){
        out << endl << v[a];
    }
    return out;
}


enum Exceptions{
    URES_VECTOR
};



int tavMaxKer(const vector<Bolygo> &v){
    int ind = 0;
    if(v.size() == 0){
        throw URES_VECTOR;
    }
    double M = v[0].getHoldakSzama();
    for(int a=1;a<v.size();a++){
        double temp = v[a].getHoldakSzama();
        if(temp > M){
            M = temp;
            ind = a;
        }
    }
    return ind;
}

int main()
{
    ifstream f("asd.txt");
    vector<Bolygo> BolygoinataVector;
    f >> BolygoinataVector;
    cout << BolygoinataVector <<endl<<endl;
    int maxInd = tavMaxKer(BolygoinataVector);
    cout << BolygoinataVector[maxInd] << endl;

    return 0;
}
